#ifndef SKA_MNG_FPGA_I2C_REGISTERS_H_
#define SKA_MNG_FPGA_I2C_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "command register: routeradd+bytenum2read+bytenum2write+ICadd"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(twi_command)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "status register"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x0C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(twi_status)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "int register"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(twi_irq)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "int en register"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x14, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(twi_irq_en)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Write Data Register (Add + data)"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x4, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(twi_wrdata)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Read data Register"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(twi_rdata)





#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_FPGA_I2C_registers[] = {
	//static const Registers registers = {
	&(REGISTER(twi_command)),
	&(REGISTER(twi_status)),
	&(REGISTER(twi_irq)),
	&(REGISTER(twi_irq_en)),	
	&(REGISTER(twi_wrdata)),
	&(REGISTER(twi_rdata)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_FPGA_I2C_attributes[] = {
	&(REGISTER(twi_command)),
	&(REGISTER(twi_status)),
	&(REGISTER(twi_irq)),
	&(REGISTER(twi_irq_en)),	
	&(REGISTER(twi_wrdata)),
	&(REGISTER(twi_rdata)),
	NULL
};
static const struct attribute_group SKA_MNG_FPGA_I2C_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_FPGA_I2C_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_FPGA_I2C_REGISTERS_H_
