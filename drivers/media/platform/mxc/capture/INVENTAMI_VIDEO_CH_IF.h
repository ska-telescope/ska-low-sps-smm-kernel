#ifndef INVENTAMI_VIDEO_CH_REGISTERS_H_
#define INVENTAMI_VIDEO_CH_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Reset"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Reset)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "EnAwbGain"
#define REGISTER_ENUM {0, "Disable"}, {1, "Enable"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(EnAwbGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "EnCsc"
#define REGISTER_ENUM {0, "Disable"}, {1, "Enable"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x00, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(EnCsc)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "StopManage"
#define REGISTER_ENUM {0, "Asynchronous"}, {1, "Synchronous"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x00, 3, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(StopManage)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "BayerPattern"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x02, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(BayerPattern)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "BayerHQ"
#define REGISTER_ENUM {0, "Disable"}, {1, "Enable"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {0x02, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(BayerHQ)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "RowNum"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 13}
#include "REGISTER_MAKE.h"
DEFECATE(RowNum)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "RowByteLen"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x06, 0, 0, 13}
#include "REGISTER_MAKE.h"
DEFECATE(RowByteLen)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Framebuffer HBlank"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 12}
#include "REGISTER_MAKE.h"
DEFECATE(HBlank)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "NibbleUsed"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0a, 0, 0, 4}
#include "REGISTER_MAKE.h"
DEFECATE(NibbleUsed)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "NibbleUsedMShift"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0a, 4, 0, 3}
#include "REGISTER_MAKE.h"
DEFECATE(NibbleUsedMShift)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "BitOffset"
#define REGISTER_SIGNED
#define REGISTER_MIN -4
#define REGISTER_MAX 4
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0a, 8, 0, 4}
#include "REGISTER_MAKE.h"
DEFECATE(BitOffset)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x30, 0, 0, 10 }
#include "REGISTER_MAKE.h"
DEFECATE(AwbGainR)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x32, 0, 0, 10 }
#include "REGISTER_MAKE.h"
DEFECATE(AwbGainG)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x34, 0, 0, 10 }
#include "REGISTER_MAKE.h"
DEFECATE(AwbGainB)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x40, 0, 0, 9 }
#include "REGISTER_MAKE.h"
DEFECATE(CscRY)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x42, 0, 0, 9 }
#include "REGISTER_MAKE.h"
DEFECATE(CscRCb)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x44, 0, 0, 9 }
#include "REGISTER_MAKE.h"
DEFECATE(CscRCr)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x46, 0, 0, 9 }
#include "REGISTER_MAKE.h"
DEFECATE(CscGY)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x48, 0, 0, 9 }
#include "REGISTER_MAKE.h"
DEFECATE(CscGCb)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x4a, 0, 0, 9 }
#include "REGISTER_MAKE.h"
DEFECATE(CscGCr)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x4c, 0, 0, 9 }
#include "REGISTER_MAKE.h"
DEFECATE(CscBY)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x4e, 0, 0, 9 }
#include "REGISTER_MAKE.h"
DEFECATE(CscBCb)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 0x50, 0, 0, 9 }
#include "REGISTER_MAKE.h"
DEFECATE(CscBCr)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x52, 0, 0, 10 }
#include "REGISTER_MAKE.h"
DEFECATE(CscYOffset)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x54, 0, 0, 10 }
#include "REGISTER_MAKE.h"
DEFECATE(CscCbOffset)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x56, 0, 0, 10 }
#include "REGISTER_MAKE.h"
DEFECATE(CscCrOffset)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x60, 0, 0, 32 }
#include "REGISTER_MAKE.h"
DEFECATE(StatR)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x64, 0, 0, 32 }
#include "REGISTER_MAKE.h"
DEFECATE(StatGR)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x68, 0, 0, 32 }
#include "REGISTER_MAKE.h"
DEFECATE(StatGB)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x6c, 0, 0, 32 }
#include "REGISTER_MAKE.h"
DEFECATE(StatB)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS { 0x70, 0, 0, 32 }
#include "REGISTER_MAKE.h"
DEFECATE(StatClip)

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * INVENTAMI_VIDEO_CH_registers[] = {
	//static const Registers registers = {
	&(REGISTER(Reset)),
	&(REGISTER(EnAwbGain)),
	&(REGISTER(EnCsc)),
	&(REGISTER(StopManage)),
	&(REGISTER(BayerPattern)),
	&(REGISTER(BayerHQ)),
	&(REGISTER(RowNum)),
	&(REGISTER(RowByteLen)),
	&(REGISTER(HBlank)),
	&(REGISTER(NibbleUsed)),
	&(REGISTER(NibbleUsedMShift)),
	&(REGISTER(BitOffset)),
	&(REGISTER(AwbGainR)),
	&(REGISTER(AwbGainG)),
	&(REGISTER(AwbGainB)),
	&(REGISTER(CscRY)),
	&(REGISTER(CscRCb)),
	&(REGISTER(CscRCr)),
	&(REGISTER(CscGY)),
	&(REGISTER(CscGCb)),
	&(REGISTER(CscGCr)),
	&(REGISTER(CscBY)),
	&(REGISTER(CscBCb)),
	&(REGISTER(CscBCr)),
	&(REGISTER(CscYOffset)),
	&(REGISTER(CscCbOffset)),
	&(REGISTER(CscCrOffset)),
	&(REGISTER(StatR)),
	&(REGISTER(StatGR)),
	&(REGISTER(StatGB)),
	&(REGISTER(StatB)),
	&(REGISTER(StatClip)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* INVENTAMI_VIDEO_CH_attributes[] = {
	&(REGISTER(Reset)),
	&(REGISTER(EnAwbGain)),
	&(REGISTER(EnCsc)),
	&(REGISTER(StopManage)),
	&(REGISTER(BayerPattern)),
	&(REGISTER(BayerHQ)),
	&(REGISTER(RowNum)),
	&(REGISTER(RowByteLen)),
	&(REGISTER(HBlank)),
	&(REGISTER(NibbleUsed)),
	&(REGISTER(NibbleUsedMShift)),
	&(REGISTER(BitOffset)),
	&(REGISTER(AwbGainR)),
	&(REGISTER(AwbGainG)),
	&(REGISTER(AwbGainB)),
	&(REGISTER(CscRY)),
	&(REGISTER(CscRCb)),
	&(REGISTER(CscRCr)),
	&(REGISTER(CscGY)),
	&(REGISTER(CscGCb)),
	&(REGISTER(CscGCr)),
	&(REGISTER(CscBY)),
	&(REGISTER(CscBCb)),
	&(REGISTER(CscBCr)),
	&(REGISTER(CscYOffset)),
	&(REGISTER(CscCbOffset)),
	&(REGISTER(CscCrOffset)),
	&(REGISTER(StatR)),
	&(REGISTER(StatGR)),
	&(REGISTER(StatGB)),
	&(REGISTER(StatB)),
	&(REGISTER(StatClip)),
	NULL
};

static const struct attribute_group INVENTAMI_VIDEO_CH_sysfs_group = {
	.name = "parameters",
	.attrs = INVENTAMI_VIDEO_CH_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef INVENTAMI_VIDEO_CH_REGISTERS_H_
