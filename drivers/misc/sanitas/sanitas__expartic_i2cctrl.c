/*
 * sanitas__inventami_expartic_i2cctrl.c
 *
 *  Created on: 04 dic 2015
 *      Author: sanitas
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


/*ARTIC I2C REGISTER OFFSTE*/


//static struct i2c_driver expartic_i2cctrl;

#define DRIVER_NAME "expartic_i2cctrl"


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
#include "EXPARTIC_I2CCTRL_IF.h"


struct EXPARTIC_I2CCTRL_deviceData
{
	struct i2c_device* i2c;
	int irq;

	struct mutex lock;

	Register_I2CBusOps8 busOps;
};

static ssize_t showRegister(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	struct i2c_device *i2c = to_i2c_client(dev);
	struct EXPARTIC_I2CCTRL_deviceData *data = i2c_get_clientdata(i2c);

	u32 tmp;

	Register_I2CRead8(&data->busOps, reg, &tmp);

	return sprintf(buf, "%d\n", tmp);

}

static ssize_t storeRegister(
		struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t count)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	struct i2c_device *i2c = to_i2c_client(dev);
	struct EXPARTIC_I2CCTRL_deviceData *data = i2c_get_clientdata(i2c);

	u32 val;
	int err;

	err = kstrtoint(buf, 0, &val);
	if (err)
		return err;

	Register_I2CWrite8(&data->busOps, reg, val);

	return count;
}








s32 getRegisterI2C(
		struct i2c_device* dev,
		u32 reg,
		u8 *data)
{

	*data=i2c_smbus_read_byte_data(dev, reg);
	return 0;
}

int setRegisterI2C(
		struct i2c_device* dev,
		u32 reg,
		u8 data)
{

	//printk(KERN_DEBUG "[LMC] Writing to register %x: %x", reg, data);

	return i2c_smbus_write_byte_data(dev, reg, data);
}


// ------------------------------------------------------------------------------------------------

static ssize_t listRegistersMap(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	const Register* reg = to_register_dev_attr(attr)->reg;
	return Registers_List(EXPARTIC_I2CCTRL_registers, buf, PAGE_SIZE);
}
static DEVICE_ATTR(ListRegistersMap, S_IRUGO, listRegistersMap, 0);

static ssize_t dumpRegistersMap(
		struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct i2c_device *i2c = to_i2c_client(dev);
	struct EXPARTIC_I2CCTRL_deviceData *data = i2c_get_clientdata(i2c);

	return Registers_I2CDump8(&data->busOps, EXPARTIC_I2CCTRL_registers, buf, PAGE_SIZE);
}
static DEVICE_ATTR(DumpRegistersMap, S_IRUGO, dumpRegistersMap, 0);

static struct attribute* EXPARTIC_I2CCTRL_sysfsControl_attributes[] = {
		&dev_attr_ListRegistersMap,
		&dev_attr_DumpRegistersMap,
		NULL
};

static const struct attribute_group EXPARTIC_I2CCTRL_sysfsControl_group = {
		.name = "control",
		.attrs = EXPARTIC_I2CCTRL_sysfsControl_attributes,
};

// ------------------------------------------------------------------------------------------------




static int expartic_i2cctrl_probe(
		struct i2c_client *client,
		const struct i2c_device_id *id)
{
	struct EXPARTIC_I2CCTRL_deviceData *data;
	int retval;

	struct device_node __maybe_unused *np = client->dev.of_node;

	dev_info(&client->dev, "probing\n");

	if (!of_device_is_available(np)) {
		return -ENODEV;
	}



	data = devm_kzalloc(&client->dev, sizeof(struct EXPARTIC_I2CCTRL_deviceData), GFP_KERNEL);
	if (!data) {
		retval = -ENOMEM;
		kfree(data);

		goto err_no_mem;
	}

	retval = sysfs_create_group(&client->dev.kobj, &EXPARTIC_I2CCTRL_sysfsRegisters_group);
	if (retval < 0) {
		dev_err(&client->dev, "unable to create %s sysfs group\n", EXPARTIC_I2CCTRL_sysfsRegisters_group.name);
		return retval;
	}

	retval = sysfs_create_group(&client->dev.kobj, &EXPARTIC_I2CCTRL_sysfsControl_group);
	if (retval < 0) {
		dev_err(&client->dev, "unable to create %s sysfs group\n", EXPARTIC_I2CCTRL_sysfsControl_group.name);
		return retval;
	}

	data->i2c = client;
	mutex_init(&data->lock);


	data->busOps.dev = client;
	data->busOps.write = setRegisterI2C;
	data->busOps.read = getRegisterI2C;

	i2c_set_clientdata(client, data);

	dev_info(&client->dev, "probed\n");

err_no_mem:
	return retval;
}


static const struct i2c_device_id EXPARTIC_I2CCTRL_id_table[] = {
		{"expartic_i2cctrl", 0},
{},
};


static int expartic_i2cctrl_remove(
		struct i2c_client *i2c)
{
	struct EXPARTIC_I2CCTRL_deviceData *data = i2c_get_clientdata(i2c);
	int retval;

	sysfs_remove_group(&i2c->dev.kobj, &EXPARTIC_I2CCTRL_sysfsRegisters_group);
	sysfs_remove_group(&i2c->dev.kobj, &EXPARTIC_I2CCTRL_sysfsControl_group);

	i2c_set_clientdata(i2c, NULL);

	dev_info(&i2c->dev, "removed\n");

	return 0;
}



static struct i2c_driver expartic_i2cctrl = {
		.driver = {
				.name = "expartic_i2cctrl",
		},
		.probe = expartic_i2cctrl_probe,
		.remove = expartic_i2cctrl_remove,
		.id_table = EXPARTIC_I2CCTRL_id_table,
};


static int __init expartic_i2cctrl_init(void)
{
	return i2c_add_driver(&expartic_i2cctrl);
}
module_init(expartic_i2cctrl_init);

static void __exit expartic_i2cctrl_exit(void)
{
	i2c_del_driver(&expartic_i2cctrl);
}
module_exit(expartic_i2cctrl_exit);




MODULE_DEVICE_TABLE(i2c, EXPARTIC_I2CCTRL_id_table);


MODULE_DESCRIPTION("EXP Artic I2C Ctrl");
MODULE_AUTHOR("Davide Rizzi");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
MODULE_ALIAS("platform:" DRIVER_NAME);


