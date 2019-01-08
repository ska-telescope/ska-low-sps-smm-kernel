/*
 * Copyright (C) 2011-2014 Freescale Semiconductor, Inc. All Rights Reserved.
 *
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

#include <linux/module.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/irqdesc.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/err.h>
#include <linux/clk.h>
#include <linux/console.h>
#include <linux/io.h>
#include <linux/bitops.h>
#include <linux/delay.h>
#include <linux/fsl_devices.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/workqueue.h>


#include <linux/mipi_csi2.h>

#include "mxc_mipi_csi2.h"

static struct mipi_csi2_info *gmipi_csi2;

void _mipi_csi2_lock(struct mipi_csi2_info *info)
{
	if (!in_irq() && !in_softirq())
		mutex_lock(&info->mutex_lock);
}

void _mipi_csi2_unlock(struct mipi_csi2_info *info)
{
	if (!in_irq() && !in_softirq())
		mutex_unlock(&info->mutex_lock);
}

static inline void mipi_csi2_write(struct mipi_csi2_info *info,
		unsigned value, unsigned offset)
{
	writel(value, info->mipi_csi2_base + offset);
}

static inline unsigned int mipi_csi2_read(struct mipi_csi2_info *info,
		unsigned offset)
{
	return readl(info->mipi_csi2_base + offset);
}

/*!
 * This function is called to enable the mipi csi2 interface.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns setted value
 */
bool mipi_csi2_enable(struct mipi_csi2_info *info)
{
	bool status;

	_mipi_csi2_lock(info);

	if (!info->mipi_en) {
		info->mipi_en = true;
		clk_prepare_enable(info->cfg_clk);
		clk_prepare_enable(info->dphy_clk);
	} else
		mipi_dbg("mipi csi2 already enabled!\n");

	status = info->mipi_en;

	_mipi_csi2_unlock(info);

	return status;
}
EXPORT_SYMBOL(mipi_csi2_enable);

/*!
 * This function is called to disable the mipi csi2 interface.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns setted value
 */
bool mipi_csi2_disable(struct mipi_csi2_info *info)
{
	bool status;

	_mipi_csi2_lock(info);

	if (info->mipi_en) {
		info->mipi_en = false;
		clk_disable_unprepare(info->dphy_clk);
		clk_disable_unprepare(info->cfg_clk);
	} else
		mipi_dbg("mipi csi2 already disabled!\n");

	status = info->mipi_en;

	_mipi_csi2_unlock(info);

	return status;
}
EXPORT_SYMBOL(mipi_csi2_disable);

/*!
 * This function is called to get mipi csi2 disable/enable status.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns mipi csi2 status
 */
bool mipi_csi2_get_status(struct mipi_csi2_info *info)
{
	bool status;

	_mipi_csi2_lock(info);
	status = info->mipi_en;
	_mipi_csi2_unlock(info);

	return status;
}
EXPORT_SYMBOL(mipi_csi2_get_status);

/*!
 * This function is called to set mipi lanes.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns setted value
 */
unsigned int mipi_csi2_set_lanes(struct mipi_csi2_info *info)
{
	unsigned int lanes;

	_mipi_csi2_lock(info);
	mipi_csi2_write(info, info->lanes - 1, MIPI_CSI2_N_LANES);
	lanes = mipi_csi2_read(info, MIPI_CSI2_N_LANES);
	_mipi_csi2_unlock(info);

	printk(KERN_INFO "MIPI lanes: %d\n", lanes + 1);

	return lanes;
}
EXPORT_SYMBOL(mipi_csi2_set_lanes);

/*!
 * This function is called to set mipi data type.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns setted value
 */
unsigned int mipi_csi2_set_datatype(struct mipi_csi2_info *info,
					unsigned int datatype)
{
	unsigned int dtype;

	_mipi_csi2_lock(info);
	info->datatype = datatype;
	dtype = info->datatype;
	_mipi_csi2_unlock(info);

	return dtype;
}
EXPORT_SYMBOL(mipi_csi2_set_datatype);

