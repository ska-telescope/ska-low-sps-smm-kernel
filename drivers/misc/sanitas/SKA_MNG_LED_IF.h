#ifndef SKA_MNG_LED_REGISTERS_H_
#define SKA_MNG_LED_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Led_User_K)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Led_User_A)




#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_LED_registers[] = {
	//static const Registers registers = {
	&(REGISTER(Led_User_K)),
	&(REGISTER(Led_User_A)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_LED_attributes[] = {
	&(REGISTER(Led_User_K)),
	&(REGISTER(Led_User_A)),
	NULL
};
static const struct attribute_group SKA_MNG_LED_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_LED_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_LED_REGISTERS_H_
