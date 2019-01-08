/*
 * Copyright (C) 2014-2015 Santas EG srl. All Rights Reserved.
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* DATE       | AUTHOR       | COMMENT
 * -----------|--------------|------------------------------------------
 * 2014/12/05 | Davide Rizzi | First Attempt
 * 2014/12/07 | Davide Rizzi | Added slaveId
 * 2014/01/16 | Davide Rizzi | Added static CS
 */

#include <linux/clk.h>
#include <linux/completion.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/irq.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/spi/spi.h>
#include <linux/spi/spi_bitbang.h>
#include <linux/types.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/delay.h>
#include <linux/vmalloc.h>
//#include <asm/io.h>

#include <linux/platform_data/spi-sanitas.h>

#define DRIVER_NAME "sanitas_spi"

struct spi_sanitas_config {
	unsigned int speed_hz; // DON'T CARE
	unsigned int bpw;      // DON'T CARE
	unsigned int mode;     // DON'T CARE
	u8           cs;
};

enum spi_sanitas_devtype {
	INVENTAMI_SPI, /* SPI on Inventami */
};

struct spi_sanitas_data;

struct spi_sanitas_devtype_data {
	void (* intctrl)(
		struct spi_sanitas_data*,
		int
	);

	int (* config)(
		struct spi_sanitas_data*,
		struct spi_sanitas_config*
	);

	void (* trigger)(
		struct spi_sanitas_data*
	);

	int (* rx_available)(
		struct spi_sanitas_data*
	);

	void (* reset)(
		struct spi_sanitas_data*
	);

	enum spi_sanitas_devtype devtype;
};

struct spi_sanitas_data {
	struct spi_bitbang bitbang;

	struct completion xfer_done;

	struct spi_message* current_message;

	void __iomem* base;
	void __iomem* bufferBase;
	void __iomem* scrap;

	int irq;

	void (* tx)(
		struct spi_sanitas_data*
	);

	void (* rx)(
		struct spi_sanitas_data*
	);

	void*       rx_buf;
	const void* tx_buf;

	unsigned int length;
	unsigned int txfifo; // number of 32 bit words pushed in TX FIFO
	unsigned int count;

	const struct spi_sanitas_devtype_data* devtype_data;

	// InventamiSPI_Registers* registers; 	// registers

	u32 rxFifoSize;
	u32 txFifoSize;

	u32 slaveIds[0];
};

#define spi_sanitas_dump

static inline void
_spi_sanitas_dump(
	struct spi_sanitas_data* spi_sanitas
) {
	return;

	printk(KERN_WARNING  "\n");
	u16 tmp0 = __raw_readw(spi_sanitas->base + 0x00);
	u16 tmp2 = __raw_readw(spi_sanitas->base + 0x02);
	u16 tmp4 = __raw_readw(spi_sanitas->base + 0x04);
	u16 tmp6 = __raw_readw(spi_sanitas->base + 0x06);

	u16 tmp8 = __raw_readw(spi_sanitas->base + 0x08);
	u16 tmpA = __raw_readw(spi_sanitas->base + 0x0A);
	u16 tmpC = __raw_readw(spi_sanitas->base + 0x0C);
	u16 tmpE = __raw_readw(spi_sanitas->base + 0x0E);

	printk(KERN_WARNING  "%04X %04X %04X %04X %04X %04X %04X %04X\n", tmp0, tmp2, tmp4, tmp6, tmp8, tmpA, tmpC, tmpE);
}


static inline unsigned
spi_sanitas_get_tx_fifosize(
	struct spi_sanitas_data* spi_sanitas
) {
	//printk(KERN_WARNING  "spi_sanitas_get_fifosize\n");

	//REGISTER(InventamiSPI_FIFOSizes, sizes);
	//REGISTER_READ(spi_sanitas, fifoSizes, sizes);

//	printk(KERN_WARNING "FIFO Sizes = %d %d\n", sizes.bits.tx, sizes.bits.rx);

	return spi_sanitas->txFifoSize;
}

