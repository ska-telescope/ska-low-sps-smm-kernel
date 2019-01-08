#ifndef SANITAS_CMVx000_FE_VIDEO_CTRL_REGISTERS_H_
#define SANITAS_CMVx000_FE_VIDEO_CTRL_REGISTERS_H_

#include "register_map.h"

#ifndef SANITAS_BASE_FE_VIDEO_CTRL_REGISTERS_H_
#include "BASE_FE_VIDEO_CTRL.h"
#define INCLUDE_BASE_FE
#endif

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_cmvx000_fe_ ## __name__
#undef REGISTER_ATTR_NAME
#define REGISTER_ATTR_NAME(__name__) register_cmvx000_fe_dev_attr_##__name__

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x100, 0, 0, 5}
#include "REGISTER_MAKE.h"
DEFECATE(WordSkip)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x100, 8, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PatternEnable)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x100, 9, 0, 1 }
#include "REGISTER_MAKE.h"
DEFECATE(OutPatternEnable)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x100, 10, 0, 1 }
#include "REGISTER_MAKE.h"
DEFECATE(HFlip)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x102, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(WordPerLine)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x104, 0, 0, 12}
#include "REGISTER_MAKE.h"
DEFECATE(PulsePerFrame)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x104, 12, 0, 3}
#include "REGISTER_MAKE.h"
DEFECATE(ExtTriggerSkip)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x104, 15, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(ExtTriggerSel)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x106, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(RxTxReset)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x106, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(SensorReset)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "Enable"}, {1, "Disable"}
#define REGISTER_CMDS {0x106, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(FrameRequestDisable)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x108, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(PatternValueH)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x10A, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(PatternValueL)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x10C, 0, 0, 6 }
#include "REGISTER_MAKE.h"
DEFECATE(FrameReqExec)

#ifdef REGISTER_MAKE_REGISTERS

static const Register * CMVx000_FE_VIDEO_CTRL_registers[] = {
#ifdef INCLUDE_BASE_FE
#undef REGISTER
#define REGISTER(__name__) register_base_fe_ ## __name__
	&(REGISTER(FirmwareVersion)),
	&(REGISTER(BuildTimestampYear)),
	&(REGISTER(BuildTimestampDayMonth)),
	&(REGISTER(BuildTimestampHourMin)),
	&(REGISTER(SensorClockFreq)),
	&(REGISTER(PulseClockFreq)),
	&(REGISTER(PulseLength)),
	&(REGISTER(FrontendType)),
#undef REGISTER
#endif
#define REGISTER(__name__) register_cmvx000_fe_ ## __name__
	&(REGISTER(WordSkip)),
	&(REGISTER(PatternEnable)),
	&(REGISTER(OutPatternEnable)),
	&(REGISTER(HFlip)),
	&(REGISTER(WordPerLine)),
	&(REGISTER(PulsePerFrame)),
	&(REGISTER(ExtTriggerSkip)),
	&(REGISTER(ExtTriggerSel)),
	&(REGISTER(RxTxReset)),
	&(REGISTER(SensorReset)),
	&(REGISTER(FrameRequestDisable)),
	&(REGISTER(PatternValueH)),
	&(REGISTER(PatternValueL)),
	&(REGISTER(FrameReqExec)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

#ifdef REGISTER_MAKE_SYSFS
static struct attribute* CMVx000_FE_VIDEO_CTRL_attributes[] = {
#ifdef INCLUDE_BASE_FE
#undef REGISTER
#define REGISTER(__name__) register_base_fe_dev_attr_##__name__.dev_attr.attr
	&(REGISTER(FirmwareVersion)),
	&(REGISTER(BuildTimestampYear)),
	&(REGISTER(BuildTimestampDayMonth)),
	&(REGISTER(BuildTimestampHourMin)),
	&(REGISTER(SensorClockFreq)),
	&(REGISTER(PulseClockFreq)),
	&(REGISTER(PulseLength)),
	&(REGISTER(FrontendType)),
#undef REGISTER
#endif
#define REGISTER(__name__) register_cmvx000_fe_dev_attr_##__name__.dev_attr.attr
	&(REGISTER(WordSkip)),
	&(REGISTER(PatternEnable)),
	&(REGISTER(OutPatternEnable)),
	&(REGISTER(HFlip)),
	&(REGISTER(WordPerLine)),
	&(REGISTER(PulsePerFrame)),
	&(REGISTER(ExtTriggerSkip)),
	&(REGISTER(ExtTriggerSel)),
	&(REGISTER(RxTxReset)),
	&(REGISTER(SensorReset)),
	&(REGISTER(FrameRequestDisable)),
	&(REGISTER(PatternValueH)),
	&(REGISTER(PatternValueL)),
	&(REGISTER(FrameReqExec)),
	NULL
};

static const struct attribute_group CMVx000_FE_VIDEO_CTRL_sysfs_group = {
	.name = "parameters",
	.attrs = CMVx000_FE_VIDEO_CTRL_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef SANITAS_CMVx000_FE_VIDEO_CTRL_REGISTERS_H_
