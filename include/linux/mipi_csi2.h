/*
 * Copyright (C) 2011-2013 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __INCLUDE_MIPI_CSI2_H
#define __INCLUDE_MIPI_CSI2_H

/* MIPI CSI2 registers */
#define MIPI_CSI2_REG(offset)		(offset)

#define	MIPI_CSI2_VERSION		MIPI_CSI2_REG(0x000)
#define	MIPI_CSI2_N_LANES		MIPI_CSI2_REG(0x004)
#define	MIPI_CSI2_PHY_SHUTDOWNZ		MIPI_CSI2_REG(0x008)
#define	MIPI_CSI2_DPHY_RSTZ		MIPI_CSI2_REG(0x00c)
#define	MIPI_CSI2_CSI2_RESETN		MIPI_CSI2_REG(0x010)
#define	MIPI_CSI2_PHY_STATE		MIPI_CSI2_REG(0x014)
#define	MIPI_CSI2_DATA_IDS_1		MIPI_CSI2_REG(0x018)
#define	MIPI_CSI2_DATA_IDS_2		MIPI_CSI2_REG(0x01c)
#define	MIPI_CSI2_ERR1			MIPI_CSI2_REG(0x020)
#define	MIPI_CSI2_ERR2			MIPI_CSI2_REG(0x024)
#define	MIPI_CSI2_MASK1			MIPI_CSI2_REG(0x028)
#define	MIPI_CSI2_MASK2			MIPI_CSI2_REG(0x02c)
#define	MIPI_CSI2_PHY_TST_CTRL0		MIPI_CSI2_REG(0x030)
#define	MIPI_CSI2_PHY_TST_CTRL1		MIPI_CSI2_REG(0x034)
#define	MIPI_CSI2_SFT_RESET		MIPI_CSI2_REG(0xf00)

