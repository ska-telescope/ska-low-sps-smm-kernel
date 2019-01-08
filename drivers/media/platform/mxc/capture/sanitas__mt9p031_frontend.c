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
 * 2015/09/29 | Davide Rizzi | First Attempt
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/clk.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/errno.h>
#include <linux/stat.h>
#include <linux/mutex.h>


#define DRIVER_NAME "sanitas_mt9p031_frontend"

/* ------------------------------------------------------------------------------------------------
 * REGISTERS DECLARATION
 * ------------------------------------------------------------------------------------------------ */

#define REGISTER_MAKE_REGISTERS
#define REGISTER_MAKE_SYSFS

static ssize_t storeRegister(
		struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t count);
static ssize_t showRegister(
		struct device *dev,
		struct device_attribute *attr,
		char *buf);

#include "register_map.h"
#include "MT9P031_FE_VIDEO_CTRL.h"

struct MT9P031_FE_VIDEO_CTRL_deviceData
{
	struct spi_device* spi;
	int irq;

	struct mutex lock;

	Register_SPIBusOps16 busOps;
};

static ssize_t showRegister(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	struct spi_device *spi = to_spi_device(dev);
	struct MT9P031_FE_VIDEO_CTRL_deviceData *data = spi_get_drvdata(spi);

	u32 tmp;

	Register_SPIRead16(&data->busOps, reg, &tmp);

	return sprintf(buf, "%d\n", tmp);
}

static ssize_t storeRegister(
		struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t count)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	struct spi_device *spi = to_spi_device(dev);
	struct MT9P031_FE_VIDEO_CTRL_deviceData *data = spi_get_drvdata(spi);

	u32 val;
	int err;

	err = kstrtoint(buf, 0, &val);
	if (err)
		return err;

	Register_SPIWrite16(&data->busOps, reg, val);

	return count;
}

// ------------------------------------------------------------------------------------------------

static ssize_t listRegistersMap(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	return Registers_List(MT9P031_FE_VIDEO_CTRL_registers, buf, PAGE_SIZE);
}
static DEVICE_ATTR(ListRegistersMap, S_IRUGO, listRegistersMap, 0);

static ssize_t dumpRegistersMap(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct spi_device *spi = to_spi_device(dev);
	struct MT9P031_FE_VIDEO_CTRL_deviceData *data = spi_get_drvdata(spi);

	return Registers_SPIDump16(&data->busOps, MT9P031_FE_VIDEO_CTRL_registers, buf, PAGE_SIZE);
}
static DEVICE_ATTR(DumpRegistersMap, S_IRUGO, dumpRegistersMap, 0);

static struct attribute* MT9P031_FE_VIDEO_CTRL_sysfsControl_attributes[] = {
		&dev_attr_ListRegistersMap,
		&dev_attr_DumpRegistersMap,
		NULL
};

static const struct attribute_group MT9P031_FE_VIDEO_CTRL_sysfsControl_group = {
		.name = "control",
		.attrs = MT9P031_FE_VIDEO_CTRL_sysfsControl_attributes,
};

// ------------------------------------------------------------------------------------------------

static int mt9p031Frontend_SPIRead(
		struct spi_device* dev,
		u32 reg,
		u16* data)
{
	struct MT9P031_FE_VIDEO_CTRL_deviceData *deviceData = spi_get_drvdata(dev);
	struct spi_transfer xfer;
	struct spi_message msg;
	int ret = 0;

	//reg += 0x00000100;

	//dev_info(&dev->dev, "SPIRead %08X\n", reg);

	memset(&xfer, 0, (sizeof xfer));

	mutex_lock(&deviceData->lock);

	// 0x03 | addr[23:16] | addr[15:8] | addr[7:0] | dummy | dummy | value_r[15:8] | value_r [7:0]

	u8 bufTx[8];
	bufTx[0] = 0x03;

	bufTx[1] = 0xFF & (reg >> 16);
	bufTx[2] = 0xFF & (reg >> 8);
	bufTx[3] = 0xFF & (reg);

	bufTx[4] = 0x00;
	bufTx[5] = 0x00;
	bufTx[6] = 0x00;
	bufTx[7] = 0x00;

	u8 bufRx[8];
	bufRx[0] = 0x00;
	bufRx[1] = 0x00;
	bufRx[2] = 0x00;
	bufRx[3] = 0x00;
	bufRx[4] = 0x00;
	bufRx[5] = 0x00;
	bufRx[6] = 0x00;
	bufRx[7] = 0x00;

	xfer.tx_buf = bufTx;
	xfer.rx_buf = bufRx;
	xfer.len = 8;
	xfer.bits_per_word = 8;

	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);

	ret = spi_sync(dev, &msg);
	if (ret) {
		dev_err(&dev->dev, "SPIRead error: %d\n", ret);
	}


//u16 tmp2 = (bufRx[7] & 0xFF) << 8 | bufRx[6];

//	dev_info(&dev->dev, "::: %02X %02X %04X %04X\n", bufRx[6], bufRx[7], tmp1, tmp2);

	*data = (bufRx[6] & 0xFF) << 8 | bufRx[7];
//	*data = *((u16*)&bufRx[6]);

	mutex_unlock(&deviceData->lock);
	return ret;
}

