#ifndef SANITAS_MT9P031_SENSOR_REGISTERS_H_
#define SANITAS_MT9P031_SENSOR_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_mt9p031_sensor_ ## __name__
#undef REGISTER_ATTR_NAME
#define REGISTER_ATTR_NAME(__name__) register_mt9p031_sensor_dev_attr_##__name__

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Two-digit BCD value typically derived from the reticle ID code.\nLegal values: [0, 255]."
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x00,8,0,8}
#include "REGISTER_MAKE.h"
DEFECATE(PartID)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Constant value incremented with each mask change for the same Part ID.\nLegal values: [0, 15]."
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x00,4,0,4}
#include "REGISTER_MAKE.h"
DEFECATE(AnalogRevision)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Constant value incremented with each digital functionality change for the same Part ID.\nLegal values: [0, 15]."
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x00,0,0,4}
#include "REGISTER_MAKE.h"
DEFECATE(DigitalRevision)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The Y coordinate of the upper-left corner of the FOV. If this register is set to an odd value, the next lower\neven value will be used. Writes are synchronized to frame boundaries. Affected by Synchronize_Changes.\nCauses a Bad Frame if written. Legal values: [0, 2004], even."
#define REGISTER_MIN 0
#define REGISTER_MAX 2004
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x01,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(RowStart)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The X coordinate of the upper-left corner of the FOV. The value will be rounded down to the nearest multiple\nof 2 times the column bin factor. Writes are synchronized to frame boundaries. Affected by\nSynchronize_Changes. Legal values: [0, 2750], even.\nNote: Set Column_Start such that it is in the form shown below, where n is an integer:\nMirror_Column = 0 Mirror_Column = 1\nno bin 4n 4n + 2\nBin 2x 8n 8n + 4\nBin 4x 16n 16n + 8"
#define REGISTER_MIN 0
#define REGISTER_MAX 2750
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x02,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(ColumnStart)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The height of the FOV minus one. If this register is set to an even value, the next higher odd value will be\nused. Writes are synchronized to frame boundaries. Affected by Synchronize_Changes.\nCauses a Bad Frame if written. Legal values: [1, 2005], odd."
#define REGISTER_MIN 1
#define REGISTER_MAX 2005
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x03,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(RowSize)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The width of the field of view minus one. If this register is set to an even value, the next higher odd value will\nbe used. In other words, it should be (2*n*(Column_Bin + 1) - 1) for some integer n. Writes are synchronized to\nframe boundaries. Affected by Synchronize_Changes. Causes a Bad Frame if written.\nLegal values: [1, 2751], odd."
#define REGISTER_MIN 1
#define REGISTER_MAX 2750
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(ColumnSize)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Extra time added to the end of each row, in pixel clocks. Incrementing this register will increase exposure and\ndecrease frame rate. Setting a value less than the minimum will use the minumum horizontal blank. The\nminimum horizontal blank depends on the mode of the sensor. Writes are synchronized to frame boundaries.\nAffected by Synchronize_Changes. Causes a Bad Frame if written. Legal values: [0, 4095]."
#define REGISTER_MIN 0
#define REGISTER_MAX 4095
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x05,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(HorizontalBlank)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Extra time added to the end of each frame in rows minus one. Incrementing this register will decrease frame\nrate, but not affect exposure. Setting a value less than the minimum will use the minimum vertical blank.\nWrites are synchronized to frame boundaries. Affected by Synchronize_Changes. Legal values: [8, 2047]."
#define REGISTER_MIN 8
#define REGISTER_MAX 2047
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x06,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(VerticalBlank)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, changes to certain registers (those with the SC attribute) are delayed until the\nbit is clear. When cleared, all the delayed writes will happen immediately. Registers with\nthe F attribute will still have the update synchronized to the next frame boundary."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x07,0,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(SynchronizeChanges)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When clear, sensor readout is stopped and analog circuitry is put in a state which draws\nminimal power. When set, the chip operates according to the current mode. Writing this\nbit does not affect the values of any other registers."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x07,1,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(ChipEnable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, pixels will be sent through the output FIFO before being sent off chip. This\nallows the output port to be running at a slower speed than f_PIXCLK, because the FIFO\nallows for pixels to be output during horizontal blank. Use of this mode requires the PLL to\nbe set up properly."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x07,2,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(FIFOParallelData)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Controls the slew rate on the PIXCLK pad. Higher values imply faster transition times.\nLegal values: [0, 7]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x07,7,0,3}
#include "REGISTER_MAKE.h"
DEFECATE(PIXCLKSlewRate)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Controls the slew rate on digital output pads except for PIXCLK. Higher values imply faster\ntransition times. Legal values: [0, 7]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x07,10,0,3}
#include "REGISTER_MAKE.h"
DEFECATE(OutputSlewRate)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The most significant bits of the shutter width, which are combined with Shutter Width Lower (R9)."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(ShutterWidthUpper)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The least significant bits of the shutter width. This is combined with Shutter_Width_Upper and Shutter_Delay\nfor the effective shutter width. If set to zero, a value of �1� will be used."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x09,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(ShutterWidthLower)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, LV, FV, and D_OUT should be captured on the rising edge of PIXCLK. When clear,\nthey should be captured on the falling edge. This is accomplished by inverting the PIXCLK\noutput.\nNOTE: This field is not reset by the soft Reset (R13)."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0A,15,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(InvertPixelClock)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Two's complement value representing how far to shift the PIXCLK output pin relative to\nDOUT, in EXTCLK cycles. Positive values shift PIXCLK later in time relative to DOUT (and thus\nrelative to the internal array/datapath clock). No effect unless PIXCLK is divided by Divide\nPixel Clock.\nNOTE: This field is not reset by the soft Reset (R13).\nLegal values: [-2, 2]."
#define REGISTER_SIGNED
#define REGISTER_MIN -2
#define REGISTER_MAX 2
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0A,8,0,3}
#include "REGISTER_MAKE.h"
DEFECATE(ShiftPixelClock)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Divide Pixel Clock\nProduces a PIXCLK that is divided by the value times two. The value must be zero or a\npower of 2. This will slow down the internal clock in the array control and datapath blocks,\nincluding pixel readout. It will not affect the two-wire serial interface clock. A value of �0�\ncorresponds to a PIXCLK with the same frequency as EXTCLK. A value of 1 means f_PIXCLK\n= (f_EXTCLK / 2); 2 means f_PIXCLK = (f_EXTCLK / 4); 64 means f_PIXCLK = (f_EXTCLK / 128);\nand so on.\nNOTE: This field is not reset by the soft Reset (R13). This field should not be written while in\nstreaming mode. Instead, Pause_Restart should be used to suspend output while the\ndivider is being changed. Legal values: [0, 1, 2, 4, 8, 16, 32, 64]."
#define REGISTER_ENUM {0, "0"},{1, "1"},{2, "2"},{4, "4"},{8, "8"},{16, "16"},{32, "32"},{64, "64"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0A,0,0,7}
#include "REGISTER_MAKE.h"
DEFECATE(DividePixelClock)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Setting this bit in Snapshot mode will cause the next trigger to occur as if the TRIGGER pin\nwere properly asserted/negated. Ineffective if not in Snapshot mode. The sense of this bit is\nNOT affected by Invert Trigger.\nWhen using this bit instead of the TRIGGER pin, make sure that either the trigger pin is\ncontinuously asserted, or that the pad is continuously negated and Invert_Trigger is set."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0B,2,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(Trigger)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, Restart will not automatically be cleared. Instead, the sensor will pause at row 0\nafter Restart is set. When Pause_Restart is cleared, the sensor will resume. This allows for a\nrepeatable delay from clearing restart to FV. When clearing this bit, be sure not to clear\nRestart as well: it will be cleared automatically when the device has restarted."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0B,1,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(PauseRestart)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Setting this bit will cause the sensor to abandon the current frame and restart from the\nfirst row. It will take up to 2 * t_ROW for the restart to take effect. This bit resets to 0\nautomatically unless Pause_Restart is set. Manually setting this bit to zero will cause\nundefined behavior.\nVolatile."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0B,0,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(Restart)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "A negative adjustment to the effective shutter width in ACLKs. See Shutter_Width_Lower. Writes are\nsynchronized to frame boundaries. Affected by Synchronize_Changes. Legal values: [0, 8191]."
#define REGISTER_MIN 0
#define REGISTER_MAX 8191
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0C,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(ShutterDelay)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Setting this bit will put the sensor into reset mode, which will set the sensor to its default power-up state and\ncause it to halt. Clearing this bit will resume normal operation. This is equivalent to pulling RESET_BAR LOW,\nexcept that the two-wire serial interface remains functional."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x0D,0,0,16}
#include "REGISTER_MAKE.h"
DEFECATE(Reset)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, use the PLL output as the system clock. When clear, use EXTCLK as the system Clock."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10,0,1,1}
#include "REGISTER_MAKE.h"
DEFECATE(PLLControlUse)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, the PLL is powered. When clear, it is not powered."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10,0,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(PLLControlPower)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PLL output frequency multiplier.\nLegal values: [16, 255]."
#define REGISTER_MIN 16
#define REGISTER_MAX 255
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x11,8,0,8}
#include "REGISTER_MAKE.h"
DEFECATE(PLLConfig1MFactor)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PLL output frequency divider minus 1.\nLegal values: [0, 63]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x11,0,0,6}
#include "REGISTER_MAKE.h"
DEFECATE(PLLConfig1NDivider)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PLL system clock divider minus 1. Use odd numbers. If this is set to an even number, the\nsystem clock duty cycle will not be 50:50. In this case, set all bits in R101 or slow down EXTCLK.\nLegal values: [0, 127]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x12,0,0,5}
#include "REGISTER_MAKE.h"
DEFECATE(PLLConfig2P1Divider)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, produce a LV signal that is the XOR of FV and the normal line_valid. Ineffective\nif Continuous Line Valid is set. When clear, produce a normal LV."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,11,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(XORLineValid)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, produce the LV signal even during the vertical blank period. When clear,\nproduce LV only when active rows are being read out (that is, only when FV is HIGH).\nIneffective if FIFO_Parallel_Data is set."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,10,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(ContinuousLineValid)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, the sense of the TRIGGER input pin will be inverted."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,9,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(InvertTrigger)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, the sensor enters snapshot mode, and will wait for a trigger event between\nframes. When clear, the sensor is in continuous mode. Writes are synchronized to frame\nboundaries. Affected by Synchronize_Changes."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,8,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(Snapshot)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, the Global Reset Release shutter will be used. When clear, the Electronic Rolling\nShutter will be used. Writes are synchronized to frame boundaries. Affected by\nSynchronize_Changes."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,7,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(GlobalReset)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, exposure time will be controlled by an external trigger. When clear, exposure\ntime will be controlled by the Shutter_Width_Lower and Shutter_Width_Upper registers.\nWrites are synchronized to frame boundaries. Affected by Synchronize_Changes."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,6,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(BulbExposure)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, the STROBE signal will be active LOW (during exposure). When clear, the\nSTROBE signal is active HIGH."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,5,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(InvertStrobe)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, a strobe signal will be generated by the digital logic during integration. When\nclear, the strobe pin will be set to the value of Invert_Strobe."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,4,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(StrobeEnable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Determines the timepoint when the strobe is asserted.\n0: First trigger\n1: Start of simultaneous exposure\n2: Shutter width\n3: Second trigger\nWrites are synchronized to frame boundaries. Affected by Synchronize_Changes."
#define REGISTER_ENUM {0, "First trigger"},{1, "Start of simultaneous exposure"},{2, "Shutter width"},{3, "Second trigger"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,2,0,2}
#include "REGISTER_MAKE.h"
DEFECATE(StrobeStart)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Determines the timepoint when the strobe is negated. If this is set equal to or less than\nStrobe_Start, the width of the strobe pulse will be t_ROW. See Strobe_Start. Writes are\nsynchronized to frame boundaries. Affected by Synchronize_Changes."
#define REGISTER_ENUM {0, "First trigger"},{1, "Start of simultaneous exposure"},{2, "Shutter width"},{3, "Second trigger"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1E,0,0,2}
#include "REGISTER_MAKE.h"
DEFECATE(StrobeEnd)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, row readout in the active image occurs in reverse numerical order starting from\n(Row_Start + Row_Size). When clear, row readout of the active image occurs in numerical\norder. This has no effect on the readout of the dark rows. Writes are synchronized to frame\nboundaries. Affected by Synchronize_Changes. Causes a Bad Frame if written."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x20,15,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(MirrorRow)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, column readout in the active image occurs in reverse numerical order, starting\nfrom (Column_Start + Column_Size). When clear, column readout of the active image\noccurs in numerical order. This has no effect on the readout of the dark columns. Writes\nare synchronized to frame boundaries. Affected by Synchronize_Changes."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x20,14,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(MirrorColumn)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, the dark columns will be output to the left of the active image, making the\noutput image wider. This has no effect on integration time or frame rate. When clear, only\ncolumns that are part of the active image will be output. Writes are synchronized to frame\nboundaries. Affected by Synchronize_Changes."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x20,12,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(ShowDarkColumns)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, the dark rows will be output before the active image rows, making the output\nimage taller. This has no effect on integration time or frame rate. When clear, only rows\nfrom the active image will be output. Writes are synchronized to frame boundaries.\nAffected by Synchronize_Changes."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x20,11,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(ShowDarkRows)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, digitally compensate for differing black levels between rows by adding Dark\nTarget (R73) and subtracting the average value of the 8 same-color dark pixels at the\nbeginning of the row. When clear, digitally add Row Black Default Offset (R75) to the\nvalue of each pixel."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x20,6,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(RowBLC)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "When set, column summing will be enabled, and in column bin modes, all sampled\ncapacitors will be enabled for column readout, resulting in an effective gain equal to the\ncolumn bin factor. When clear, column averaging will be done, and there will be no\nadditional gain related to the column bin factor.\nWrites are synchronized to frame boundaries. Affected by Synchronize_Changes."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x20,5,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(ColumnSum)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The number of rows to be read and averaged per row output minus one. The rows will be\nread independently into sampling capacitors, then averaged before column readout. For\nnormal readout, this should be 0. For Bin 2X, it should be 1; for Bin 4X, it should be 3.\nWrites are synchronized to frame boundaries. Affected by Synchronize_Changes. Causes a\nBad Frame if written. Legal values: [0, 3]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x22,4,0,2}
#include "REGISTER_MAKE.h"
DEFECATE(RowBin)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The number of row-pairs to skip for every row-pair output. A value of zero means to read\nevery row. For Skip 2X, this should be 1; for Skip 3X, it should be 2, and so on. This value\nshould be no less than Row_Bin. For full binning, Row_Skip should equal Row_Bin.\nWrites are synchronized to frame boundaries. Affected by Synchronize_Changes. Causes a\nBad Frame if written. Legal values: [0, 7]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x22,0,0,3}
#include "REGISTER_MAKE.h"
DEFECATE(RowSkip)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The number of columns to be read and averaged per column output minus one. For normal\nreadout, this should be zero. For Bin 2X, it shoud be 1; for Bin 4X, it should be 3. Writes are\nsynchronized to frame boundaries. Affected by Synchronize_Changes. Causes a Bad Frame\nif written. Legal values: {0, 1, 3}."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x23,4,0,2}
#include "REGISTER_MAKE.h"
DEFECATE(ColumnBin)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The number of column-pairs to skip for every column-pair output. A value of zero means to\nread every column in the active image. For Skip 2X, this should be 1; for Skip 3X, this should\nbe 2, and so on. This value should be no less than Column_Bin. For full binning,\nColumn_Skip should equal Column_Bin. Writes are synchronized to frame boundaries.\nAffected by Synchronize_Changes. Causes a Bad Frame if written. Legal values: [0, 6]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x23,0,0,3}
#include "REGISTER_MAKE.h"
DEFECATE(ColumnSkip)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Digital Gain for the Green1 channel minus 1 times 8. The actual digital gain is (1 + value/8),\nand can range from 1 (a setting of 0) to 16 (a setting of 120) in increments of 1/8. Writes\nare synchronized to frame boundaries. Affected by Synchronize_Changes. Volatile.\nLegal values: [0, 120]."
#define REGISTER_MIN 0
#define REGISTER_MAX 120
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2B,8,0,6}
#include "REGISTER_MAKE.h"
DEFECATE(Green1DigitalGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Green1 Analog Multiplier\nAnalog gain multiplier for the Green1 channel minus 1. If 1, an additional analog gain of\n2X will be applied. If 0, no additional gain is applied. Writes are synchronized to frame\nboundaries. Affected by Synchronize_Changes. Volatile."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2B,6,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(Green1AnalogMultiplier)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Analog gain setting for the Green1 channel times 8. The effective gain for the channel is\n(((Green1_Digital_Gain/8) + 1) * (Green1_Analog_Multiplier + 1) * (Green1_Analog_Gain/\n8)). Writes are synchronized to frame boundaries. Affected by Synchronize_Changes.\nVolatile. Legal values: [8, 63]."
#define REGISTER_MIN 8
#define REGISTER_MAX 63
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2B,0,0,6}
#include "REGISTER_MAKE.h"
DEFECATE(Green1AnalogGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Digital Gain for the Blue channel minus 1 times 8. The actual digital gain is (1 + value/8),\nand can range from 1 (a setting of 0) to 16 (a setting of 120) in increments of 1/8. Writes\nare synchronized to frame boundaries. Affected by Synchronize_Changes. Volatile.\nLegal values: [0, 120]."
#define REGISTER_MIN 0
#define REGISTER_MAX 120
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2C,8,0,7}
#include "REGISTER_MAKE.h"
DEFECATE(BlueDigitalGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Analog gain multiplier for the Blue channel minus 1. If 1, an additional analog gain of 2X\nwill be applied. If 0, no additional gain is applied. Writes are synchronized to frame\nboundaries. Affected by Synchronize_Changes. Volatile."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2C,6,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(BlueAnalogMultiplier)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Analog gain setting for the Blue channel times 8. The effective gain for the channel is\n(((Blue_Digital_Gain/8) + 1) * (Blue_Analog_Multiplier + 1) * (Blue_Analog_Gain/8)). Writes\nare synchronized to frame boundaries. Affected by Synchronize_Changes. Volatile.\nLegal values: [8, 63]."
#define REGISTER_MIN 8
#define REGISTER_MAX 63
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2C,0,0,6}
#include "REGISTER_MAKE.h"
DEFECATE(BlueAnalogGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Digital Gain for the Red channel minus 1 times 8. The actual digital gain is (1 + value/8),\nand can range from 1 (a setting of 0) to 16 (a setting of 120) in increments of 1/8. Writes\nare synchronized to frame boundaries. Affected by Synchronize_Changes. Volatile.\nLegal values: [0, 120]."
#define REGISTER_MIN 0
#define REGISTER_MAX 120
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2D,8,0,7}
#include "REGISTER_MAKE.h"
DEFECATE(RedDigitalGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Analog gain multiplier for the Red channel minus 1. If 1, an additional analog gain of 2X\nwill be applied. If 0, no additional gain is applied. Writes are synchronized to frame\nboundaries. Affected by Synchronize_Changes. Volatile."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2D,6,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(RedAnalogMultiplier)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Analog gain setting for the Red channel times 8. The effective gain for the channel is\n(((Red_Digital_Gain/8) + 1) * (Red_Analog_Multiplier + 1) * (Red_Analog_Gain/8)). Writes\nare synchronized to frame boundaries. Affected by Synchronize_Changes. Volatile. Legal\nValues: [8, 63]."
#define REGISTER_MIN 8
#define REGISTER_MAX 63
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2D,0,0,6}
#include "REGISTER_MAKE.h"
DEFECATE(RedAnalogGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Digital Gain for the Green2 channel minus 1 times 8. The actual digital gain is (1 + value/8),\nand can range from 1 (a setting of 0) to 16 (a setting of 120) in increments of 1/8. Writes\nare synchronized to frame boundaries. Affected by Synchronize_Changes. Volatile.\nLegal values: [0, 120]."
#define REGISTER_MIN 0
#define REGISTER_MAX 120
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2E,8,0,7}
#include "REGISTER_MAKE.h"
DEFECATE(Green2DigitalGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Analog gain multiplier for the Green2 channel minus 1. If 1, an additional analog gain of\n2X will be applied. If 0, no additional gain is applied. Writes are synchronized to frame\nboundaries. Affected by Synchronize_Changes. Volatile."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2E,6,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(Green2AnalogMultiplier)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Analog gain setting for the Green2 channel times 8. The effective gain for the channel is\n(((Green2_Digital_Gain/8) + 1) * (Green2_Analog_Multiplier + 1) * (Green2_Analog_Gain/\n8)). Writes are synchronized to frame boundaries. Affected by Synchronize_Changes.\nVolatile. Legal values: [8, 63]."
#define REGISTER_MIN 8
#define REGISTER_MAX 63
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x2E,0,0,6}
#include "REGISTER_MAKE.h"
DEFECATE(Green2AnalogGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Writing the GlogalDigitalGain sets all four individual gain registers to the value. This register should not be read."
#define REGISTER_MIN 0
#define REGISTER_MAX 120
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x35,8,0,7}
#include "REGISTER_MAKE.h"
DEFECATE(GlogalDigitalGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Writing the GlogalAnalogMultiplier sets all four individual gain registers to the value. This register should not be read."
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x35,6,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(GlobalAnalogMultiplier)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Writing the GlogalAnalogGain sets all four individual gain registers to the value. This register should not be read."
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x35,0,0,6}
#include "REGISTER_MAKE.h"
DEFECATE(GlobalAnalogGain)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Sets the test pattern mode.\nLegal values: [0, 15]."
#define REGISTER_ENUM {0, "Color field"}, {1, "Horizontal gradient"}, {2, "Vertical gradient"}, {3, "Diagonal"}, {4, "Classic"}, {5, "Walking 1s"}, {6, "Monochrome horizontal bars"}, {7, "Monochrome vertical bars"}, {8, "Vertical color bars"}
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0xA0,3,0,4}
#include "REGISTER_MAKE.h"
DEFECATE(TestPatternControl)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Enables the test pattern. When set, data from the ADC will be replaced with a digitally\ngenerated test pattern specified by Test_Pattern_Mode."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0xA0,0,0,1}
#include "REGISTER_MAKE.h"
DEFECATE(EnableTestPattern)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Value used for green pixels of dark rows and columns in all test patterns, and for the color\nfield.\nLegal values: [0, 4095]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0xA1,0,0,12}
#include "REGISTER_MAKE.h"
DEFECATE(TestPatternGreen)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Value used for red pixels of dark rows and columns in all test patterns, and for the color field.\nLegal values: [0, 4095]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0xA2,0,0,12}
#include "REGISTER_MAKE.h"
DEFECATE(TestPatternRed)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Value used for blue pixels of dark rows and columns in all test patterns, and for the color field.\nLegal values: [0, 4095]."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0xA3,0,0,12}
#include "REGISTER_MAKE.h"
DEFECATE(TestPatternBlue)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "The width of the monochrome color bars in test modes 6 and 7. This should be set to an odd value.\nLegal values: [0, 4095], odd."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0xA4,0,0,12}
#include "REGISTER_MAKE.h"
DEFECATE(TestPatternBarWidth)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Mirror of R0[15:0]. Read-only. Duplicate. Appears in all pages. Legal values: special."
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xFF,0,0,15}
#include "REGISTER_MAKE.h"
DEFECATE(ChipVersionAlt)

