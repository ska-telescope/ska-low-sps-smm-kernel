#ifndef SANITAS__INVENTAMI_COLORBAR_REGISTERS_H_
#define SANITAS__INVENTAMI_COLORBAR_REGISTERS_H_

#include "register_map.h"

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x00, 0, 0, 1 }
#include "REGISTER_MAKE.h"
DEFECATE(Reset)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x00, 1, 0, 1 }
#include "REGISTER_MAKE.h"
DEFECATE(Divider)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x00, 2, 0, 2 }
#include "REGISTER_MAKE.h"
DEFECATE(DataMode)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x00, 4, 0, 2 }
#include "REGISTER_MAKE.h"
DEFECATE(DataColor)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x00, 8, 0, 4 }
#include "REGISTER_MAKE.h"
DEFECATE(DataParam)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x00, 16, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(HFrontBlank)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x04, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(HActiveEven)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x04, 16, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(HActiveOdd)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x08, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(HBackBlank)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x08, 16, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(VFrontBlank)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x0C, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(VActive)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x0C, 16, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(VBackBlank)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x10, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(VSpacer)


#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_##__name__

static const Register* InventamiColorbar_registers[] = {
//static const Registers registers = {
		&(REGISTER(Reset)),
		&(REGISTER(Divider)),
		&(REGISTER(DataMode)),
		&(REGISTER(DataColor)),
		&(REGISTER(DataParam)),
		&(REGISTER(HFrontBlank)),
		&(REGISTER(HActiveEven)),
		&(REGISTER(HActiveOdd)),
		&(REGISTER(HBackBlank)),
		&(REGISTER(VFrontBlank)),
		&(REGISTER(VActive)),
		&(REGISTER(VBackBlank)),
		&(REGISTER(VSpacer)),
		NULL
};

#undef REGISTER
#endif

#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* InventamiColorbarSysfsRegisters_attributes[] = {
		&(REGISTER(Reset)),
		&(REGISTER(Divider)),
		&(REGISTER(DataMode)),
		&(REGISTER(DataColor)),
		&(REGISTER(DataParam)),
		&(REGISTER(HFrontBlank)),
		&(REGISTER(HActiveEven)),
		&(REGISTER(HActiveOdd)),
		&(REGISTER(HBackBlank)),
		&(REGISTER(VFrontBlank)),
		&(REGISTER(VActive)),
		&(REGISTER(VBackBlank)),
		&(REGISTER(VSpacer)),
		NULL
};

static const struct attribute_group InventamiColorbarSysfsRegisters_group = {
	.name = "parameters",
	.attrs = InventamiColorbarSysfsRegisters_attributes,
};

#undef REGISTER
#endif

#endif 
