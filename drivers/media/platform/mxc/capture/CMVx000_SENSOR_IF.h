#ifndef SANITAS_CMVx000_SENSOR_REGISTERS_H_
#define SANITAS_CMVx000_SENSOR_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_cmvx000_sensor_ ## __name__
#undef REGISTER_ATTR_NAME
#define REGISTER_ATTR_NAME(__name__) register_cmvx000_sensor_dev_attr_##__name__

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg0)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Total number of lines read-out by the sensor"
#define REGISTER_MAX 2048
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {1, 0, 0, 8}, {2, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberLines)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Start line of window #1"
#define REGISTER_MAX 2047
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {3, 0, 0, 8}, {4, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Start1)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Start line of window #2"
#define REGISTER_MAX 2047
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {5, 0, 0, 8}, {6, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Start2)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Start line of window #3"
#define REGISTER_MAX 2047
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {7, 0, 0, 8}, {8, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Start3)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Start line of window #4"
#define REGISTER_MAX 2047
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {9, 0, 0, 8}, {10, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Start4)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Start line of window #5"
#define REGISTER_MAX 2047
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {11, 0, 0, 8}, {12, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Start5)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Start line of window #6"
#define REGISTER_MAX 2047
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {13, 0, 0, 8}, {14, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Start6)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Start line of window #7"
#define REGISTER_MAX 2047
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {15, 0, 0, 8}, {16, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Start7)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Start line of window #8"
#define REGISTER_MAX 2047
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {17, 0, 0, 8}, {18, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Start8)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Total number of lines of window #1"
#define REGISTER_MAX 2048
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {19, 0, 0, 8}, {20, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberLines1)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Total number of lines of window #2"
#define REGISTER_MAX 2048
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {21, 0, 0, 8}, {22, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberLines2)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Total number of lines of window #3"
#define REGISTER_MAX 2048
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {23, 0, 0, 8}, {24, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberLines3)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Total number of lines of window #4"
#define REGISTER_MAX 2048
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {25, 0, 0, 8}, {26, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberLines4)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Total number of lines of window #5"
#define REGISTER_MAX 2048
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {27, 0, 0, 8}, {28, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberLines5)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Total number of lines of window #6"
#define REGISTER_MAX 2048
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {29, 0, 0, 8}, {30, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberLines6)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Total number of lines of window #7"
#define REGISTER_MAX 2048
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {31, 0, 0, 8}, {32, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberLines7)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Total number of lines of window #8"
#define REGISTER_MAX 2048
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {33, 0, 0, 8}, {34, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberLines8)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "???"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {35, 0, 0, 8}, {36, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(SubS)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "???"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {37, 0, 0, 8}, {38, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(SubA)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Color sensor"
#define REGISTER_ENUM {0, "Color"}, {1, "Mono"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {39, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Color)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Image Flipping"
#define REGISTER_ENUM {0, "No flipping"}, {1, "X flipping"}, {2, "Y flipping"}, {3, "X & Y flipping"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {40, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(ImageFlipping)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Exposure mode"
#define REGISTER_ENUM {0, "Internal sequencer"}, {1, "External pins"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {41, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(ImageExpExt)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Interleaved exposure"
#define REGISTER_ENUM {0, "Disabled"}, {1, "Enabled"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {41, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(ImageExpDual)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "???"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {41, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(ImageExpSync)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Exposure time, if Exposure Mode is External:\n ExpTime = ( ExposureTime[us] * f[MHz] / 129) - 0.43 * FotLength"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {42, 0, 0, 8}, {43, 0, 8, 8}, {44, 0, 16, 8}
#include "REGISTER_MAKE.h"
DEFECATE(ExpTime)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {45, 0, 0, 8}, {46, 0, 8, 8}, {47, 0, 16, 8}
#include "REGISTER_MAKE.h"
DEFECATE(ExpStep)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {48, 0, 0, 8}, {49, 0, 8, 8}, {50, 0, 16, 8}
#include "REGISTER_MAKE.h"
DEFECATE(ExpKp1)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {51, 0, 0, 8}, {52, 0, 8, 8}, {53, 0, 16, 8}
#include "REGISTER_MAKE.h"
DEFECATE(ExpKp2)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {54, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(NrSlopes)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {55, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(ExpSeq)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {56, 0, 0, 8}, {57, 0, 8, 8}, {58, 0, 16, 8}
#include "REGISTER_MAKE.h"
DEFECATE(ExpTime2)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {59, 0, 0, 8}, {60, 0, 8, 8}, {61, 0, 16, 8}
#include "REGISTER_MAKE.h"
DEFECATE(ExpStep2)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_ADVANCED
#define REGISTER_CMDS {62, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Reg62)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {63, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg63)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {64, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg64)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {65, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg65)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {66, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg66)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {67, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg67)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {68, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(NrSlopes2)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ADVANCED
#define REGISTER_CMDS {69, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(ExpSeq2)

#include "REGISTER_RESET.h"
#define REGITSER_DESCRIPTION "Number of frames to acquire in internal exposure mode"
#define REGISTER_MIN 0
#define REGISTER_MAX 65548
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {70, 0, 0, 8}, {71, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(NumberFrames)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Number of enabled LVDS lanes"
#define REGISTER_ENUM {0, "16 lanes"}, {1, "8 lanes"}, {2, "4 lanes"}, {3, "2 lanes"}
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {72, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(OutputMode)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_ADVANCED
#define REGISTER_CMDS {73, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(FotLength)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 0
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {74, 0, 0, 2}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(ILvdsRec)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {75, 0, 0, 2}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg75)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {76, 0, 0, 2}
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg76)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {77, 0, 0, 2}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(ADCCalib)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS { 77, 1, 0, 1 }
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(ColCalib)

#include "REGISTER_RESET.h"
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {78, 0, 0, 8}, {79, 0, 8, 4}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(TrainingPattern)

#include "REGISTER_RESET.h"
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {80, 0, 0, 8}, {81, 0, 8, 8}, {82, 0, 16, 2}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(ChannelEn)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {83, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(ILvds)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 4
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {84, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(LCol)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 1
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {85, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(LColPrech)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 14
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {86, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg86)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 12
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS { 87, 0, 0, 4 }
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(LAmp)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 64
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS { 88, 0, 0, 7}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(VtfL1)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 89, 0, 0, 7}
#include "REGISTER_MAKE.h"
DEFECATE(VLow2)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 90, 0, 0, 7}
#include "REGISTER_MAKE.h"
DEFECATE(VLow3)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 64
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS { 91, 0, 0, 7 }
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(VResLow)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {92, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg92)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {93, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg93)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 101
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS { 94, 0, 0, 7}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(VPrech)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 106
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {95, 0, 0, 7}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(VRef)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {96, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg96)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {97, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg97)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Voltage of the ramp used by the column ramp ADC (whatever that means...)"
#define REGISTER_MODE_READ
#define REGISTER_INIT 109
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS { 98, 0, 0, 7}
#include "REGISTER_MAKE.h"
DEFECATE(VRamp1)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Voltage of the ramp used by the column ramp ADC (whatever that means...)"
#define REGISTER_MODE_READ
#define REGISTER_INIT 109
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS { 99, 0, 0, 7}
#include "REGISTER_MAKE.h"
DEFECATE(VRamp2)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Dark Level offset applied to the output signal"
#define REGISTER_SIGNED
#define REGISTER_MIN -8192
#define REGISTER_MAX 8191
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {100, 0, 0, 8}, {101, 0, 8, 6}
#include "REGISTER_MAKE.h"
DEFECATE(Offset)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Programmable Gain Amplifier"
#define REGISTER_ENUM {0, "1.0"}, {1, "1.2"}, {2, "1.4"}, {3, "1.6"}, {4, "2.0"}, {5, "2.4"}, {6, "2.8"}, {7, "3.2"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {102, 0, 0, 2}, {121, 0, 2, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PGA)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "ADC Gain - see page 41 of the CMV4000 DataSheet"
#define REGISTER_MIN 0
#define REGISTER_MAX 255
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_INIT 41
#define REGISTER_CMDS {103, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(ADCGain)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_ADVANCED
#define REGISTER_CMDS {104, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Reg104)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_ADVANCED
#define REGISTER_CMDS {105, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Reg105)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_ADVANCED
#define REGISTER_CMDS {106, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Reg106)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_ADVANCED
#define REGISTER_CMDS {107, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Reg107)

// DAVIDE: Page 26
#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "INTE1"}, {1, "INTE2"}, {2, "DVAL"}, {3, "LVAL"}, {4, "FVAL"}
#define REGISTER_CMDS { 108, 0, 0, 4}
#include "REGISTER_MAKE.h"
//DEFECATE(Reg108)
DEFECATE(TDig1)

// DAVIDE: Page 26
#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "INTE1"}, {1, "INTE2"}, {2, "DVAL"}, {3, "LVAL"}, {4, "FVAL"}
#define REGISTER_CMDS { 109, 0, 0, 4}
#include "REGISTER_MAKE.h"
//DEFECATE(Reg109)
DEFECATE(TDig2)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {110, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg110)

#include "REGISTER_RESET.h"
#define REGISTER_ENUM {0, "12 bits per pixel"}, {1, "10 bits per pixel"}
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS { 111, 0, 0, 1}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(BitMode)

#include "REGISTER_RESET.h"
#define REGISTER_ENUM {0, "10 bits per pixel"}, {1, "12 bits per pixel"}
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {112, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(ADCResolution)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_ADVANCED
#define REGISTER_CMDS { 113, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PLLEnable)

#include "REGISTER_RESET.h"
#define REGISTER_ENUM {0, "20 - 48 MHz"}, {1, "10 - 20 MHz"}, {3, "5 - 10 MHz"}
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {114, 0, 0, 2}
#include "REGISTER_MAKE.h"
DEFECATE(PLLINFreq)

#include "REGISTER_RESET.h"
#define REGISTER_ENUM {0, "Internal PLL"}, {1, "Bypass the PLL"}
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS { 115, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PLLBypass)

#include "REGISTER_RESET.h"
#define REGISTER_ENUM {0, "---"}, {9, "10 bits per pixel"}, {11, "12 bits per pixel"}
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {116, 0, 0, 4}
#include "REGISTER_MAKE.h"
DEFECATE(PLLDiv)

#include "REGISTER_RESET.h"
#define REGISTER_ENUM {0, "5 - 15 MHz"}, {1, "15 - 30 MHz"}, {5, "30 - 48 MHz"}
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {116, 4, 0, 3}
#include "REGISTER_MAKE.h"
DEFECATE(PLLOUTFreq)

#include "REGISTER_RESET.h"
#define REGISTER_ENUM {0, "5 - 7.5 MHz, 10 - 15 MHz, 20 - 30 MHz"}, {1, "7.5 - 10 MHz, 15 - 20 MHz, 30 - 48 MHz"}
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {116, 7, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PLLRange)

#include "REGISTER_RESET.h"
#define REGISTER_ENUM {0, "---"}, {4, "12 bits per pixel"}, {8, "10 bits per pixel"}
#define REGISTER_ADVANCED
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {117, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(PLLLoad)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_INIT 1
#define REGISTER_CMDS {118, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Dummy)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_ADVANCED
#define REGISTER_CMDS {119, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Reg119)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {120, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg120)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {121, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(BlackColEn)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {122, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg122)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_INIT 98
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {123, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(VBlackSun)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#ifndef PROTECT_PRIVATE_REGS
#define REGISTER_MODE_WRITE
#endif
#define REGISTER_CMDS {124, 0, 0, 8}
#define REGISTER_ADVANCED
#include "REGISTER_MAKE.h"
DEFECATE(Reg124)

//DAVIDE: Page 46
#include "REGISTER_RESET.h"
#define REGISTER_ENUM {0, "---"}, {32, "CMV2000 v2"}, {35, "CMV2000 v3"}, {64, "CMV4000 v2"}, {67, "CMV4000 v3"}
#define REGISTER_MODE_READ
#define REGISTER_CMDS {125, 0, 0, 8}
#include "REGISTER_MAKE.h"
//DEFECATE(Reg125)
DEFECATE(SensorType)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Temperature sensor\n T_amb[°C] ~= ( RegValue - (1000 * f[MHz] / 40) ) * 0.3 * 40 / f[MHz]"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {126, 0, 0, 8}, {127, 0, 8, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Temp)
#include "REGISTER_RESET.h"

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_cmvx000_sensor_ ## __name__
static const Register * CMVx000_SENSOR_registers[] = {
	&(REGISTER(Reg0)),
	&(REGISTER(NumberLines)),
	&(REGISTER(Start1)),
	&(REGISTER(Start2)),
	&(REGISTER(Start3)),
	&(REGISTER(Start4)),
	&(REGISTER(Start5)),
	&(REGISTER(Start6)),
	&(REGISTER(Start7)),
	&(REGISTER(Start8)),
	&(REGISTER(NumberLines1)),
	&(REGISTER(NumberLines2)),
	&(REGISTER(NumberLines3)),
	&(REGISTER(NumberLines4)),
	&(REGISTER(NumberLines5)),
	&(REGISTER(NumberLines6)),
	&(REGISTER(NumberLines7)),
	&(REGISTER(NumberLines8)),
	&(REGISTER(SubS)),
	&(REGISTER(SubA)),
	&(REGISTER(Color)),
	&(REGISTER(ImageFlipping)),
	&(REGISTER(ImageExpExt)),
	&(REGISTER(ImageExpDual)),
	&(REGISTER(ImageExpSync)),
	&(REGISTER(ExpTime)),
	&(REGISTER(ExpStep)),
	&(REGISTER(ExpKp1)),
	&(REGISTER(ExpKp2)),
	&(REGISTER(NrSlopes)),
	&(REGISTER(ExpSeq)),
	&(REGISTER(ExpTime2)),
	&(REGISTER(ExpStep2)),
	&(REGISTER(Reg62)),
	&(REGISTER(Reg63)),
	&(REGISTER(Reg64)),
	&(REGISTER(Reg65)),
	&(REGISTER(Reg66)),
	&(REGISTER(Reg67)),
	&(REGISTER(NrSlopes2)),
	&(REGISTER(ExpSeq2)),
	&(REGISTER(NumberFrames)),
	&(REGISTER(OutputMode)),
	&(REGISTER(FotLength)),
	&(REGISTER(ILvdsRec)),
	&(REGISTER(Reg75)),
	&(REGISTER(Reg76)),
	&(REGISTER(ADCCalib)),
	&(REGISTER(TrainingPattern)),
	&(REGISTER(ChannelEn)),
	&(REGISTER(ILvds)),
	&(REGISTER(LCol)),
	&(REGISTER(LColPrech)),
	&(REGISTER(Reg86)),
	&(REGISTER(LAmp)),
	&(REGISTER(VtfL1)),
	&(REGISTER(VLow2)),
	&(REGISTER(VLow3)),
	&(REGISTER(VResLow)),
	&(REGISTER(Reg92)),
	&(REGISTER(Reg93)),
	&(REGISTER(VPrech)),
	&(REGISTER(VRef)),
	&(REGISTER(Reg96)),
	&(REGISTER(Reg97)),
	&(REGISTER(VRamp1)),
	&(REGISTER(VRamp2)),
	&(REGISTER(Offset)),
	&(REGISTER(PGA)),
	&(REGISTER(ADCGain)),
	&(REGISTER(Reg104)),
	&(REGISTER(Reg105)),
	&(REGISTER(Reg106)),
	&(REGISTER(Reg107)),
	//		&(REGISTER(Reg108)),
	&(REGISTER(TDig1)),
	//		&(REGISTER(Reg109)),
	&(REGISTER(TDig2)),
	&(REGISTER(Reg110)),
	&(REGISTER(BitMode)),
	&(REGISTER(ADCResolution)),
	&(REGISTER(PLLEnable)),
	&(REGISTER(PLLINFreq)),
	&(REGISTER(PLLBypass)),
	&(REGISTER(PLLDiv)),
	&(REGISTER(PLLOUTFreq)),
	&(REGISTER(PLLRange)),
	&(REGISTER(PLLLoad)),
	&(REGISTER(Dummy)),
	&(REGISTER(Reg119)),
	&(REGISTER(Reg120)),
	&(REGISTER(BlackColEn)),
	&(REGISTER(Reg122)),
	&(REGISTER(VBlackSun)),
	&(REGISTER(Reg124)),
	//		&(REGISTER(Reg125)),
	&(REGISTER(SensorType)),
	&(REGISTER(Temp)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_cmvx000_sensor_dev_attr_##__name__.dev_attr.attr
static struct attribute* CMVx000_SENSOR_attributes[] = {
	&(REGISTER(Reg0)),
	&(REGISTER(NumberLines)),
	&(REGISTER(Start1)),
	&(REGISTER(Start2)),
	&(REGISTER(Start3)),
	&(REGISTER(Start4)),
	&(REGISTER(Start5)),
	&(REGISTER(Start6)),
	&(REGISTER(Start7)),
	&(REGISTER(Start8)),
	&(REGISTER(NumberLines1)),
	&(REGISTER(NumberLines2)),
	&(REGISTER(NumberLines3)),
	&(REGISTER(NumberLines4)),
	&(REGISTER(NumberLines5)),
	&(REGISTER(NumberLines6)),
	&(REGISTER(NumberLines7)),
	&(REGISTER(NumberLines8)),
	&(REGISTER(SubS)),
	&(REGISTER(SubA)),
	&(REGISTER(Color)),
	&(REGISTER(ImageFlipping)),
	&(REGISTER(ImageExpExt)),
	&(REGISTER(ImageExpDual)),
	&(REGISTER(ImageExpSync)),
	&(REGISTER(ExpTime)),
	&(REGISTER(ExpStep)),
	&(REGISTER(ExpKp1)),
	&(REGISTER(ExpKp2)),
	&(REGISTER(NrSlopes)),
	&(REGISTER(ExpSeq)),
	&(REGISTER(ExpTime2)),
	&(REGISTER(ExpStep2)),
	&(REGISTER(Reg62)),
	&(REGISTER(Reg63)),
	&(REGISTER(Reg64)),
	&(REGISTER(Reg65)),
	&(REGISTER(Reg66)),
	&(REGISTER(Reg67)),
	&(REGISTER(NrSlopes2)),
	&(REGISTER(ExpSeq2)),
	&(REGISTER(NumberFrames)),
	&(REGISTER(OutputMode)),
	&(REGISTER(FotLength)),
	&(REGISTER(ILvdsRec)),
	&(REGISTER(Reg75)),
	&(REGISTER(Reg76)),
	&(REGISTER(ADCCalib)),
	&(REGISTER(TrainingPattern)),
	&(REGISTER(ChannelEn)),
	&(REGISTER(ILvds)),
	&(REGISTER(LCol)),
	&(REGISTER(LColPrech)),
	&(REGISTER(Reg86)),
	&(REGISTER(LAmp)),
	&(REGISTER(VtfL1)),
	&(REGISTER(VLow2)),
	&(REGISTER(VLow3)),
	&(REGISTER(VResLow)),
	&(REGISTER(Reg92)),
	&(REGISTER(Reg93)),
	&(REGISTER(VPrech)),
	&(REGISTER(VRef)),
	&(REGISTER(Reg96)),
	&(REGISTER(Reg97)),
	&(REGISTER(VRamp1)),
	&(REGISTER(VRamp2)),
	&(REGISTER(Offset)),
	&(REGISTER(PGA)),
	&(REGISTER(ADCGain)),
	&(REGISTER(Reg104)),
	&(REGISTER(Reg105)),
	&(REGISTER(Reg106)),
	&(REGISTER(Reg107)),
	//		&(REGISTER(Reg108)),
	&(REGISTER(TDig1)),
	//		&(REGISTER(Reg109)),
	&(REGISTER(TDig2)),
	&(REGISTER(Reg110)),
	&(REGISTER(BitMode)),
	&(REGISTER(ADCResolution)),
	&(REGISTER(PLLEnable)),
	&(REGISTER(PLLINFreq)),
	&(REGISTER(PLLBypass)),
	&(REGISTER(PLLDiv)),
	&(REGISTER(PLLOUTFreq)),
	&(REGISTER(PLLRange)),
	&(REGISTER(PLLLoad)),
	&(REGISTER(Dummy)),
	&(REGISTER(Reg119)),
	&(REGISTER(Reg120)),
	&(REGISTER(BlackColEn)),
	&(REGISTER(Reg122)),
	&(REGISTER(VBlackSun)),
	&(REGISTER(Reg124)),
	//		&(REGISTER(Reg125)),
	&(REGISTER(SensorType)),
	&(REGISTER(Temp)),
	NULL
};

static const struct attribute_group CMVx000_SENSOR_sysfsRegisters_group = {
	.name = "parameters",
	.attrs = CMVx000_SENSOR_attributes,
};

#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef SANITAS_CMVx000_SENSOR_REGISTERS_H_
