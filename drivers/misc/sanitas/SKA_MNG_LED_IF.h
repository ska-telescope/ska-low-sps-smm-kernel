#ifndef SKA_MNG_LED_REGISTERS_H_
#define SKA_MNG_LED_REGISTERS_H_

#include "register_map.h"
/*
<node id="leduser_k"           	address="0x0400"    mask="0x0000000f" permission="rw"   hw_permission= "w"											description="USER LED K"/>
		<node id="leduser_a"    address="0x0404"    mask="0x0000000f" permission="rw"   hw_permission= "w"											description="USER LED A"/>
		<node id="ledmode"         address="0x0408">
			<node id="led3"        mask="0x0000f000" permission="rw"         description="0 HW managed, 1 CPU managed by MX6_INT(3) as GREEN, , 2 CPU managed by MX6_INT(3) as RED"/>

*/

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

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Led_Mode)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 12, 0, 4}
#include "REGISTER_MAKE.h"
DEFECATE(Led_3)


#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_LED_registers[] = {
	//static const Registers registers = {
	&(REGISTER(Led_User_K)),
	&(REGISTER(Led_User_A)),
	&(REGISTER(Led_Mode)),
	&(REGISTER(Led_3)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_LED_attributes[] = {
	&(REGISTER(Led_User_K)),
	&(REGISTER(Led_User_A)),
	&(REGISTER(Led_Mode)),
	&(REGISTER(Led_3)),
	NULL
};
static const struct attribute_group SKA_MNG_LED_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_LED_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_LED_REGISTERS_H_
