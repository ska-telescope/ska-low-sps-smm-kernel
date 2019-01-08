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
 * 2015/02/12 | Davide Rizzi | First Attempt
 */

#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/regulator/consumer.h>
#include <linux/slab.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/clk.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/stat.h>
#include <linux/io.h>

#define DRIVER_NAME "inventami_fpga"

struct INVENTAMI_FPGA_deviceData
{
	struct device *dev;
	void __iomem* base;

	spinlock_t lock;
};


/*
 * REGISTERS DECLARATION
 */

#define REGISTER_MAKE_REGISTERS
#define REGISTER_MAKE_SYSFS

static ssize_t storeRegister(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
static ssize_t showRegister(struct device *dev, struct device_attribute *attr, char *buf);

#include "register_map.h"
#include "INVENTAMI_FWVER_IF.h"

static ssize_t showRegister(struct device *dev, struct device_attribute *attr, char *buf)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	struct platform_device *pdev = dev_get_platdata(dev);
	struct INVENTAMI_FPGA_deviceData *data = dev_get_drvdata(dev);

	u32 tmp;
	Register_MemoryRead16(data->base, reg, &(tmp));

	return sprintf(buf, "%d\n", tmp);
}

static ssize_t storeRegister(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	u32 val;
	int err;

	const Register* reg = to_register_dev_attr(attr)->reg;
	struct platform_device *pdev = dev_get_platdata(dev);
	struct INVENTAMI_FPGA_deviceData *data = dev_get_drvdata(dev);

	err = kstrtoint(buf, 10, &val);
	if (err)
		return err;

	Register_MemoryWrite16(data->base, reg, val);

	return count;
}

// ---------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------

static ssize_t listRegistersMapFwVer(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	return Registers_List(INVENTAMI_FWVER_registers, buf, PAGE_SIZE);
}
static DEVICE_ATTR(ListFirmwareVersionRegistersMap, S_IRUGO, listRegistersMapFwVer, 0);

static ssize_t dumpRegistersMapFwVer(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct platform_device *pdev = dev_get_platdata(dev);
	struct INVENTAMI_FPGA_deviceData *data = dev_get_drvdata(dev);

	return Registers_MemoryDump16(data->base, INVENTAMI_FWVER_registers, buf, PAGE_SIZE);
}
static DEVICE_ATTR(DumpFirmwareVersionRegistersMap, S_IRUGO, dumpRegistersMapFwVer, 0);

static struct attribute* INVENTAMI_FPGA_sysfsControl_attributes[] = {
		&dev_attr_ListFirmwareVersionRegistersMap,
		&dev_attr_DumpFirmwareVersionRegistersMap,
		NULL
};

static const struct attribute_group INVENTAMI_FPGA_sysfsControl_group = {
		.name = "control",
		.attrs = INVENTAMI_FPGA_sysfsControl_attributes,
};

// ------------------------------------------------------------------------------------------------
static int inventami_fpga_probe(
		struct platform_device* pdev)
{
	struct INVENTAMI_FPGA_deviceData *data;
	struct resource *res;
	int ret = -EINVAL;
	struct device_node* np = pdev->dev.of_node;

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data) {
		ret = -ENOMEM;
		goto out_error;
	}
	platform_set_drvdata(pdev, data);

	/* get the resource */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		ret = -EINVAL;
		goto out_error;
	}

	dev_info(&pdev->dev, "%08X - %08X\n", res->start, res->end);

	data->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(data->base)) {
		ret = PTR_ERR(data->base);
		goto out_error;
	}

	u16 version = 0;
	Register_MemoryRead16(data->base, &register_fwver_FirmwareVersion, &version);

	if(version == 0) {
		dev_err(&pdev->dev, "invalid firmware version: %04X\n", version);
		ret = -EINVAL;
	} else {
		u16 year, monthday, hourminute;
		Register_MemoryRead16(data->base, &register_fwver_BuildYear, &year);
		Register_MemoryRead16(data->base, &register_fwver_BuildMonthDay, &monthday);
		Register_MemoryRead16(data->base, &register_fwver_BuildTime, &hourminute);
		dev_info(&pdev->dev, "firmware version %04X built on %04X%04X at %04X\n", version, year,  monthday, hourminute);
	}

	ret = sysfs_create_group(&pdev->dev.kobj, &INVENTAMI_FWVER_sysfs_group);
	if (ret < 0) {
		dev_err(&pdev->dev, "unable to create %s sysfs group\n", INVENTAMI_FWVER_sysfs_group.name);
		goto out_error;
	}

	ret = sysfs_create_group(&pdev->dev.kobj, &INVENTAMI_FPGA_sysfsControl_group);
	if (ret < 0) {
		dev_err(&pdev->dev, "unable to create %s sysfs group\n", INVENTAMI_FPGA_sysfsControl_group.name);
		return ret;
	}

	dev_info(&pdev->dev, "driver registered.\n");

	return 0;

out_error:
	return ret;
}

static int inventami_fpga_remove(
		struct platform_device* pdev)
{

	sysfs_remove_group(&pdev->dev.kobj, &INVENTAMI_FWVER_sysfs_group);
	sysfs_remove_group(&pdev->dev.kobj, &INVENTAMI_FPGA_sysfsControl_group);

	dev_info(&pdev->dev, "driver removed.\n");

	return 0;
}

static const struct of_device_id INVENTAMI_FPGA_id_table[] = {
		{ .compatible = "sanitas,inventami-fpga", },
		{ }
};
MODULE_DEVICE_TABLE(of, INVENTAMI_FPGA_id_table);

static struct platform_driver INVENTAMI_FPGA_driver = {
		.probe = inventami_fpga_probe,
		.remove = inventami_fpga_remove,
		.driver = {
				.name = DRIVER_NAME,
				.of_match_table = INVENTAMI_FPGA_id_table,
				.owner = THIS_MODULE,
		},
};

module_platform_driver(INVENTAMI_FPGA_driver);

MODULE_DESCRIPTION("Sanitas EG Inventami FPGA driver");
MODULE_AUTHOR("Davide Rizzi, Sanitas EG");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:" DRIVER_NAME);
