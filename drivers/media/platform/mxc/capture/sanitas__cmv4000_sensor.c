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
 * 2014/12/16 | Davide Rizzi | First Attempt
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


#define DRIVER_NAME "sanitas_cmvx000_sensor"

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
#include "CMVx000_SENSOR_IF.h"

struct CMVx000_SENSOR_deviceData
{
	struct spi_device* spi;
	int irq;

	struct mutex lock;

	Register_SPIBusOps8 busOps;
};

static ssize_t showRegister(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	struct spi_device *spi = to_spi_device(dev);
	struct CMVx000_SENSOR_deviceData *data = spi_get_drvdata(spi);

	u32 tmp;

	Register_SPIRead8(&data->busOps, reg, &tmp);

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
	struct CMVx000_SENSOR_deviceData *data = spi_get_drvdata(spi);

	u32 val;
	int err;

	err = kstrtoint(buf, 0, &val);
	if (err)
		return err;

	Register_SPIWrite8(&data->busOps, reg, val);

	return count;
}

// ------------------------------------------------------------------------------------------------

static ssize_t listRegistersMap(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	return Registers_List(CMVx000_SENSOR_registers, buf, PAGE_SIZE);
}
static DEVICE_ATTR(ListRegistersMap, S_IRUGO, listRegistersMap, 0);

static ssize_t dumpRegistersMap(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct spi_device *spi = to_spi_device(dev);
	struct CMVx000_SENSOR_deviceData *data = spi_get_drvdata(spi);

	return Registers_SPIDump8(&data->busOps, CMVx000_SENSOR_registers, buf, PAGE_SIZE);
}
static DEVICE_ATTR(DumpRegistersMap, S_IRUGO, dumpRegistersMap, 0);

static struct attribute* CMVx000_SENSOR_sysfsControl_attributes[] = {
		&dev_attr_ListRegistersMap,
		&dev_attr_DumpRegistersMap,
		NULL
};

static const struct attribute_group CMVx000_SENSOR_sysfsControl_group = {
		.name = "control",
		.attrs = CMVx000_SENSOR_sysfsControl_attributes,
};

// ------------------------------------------------------------------------------------------------

static int cmvx000Sensor_SPIRead(
		struct spi_device* dev,
		u32 reg,
		u8* data)
{
	struct CMVx000_SENSOR_deviceData *deviceData = spi_get_drvdata(dev);
	struct spi_transfer xfer;
	struct spi_message msg;
	int ret = 0;

	//dev_info(&dev->dev, "SPIRead %d\n", reg);

	mutex_lock(&deviceData->lock);

	memset(&xfer, 0, (sizeof xfer));

	reg &= 0xFF;
	reg &= ~0x80;

	u8 bufTx[2];
	bufTx[0] = reg;
	bufTx[1] = 0x00;

	u8 bufRx[2];
	bufRx[0] = 0x00;
	bufRx[1] = 0x00;

	xfer.tx_buf = bufTx;
	xfer.rx_buf = bufRx;
	xfer.len = 2;
	xfer.bits_per_word = 8;
//	xfer.cs_change = false;

	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);

	ret = spi_sync(dev, &msg);
	if (ret) {
		dev_err(&dev->dev, "SPIRead error: %d\n", ret);
	}


//	dev_info(&dev->dev, "::: %02X %02X\n", bufRx[0], bufRx[1]);

	*data = bufRx[1];
	mutex_unlock(&deviceData->lock);
	return ret;
}

static int cmvx000Sensor_SPIWrite(
		struct spi_device* dev,
		u32 reg,
		u8 data)
{
	struct CMVx000_SENSOR_deviceData *deviceData = spi_get_drvdata(dev);
	struct spi_transfer xfer;
	struct spi_message msg;
	int ret;

	mutex_lock(&deviceData->lock);

//	dev_info(&dev->dev, "SPIWrite %d\n", reg);

	memset(&xfer, 0, (sizeof xfer));

	reg &= 0xFF;
	reg |= 0x80;

	u8 bufTx[2];
	bufTx[0] = reg;
	bufTx[1] = data;

	u8 bufRx[2];
	bufRx[0] = 0x00;
	bufRx[1] = 0x00;

	xfer.tx_buf = bufTx;
	xfer.rx_buf = bufRx;
	xfer.len = 2;
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

static int cmvx000Sensor_probe(
		struct spi_device *spi)
{
	struct CMVx000_SENSOR_deviceData *data;
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

	data = devm_kzalloc(&spi->dev, sizeof(struct CMVx000_SENSOR_deviceData), GFP_KERNEL);
	if (!data) {
		retval = -ENOMEM;
		kfree(data);

		goto err_no_mem;
	}

	retval = sysfs_create_group(&spi->dev.kobj, &CMVx000_SENSOR_sysfsRegisters_group);
	if (retval < 0) {
		dev_err(&spi->dev, "unable to create %s sysfs group\n", CMVx000_SENSOR_sysfsRegisters_group.name);
		return retval;
	}

	retval = sysfs_create_group(&spi->dev.kobj, &CMVx000_SENSOR_sysfsControl_group);
	if (retval < 0) {
		dev_err(&spi->dev, "unable to create %s sysfs group\n", CMVx000_SENSOR_sysfsControl_group.name);
		return retval;
	}

	data->spi = spi;
	data->irq = spi->irq;
	mutex_init(&data->lock);


	data->busOps.dev = spi;
	data->busOps.write = cmvx000Sensor_SPIWrite;
	data->busOps.read = cmvx000Sensor_SPIRead;

	spi_set_drvdata(spi, data);

	dev_info(&spi->dev, "probed\n");

err_no_mem:
	return retval;
}

static int cmvx000Sensor_remove(
		struct spi_device *spi)
{
	struct CMVx000_SENSOR_deviceData *data = spi_get_drvdata(spi);
	int retval;

	sysfs_remove_group(&spi->dev.kobj, &CMVx000_SENSOR_sysfsRegisters_group);
	sysfs_remove_group(&spi->dev.kobj, &CMVx000_SENSOR_sysfsControl_group);

	spi_set_drvdata(spi, NULL);

	dev_info(&spi->dev, "removed\n");

	return 0;
}

static const struct spi_device_id CMVx000_SENSOR_id_table[] = {
		{ "cmvx000_sensor", 0 },
		{ },
};
MODULE_DEVICE_TABLE(spi, CMVx000_SENSOR_id_table);

static struct spi_driver CMVx000_SENSOR_spi_driver = {
		.driver = {
				.name = DRIVER_NAME,
				.owner = THIS_MODULE,
//		.pm	= &cmvx000Sensor_pm_ops, // No Power management for now
		},
		.probe = cmvx000Sensor_probe,
		.remove = cmvx000Sensor_remove,
		.id_table = CMVx000_SENSOR_id_table,
};

module_spi_driver(CMVx000_SENSOR_spi_driver);

MODULE_AUTHOR("Sanitas EG srl");
MODULE_DESCRIPTION("Sanitas CMVx000 Sensor SPI Driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
MODULE_ALIAS("platform:" DRIVER_NAME);