#define SANITAS_SPI_BUF_RX(type)                                                \
static void spi_sanitas_buf_rx_ ## type(struct spi_sanitas_data* spi_sanitas) { \
	type val = __be16_to_cpu(__raw_readw(spi_sanitas->bufferBase));             \
	if (spi_sanitas->rx_buf) {													\
		*(type*)spi_sanitas->rx_buf = val;                                      \
		spi_sanitas->rx_buf+= sizeof(type);                                     \
	}                                                                           \
	spi_sanitas_dump(spi_sanitas);                                              \
}
//		printk(KERN_WARNING "spi_sanitas_buf_rx %04X\n", val);                  \


#define SANITAS_SPI_BUF_TX(type)                                                \
static void spi_sanitas_buf_tx_ ## type(struct spi_sanitas_data* spi_sanitas) { \
	type val = 0;                                                               \
	if (spi_sanitas->tx_buf) {                                                  \
		val = __cpu_to_be16(*(type*)spi_sanitas->tx_buf);                       \
		spi_sanitas->tx_buf += sizeof(type);                                    \
	}                                                                           \
	spi_sanitas->count -= sizeof(type);                                         \
	__raw_writew(val, spi_sanitas->bufferBase);                                 \
	spi_sanitas_dump(spi_sanitas);\
}
//	printk(KERN_WARNING "spi_sanitas_buf_tx %04X\n", val);                      \




SANITAS_SPI_BUF_RX(u8)
SANITAS_SPI_BUF_TX(u8)
SANITAS_SPI_BUF_RX(u16)
SANITAS_SPI_BUF_TX(u16)
SANITAS_SPI_BUF_RX(u32)
SANITAS_SPI_BUF_TX(u32)

static inline void __maybe_unused
inventami_spi_reset(
	struct spi_sanitas_data* spi_sanitas
) {
	//printk(KERN_WARNING "inventami_spi_reset\n");
	spi_sanitas_dump(spi_sanitas);
	__raw_writew(0x00000000, spi_sanitas->base + INVENTAMI_SPI_FIFO_PTR_ADD);
	__raw_writew(0x00000000, spi_sanitas->base + INVENTAMI_SPI_FIFO_PTR_ADD + 2);
	spi_sanitas_dump(spi_sanitas);
}

static void __maybe_unused
inventami_spi_intctrl(
	struct spi_sanitas_data* spi_sanitas,
	int                      enable
) {
	// printk(KERN_WARNING  "inventami_spi_intctrl (enable = %d)\n", enable);
}

static void __maybe_unused
inventami_spi_trigger(
	struct spi_sanitas_data* spi_sanitas
) {
	// printk(KERN_WARNING  "inventami_spi_trigger (txfifo = %d, length = %d)\n", spi_sanitas->txfifo, spi_sanitas->length);

	spi_sanitas_dump(spi_sanitas);
	__raw_writew(spi_sanitas->length, spi_sanitas->base + INVENTAMI_SPI_CMD_TX_ADD);
	spi_sanitas_dump(spi_sanitas);
}

static int __maybe_unused
inventami_spi_config(
	struct spi_sanitas_data*   spi_sanitas,
	struct spi_sanitas_config* config
) {
//	printk(KERN_WARNING  "inventami_spi_config cs = %02X\n", config->cs);
	spi_sanitas_dump(spi_sanitas);

	u32 slaveId = spi_sanitas->slaveIds[config->cs];

	if(slaveId == 0xFFFFFFFF) {
		// printk(KERN_ERR "SlaveID for CS %d is invalid\n", config->cs);
		return -EINVAL;
	}

	inventami_spi_reset(spi_sanitas);

	//slaveId >>= 8;
	slaveId &= 0x000000FF;

	// printk(KERN_WARNING "inventami_spi_config slaveId = %02X\n", slaveId);

	__raw_writew((u16)slaveId, spi_sanitas->base + INVENTAMI_SPI_CHIP_SELECTS_ADD);
	spi_sanitas_dump(spi_sanitas);

	return 0;
} /* inventami_spi_config */