// Derived from Lauterbach peripheral file
#define MIPI_CSI2_ERR1__ERR_ECC_DOUBLE        1 << 28 // Header ECC contains 2 errors
#define MIPI_CSI2_ERR1__VC3_ERR_CRC           1 << 27 // Checksum Error detected on Virtual Channel 3
#define MIPI_CSI2_ERR1__VC2_ERR_CRC           1 << 26 // Checksum Error detected on Virtual Channel 2
#define MIPI_CSI2_ERR1__VC1_ERR_CRC           1 << 25 // Checksum Error detected on Virtual Channel 1
#define MIPI_CSI2_ERR1__VC0_ERR_CRC           1 << 24 // Checksum Error detected on Virtual Channel 0
#define MIPI_CSI2_ERR1__ERR_I_SEQ_DI3         1 << 23 // Error in the sequence of lines for vc3 and dt3
#define MIPI_CSI2_ERR1__ERR_I_SEQ_DI2         1 << 22 // Error in the sequence of lines for vc2 and dt2
#define MIPI_CSI2_ERR1__ERR_I_SEQ_DI1         1 << 21 // Error in the sequence of lines for vc1 and dt1
#define MIPI_CSI2_ERR1__ERR_I_SEQ_DI0         1 << 20 // Error in the sequence of lines for vc0 and dt0
#define MIPI_CSI2_ERR1__ERR_I_BNDRY_MATCH_DI3 1 << 19 // Error matching Line Start with Line End for vc3 and dt3
#define MIPI_CSI2_ERR1__ERR_I_BNDRY_MATCH_DI2 1 << 18 // Error matching Line Start with Line End for vc2 and dt2
#define MIPI_CSI2_ERR1__ERR_I_BNDRY_MATCH_DI1 1 << 17 // Error matching Line Start with Line End for vc1 and dt1
#define MIPI_CSI2_ERR1__ERR_I_BNDRY_MATCH_DI0 1 << 16 // Error matching Line Start with Line End for vc0 and dt0
#define MIPI_CSI2_ERR1__ERR_FRAME_DATA_VC3    1 << 15 // Last received frame1 << //  in Virtual Channel 31 << //  had at least one CRC error
#define MIPI_CSI2_ERR1__ERR_FRAME_DATA_VC2    1 << 14 // Last received frame1 << //  in Virtual Channel 21 << //  had at least one CRC error
#define MIPI_CSI2_ERR1__ERR_FRAME_DATA_VC1    1 << 13 // Last received frame1 << //  in Virtual Channel 11 << //  had at least one CRC error
#define MIPI_CSI2_ERR1__ERR_FRAME_DATA_VC0    1 << 12 // Last received frame1 << //  in Virtual Channel 01 << //  had at least one CRC error
#define MIPI_CSI2_ERR1__ERR_F_SEQ_VC3         1 << 11 // Incorrect Frame Sequence detected in Virtual Channel 3
#define MIPI_CSI2_ERR1__ERR_F_SEQ_VC2         1 << 10 // Incorrect Frame Sequence detected in Virtual Channel 2
#define MIPI_CSI2_ERR1__ERR_F_SEQ_VC1         1 << 9  // Incorrect Frame Sequence detected in Virtual Channel 1
#define MIPI_CSI2_ERR1__ERR_F_SEQ_VC0         1 << 8  // Incorrect Frame Sequence detected in Virtual Channel 0
#define MIPI_CSI2_ERR1__ERR_F_BNDRY_MATCH_VC3 1 << 7  // Error matching Frame Start with Frame End for Virtual Channel 3
#define MIPI_CSI2_ERR1__ERR_F_BNDRY_MATCH_VC2 1 << 6  // Error matching Frame Start with Frame End for Virtual Channel 2
#define MIPI_CSI2_ERR1__ERR_F_BNDRY_MATCH_VC1 1 << 5  // Error matching Frame Start with Frame End for Virtual Channel 1
#define MIPI_CSI2_ERR1__ERR_F_BNDRY_MATCH_VC0 1 << 4  // Error matching Frame Start with Frame End for Virtual Channel 0
#define MIPI_CSI2_ERR1__PHY_ERRSOTSYNCHS_3    1 << 3  // Start of Transmission Error on data lane 3
#define MIPI_CSI2_ERR1__PHY_ERRSOTSYNCHS_2    1 << 2  // Start of Transmission Error on data lane 2
#define MIPI_CSI2_ERR1__PHY_ERRSOTSYNCHS_1    1 << 1  // Start of Transmission Error on data lane 1
#define MIPI_CSI2_ERR1__PHY_ERRSOTSYNCHS_0    1 << 0  // Start of Transmission Error on data lane 0