/*!
 * This function is called to get mipi data type.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns mipi data type
 */
unsigned int mipi_csi2_get_datatype(struct mipi_csi2_info *info)
{
	unsigned int dtype;

	_mipi_csi2_lock(info);
	dtype = info->datatype;
	_mipi_csi2_unlock(info);

	return dtype;
}
EXPORT_SYMBOL(mipi_csi2_get_datatype);

/*!
 * This function is called to get mipi csi2 dphy status.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns dphy status
 */
unsigned int mipi_csi2_dphy_status(struct mipi_csi2_info *info)
{
	unsigned int status;

	_mipi_csi2_lock(info);
	status = mipi_csi2_read(info, MIPI_CSI2_PHY_STATE);
	_mipi_csi2_unlock(info);

	return status;
}
EXPORT_SYMBOL(mipi_csi2_dphy_status);

/*!
 * This function is called to get mipi csi2 error1 status.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns error1 value
 */
unsigned int mipi_csi2_get_error1(struct mipi_csi2_info *info)
{
	unsigned int err1;

	_mipi_csi2_lock(info);
	err1 = mipi_csi2_read(info, MIPI_CSI2_ERR1);
	_mipi_csi2_unlock(info);

	return err1;
}
EXPORT_SYMBOL(mipi_csi2_get_error1);

/*!
 * This function is called to get mipi csi2 error1 status.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns error1 value
 */
unsigned int mipi_csi2_get_error2(struct mipi_csi2_info *info)
{
	unsigned int err2;

	_mipi_csi2_lock(info);
	err2 = mipi_csi2_read(info, MIPI_CSI2_ERR2);
	_mipi_csi2_unlock(info);

	return err2;
}
EXPORT_SYMBOL(mipi_csi2_get_error2);

/*!
 * This function is called to enable mipi to ipu pixel clock.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns 0 on success or negative error code on fail
 */
int mipi_csi2_pixelclk_enable(struct mipi_csi2_info *info)
{
	printk(KERN_DEBUG "MIPI mipi_csi2_pixelclk_enable");
	return clk_prepare_enable(info->pixel_clk);
}
EXPORT_SYMBOL(mipi_csi2_pixelclk_enable);

/*!
 * This function is called to disable mipi to ipu pixel clock.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns 0 on success or negative error code on fail
 */
void mipi_csi2_pixelclk_disable(struct mipi_csi2_info *info)
{
	printk(KERN_DEBUG "MIPI mipi_csi2_pixelclk_disable");
	clk_disable_unprepare(info->pixel_clk);
}
EXPORT_SYMBOL(mipi_csi2_pixelclk_disable);

/*!
 * This function is called to power on mipi csi2.
 *
 * @param	info		mipi csi2 hander
 * @return      Returns 0 on success or negative error code on fail
 */