static int __maybe_unused
inventami_spi_rx_available(
	struct spi_sanitas_data* spi_sanitas
) {
	// printk(KERN_WARNING  "inventami_spi_rx_available: ");
	spi_sanitas_dump(spi_sanitas);
	u16 tmp = __raw_readw(spi_sanitas->base + INVENTAMI_SPI_CMD_RX_ADD);

	// printk(KERN_WARNING  "%d\n", tmp);

	return tmp;
}

static int __maybe_unused
inventami_spi_tx_remaining(
	struct spi_sanitas_data* spi_sanitas
) {
	spi_sanitas_dump(spi_sanitas);
	u16 tmp = __raw_readw(spi_sanitas->base + INVENTAMI_SPI_CMD_RX_ADD);

	//printk(KERN_WARNING  "inventami_spi_tx_remaining: %d\n", tmp);

	return tmp;
}

static struct spi_sanitas_devtype_data inventami_spi_devtype_data = {
	.intctrl      = inventami_spi_intctrl,
	.config       = inventami_spi_config,
	.trigger      = inventami_spi_trigger,
	.rx_available = inventami_spi_rx_available,
	.reset        = inventami_spi_reset,
	.devtype      = INVENTAMI_SPI,
};

static struct platform_device_id spi_sanitas_devtype[] = {
	{
		.name        = "inventami-spi",
		.driver_data = (kernel_ulong_t)&inventami_spi_devtype_data,
	},
	{/* sentinel */}
};

static const struct of_device_id spi_sanitas_dt_ids[] = {
	{
		.compatible = "sanitas,inventami-spi",
		.data = &inventami_spi_devtype_data,
	},
	{/* sentinel */}
};
MODULE_DEVICE_TABLE(of, spi_sanitas_dt_ids);

static void
spi_sanitas_chipselect(
	struct spi_device* spi,
	int                is_active
) {
	//printk(KERN_WARNING "spi_sanitas_chipselect (%d is_active = %d)\n", spi->chip_select, is_active);

	struct spi_sanitas_data* spi_sanitas = spi_master_get_devdata(spi->master);
//	int active = is_active != BITBANG_CS_INACTIVE;
//	int dev_is_lowactive = !(spi->mode & SPI_CS_HIGH);

	u16 flag = __raw_readw(spi_sanitas->base + INVENTAMI_SPI_FLAGS_STATIC_CS);
	u16 mask = 0x0001 << INVENTAMI_SPI_FLAGS_STATIC_CS_OFF;

//	if(dev_is_lowactive ^ active) {
	if(is_active) {
		flag &= ~mask;
	} else {
		flag |= mask;
	}

	__raw_writew(flag, spi_sanitas->base + INVENTAMI_SPI_FLAGS_STATIC_CS);
}

static void spi_sanitas_push(
	struct spi_sanitas_data* spi_sanitas
) {
	// printk(KERN_WARNING "spi_sanitas_push count=%d txfifo=%d\n", spi_sanitas->count, spi_sanitas->txfifo);

	while (spi_sanitas->txfifo < (spi_sanitas_get_tx_fifosize(spi_sanitas) / 2)) {
		// printk(KERN_WARNING "--> count=%d txfifo=%d\n", spi_sanitas->count, spi_sanitas->txfifo);
		if (!spi_sanitas->count) {
			break;
		}

		spi_sanitas->tx(spi_sanitas);
		spi_sanitas->txfifo++;
	}

	spi_sanitas->devtype_data->trigger(spi_sanitas);
}

static void spi_sanitas_pull(
	struct spi_sanitas_data* spi_sanitas)
{
	// printk(KERN_WARNING "spi_sanitas_pull\n");

	//spi_sanitas->devtype_data->reset(spi_sanitas);

	while (spi_sanitas->txfifo) {
	//while (spi_sanitas->devtype_data->rx_available(spi_sanitas)) {
		spi_sanitas->rx(spi_sanitas);
		spi_sanitas->txfifo--;
	}
}

