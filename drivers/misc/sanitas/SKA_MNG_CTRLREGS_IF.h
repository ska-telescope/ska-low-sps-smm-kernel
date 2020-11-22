#ifndef SKA_MNG_CTRLREGS_REGISTERS_H_
#define SKA_MNG_CTRLREGS_REGISTERS_H_

#include "register_map.h"
#undef REGISTER_REG_NAME

/*
<node id="sam_resetn"          		address="0x0900"    mask="0x00000001" permission="rw"   									hw_rst="0x00000001" 	description="SAM ResetN Status"/>
<node id="sam_pooltime"        		address="0x0904"    mask="0xffffffff" permission="rw"   									hw_rst="0x000001f4" 	description="SAM Pooling Time"/>
<node id="eim_hadd"                 address="0x0A00"    mask="0xffffffff" permission="rw"   hw_permission= "w"  hw_prio="bus"	hw_rst="0x00000000" 	description="Eim TPM Base Address"/>
<node id="xo3_done"                 address="0x0B00"    mask="0x00000001" permission="rw"      									hw_rst="0x00000000" 	description="XO3 Done signal status - Enable 5V to Backplane"/>

 */

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU Reset Status"
#define REGISTER_MODE_WRITE
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x0, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(McuReset)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Hot Swap Controller Power In Alert (Active Low)"
#define REGISTER_MODE_WRITE
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x4, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(McuPollingTime)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "EIM HAddress for TPM access via singlewire"
#define REGISTER_MODE_WRITE
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x100, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(EIMHadd)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Control Done(xo3_done) to Power ON/OFF Backplane"
#define REGISTER_MODE_WRITE
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x200, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(BkplOnOff)




#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_CTRLREGS_registers[] = {
	//static const Registers registers = {
		&(REGISTER(McuReset)),
		&(REGISTER(McuPollingTime)),
		&(REGISTER(EIMHadd)),
		&(REGISTER(BkplOnOff)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_CTRLREGS_attributes[] = {
		&(REGISTER(McuReset)),
		&(REGISTER(McuPollingTime)),
		&(REGISTER(EIMHadd)),
		&(REGISTER(BkplOnOff)),
	NULL
};
static const struct attribute_group SKA_MNG_CTRLREGS_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_CTRLREGS_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SKA_MNG_CTRLREGS_REGISTERS_H