int mipi_csi2_reset(struct mipi_csi2_info *info)
{
	_mipi_csi2_lock(info);

	mipi_csi2_write(info, 0x0, MIPI_CSI2_PHY_SHUTDOWNZ);
	mipi_csi2_write(info, 0x0, MIPI_CSI2_DPHY_RSTZ);
	mipi_csi2_write(info, 0x0, MIPI_CSI2_CSI2_RESETN);

	mipi_csi2_write(info, 0x00000001, MIPI_CSI2_PHY_TST_CTRL0);
	mipi_csi2_write(info, 0x00000000, MIPI_CSI2_PHY_TST_CTRL1);
	mipi_csi2_write(info, 0x00000000, MIPI_CSI2_PHY_TST_CTRL0);
	mipi_csi2_write(info, 0x00000002, MIPI_CSI2_PHY_TST_CTRL0);
	mipi_csi2_write(info, 0x00010044, MIPI_CSI2_PHY_TST_CTRL1);
	mipi_csi2_write(info, 0x00000000, MIPI_CSI2_PHY_TST_CTRL0);
	//mipi_csi2_write(info, 0x00000014, MIPI_CSI2_PHY_TST_CTRL1);
	mipi_csi2_write(info, info->pll, MIPI_CSI2_PHY_TST_CTRL1);
	mipi_csi2_write(info, 0x00000002, MIPI_CSI2_PHY_TST_CTRL0);
	mipi_csi2_write(info, 0x00000000, MIPI_CSI2_PHY_TST_CTRL0);

	mipi_csi2_write(info, 0xffffffff, MIPI_CSI2_PHY_SHUTDOWNZ);
	mipi_csi2_write(info, 0xffffffff, MIPI_CSI2_DPHY_RSTZ);
	mipi_csi2_write(info, 0xffffffff, MIPI_CSI2_CSI2_RESETN);

	_mipi_csi2_unlock(info);

	printk(KERN_DEBUG "MIPI pll: %02X\n", info->pll);
	printk(KERN_DEBUG "MIPI cfg_clk: %lu\n", clk_get_rate(info->cfg_clk));
	printk(KERN_DEBUG "MIPI dphy_clk: %lu\n", clk_get_rate(info->dphy_clk));
	printk(KERN_DEBUG "MIPI pixel_clk: %lu\n", clk_get_rate(info->pixel_clk));

	return 0;
}
EXPORT_SYMBOL(mipi_csi2_reset);

/*!
 * This function is called to get mipi csi2 info.
 *
 * @return      Returns mipi csi2 info struct pointor
 */
struct mipi_csi2_info *mipi_csi2_get_info(void)
{
	return gmipi_csi2;
}
EXPORT_SYMBOL(mipi_csi2_get_info);

/*!
 * This function is called to get mipi csi2 bind ipu num.
 *
 * @return      Returns mipi csi2 bind ipu num
 */
int mipi_csi2_get_bind_ipu(struct mipi_csi2_info *info)
{
	int ipu_id;

	_mipi_csi2_lock(info);
	ipu_id = info->ipu_id;
	_mipi_csi2_unlock(info);

	return ipu_id;
}
EXPORT_SYMBOL(mipi_csi2_get_bind_ipu);

/*!
 * This function is called to get mipi csi2 bind csi num.
 *
 * @return      Returns mipi csi2 bind csi num
 */
unsigned int mipi_csi2_get_bind_csi(struct mipi_csi2_info *info)
{
	unsigned int csi_id;

	_mipi_csi2_lock(info);
	csi_id = info->csi_id;
	_mipi_csi2_unlock(info);

	return csi_id;
}
EXPORT_SYMBOL(mipi_csi2_get_bind_csi);

/*!
 * This function is called to get mipi csi2 virtual channel.
 *
 * @return      Returns mipi csi2 virtual channel num
 */
unsigned int mipi_csi2_get_virtual_channel(struct mipi_csi2_info *info)
{
	unsigned int v_channel;

	_mipi_csi2_lock(info);
	v_channel = info->v_channel;
	_mipi_csi2_unlock(info);

	return v_channel;
}
EXPORT_SYMBOL(mipi_csi2_get_virtual_channel);


#define UPDATE_ERROR_COUNTERS(__value__, __name__) if(__value__ & (MIPI_CSI2_ERR1__##__name__)) info->errors.__name__++