#ifndef SANITAS_SPI_POLLING
static irqreturn_t
spi_sanitas_isr(
	int   irq,
	void* dev_id
) {
	printk(KERN_WARNING "spi_sanitas_isr (irq = %d)\n", irq);

	struct spi_sanitas_data* spi_sanitas = dev_id;

	while (spi_sanitas->devtype_data->rx_available(spi_sanitas)) {
		spi_sanitas->rx(spi_sanitas);
		spi_sanitas->txfifo--;
	}

	if (spi_sanitas->count) {
		spi_sanitas_push(spi_sanitas);
		return IRQ_HANDLED;
	}

	if (spi_sanitas->txfifo) {
	/* No data left to push, but still waiting for rx data,
	 * enable receive data available interrupt.
	 */
		spi_sanitas->devtype_data->intctrl(spi_sanitas, MXC_INT_RR);
		return IRQ_HANDLED;
	}

	spi_sanitas->devtype_data->intctrl(spi_sanitas, 0);
	complete(&spi_sanitas->xfer_done);

	return IRQ_HANDLED;
} /* spi_sanitas_isr */
#endif

static int
spi_sanitas_setupxfer(
	struct spi_device*   spi,
	struct spi_transfer* transfer
) {
//	printk(KERN_WARNING "spi_sanitas_setupxfer\n");

	struct spi_sanitas_data*  spi_sanitas = spi_master_get_devdata(spi->master);
	struct spi_sanitas_config config;

	config.bpw      = transfer ? transfer->bits_per_word : spi->bits_per_word;
	config.speed_hz = transfer ? transfer->speed_hz : spi->max_speed_hz;
	config.mode     = spi->mode;
	config.cs       = spi->chip_select;

	if (!config.speed_hz) {
		config.speed_hz = spi->max_speed_hz;
	}

	if (!config.bpw) {
		config.bpw = spi->bits_per_word;
	}

	config.bpw = 16; // Override here

	/* Initialize the functions for transfer */
	if (config.bpw <= 8) {
		spi_sanitas->rx = spi_sanitas_buf_rx_u8;
		spi_sanitas->tx = spi_sanitas_buf_tx_u8;
	} else if (config.bpw <= 16) {
		spi_sanitas->rx = spi_sanitas_buf_rx_u16;
		spi_sanitas->tx = spi_sanitas_buf_tx_u16;
	} else {
		spi_sanitas->rx = spi_sanitas_buf_rx_u32;
		spi_sanitas->tx = spi_sanitas_buf_tx_u32;
	}

	spi_sanitas->devtype_data->config(spi_sanitas, &config);

	return 0;
} /* spi_sanitas_setupxfer */

