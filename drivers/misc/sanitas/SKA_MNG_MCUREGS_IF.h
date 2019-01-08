#ifndef SKA_MNG_MCUREGS_REGISTERS_H_
#define SKA_MNG_MCUREGS_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU FW Version"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(McuFWBuildVersion)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU FW Build Time"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(McuFWBuildTime)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU FW Build Date"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(McuFWBuildDate)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU General Purpose User Register 0"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x100, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(GPReg0)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU General Purpose User Register 1"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x104, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(GPReg1)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU General Purpose User Register 2"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x108, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(GPReg2)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU General Purpose User Register 3"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(GPReg3)


////////////////// POWER SUPPLY INFORMATION ////

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "SOC Voltage Value"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x200, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(VoltageSOC)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "ARM Voltage"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x204, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(VoltageARM)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "DDR Voltage"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x208, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(VoltageDDR)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "2V5 Voltage"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x20c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Voltage2V5)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "1V0 Voltage Value"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x210, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Voltage1V0)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "1V1 Voltage"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x214, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Voltage1V1)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "VCORE Voltage"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x218, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(VoltageVCORE)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "1V5 Voltage"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x21c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Voltage1V5)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "3V3 Voltage Value"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x220, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Voltage3V3)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "5V Voltage"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x224, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Voltage5V)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "3V Voltage"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x228, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Voltage3V)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "2V8 Voltage"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x22c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Voltage2V8)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Buck Regulator Temperature"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x300, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(BuckRegTemp)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MCU internal Temperature"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x304, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(MCUTemp)







#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_MCUREGS_registers[] = {
	//static const Registers registers = {
	&(REGISTER(McuFWBuildVersion)),
	&(REGISTER(McuFWBuildTime)),
	&(REGISTER(McuFWBuildDate)),
	&(REGISTER(GPReg0)),
	&(REGISTER(GPReg1)),
	&(REGISTER(GPReg2)),
	&(REGISTER(GPReg3)),
	&(REGISTER(VoltageSOC)),
	&(REGISTER(VoltageARM)),
	&(REGISTER(VoltageDDR)),
	&(REGISTER(Voltage2V5)),
	&(REGISTER(Voltage1V0)),
	&(REGISTER(Voltage1V1)),
	&(REGISTER(VoltageVCORE)),
	&(REGISTER(Voltage1V5)),
	&(REGISTER(Voltage3V3)),
	&(REGISTER(Voltage5V)),
	&(REGISTER(Voltage3V)),
	&(REGISTER(Voltage2V8)),
	&(REGISTER(BuckRegTemp)),
	&(REGISTER(MCUTemp)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_MCUREGS_attributes[] = {
		&(REGISTER(McuFWBuildVersion)),
		&(REGISTER(McuFWBuildTime)),
		&(REGISTER(McuFWBuildDate)),
		&(REGISTER(GPReg0)),
		&(REGISTER(GPReg1)),
		&(REGISTER(GPReg2)),
		&(REGISTER(GPReg3)),
		&(REGISTER(VoltageSOC)),
		&(REGISTER(VoltageARM)),
		&(REGISTER(VoltageDDR)),
		&(REGISTER(Voltage2V5)),
		&(REGISTER(Voltage1V0)),
		&(REGISTER(Voltage1V1)),
		&(REGISTER(VoltageVCORE)),
		&(REGISTER(Voltage1V5)),
		&(REGISTER(Voltage3V3)),
		&(REGISTER(Voltage5V)),
		&(REGISTER(Voltage3V)),
		&(REGISTER(Voltage2V8)),
		&(REGISTER(BuckRegTemp)),
		&(REGISTER(MCUTemp)),
	NULL
};
static const struct attribute_group SKA_MNG_MCUREGS_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_MCUREGS_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_MCUREGS_REGISTERS_H_