static irqreturn_t mipi_csi2_isr0(int irq, void *data)
{
	struct mipi_csi2_info *info = data;
	unsigned long flags;
	u32 err;

	spin_lock_irqsave(&info->irq_lock, flags);

	err = mipi_csi2_read(info, MIPI_CSI2_ERR1);

	info->errors.ERROR1_COUNT++;
	UPDATE_ERROR_COUNTERS(err, ERR_ECC_DOUBLE);
	UPDATE_ERROR_COUNTERS(err, VC3_ERR_CRC);
	UPDATE_ERROR_COUNTERS(err, VC2_ERR_CRC);
	UPDATE_ERROR_COUNTERS(err, VC1_ERR_CRC);
	UPDATE_ERROR_COUNTERS(err, VC0_ERR_CRC);
	UPDATE_ERROR_COUNTERS(err, ERR_I_SEQ_DI3);
	UPDATE_ERROR_COUNTERS(err, ERR_I_SEQ_DI2);
	UPDATE_ERROR_COUNTERS(err, ERR_I_SEQ_DI1);
	UPDATE_ERROR_COUNTERS(err, ERR_I_SEQ_DI0);
	UPDATE_ERROR_COUNTERS(err, ERR_I_BNDRY_MATCH_DI3);
	UPDATE_ERROR_COUNTERS(err, ERR_I_BNDRY_MATCH_DI2);
	UPDATE_ERROR_COUNTERS(err, ERR_I_BNDRY_MATCH_DI1);
	UPDATE_ERROR_COUNTERS(err, ERR_I_BNDRY_MATCH_DI0);
	UPDATE_ERROR_COUNTERS(err, ERR_FRAME_DATA_VC3);
	UPDATE_ERROR_COUNTERS(err, ERR_FRAME_DATA_VC2);
	UPDATE_ERROR_COUNTERS(err, ERR_FRAME_DATA_VC1);
	UPDATE_ERROR_COUNTERS(err, ERR_FRAME_DATA_VC0);
	UPDATE_ERROR_COUNTERS(err, ERR_F_SEQ_VC3);
	UPDATE_ERROR_COUNTERS(err, ERR_F_SEQ_VC2);
	UPDATE_ERROR_COUNTERS(err, ERR_F_SEQ_VC1);
	UPDATE_ERROR_COUNTERS(err, ERR_F_SEQ_VC0);
	UPDATE_ERROR_COUNTERS(err, ERR_F_BNDRY_MATCH_VC3);
	UPDATE_ERROR_COUNTERS(err, ERR_F_BNDRY_MATCH_VC2);
	UPDATE_ERROR_COUNTERS(err, ERR_F_BNDRY_MATCH_VC1);
	UPDATE_ERROR_COUNTERS(err, ERR_F_BNDRY_MATCH_VC0);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRSOTSYNCHS_3);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRSOTSYNCHS_2);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRSOTSYNCHS_1);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRSOTSYNCHS_0);
	//pr_debug("MIPI CSI interrupt received\n");
	//pr_debug("MIPI CSI interrupt received\n");
	//dev_info(&(info->pdev->dev), "MIPI CSI ERROR 1 STATUS %08X\n", err);

	info->last_err1 = err;

	spin_unlock_irqrestore(&info->irq_lock, flags);

	return IRQ_HANDLED;
}

