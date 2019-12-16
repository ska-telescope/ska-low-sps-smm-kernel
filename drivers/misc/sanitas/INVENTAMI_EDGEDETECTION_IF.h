/*  COPYRIGHT (c) 2015-2016 by Sanitas EG
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 *
 */

#ifndef INVENTAMI_EDGEDETECTION_REGISTERS_H_
#define INVENTAMI_EDGEDETECTION_REGISTERS_H_

//! \cond REGISTERS

#include "register_map.h"

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_EdgeDetection_system_ ## __name__

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "ROI_Out_enable"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(ROI_Out_enable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "EDGE_Out_enable"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(EDGE_Out_enable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter_Out_enable"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Filter_Out_enable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_enable"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0, 3, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_enable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter2_enable"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0, 4, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Filter2_enable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "DDP ROI width"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {2, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(DdpRoiWidth)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "DarkThreshold"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {4, 0, 16, 16}, {6, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(DarkThreshold)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "SaturationThreshold"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {8, 0, 16, 16}, {10, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(SaturationThreshold)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "EdgeThreshold"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {12, 0, 16, 16}, {14, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(EdgeThreshold)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "EdgeSegmentLength"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {16, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(EdgeSegmentLength)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "RowMinusEdgeSegmentLength"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {18, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(RowMinusEdgeSegmentLength)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "MaxCount"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {20, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(MaxCount)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "SaturationCount"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {22, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(SaturationCount)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "EdgeThresholdCount"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {24, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(EdgeThresholdCount)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "InflactionMissCount"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {26, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(InflactionMissCount)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Udp port for ROI video stream"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {28, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(UdpPortROI)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Udp port for EDGE video stream"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {30, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(UdpPortEDGE)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_00"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {32, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_00)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_01"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {34, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_01)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_02"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {36, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_02)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_10"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {38, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_10)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_11"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {40, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_11)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_12"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {42, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_12)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_20"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {44, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_20)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_21"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {46, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_21)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_22"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {48, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_22)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_Rsh"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {50, 0, 0, 5}
#include "REGISTER_MAKE.h"
DEFECATE(Filter1_Rsh)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter2_00"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {64, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter2_00)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter2_01"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {66, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter2_01)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter2_02"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {68, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter2_02)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter2_03"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {70, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter2_03)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter2_04"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_SIGNED
#define REGISTER_CMDS {72, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Filter2_04)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Filter1_2_Rsh"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {74, 0, 0, 5}
#include "REGISTER_MAKE.h"
DEFECATE(Filter2_Rsh)

#include "REGISTER_RESET.h"

//! \endcond REGISTERS

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_EdgeDetection_system_ ## __name__

static const Register * EdgeDetection_registers[] = {
	&(REGISTER(ROI_Out_enable            )),
	&(REGISTER(EDGE_Out_enable           )),
	&(REGISTER(Filter_Out_enable         )),
	&(REGISTER(Filter1_enable            )),
	&(REGISTER(Filter2_enable            )),
    &(REGISTER(DdpRoiWidth               )),
	&(REGISTER(DarkThreshold             )),
	&(REGISTER(SaturationThreshold       )),
	&(REGISTER(EdgeThreshold             )),
	&(REGISTER(EdgeSegmentLength         )),
	&(REGISTER(RowMinusEdgeSegmentLength )),
	&(REGISTER(MaxCount                  )),
	&(REGISTER(SaturationCount           )),
	&(REGISTER(EdgeThresholdCount        )),
	&(REGISTER(InflactionMissCount       )),
    &(REGISTER(UdpPortROI                )),
    &(REGISTER(UdpPortEDGE               )),
    &(REGISTER(Filter1_00                )),
	&(REGISTER(Filter1_01                )),
	&(REGISTER(Filter1_02                )),
	&(REGISTER(Filter1_10                )),
	&(REGISTER(Filter1_11                )),
	&(REGISTER(Filter1_12                )),
	&(REGISTER(Filter1_20                )),
	&(REGISTER(Filter1_21                )),
	&(REGISTER(Filter1_22                )),
	&(REGISTER(Filter1_Rsh               )),
	&(REGISTER(Filter2_00                )),
	&(REGISTER(Filter2_01                )),
	&(REGISTER(Filter2_02                )),
	&(REGISTER(Filter2_03                )),
	&(REGISTER(Filter2_04                )),
	&(REGISTER(Filter2_Rsh               )),
	NULL
};

#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* EdgeDetection_attributes[] = {
	&(REGISTER(ROI_Out_enable            )),
	&(REGISTER(EDGE_Out_enable           )),
	&(REGISTER(Filter_Out_enable         )),
	&(REGISTER(Filter1_enable            )),
	&(REGISTER(Filter2_enable            )),
    &(REGISTER(DdpRoiWidth               )),
	&(REGISTER(DarkThreshold             )),
	&(REGISTER(SaturationThreshold       )),
	&(REGISTER(EdgeThreshold             )),
	&(REGISTER(EdgeSegmentLength         )),
	&(REGISTER(RowMinusEdgeSegmentLength )),
	&(REGISTER(MaxCount                  )),
	&(REGISTER(SaturationCount           )),
	&(REGISTER(EdgeThresholdCount        )),
	&(REGISTER(InflactionMissCount       )),
	&(REGISTER(UdpPortROI                )),
    &(REGISTER(UdpPortEDGE               )),
    &(REGISTER(Filter1_00                )),
	&(REGISTER(Filter1_01                )),
	&(REGISTER(Filter1_02                )),
	&(REGISTER(Filter1_10                )),
	&(REGISTER(Filter1_11                )),
	&(REGISTER(Filter1_12                )),
	&(REGISTER(Filter1_20                )),
	&(REGISTER(Filter1_21                )),
	&(REGISTER(Filter1_22                )),
	&(REGISTER(Filter1_Rsh               )),
	&(REGISTER(Filter2_00                )),
	&(REGISTER(Filter2_01                )),
	&(REGISTER(Filter2_02                )),
	&(REGISTER(Filter2_03                )),
	&(REGISTER(Filter2_04                )),
	&(REGISTER(Filter2_Rsh               )),
	NULL
};

static const struct attribute_group EdgeDetection_sysfs_group = {
	.name  = "parameters",
	.attrs = EdgeDetection_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef INVENTAMI_EDGEDETECTION_REGISTERS_H_
