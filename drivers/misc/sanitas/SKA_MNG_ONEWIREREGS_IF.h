#ifndef SKA_MNG_ONEWIRE_REGISTERS_H_
#define SKA_MNG_ONEWIRE_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Commnad1WM)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Data1WM)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Int1WM)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(IntEn1WM)


#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Clock1WM)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x14, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Ctrl1WM)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x18, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Mux1WM)




#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_ONEWIRE_registers[] = {
	//static const Registers registers = {
	&(REGISTER(Commnad1WM)),
	&(REGISTER(Data1WM)),
	&(REGISTER(Int1WM)),
	&(REGISTER(IntEn1WM)),
	&(REGISTER(Clock1WM)),
	&(REGISTER(Ctrl1WM)),
	&(REGISTER(Mux1WM)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_ONEWIRE_attributes[] = {
		&(REGISTER(Commnad1WM)),
		&(REGISTER(Data1WM)),
		&(REGISTER(Int1WM)),
		&(REGISTER(IntEn1WM)),
		&(REGISTER(Clock1WM)),
		&(REGISTER(Ctrl1WM)),
		&(REGISTER(Mux1WM)),
	NULL
};
static const struct attribute_group SKA_MNG_ONEWIRE_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_ONEWIRE_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_ONEWIRE_REGISTERS_H_
