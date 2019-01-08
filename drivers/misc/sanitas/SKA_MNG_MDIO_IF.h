#ifndef SKA_MNG_MDIO_REGISTERS_H_
#define SKA_MNG_MDIO_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(CFG_REG0)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADR_REG1)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(RAW_REG2)




#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_MDIO_registers[] = {
	//static const Registers registers = {
	&(REGISTER(CFG_REG0)),
	&(REGISTER(ADR_REG1)),
	&(REGISTER(RAW_REG2)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_MDIO_attributes[] = {
	&(REGISTER(CFG_REG0)),
	&(REGISTER(ADR_REG1)),
	&(REGISTER(RAW_REG2)),
	NULL
};
static const struct attribute_group SKA_MNG_MDIO_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_MDIO_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_MDIO_REGISTERS_H_
