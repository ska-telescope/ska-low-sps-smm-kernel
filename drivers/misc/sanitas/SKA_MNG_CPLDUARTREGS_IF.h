#ifndef SKA_MNG_CPLDUARTREGS_REGISTERS_H_
#define SKA_MNG_CPLDUARTREGS_REGISTERS_H_

#include "register_map.h"
#undef REGISTER_REG_NAME

/*
	<node id="uart" address="0x00070000" description="UART Interface">
		<node id="rnw"                  	address="0x0000"    mask="0x00000001" permission="rw"   															description="Read Not Write Command Execute"/>
		<node id="txdata"               	address="0x0004"    mask="0x000000ff" permission="rw"   															description="TX Data"/>
		<node id="rxdata"               	address="0x0008"    mask="0x000000ff" permission="r"    hw_permission= "w"  										description="RX Data"/>
		<node id="status"               	address="0x000c"    mask="0x00000003" permission="r"    hw_permission= "w"
*/

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Rnw Register select operation 1 Read 0 Write"
#define REGISTER_MODE_WRITE
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x0, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Rnw)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "TxData Register: transmit data reg"
#define REGISTER_MODE_WRITE
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x4, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(TxData)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "RxData Register: transmit data reg"
#define REGISTER_MODE_WRITE
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x8, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(RxData)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Status Register: transmit data reg"
#define REGISTER_MODE_WRITE
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xC, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Status)




#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_CPLDUARTREGS_registers[] = {
	//static const Registers registers = {
		&(REGISTER(Rnw)),
		&(REGISTER(TxData)),
		&(REGISTER(RxData)),
		&(REGISTER(Status)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_CPLDUARTREGS_attributes[] = {
		&(REGISTER(Rnw)),
		&(REGISTER(TxData)),
		&(REGISTER(RxData)),
		&(REGISTER(Status)),
	NULL
};
static const struct attribute_group SKA_MNG_CPLDUARTREGS_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_CPLDUARTREGS_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef  SKA_MNG_CPLDUARTREGS_REGISTERS_H_
