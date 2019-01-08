#ifndef INVENTAMI_VIDEO_OUT_REGISTERS_H_
#define INVENTAMI_VIDEO_OUT_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "CsiMode"
#define REGISTER_ENUM {0, "Disabled"}, {1, "CH1"}, {2, "CH2"}, {3, "ColorBar"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(CsiMode)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "CsiColor"
#define REGISTER_ENUM {0, "RAW (16bit)"}, {1, "Color (YUYV)"}, {2, "RAW (YUYV)"}, {3, "Greyscale (YUYV)"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x00, 2, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(CsiColor)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MIPI_Mode"
#define REGISTER_ENUM {0, "Disabled"}, {1, "CH1"}, {2, "CH2"}, {3, "ColorBar"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(MipiMode)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MIPIColor"
#define REGISTER_ENUM {0, "RAW (16bit)"}, {1, "Color (YUYV)"}, {2, "RAW (YUYV)"}, {3, "Greyscale (YUYV)"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x10, 2, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(MipiColor)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MIPI_ForceEccErr"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10, 4, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(MipiForceEccErr)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MIPI_ForceCrcErr"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10, 5, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(MipiForceCrcErr)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MIPI_Restart"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10, 8, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(MipiRestart)



#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MIPI_WC"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x12, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(MipiWC)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "AlphaBlendingEnable"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x30, 15, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(AlphaBlendingEnable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "AlphaBlendingAlpha"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x30, 0, 0, 9}
#include "REGISTER_MAKE.h"
DEFECATE(AlphaBlendingAlpha)

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * INVENTAMI_VIDEO_OUT_registers[] = {
	//static const Registers registers = {
	&(REGISTER(CsiMode)),
	&(REGISTER(CsiColor)),
	&(REGISTER(MipiMode)),
	&(REGISTER(MipiColor)),
	&(REGISTER(MipiForceEccErr)),
	&(REGISTER(MipiForceCrcErr)),
	&(REGISTER(MipiRestart)),
	&(REGISTER(MipiWC)),
	&(REGISTER(AlphaBlendingEnable)),
	&(REGISTER(AlphaBlendingAlpha)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* INVENTAMI_VIDEO_OUT_attributes[] = {
	&(REGISTER(CsiMode)),
	&(REGISTER(CsiColor)),
	&(REGISTER(MipiMode)),
	&(REGISTER(MipiColor)),
	&(REGISTER(MipiForceEccErr)),
	&(REGISTER(MipiForceCrcErr)),
	&(REGISTER(MipiRestart)),
	&(REGISTER(MipiWC)),
	&(REGISTER(AlphaBlendingEnable)),
	&(REGISTER(AlphaBlendingAlpha)),
	NULL
};
static const struct attribute_group INVENTAMI_VIDEO_OUT_sysfs_group = {
	.name = "parameters",
	.attrs = INVENTAMI_VIDEO_OUT_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_INVENTAMI_VIDEO_OUT_REGISTERS_H_