static int
spi_sanitas_transfer(
	struct spi_device*   spi,
	struct spi_transfer* transfer
) {
	//printk(KERN_WARNING "spi_sanitas_transfer\n");

	struct spi_sanitas_data* spi_sanitas = spi_master_get_devdata(spi->master);

	spi_sanitas->tx_buf = transfer->tx_buf;
	spi_sanitas->rx_buf = transfer->rx_buf;
	spi_sanitas->count  = transfer->len;
	spi_sanitas->length = transfer->len;
	spi_sanitas->txfifo = 0;

	u32 slaveId = spi_sanitas->slaveIds[spi->chip_select];
	slaveId >>= 8;
	slaveId &= 0x000000FF;

	u8* tmp = NULL;
	tmp = vmalloc(transfer->len + 8); // Make sure we have some (4) spare bytes at the end...
	if(!tmp) {
		dev_err(&spi->dev, "unable to allocate temporary buffer");
		return -ENOMEM;
	}

	memset(tmp, 0, transfer->len + 8);

	u32 offset = 0;
	bool last = false;

	if(spi_sanitas->current_message != NULL) {
		if(transfer->transfer_list.next == &spi_sanitas->current_message->transfers) {
			last = true;
		}
	}

	if(slaveId) {
		// dev_info(&spi->dev, "routed transfer [%02X]\n", slaveId);
		if(transfer->len < 128) {
			tmp[0] = (u8)(slaveId);
			tmp[1] = transfer->len & ~0x80;

//			tmp[transfer->len + 3] = 0x00;

			spi_sanitas->length = transfer->len + 3;
			spi_sanitas->count = transfer->len + 3;

			offset = 2;
		} else {
			tmp[0] = (u8)(slaveId);
			tmp[1] = 0x80;

			tmp[2] = (transfer->len >> 8) & 0xFF;
			tmp[3] = transfer->len & 0xFF;

//			tmp[transfer->len + 4] = 0x00;

			spi_sanitas->length = transfer->len + 5;
			spi_sanitas->count = transfer->len + 5;

			offset = 4;
		}

		if(last) {
			tmp[0] &= ~0x80;
		} else {
			tmp[0] |= 0x80;
		}
	}

	if(transfer->tx_buf) {
		memcpy(&tmp[offset], transfer->tx_buf, transfer->len);
	}

	spi_sanitas->tx_buf = (void*)tmp;
	spi_sanitas->rx_buf = (void*)tmp;

	if(spi_sanitas->count & 0x00000001) {
		spi_sanitas->count++;
	}
	//spi_sanitas->count = 2 + 2 * (spi_sanitas->count / 2); // Make sure we are pushing 4 bytes at a time...

	//dev_info(&spi->dev, "transfer %d bytes in %d/2 16bit words\n", spi_sanitas->length, spi_sanitas->count);

	spi_sanitas->devtype_data->reset(spi_sanitas);

	// init_completion(&spi_sanitas->xfer_done);
	spi_sanitas_push(spi_sanitas);
	// Go Polling

	do {
		udelay(25);
//		cpu_relax();
	} while(inventami_spi_tx_remaining(spi_sanitas) > 0);

	spi_sanitas->devtype_data->reset(spi_sanitas);

	spi_sanitas_pull(spi_sanitas);

	if(transfer->rx_buf) {
		memcpy(transfer->rx_buf, &tmp[offset], transfer->len);
	}

	vfree(tmp);
	//wait_for_completion(&spi_sanitas->xfer_done);

	return transfer->len;
} /* spi_sanitas_transfer */

static int spi_sanitas_setup(
	struct spi_device* spi
) {
	struct spi_sanitas_data* spi_sanitas = spi_master_get_devdata(spi->master);

	dev_info(&spi->dev, "device setup: CS: %d -> SlaveID: %08X (mode: %d, bits per word: %d, speed: %d)\n", spi->chip_select, spi_sanitas->slaveIds[spi->chip_select], spi->mode,	spi->bits_per_word, spi->max_speed_hz);

	return 0;
}

static void spi_sanitas_cleanup(
	struct spi_device* spi
) {
	// printk(KERN_WARNING "spi_sanitas_cleanup\n");
}

static inline int
spi_sanitas_prepare_message(
	struct spi_master*  master,
	struct spi_message* msg
) {
	struct spi_sanitas_data* spi_sanitas = spi_master_get_devdata(master);
	spi_sanitas->current_message = msg;

	//printk(KERN_WARNING "spi_sanitas_prepare_message\n");
//	printk(KERN_WARNING "}}}} %08X %08X %08X\n", &msg->transfers, msg->transfers.next, msg->transfers.prev);

	return 0;
} /* spi_sanitas_prepare_message */

static inline int
spi_sanitas_unprepare_message(
	struct spi_master*  master,
	struct spi_message* msg
) {
	struct spi_sanitas_data* spi_sanitas = spi_master_get_devdata(master);
	spi_sanitas->current_message = NULL;

	//printk(KERN_WARNING "spi_sanitas_unprepare_message\n");

	//   struct spi_sanitas_data* spi_sanitas = spi_master_get_devdata(master);

	// NOP

	return 0;
}

