#ifndef SANITAS_BASE_FE_VIDEO_CTRL_REGISTERS_H_
#define SANITAS_BASE_FE_VIDEO_CTRL_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_base_fe_ ## __name__
#undef REGISTER_ATTR_NAME
#define REGISTER_ATTR_NAME(__name__) register_base_fe_dev_attr_##__name__


#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x000, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(FirmwareVersion)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x002, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(BuildTimestampYear)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x004, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(BuildTimestampDayMonth)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x006, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(BuildTimestampHourMin)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Sensor clock frequency [10 KHz]"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x008, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(SensorClockFreq)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Pulse clock frequency [10 KHz]"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x00A, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(PulseClockFreq)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Pulse length"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x00C, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(PulseLength)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Frontend Type"
#define REGISTER_MODE_READ
#define REGISTER_ENUM {0, "CMVx000"}, {1, "Alpha_5MP"}, {2, "Alpha_FLIR"}
#define REGISTER_CMDS { 0x00E, 0, 0, 16 }
#include "REGISTER_MAKE.h"
DEFECATE(FrontendType)

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_base_fe_ ## __name__

static const Register * BASE_FE_VIDEO_CTRL_registers[] = {
	//static const Registers registers = {
	&(REGISTER(FirmwareVersion)),
	&(REGISTER(BuildTimestampYear)),
	&(REGISTER(BuildTimestampDayMonth)),
	&(REGISTER(BuildTimestampHourMin)),
	&(REGISTER(SensorClockFreq)),
	&(REGISTER(PulseClockFreq)),
	&(REGISTER(PulseLength)),
	&(REGISTER(FrontendType)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_base_fe_dev_attr_##__name__.dev_attr.attr

static struct attribute* BASE_FE_VIDEO_CTRL_attributes[] = {
	&(REGISTER(FirmwareVersion)),
	&(REGISTER(BuildTimestampYear)),
	&(REGISTER(BuildTimestampDayMonth)),
	&(REGISTER(BuildTimestampHourMin)),
	&(REGISTER(SensorClockFreq)),
	&(REGISTER(PulseClockFreq)),
	&(REGISTER(PulseLength)),
	&(REGISTER(FrontendType)),
	NULL
};
static const struct attribute_group BASE_FE_VIDEO_CTRL_sysfs_group = {
	.name = "parameters_base",
	.attrs = BASE_FE_VIDEO_CTRL_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef SANITAS_BASE_FE_VIDEO_CTRL_REGISTERS_H_