#undef UPDATE_ERROR_COUNTERS
#define UPDATE_ERROR_COUNTERS(__value__, __name__) if(__value__ & (MIPI_CSI2_ERR2__##__name__)) info->errors.__name__++
static irqreturn_t mipi_csi2_isr1(int irq, void *data)
{
	struct mipi_csi2_info *info = data;
	unsigned long flags;
	u32 err;

	spin_lock_irqsave(&info->irq_lock, flags);

	err = mipi_csi2_read(info, MIPI_CSI2_ERR2);

	info->errors.ERROR2_COUNT++;
	UPDATE_ERROR_COUNTERS(err, ERR_I_SEQ_DI7);
	UPDATE_ERROR_COUNTERS(err, ERR_I_SEQ_DI6);
	UPDATE_ERROR_COUNTERS(err, ERR_I_SEQ_DI5);
	UPDATE_ERROR_COUNTERS(err, ERR_I_SEQ_DI4);
	UPDATE_ERROR_COUNTERS(err, ERR_I_BNDRY_MATCH_DI7);
	UPDATE_ERROR_COUNTERS(err, ERR_I_BNDRY_MATCH_DI6);
	UPDATE_ERROR_COUNTERS(err, ERR_I_BNDRY_MATCH_DI5);
	UPDATE_ERROR_COUNTERS(err, ERR_I_BNDRY_MATCH_DI4);
	UPDATE_ERROR_COUNTERS(err, ERR_ID_VC3);
	UPDATE_ERROR_COUNTERS(err, ERR_ID_VC2);
	UPDATE_ERROR_COUNTERS(err, ERR_ID_VC1);
	UPDATE_ERROR_COUNTERS(err, ERR_ID_VC0);
	UPDATE_ERROR_COUNTERS(err, VC3_ERR_ECC_CORRECTED);
	UPDATE_ERROR_COUNTERS(err, VC2_ERR_ECC_CORRECTED);
	UPDATE_ERROR_COUNTERS(err, VC1_ERR_ECC_CORRECTED);
	UPDATE_ERROR_COUNTERS(err, VC0_ERR_ECC_CORRECTED);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRSOTHS_3);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRSOTHS_2);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRSOTHS_1);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRSOTHS_0);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRESC_3);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRESC_2);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRESC_1);
	UPDATE_ERROR_COUNTERS(err, PHY_ERRESC_0);
 
	//pr_debug("MIPI CSI interrupt received\n");
	//dev_info(&(info->pdev->dev), "MIPI CSI ERROR 2 STATUS %08X\n", err);

	info->last_err2 = err;

	spin_unlock_irqrestore(&info->irq_lock, flags);

	return IRQ_HANDLED;
}

#define APPEND_ERROR_COUNTER(__name__) len += snprintf(buf + len, PAGE_SIZE - len, "%s: %u\n", #__name__, errors.__name__)