#define MIPI_CSI2_ERR2__ERR_I_SEQ_DI7         1 << 23 // Error in the sequence of lines for vc7 and dt7
#define MIPI_CSI2_ERR2__ERR_I_SEQ_DI6         1 << 22 // Error in the sequence of lines for vc6 and dt6
#define MIPI_CSI2_ERR2__ERR_I_SEQ_DI5         1 << 21 // Error in the sequence of lines for vc5 and dt5
#define MIPI_CSI2_ERR2__ERR_I_SEQ_DI4         1 << 20 // Error in the sequence of lines for vc4 and dt4
#define MIPI_CSI2_ERR2__ERR_I_BNDRY_MATCH_DI7 1 << 19 // Error matching Line Start with Line End for vc7 and dt7
#define MIPI_CSI2_ERR2__ERR_I_BNDRY_MATCH_DI6 1 << 18 // Error matching Line Start with Line End for vc6 and dt6
#define MIPI_CSI2_ERR2__ERR_I_BNDRY_MATCH_DI5 1 << 17 // Error matching Line Start with Line End for vc5 and dt5
#define MIPI_CSI2_ERR2__ERR_I_BNDRY_MATCH_DI4 1 << 16 // Error matching Line Start with Line End for vc4 and dt4
#define MIPI_CSI2_ERR2__ERR_ID_VC3            1 << 15 // Unrecognized or unimplemented data type detected in Virtual Channel 3
#define MIPI_CSI2_ERR2__ERR_ID_VC2            1 << 14 // Unrecognized or unimplemented data type detected in Virtual Channel 2
#define MIPI_CSI2_ERR2__ERR_ID_VC1            1 << 13 // Unrecognized or unimplemented data type detected in Virtual Channel 1
#define MIPI_CSI2_ERR2__ERR_ID_VC0            1 << 12 // Unrecognized or unimplemented data type detected in Virtual Channel 0
#define MIPI_CSI2_ERR2__VC3_ERR_ECC_CORRECTED 1 << 11 // Header error detected and corrected on Virtual Channel 3
#define MIPI_CSI2_ERR2__VC2_ERR_ECC_CORRECTED 1 << 10 // Header error detected and corrected on Virtual Channel 2
#define MIPI_CSI2_ERR2__VC1_ERR_ECC_CORRECTED 1 << 9  // Header error detected and corrected on Virtual Channel 1
#define MIPI_CSI2_ERR2__VC0_ERR_ECC_CORRECTED 1 << 8  // Header error detected and corrected on Virtual Channel 0
#define MIPI_CSI2_ERR2__PHY_ERRSOTHS_3        1 << 7  // Start of Transmission Error on data lane 3
#define MIPI_CSI2_ERR2__PHY_ERRSOTHS_2        1 << 6  // Start of Transmission Error on data lane 2
#define MIPI_CSI2_ERR2__PHY_ERRSOTHS_1        1 << 5  // Start of Transmission Error on data lane 1
#define MIPI_CSI2_ERR2__PHY_ERRSOTHS_0        1 << 4  // Start of Transmission Error on data lane 0
#define MIPI_CSI2_ERR2__PHY_ERRESC_3          1 << 3  // Escape Entry Error (ULPM) on data lane 3
#define MIPI_CSI2_ERR2__PHY_ERRESC_2          1 << 2  // Escape Entry Error (ULPM) on data lane 2
#define MIPI_CSI2_ERR2__PHY_ERRESC_1          1 << 1  // Escape Entry Error (ULPM) on data lane 1
#define MIPI_CSI2_ERR2__PHY_ERRESC_0          1 << 0  // Escape Entry Error (ULPM) on data lane 0

/* mipi data type */
#define MIPI_DT_YUV420		0x18 /* YYY.../UYVY.... */
#define MIPI_DT_YUV420_LEGACY	0x1a /* UYY.../VYY...   */
#define MIPI_DT_YUV422		0x1e /* UYVY...		*/
#define MIPI_DT_RGB444		0x20
#define MIPI_DT_RGB555		0x21
#define MIPI_DT_RGB565		0x22
#define MIPI_DT_RGB666		0x23
#define MIPI_DT_RGB888		0x24
#define MIPI_DT_RAW6		0x28
#define MIPI_DT_RAW7		0x29
#define MIPI_DT_RAW8		0x2a
#define MIPI_DT_RAW10		0x2b
#define MIPI_DT_RAW12		0x2c
#define MIPI_DT_RAW14		0x2d


struct mipi_csi2_info;
/* mipi csi2 API */
struct mipi_csi2_info *mipi_csi2_get_info(void);

bool mipi_csi2_enable(struct mipi_csi2_info *info);

bool mipi_csi2_disable(struct mipi_csi2_info *info);

bool mipi_csi2_get_status(struct mipi_csi2_info *info);

int mipi_csi2_get_bind_ipu(struct mipi_csi2_info *info);

unsigned int mipi_csi2_get_bind_csi(struct mipi_csi2_info *info);

unsigned int mipi_csi2_get_virtual_channel(struct mipi_csi2_info *info);

unsigned int mipi_csi2_set_lanes(struct mipi_csi2_info *info);

unsigned int mipi_csi2_set_datatype(struct mipi_csi2_info *info,
					unsigned int datatype);

unsigned int mipi_csi2_get_datatype(struct mipi_csi2_info *info);

unsigned int mipi_csi2_dphy_status(struct mipi_csi2_info *info);

unsigned int mipi_csi2_get_error1(struct mipi_csi2_info *info);

unsigned int mipi_csi2_get_error2(struct mipi_csi2_info *info);

int mipi_csi2_pixelclk_enable(struct mipi_csi2_info *info);

void mipi_csi2_pixelclk_disable(struct mipi_csi2_info *info);

int mipi_csi2_reset(struct mipi_csi2_info *info);

#endif
