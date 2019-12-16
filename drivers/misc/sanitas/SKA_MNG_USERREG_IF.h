#ifndef SKA_MNG_USERREG_REGISTERS_H_
#define SKA_MNG_USERREG_REGISTERS_H_

#include "register_map.h"


#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_ ## __name__
#undef REGISTER_ATTR_NAME
#define REGISTER_ATTR_NAME(__name__) register_dev_attr_ ## __name__


#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(UserReg0)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(UserReg1)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(UserReg2)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(UserReg3)






#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_USERREG_registers[] = {
	//static const Registers registers = {
	&(REGISTER(UserReg0)),
	&(REGISTER(UserReg1)),
	&(REGISTER(UserReg2)),
	&(REGISTER(UserReg3)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_USERREG_attributes[] = {
	&(REGISTER(UserReg0)),
	&(REGISTER(UserReg1)),
	&(REGISTER(UserReg2)),
	&(REGISTER(UserReg3)),
	NULL
};
static const struct attribute_group SKA_MNG_USERREG_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_USERREG_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_USERREG_REGISTERS_H_