static ssize_t dumpErrorCounters(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct platform_device *pdev = dev_get_platdata(dev);
	struct mipi_csi2_info *info  = dev_get_drvdata(dev);
	unsigned long flags;
	struct mipi_csi2_error errors;
	u32 err;
	size_t len;

	spin_lock_irqsave(&info->irq_lock, flags);

	errors = info->errors;
	memset(&info->errors, 0, sizeof(struct mipi_csi2_error));

	spin_unlock_irqrestore(&info->irq_lock, flags);

	len = 0;

	APPEND_ERROR_COUNTER(ERR_ECC_DOUBLE);
	APPEND_ERROR_COUNTER(VC3_ERR_CRC);
	APPEND_ERROR_COUNTER(VC2_ERR_CRC);
	APPEND_ERROR_COUNTER(VC1_ERR_CRC);
	APPEND_ERROR_COUNTER(VC0_ERR_CRC);
	APPEND_ERROR_COUNTER(ERR_I_SEQ_DI3);
	APPEND_ERROR_COUNTER(ERR_I_SEQ_DI2);
	APPEND_ERROR_COUNTER(ERR_I_SEQ_DI1);
	APPEND_ERROR_COUNTER(ERR_I_SEQ_DI0);
	APPEND_ERROR_COUNTER(ERR_I_BNDRY_MATCH_DI3);
	APPEND_ERROR_COUNTER(ERR_I_BNDRY_MATCH_DI2);
	APPEND_ERROR_COUNTER(ERR_I_BNDRY_MATCH_DI1);
	APPEND_ERROR_COUNTER(ERR_I_BNDRY_MATCH_DI0);
	APPEND_ERROR_COUNTER(ERR_FRAME_DATA_VC3);
	APPEND_ERROR_COUNTER(ERR_FRAME_DATA_VC2);
	APPEND_ERROR_COUNTER(ERR_FRAME_DATA_VC1);
	APPEND_ERROR_COUNTER(ERR_FRAME_DATA_VC0);
	APPEND_ERROR_COUNTER(ERR_F_SEQ_VC3);
	APPEND_ERROR_COUNTER(ERR_F_SEQ_VC2);
	APPEND_ERROR_COUNTER(ERR_F_SEQ_VC1);
	APPEND_ERROR_COUNTER(ERR_F_SEQ_VC0);
	APPEND_ERROR_COUNTER(ERR_F_BNDRY_MATCH_VC3);
	APPEND_ERROR_COUNTER(ERR_F_BNDRY_MATCH_VC2);
	APPEND_ERROR_COUNTER(ERR_F_BNDRY_MATCH_VC1);
	APPEND_ERROR_COUNTER(ERR_F_BNDRY_MATCH_VC0);
	APPEND_ERROR_COUNTER(PHY_ERRSOTSYNCHS_3);
	APPEND_ERROR_COUNTER(PHY_ERRSOTSYNCHS_2);
	APPEND_ERROR_COUNTER(PHY_ERRSOTSYNCHS_1);
	APPEND_ERROR_COUNTER(PHY_ERRSOTSYNCHS_0);
	APPEND_ERROR_COUNTER(ERR_I_SEQ_DI7);
	APPEND_ERROR_COUNTER(ERR_I_SEQ_DI6);
	APPEND_ERROR_COUNTER(ERR_I_SEQ_DI5);
	APPEND_ERROR_COUNTER(ERR_I_SEQ_DI4);
	APPEND_ERROR_COUNTER(ERR_I_BNDRY_MATCH_DI7);
	APPEND_ERROR_COUNTER(ERR_I_BNDRY_MATCH_DI6);
	APPEND_ERROR_COUNTER(ERR_I_BNDRY_MATCH_DI5);
	APPEND_ERROR_COUNTER(ERR_I_BNDRY_MATCH_DI4);
	APPEND_ERROR_COUNTER(ERR_ID_VC3);
	APPEND_ERROR_COUNTER(ERR_ID_VC2);
	APPEND_ERROR_COUNTER(ERR_ID_VC1);
	APPEND_ERROR_COUNTER(ERR_ID_VC0);
	APPEND_ERROR_COUNTER(VC3_ERR_ECC_CORRECTED);
	APPEND_ERROR_COUNTER(VC2_ERR_ECC_CORRECTED);
	APPEND_ERROR_COUNTER(VC1_ERR_ECC_CORRECTED);
	APPEND_ERROR_COUNTER(VC0_ERR_ECC_CORRECTED);
	APPEND_ERROR_COUNTER(PHY_ERRSOTHS_3);
	APPEND_ERROR_COUNTER(PHY_ERRSOTHS_2);
	APPEND_ERROR_COUNTER(PHY_ERRSOTHS_1);
	APPEND_ERROR_COUNTER(PHY_ERRSOTHS_0);
	APPEND_ERROR_COUNTER(PHY_ERRESC_3);
	APPEND_ERROR_COUNTER(PHY_ERRESC_2);
	APPEND_ERROR_COUNTER(PHY_ERRESC_1);
	APPEND_ERROR_COUNTER(PHY_ERRESC_0);

	return len;
}
static DEVICE_ATTR(ErrorCounters, S_IRUGO, dumpErrorCounters, 0);

static struct attribute* mipi_csi2_sysfsStatus_attributes[] = {
		&dev_attr_ErrorCounters,
		NULL
};

static const struct attribute_group mipi_csi2_sysfsStatus_group = {
		.name = "status",
		.attrs = mipi_csi2_sysfsStatus_attributes,
};


/**
 * This function is called by the driver framework to initialize the MIPI CSI2
 * device.
 *
 * @param	pdev	The device structure for the MIPI CSI2 passed in by the
 *			driver framework.
 *
 * @return      Returns 0 on success or negative error code on error
 */
