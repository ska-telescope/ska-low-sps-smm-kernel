#ifndef INVENTAMI_DEBUG_REGISTERS_H_
#define INVENTAMI_DEBUG_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x00, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(EimAddrDebugH)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x02, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(EimAddrDebugL)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(DdrPllLock)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(DdrReady)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(DdrRtErr)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 3, 0, 3}
#include "REGISTER_MAKE.h"
DEFECATE(DdrRtRdClkSel)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 6, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(DdrMxClkOutLock)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x12, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(DbgGpioOut)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x14, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(DbgGpioTri)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x16, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(DbgGpioIn)


#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * INVENTAMI_DEBUG_registers[] = {
	//static const Registers registers = {
	&(REGISTER(EimAddrDebugH)),
	&(REGISTER(EimAddrDebugL)),
	&(REGISTER(DdrPllLock)),
	&(REGISTER(DdrReady)),
	&(REGISTER(DdrRtErr)),
	&(REGISTER(DdrRtRdClkSel)),
	&(REGISTER(DdrMxClkOutLock)),
	&(REGISTER(DbgGpioOut)),
	&(REGISTER(DbgGpioTri)),
	&(REGISTER(DbgGpioIn)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* INVENTAMI_DEBUG_attributes[] = {
	&(REGISTER(EimAddrDebugH)),
	&(REGISTER(EimAddrDebugL)),
	&(REGISTER(DdrPllLock)),
	&(REGISTER(DdrReady)),
	&(REGISTER(DdrRtErr)),
	&(REGISTER(DdrRtRdClkSel)),
	&(REGISTER(DdrMxClkOutLock)),
	&(REGISTER(DbgGpioOut)),
	&(REGISTER(DbgGpioTri)),
	&(REGISTER(DbgGpioIn)),
	NULL
};
static const struct attribute_group INVENTAMI_DEBUG_sysfs_group = {
	.name = "parameters",
	.attrs = INVENTAMI_DEBUG_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_INVENTAMI_DEBUG_REGISTERS_H_