static int mt9p031Frontend_SPIWrite(
		struct spi_device* dev,
		u32 reg,
		u16 data)
{
	struct MT9P031_FE_VIDEO_CTRL_deviceData *deviceData = spi_get_drvdata(dev);
	struct spi_transfer xfer;
	struct spi_message msg;
	int ret;

	//reg += 0x00000100;

	mutex_lock(&deviceData->lock);

	// 0x01 | addr[23:16] | addr[15:8] | addr[7:0] | value_2bw[15:8] | value_2bw[7:0]

//	dev_info(&dev->dev, "SPIWrite %08X\n", reg);

	memset(&xfer, 0, (sizeof xfer));

	u8 bufTx[8];
	bufTx[0] = 0x01;

	bufTx[1] = 0xFF & (reg >> 16);
	bufTx[2] = 0xFF & (reg >> 8);
	bufTx[3] = 0xFF & (reg);

	bufTx[4] = 0xFF & (data >> 8);
	bufTx[5] = 0xFF & (data);
	bufTx[6] = 0x00;
	bufTx[7] = 0x00;

	u8 bufRx[8];
	bufRx[0] = 0x00;
	bufRx[1] = 0x00;
	bufRx[2] = 0x00;
	bufRx[3] = 0x00;
	bufRx[4] = 0x00;
	bufRx[5] = 0x00;
	bufRx[6] = 0x00;
	bufRx[7] = 0x00;

	xfer.tx_buf = bufTx;
	xfer.rx_buf = bufRx;
	xfer.len = 8;
	xfer.bits_per_word = 8;
//	xfer.cs_change = false;

	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);

	ret = spi_sync(dev, &msg);
	if (ret) {
		dev_err(&dev->dev, "SPIWrite error: %d\n", ret);
	}

	mutex_unlock(&deviceData->lock);

	return ret;
}

static int mt9p031Frontend_probe(
		struct spi_device *spi)
{
	struct MT9P031_FE_VIDEO_CTRL_deviceData *data;
	int retval;

	struct device_node __maybe_unused *np = spi->dev.of_node;

	dev_info(&spi->dev, "probing\n");

	if (!of_device_is_available(np)) {
		return -ENODEV;
	}

	/* Set up SPI*/
	spi->bits_per_word = 32;
	spi->mode = SPI_MODE_0;
	retval = spi_setup(spi);

	if (retval < 0) {
		dev_err(&spi->dev, "SPI setup error %d\n", retval);
		return retval;
	}

	data = devm_kzalloc(&spi->dev, sizeof(struct MT9P031_FE_VIDEO_CTRL_deviceData), GFP_KERNEL);
	if (!data) {
		retval = -ENOMEM;
		kfree(data);

		goto err_no_mem;
	}

	retval = sysfs_create_group(&spi->dev.kobj, &MT9P031_FE_VIDEO_CTRL_sysfs_group);
	if (retval < 0) {
		dev_err(&spi->dev, "unable to create %s sysfs group\n", MT9P031_FE_VIDEO_CTRL_sysfs_group.name);
		return retval;
	}

	retval = sysfs_create_group(&spi->dev.kobj, &MT9P031_FE_VIDEO_CTRL_sysfsControl_group);
	if (retval < 0) {
		dev_err(&spi->dev, "unable to create %s sysfs group\n", MT9P031_FE_VIDEO_CTRL_sysfsControl_group.name);
		return retval;
	}

	data->spi = spi;
	data->irq = spi->irq;
	mutex_init(&data->lock);


	data->busOps.dev = spi;
	data->busOps.write = mt9p031Frontend_SPIWrite;
	data->busOps.read = mt9p031Frontend_SPIRead;

	spi_set_drvdata(spi, data);

	dev_info(&spi->dev, "probed\n");

err_no_mem:
	return retval;
}

static int mt9p031Frontend_remove(
		struct spi_device *spi)
{
	struct MT9P031_FE_VIDEO_CTRL_deviceData *data = spi_get_drvdata(spi);
	int retval;

	sysfs_remove_group(&spi->dev.kobj, &MT9P031_FE_VIDEO_CTRL_sysfs_group);
	sysfs_remove_group(&spi->dev.kobj, &MT9P031_FE_VIDEO_CTRL_sysfsControl_group);

	spi_set_drvdata(spi, NULL);

	dev_info(&spi->dev, "removed\n");

	return 0;
}

static const struct spi_device_id MT9P031_FE_VIDEO_CTRL_id_table[] = {
		{ "mt9p031_frontend", 0 },
		{ },
};
MODULE_DEVICE_TABLE(spi, MT9P031_FE_VIDEO_CTRL_id_table);

static struct spi_driver MT9P031_FE_VIDEO_CTRL_spi_driver = {
		.driver = {
				.name = DRIVER_NAME,
				.owner = THIS_MODULE,
//		.pm	= &mt9p031Frontend_pm_ops, // No Power management for now
		},
		.probe = mt9p031Frontend_probe,
		.remove = mt9p031Frontend_remove,
		.id_table = MT9P031_FE_VIDEO_CTRL_id_table,
};

module_spi_driver(MT9P031_FE_VIDEO_CTRL_spi_driver);

MODULE_AUTHOR("Sanitas EG srl");
MODULE_DESCRIPTION("Sanitas MT9P031 Sensor Frontend SPI Driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
MODULE_ALIAS("platform:" DRIVER_NAME);