static int mipi_csi2_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = pdev->dev.of_node;
	struct resource *res;
	u32 mipi_csi2_dphy_ver;
	int ret;
	int irq0;
	int irq1;

	gmipi_csi2 = kmalloc(sizeof(struct mipi_csi2_info), GFP_KERNEL);
	if (!gmipi_csi2) {
		ret = -ENOMEM;
		goto alloc_failed;
	}

	memset(gmipi_csi2, 0, sizeof(struct mipi_csi2_info));

	ret = of_property_read_u32(np, "ipu_id", &(gmipi_csi2->ipu_id));
	if (ret) {
		dev_err(&pdev->dev, "ipu_id missing or invalid\n");
		goto err;
	}

	ret = of_property_read_u32(np, "csi_id", &(gmipi_csi2->csi_id));
	if (ret) {
		dev_err(&pdev->dev, "csi_id missing or invalid\n");
		goto err;
	}

	ret = of_property_read_u32(np, "v_channel", &(gmipi_csi2->v_channel));
	if (ret) {
		dev_err(&pdev->dev, "v_channel missing or invalid\n");
		goto err;
	}

	ret = of_property_read_u32(np, "lanes", &(gmipi_csi2->lanes));
	if (ret) {
		dev_err(&pdev->dev, "lanes missing or invalid\n");
		goto err;
	}

	ret = of_property_read_u32(np, "gated", &(gmipi_csi2->gated));
	if (ret) {
		dev_err(&pdev->dev, "gated missing or invalid. Ignoring!\n");
		gmipi_csi2->gated = 1;
		//goto err;
	}

	ret = of_property_read_u32(np, "pll", &(gmipi_csi2->pll));
	if (ret) {
		dev_err(&pdev->dev, "pll missing or invalid. Defaulting to 0x00000014!\n");
		gmipi_csi2->pll = 0x00000014;
		//goto err;
	}

	ret = of_property_read_u32(np, "isr", &(gmipi_csi2->isr_enable));
	if (ret) {
		dev_err(&pdev->dev, "isr missing or invalid. Defaulting to 0x00000000!\n");
		gmipi_csi2->isr_enable = 0x00000014;
		//goto err;
	}

	if(gmipi_csi2->isr_enable != 0x00000000) {
		irq0 = platform_get_irq(pdev, 0);
		ret = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
		if (unlikely(ret == NULL)) {
			dev_err(&pdev->dev, "mipi_csi2: No irq0 line provided\n");
			goto err;
		}

		irq1 = platform_get_irq(pdev, 1);
		ret = platform_get_resource(pdev, IORESOURCE_IRQ, 1);
		if (unlikely(ret == NULL)) {
			dev_err(&pdev->dev, "mipi_csi2: No irq1 line provided\n");
			goto err;
		}

		spin_lock_init(&gmipi_csi2->irq_lock);


		ret = devm_request_irq(&pdev->dev, irq0, mipi_csi2_isr0, IRQF_SHARED, dev_name(&pdev->dev), gmipi_csi2);
		if (ret < 0) {
			dev_err(&pdev->dev, "mipi_csi2: Unable to request irq 0: %d\n", ret);
			goto err;
		}

		ret = devm_request_irq(&pdev->dev, irq1, mipi_csi2_isr1, IRQF_SHARED, dev_name(&pdev->dev), gmipi_csi2);
		if (ret < 0) {
			dev_err(&pdev->dev, "mipi_csi2: Unable to request irq 1: %d\n", ret);
			goto err;
		}
	}

	if ((gmipi_csi2->ipu_id < 0) || (gmipi_csi2->ipu_id > 1) ||
		(gmipi_csi2->csi_id > 1) || (gmipi_csi2->v_channel > 3) ||
		(gmipi_csi2->lanes > 4)) {
		dev_err(&pdev->dev, "invalid param for mipi csi2!\n");
		ret = -EINVAL;
		goto err;
	}

	/* initialize mutex */
	mutex_init(&gmipi_csi2->mutex_lock);

	/* get mipi csi2 informaiton */
	gmipi_csi2->pdev = pdev;
	gmipi_csi2->mipi_en = false;

	gmipi_csi2->cfg_clk = devm_clk_get(dev, "cfg_clk");
	if (IS_ERR(gmipi_csi2->cfg_clk)) {
		dev_err(&pdev->dev, "failed to get cfg_clk\n");
		ret = PTR_ERR(gmipi_csi2->cfg_clk);
		goto err;
	}

	/* get mipi dphy clk */
	gmipi_csi2->dphy_clk = devm_clk_get(dev, "dphy_clk");
	if (IS_ERR(gmipi_csi2->dphy_clk)) {
		dev_err(&pdev->dev, "failed to get dphy pll_ref_clk\n");
		ret = PTR_ERR(gmipi_csi2->dphy_clk);
		goto err;
	}

	/* get mipi to ipu pixel clk */
	gmipi_csi2->pixel_clk = devm_clk_get(dev, "pixel_clk");
	if (IS_ERR(gmipi_csi2->pixel_clk)) {
		dev_err(&pdev->dev, "failed to get mipi pixel clk\n");
		ret = PTR_ERR(gmipi_csi2->pixel_clk);
		goto err;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		ret = -ENODEV;
		goto err;
	}

	/* mipi register mapping */
	gmipi_csi2->mipi_csi2_base = ioremap(res->start, PAGE_SIZE);
	if (!gmipi_csi2->mipi_csi2_base) {
		ret = -ENOMEM;
		goto err;
	}

	/* mipi dphy clk enable for register access */
	clk_prepare_enable(gmipi_csi2->dphy_clk);
	/* get mipi csi2 dphy version */
	mipi_csi2_dphy_ver = mipi_csi2_read(gmipi_csi2, MIPI_CSI2_VERSION);

	clk_disable_unprepare(gmipi_csi2->dphy_clk);

	platform_set_drvdata(pdev, gmipi_csi2);

	ret = sysfs_create_group(&pdev->dev.kobj, &mipi_csi2_sysfsStatus_group);
	if (ret < 0) {
		dev_err(&pdev->dev, "unable to create %s sysfs group\n", mipi_csi2_sysfsStatus_group.name);
		goto err;
	}

	dev_info(&pdev->dev, "i.MX MIPI CSI2 driver probed\n");
	dev_info(&pdev->dev, "i.MX MIPI CSI2 dphy version is 0x%x\n",
						mipi_csi2_dphy_ver);

	return 0;