#include "REGISTER_RESET.h"

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_mt9p031_sensor_ ## __name__
static const Register * MT9P031_SENSOR_registers[] = {
	&(REGISTER(PartID)),
	&(REGISTER(AnalogRevision)),
	&(REGISTER(DigitalRevision)),
	&(REGISTER(RowStart)),
	&(REGISTER(ColumnStart)),
	&(REGISTER(RowSize)),
	&(REGISTER(ColumnSize)),
	&(REGISTER(HorizontalBlank)),
	&(REGISTER(VerticalBlank)),
	&(REGISTER(SynchronizeChanges)),
	&(REGISTER(ChipEnable)),
	&(REGISTER(FIFOParallelData)),
	&(REGISTER(PIXCLKSlewRate)),
	&(REGISTER(OutputSlewRate)),
	&(REGISTER(ShutterWidthUpper)),
	&(REGISTER(ShutterWidthLower)),
	&(REGISTER(InvertPixelClock)),
	&(REGISTER(ShiftPixelClock)),
	&(REGISTER(DividePixelClock)),
	&(REGISTER(Trigger)),
	&(REGISTER(PauseRestart)),
	&(REGISTER(Restart)),
	&(REGISTER(ShutterDelay)),
	&(REGISTER(Reset)),
	&(REGISTER(PLLControlUse)),
	&(REGISTER(PLLControlPower)),
	&(REGISTER(PLLConfig1MFactor)),
	&(REGISTER(PLLConfig1NDivider)),
	&(REGISTER(PLLConfig2P1Divider)),
	&(REGISTER(XORLineValid)),
	&(REGISTER(ContinuousLineValid)),
	&(REGISTER(InvertTrigger)),
	&(REGISTER(Snapshot)),
	&(REGISTER(GlobalReset)),
	&(REGISTER(BulbExposure)),
	&(REGISTER(InvertStrobe)),
	&(REGISTER(StrobeEnable)),
	&(REGISTER(StrobeStart)),
	&(REGISTER(StrobeEnd)),
	&(REGISTER(MirrorRow)),
	&(REGISTER(MirrorColumn)),
	&(REGISTER(ShowDarkColumns)),
	&(REGISTER(ShowDarkRows)),
	&(REGISTER(RowBLC)),
	&(REGISTER(ColumnSum)),
	&(REGISTER(RowBin)),
	&(REGISTER(RowSkip)),
	&(REGISTER(ColumnBin)),
	&(REGISTER(ColumnSkip)),
	&(REGISTER(Green1DigitalGain)),
	&(REGISTER(Green1AnalogMultiplier)),
	&(REGISTER(Green1AnalogGain)),
	&(REGISTER(BlueDigitalGain)),
	&(REGISTER(BlueAnalogMultiplier)),
	&(REGISTER(BlueAnalogGain)),
	&(REGISTER(RedDigitalGain)),
	&(REGISTER(RedAnalogMultiplier)),
	&(REGISTER(RedAnalogGain)),
	&(REGISTER(Green2DigitalGain)),
	&(REGISTER(Green2AnalogMultiplier)),
	&(REGISTER(Green2AnalogGain)),
	&(REGISTER(GlogalDigitalGain)),
	&(REGISTER(GlobalAnalogMultiplier)),
	&(REGISTER(GlobalAnalogGain)),
	&(REGISTER(TestPatternControl)),
	&(REGISTER(EnableTestPattern)),
	&(REGISTER(TestPatternGreen)),
	&(REGISTER(TestPatternRed)),
	&(REGISTER(TestPatternBlue)),
	&(REGISTER(TestPatternBarWidth)),
	&(REGISTER(ChipVersionAlt)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_mt9p031_sensor_dev_attr_##__name__.dev_attr.attr
static struct attribute* MT9P031_SENSOR_attributes[] = {
	&(REGISTER(PartID)),
	&(REGISTER(AnalogRevision)),
	&(REGISTER(DigitalRevision)),
	&(REGISTER(RowStart)),
	&(REGISTER(ColumnStart)),
	&(REGISTER(RowSize)),
	&(REGISTER(ColumnSize)),
	&(REGISTER(HorizontalBlank)),
	&(REGISTER(VerticalBlank)),
	&(REGISTER(SynchronizeChanges)),
	&(REGISTER(ChipEnable)),
	&(REGISTER(FIFOParallelData)),
	&(REGISTER(PIXCLKSlewRate)),
	&(REGISTER(OutputSlewRate)),
	&(REGISTER(ShutterWidthUpper)),
	&(REGISTER(ShutterWidthLower)),
	&(REGISTER(InvertPixelClock)),
	&(REGISTER(ShiftPixelClock)),
	&(REGISTER(DividePixelClock)),
	&(REGISTER(Trigger)),
	&(REGISTER(PauseRestart)),
	&(REGISTER(Restart)),
	&(REGISTER(ShutterDelay)),
	&(REGISTER(Reset)),
	&(REGISTER(PLLControlUse)),
	&(REGISTER(PLLControlPower)),
	&(REGISTER(PLLConfig1MFactor)),
	&(REGISTER(PLLConfig1NDivider)),
	&(REGISTER(PLLConfig2P1Divider)),
	&(REGISTER(XORLineValid)),
	&(REGISTER(ContinuousLineValid)),
	&(REGISTER(InvertTrigger)),
	&(REGISTER(Snapshot)),
	&(REGISTER(GlobalReset)),
	&(REGISTER(BulbExposure)),
	&(REGISTER(InvertStrobe)),
	&(REGISTER(StrobeEnable)),
	&(REGISTER(StrobeStart)),
	&(REGISTER(StrobeEnd)),
	&(REGISTER(MirrorRow)),
	&(REGISTER(MirrorColumn)),
	&(REGISTER(ShowDarkColumns)),
	&(REGISTER(ShowDarkRows)),
	&(REGISTER(RowBLC)),
	&(REGISTER(ColumnSum)),
	&(REGISTER(RowBin)),
	&(REGISTER(RowSkip)),
	&(REGISTER(ColumnBin)),
	&(REGISTER(ColumnSkip)),
	&(REGISTER(Green1DigitalGain)),
	&(REGISTER(Green1AnalogMultiplier)),
	&(REGISTER(Green1AnalogGain)),
	&(REGISTER(BlueDigitalGain)),
	&(REGISTER(BlueAnalogMultiplier)),
	&(REGISTER(BlueAnalogGain)),
	&(REGISTER(RedDigitalGain)),
	&(REGISTER(RedAnalogMultiplier)),
	&(REGISTER(RedAnalogGain)),
	&(REGISTER(Green2DigitalGain)),
	&(REGISTER(Green2AnalogMultiplier)),
	&(REGISTER(Green2AnalogGain)),
	&(REGISTER(GlogalDigitalGain)),
	&(REGISTER(GlobalAnalogMultiplier)),
	&(REGISTER(GlobalAnalogGain)),
	&(REGISTER(TestPatternControl)),
	&(REGISTER(EnableTestPattern)),
	&(REGISTER(TestPatternGreen)),
	&(REGISTER(TestPatternRed)),
	&(REGISTER(TestPatternBlue)),
	&(REGISTER(TestPatternBarWidth)),
	&(REGISTER(ChipVersionAlt)),
	NULL
};

static const struct attribute_group MT9P031_SENSOR_sysfsRegisters_group = {
	.name = "parameters",
	.attrs = MT9P031_SENSOR_attributes,
};

#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef SANITAS_MT9P031_SENSOR_REGISTERS_H_
