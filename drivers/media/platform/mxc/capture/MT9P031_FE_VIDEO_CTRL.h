#ifndef SANITAS_MT9P031_FE_VIDEO_CTRL_REGISTERS_H_
#define SANITAS_MT9P031_FE_VIDEO_CTRL_REGISTERS_H_

#include "register_map.h"

#ifndef SANITAS_BASE_FE_VIDEO_CTRL_REGISTERS_H_
#include "BASE_FE_VIDEO_CTRL.h"
#define INCLUDE_BASE_FE
#endif

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_mt9p031_fe_ ## __name__
#undef REGISTER_ATTR_NAME
#define REGISTER_ATTR_NAME(__name__) register_mt9p031_fe_dev_attr_##__name__

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
#define REGISTER_CMDS { 0x100, 10, 0, 1 }
#include "REGISTER_MAKE.h"
DEFECATE(HFlip)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
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
#define REGISTER_ENUM {0, "Power-on"}, {1, "Stand-by"}
#define REGISTER_CMDS {0x106, 3, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(SensorStandby)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "Disable"}, {1, "Enable"}
#define REGISTER_CMDS {0x106, 4, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(SensorConfEnable)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "Enable"}, {1, "Disable"}
#define REGISTER_CMDS {0x106, 5, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(SensorOutputEnable)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x108, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(Exposure)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x10A, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(GlobalGain)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_HEX
#define REGISTER_CMDS { 0x400000, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(I2C_PhyByteNum)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_HEX
#define REGISTER_CMDS { 0x400002, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(I2C_Offset)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_HEX
#define REGISTER_CMDS { 0x400004, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(I2C_DOut)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_HEX
#define REGISTER_CMDS { 0x400006, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(I2C_Command)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_HEX
#define REGISTER_CMDS { 0x400008, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(I2C_DIn)

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_mt9p031_fe_ ## __name__

static const Register * MT9P031_FE_VIDEO_CTRL_registers[] = {
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
#define REGISTER(__name__) register_mt9p031_fe_ ## __name__
	&(REGISTER(WordSkip)),
	&(REGISTER(PatternEnable)),
	&(REGISTER(HFlip)),
	&(REGISTER(WordPerLine)),
	&(REGISTER(PulsePerFrame)),
	&(REGISTER(ExtTriggerSkip)),
	&(REGISTER(ExtTriggerSel)),
	&(REGISTER(RxTxReset)),
	&(REGISTER(SensorReset)),
	&(REGISTER(FrameRequestDisable)),
	&(REGISTER(SensorStandby)),
	&(REGISTER(SensorConfEnable)),
	&(REGISTER(SensorOutputEnable)),
	&(REGISTER(Exposure)),
	&(REGISTER(GlobalGain)),
	&(REGISTER(I2C_PhyByteNum)),
	&(REGISTER(I2C_Offset)),
	&(REGISTER(I2C_DOut)),
	&(REGISTER(I2C_Command)),
	&(REGISTER(I2C_DIn)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

#ifdef REGISTER_MAKE_SYSFS
static struct attribute* MT9P031_FE_VIDEO_CTRL_attributes[] = {
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
#define REGISTER(__name__) register_mt9p031_fe_dev_attr_ ## __name__.dev_attr.attr
	&(REGISTER(WordSkip)),
	&(REGISTER(PatternEnable)),
	&(REGISTER(HFlip)),
	&(REGISTER(WordPerLine)),
	&(REGISTER(PulsePerFrame)),
	&(REGISTER(ExtTriggerSkip)),
	&(REGISTER(ExtTriggerSel)),
	&(REGISTER(RxTxReset)),
	&(REGISTER(SensorReset)),
	&(REGISTER(FrameRequestDisable)),
	&(REGISTER(SensorStandby)),
	&(REGISTER(SensorConfEnable)),
	&(REGISTER(SensorOutputEnable)),
	&(REGISTER(Exposure)),
	&(REGISTER(GlobalGain)),
	&(REGISTER(I2C_PhyByteNum)),
	&(REGISTER(I2C_Offset)),
	&(REGISTER(I2C_DOut)),
	&(REGISTER(I2C_Command)),
	&(REGISTER(I2C_DIn)),
	NULL
};

static const struct attribute_group MT9P031_FE_VIDEO_CTRL_sysfs_group = {
	.name = "parameters",
	.attrs = MT9P031_FE_VIDEO_CTRL_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef SANITAS_MT9P031_FE_VIDEO_CTRL_REGISTERS_H_
