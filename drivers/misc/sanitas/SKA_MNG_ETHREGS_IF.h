#ifndef SKA_MNG_ETHREGS_REGISTERS_H_
#define SKA_MNG_ETHREGS_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MAC 0 Low Part"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Mac0_L)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MAC 0 High Part"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Mac0_H)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MAC 1 Low Part"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Mac1_L)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MAC 1 High Part"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Mac1_H)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "IP Address"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(IP)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Netmask"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x14, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Netmask)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Gateway"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x18, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Gateway)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Ucp RX Destination UDP PORT Low"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x100, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(UcpRXDestUDPPort_L)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Ucp RX Destination UDP PORT High"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x104, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(UcpRXDestUDPPort_H)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Ucp Last Psn"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x108, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(UcpLastPsn)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "DPLL Reset Status"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x200, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(DPLLResetStatus)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "DPLL Multifunction Status"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {204, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(DPLLMultifuncStatus)




#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_ETHREGS_registers[] = {
	//static const Registers registers = {
	&(REGISTER(Mac0_L)),
	&(REGISTER(Mac0_H)),
	&(REGISTER(Mac1_L)),
	&(REGISTER(Mac1_H)),
	&(REGISTER(IP)),
	&(REGISTER(Netmask)),
	&(REGISTER(Gateway)),
	&(REGISTER(UcpRXDestUDPPort_L)),
	&(REGISTER(UcpRXDestUDPPort_H)),
	&(REGISTER(UcpLastPsn)),
	&(REGISTER(DPLLResetStatus)),
	&(REGISTER(DPLLMultifuncStatus)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_ETHREGS_attributes[] = {
		&(REGISTER(Mac0_L)),
		&(REGISTER(Mac0_H)),
		&(REGISTER(Mac1_L)),
		&(REGISTER(Mac1_H)),
		&(REGISTER(IP)),
		&(REGISTER(Netmask)),
		&(REGISTER(Gateway)),
		&(REGISTER(UcpRXDestUDPPort_L)),
		&(REGISTER(UcpRXDestUDPPort_H)),
		&(REGISTER(UcpLastPsn)),
		&(REGISTER(DPLLResetStatus)),
		&(REGISTER(DPLLMultifuncStatus)),
	NULL
};
static const struct attribute_group SKA_MNG_ETHREGS_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_ETHREGS_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_ETHREGS_REGISTERS_H_