err:
	kfree(gmipi_csi2);
alloc_failed:
	dev_err(&pdev->dev, "i.MX MIPI CSI2 driver probed -  error\n");
	return ret;
}

static int mipi_csi2_remove(struct platform_device *pdev)
{
	/* unmapping mipi register */
	iounmap(gmipi_csi2->mipi_csi2_base);

	sysfs_remove_group(&pdev->dev.kobj, &mipi_csi2_sysfsStatus_group);
	kfree(gmipi_csi2);

	dev_set_drvdata(&pdev->dev, NULL);

	return 0;
}

static const struct of_device_id imx_mipi_csi2_dt_ids[] = {
	{ .compatible = "fsl,imx6q-mipi-csi2", },
	{ /* sentinel */ }
};

static struct platform_driver mipi_csi2_driver = {
	.driver = {
		   .name = "mxc_mipi_csi2",
		   .of_match_table = imx_mipi_csi2_dt_ids,
	},
	.probe = mipi_csi2_probe,
	.remove = mipi_csi2_remove,
};

static int __init mipi_csi2_init(void)
{
	int err;

	err = platform_driver_register(&mipi_csi2_driver);
	if (err) {
		pr_err("mipi_csi2_driver register failed\n");
		return -ENODEV;
	}

	pr_info("MIPI CSI2 driver module loaded\n");

	return 0;
}

static void __exit mipi_csi2_cleanup(void)
{
	platform_driver_unregister(&mipi_csi2_driver);
}

subsys_initcall(mipi_csi2_init);
module_exit(mipi_csi2_cleanup);

MODULE_AUTHOR("Freescale Semiconductor, Inc.");
MODULE_DESCRIPTION("i.MX MIPI CSI2 driver");
MODULE_LICENSE("GPL");
