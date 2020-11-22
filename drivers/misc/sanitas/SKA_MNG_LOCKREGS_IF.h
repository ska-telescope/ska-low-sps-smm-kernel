#ifndef SKA_MNG_LOCKREGS_REGISTERS_H_
#define SKA_MNG_LOCKREGS_REGISTERS_H_

#include "register_map.h"
#undef REGISTER_REG_NAME
/*
<node id="lock" address="0x000C0000" description="Peripheral Lock">
		<node id="mlock0"      				address="0x0"   	mask="0xffffffff" permission="rw"  	hw_permission= "we" 	hw_rst="0xffffffff" 				description="MCU slave lock 0"/>
		<node id="mlock1"      				address="0x4"   	mask="0xffffffff" permission="rw"  	hw_permission= "we" 	hw_rst="0xffffffff" 				description="UCP slave lock 1"/>
		<node id="mlock2"      				address="0x8"   	mask="0xffffffff" permission="rw"  	hw_permission= "we" 	hw_rst="0xffffffff" 				description="CPU slave lock 2"/>
	</node>
*/


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU Lock Reg"
#define REGISTERTYPE_HEX
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(MCULock)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "UCP Lock Reg"
#define REGISTERTYPE_HEX
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(UCPLock)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "CPU Lock Reg"
#define REGISTERTYPE_HEX
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(CPULock)




#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_LOCKREGS_registers[] = {
	//static const Registers registers = {
	&(REGISTER(MCULock)),
	&(REGISTER(UCPLock)),
	&(REGISTER(CPULock)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_LOCKREGS_attributes[] = {
		&(REGISTER(MCULock)),
		&(REGISTER(UCPLock)),
		&(REGISTER(CPULock)),
	NULL
};
static const struct attribute_group SKA_MNG_LOCKREGS_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_LOCKREGS_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_LOCKREGS_REGISTERS_H_