/* Parse and set the timing for this device. */
static int
spi_sanitas_routing_setup(
	struct platform_device*  pdev,
	struct device_node*      np,
	struct spi_master*       master,
	struct spi_sanitas_data* spi_sanitas
) {
	u32 slaveId = 0xFFFFFFFF;
	u32 cs_idx;
	int ret;

//	dev_info(&pdev->dev, "Setting Routing for %s\n", np->name);

	/* get the CS index from this child node's "reg" property. */
	ret = of_property_read_u32(np, "reg", &(cs_idx));
	if (ret) {
		dev_err(&pdev->dev, "register missing or invalid\n");
		return ret;
	}

	if(cs_idx >= master->num_chipselect) {
		dev_err(&pdev->dev, "register %d >= %d\n", cs_idx, master->num_chipselect);
		return -EINVAL;
	}

	ret = of_property_read_u32(np, "sanitas,slaveid", &(slaveId));
	if (ret) {
		dev_err(&pdev->dev, "sanitas,slaveid missing or invalid\n");
		slaveId = 0xFFFFFFFF;
//		return -EINVAL;
	}

	spi_sanitas->slaveIds[cs_idx] = slaveId;

	return 0;
}

static int
spi_sanitas_probe(
	struct platform_device* pdev
) {
	printk(KERN_WARNING "spi_sanitas_probe\n");

	struct device_node*         np = pdev->dev.of_node;
	struct device_node*         child;
	const struct of_device_id*  of_id = of_match_device(spi_sanitas_dt_ids, &pdev->dev);
	struct spi_sanitas_master*  sanitas_platform_info = dev_get_platdata(&pdev->dev);
	struct spi_master*          master;
	struct spi_sanitas_data*    spi_sanitas;
	struct resource*            res;
	int ret;
	int num_cs;

	if (!np && !sanitas_platform_info) {
		dev_err(&pdev->dev, "can't get the platform data\n");
		return -EINVAL;
	}

	ret = of_property_read_u32(np, "sanitas,spi-num-chipselects", &num_cs);

	if (ret < 0) {
		if (sanitas_platform_info) {
			num_cs = sanitas_platform_info->num_chipselect;
		} else {
			return ret;
		}
	}

	master = spi_alloc_master(&pdev->dev, sizeof(struct spi_sanitas_data) + sizeof(u32) * num_cs);

	if (!master) {
		return -ENOMEM;
	}

	platform_set_drvdata(pdev, master);

	master->bits_per_word_mask = 0;
	master->bus_num        = pdev->id;
	master->num_chipselect = num_cs;

	spi_sanitas = spi_master_get_devdata(master);
	spi_sanitas->bitbang.master = master;

	spi_sanitas->bitbang.chipselect                = spi_sanitas_chipselect;
	spi_sanitas->bitbang.setup_transfer            = spi_sanitas_setupxfer;
	spi_sanitas->bitbang.txrx_bufs                 = spi_sanitas_transfer;
	spi_sanitas->bitbang.master->setup             = spi_sanitas_setup;
	spi_sanitas->bitbang.master->cleanup           = spi_sanitas_cleanup;
	spi_sanitas->bitbang.master->prepare_message   = spi_sanitas_prepare_message;
	spi_sanitas->bitbang.master->unprepare_message = spi_sanitas_unprepare_message;
	spi_sanitas->bitbang.master->mode_bits         = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;

	init_completion(&spi_sanitas->xfer_done);

	spi_sanitas->devtype_data = of_id ? of_id->data : (struct spi_sanitas_devtype_data*)pdev->id_entry->driver_data;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	dev_info(&pdev->dev, "%08X - %08X\n", res->start, res->end);

	spi_sanitas->base = devm_ioremap_resource(&pdev->dev, res);
	// spi_sanitas->registers = (InventamiSPI_Registers*)spi_sanitas->base;

	//dev_info(&pdev->dev, "Base = %08x\n", spi_sanitas->base);

	if (IS_ERR(spi_sanitas->base)) {
		ret = PTR_ERR(spi_sanitas->base);
		goto out_master_put;
	}

	spi_sanitas->txFifoSize =  __raw_readw(spi_sanitas->base + INVENTAMI_SPI_TXFIFO_SIZE_ADD);
	spi_sanitas->rxFifoSize =  __raw_readw(spi_sanitas->base + INVENTAMI_SPI_RXFIFO_SIZE_ADD);
	dev_info(&pdev->dev, "FIFO Sizes: tx = %d, rx = %d\n", spi_sanitas->txFifoSize, spi_sanitas->rxFifoSize);


	u32 tmp = 0xffffffff;

	ret = of_property_read_u32(np, "bufferbase", &tmp);
	if (ret) {
		dev_err(&pdev->dev, "bufferbase id missing or invalid\n");
		return ret;
	}

	spi_sanitas->bufferBase = devm_ioremap(&pdev->dev, tmp, 0xFFFF); //64KB

	// dev_info(&pdev->dev, "BufferBase = %08x -> %08x\n", tmp, spi_sanitas->bufferBase);

	if (IS_ERR(spi_sanitas->bufferBase)) {
		ret = PTR_ERR(spi_sanitas->bufferBase);
		goto out_master_put;
	}

	for_each_child_of_node(pdev->dev.of_node, child) {
		if (!child->name)
			continue;

		ret = spi_sanitas_routing_setup(pdev, child, master, spi_sanitas);
		if(ret) {
			dev_err(&pdev->dev, "can't configure routing\n");
			return ret;
		}
	}

	u32 tmp2 = 0x08000800;

	spi_sanitas->scrap = devm_ioremap(&pdev->dev, tmp2, 0xFFFF); //64KB

	// dev_info(&pdev->dev, "Scrap = %08x -> %08x\n", tmp2, spi_sanitas->scrap);

	if (IS_ERR(spi_sanitas->scrap)) {
		ret = PTR_ERR(spi_sanitas->scrap);
		goto out_master_put;
	}

	/* NO IRQ at the very moment... Let's go polling!
	spi_sanitas->irq = platform_get_irq(pdev, 0);

	if (spi_sanitas->irq < 0) {
	ret = -EINVAL;
	goto out_master_put;
	}

	ret = devm_request_irq(&pdev->dev, spi_sanitas->irq, spi_sanitas_isr, 0, DRIVER_NAME, spi_sanitas);

	if (ret) {
	dev_err(&pdev->dev, "can't get irq%d: %d\n", spi_sanitas->irq, ret);
	goto out_master_put;
	}
	*/
	spi_sanitas->devtype_data->reset(spi_sanitas);
	spi_sanitas->devtype_data->intctrl(spi_sanitas, 0);

	master->dev.of_node = pdev->dev.of_node;

	ret = spi_bitbang_start(&spi_sanitas->bitbang);

	if (ret) {
		dev_err(&pdev->dev, "bitbang start failed with %d\n", ret);
		goto out_master_put;
	}

	dev_info(&pdev->dev, "probed\n");

	return ret;

out_master_put:
	spi_master_put(master);
	return ret;
} /* spi_sanitas_probe */

static int
spi_sanitas_remove(
	struct platform_device* pdev
) {
	//printk(KERN_WARNING "spi_sanitas_remove\n");

	struct spi_master*       master      = platform_get_drvdata(pdev);
	struct spi_sanitas_data* spi_sanitas = spi_master_get_devdata(master);

	spi_bitbang_stop(&spi_sanitas->bitbang);
	spi_master_put(master);

	return 0;
}

static struct platform_driver spi_sanitas_driver = {
	.driver = {
		.name           = DRIVER_NAME,
		.owner          = THIS_MODULE,
		.of_match_table = spi_sanitas_dt_ids,
	},
	.id_table = spi_sanitas_devtype,
	.probe    = spi_sanitas_probe,
	.remove   = spi_sanitas_remove,
};
module_platform_driver(spi_sanitas_driver);

MODULE_DESCRIPTION("SPI Master Controller driver");
MODULE_AUTHOR("Davide Rizzi, Sanitas EG");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:" DRIVER_NAME);
