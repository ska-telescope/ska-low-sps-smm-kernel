/*
 * Copyright (C) 2011-2014 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __MXC_MIPI_CSI2_H__
#define __MXC_MIPI_CSI2_H__

#ifdef DEBUG
#define mipi_dbg(fmt, ...)	\
	printk(KERN_DEBUG pr_fmt(fmt), ##__VA_ARGS__)
#else
#define mipi_dbg(fmt, ...)
#endif

struct mipi_csi2_error {
// ERR1
	unsigned int ERROR1_COUNT          ;
	unsigned int ERR_ECC_DOUBLE        ; //28 // Header ECC contains 2 errors
	unsigned int VC3_ERR_CRC           ; //27 // Checksum Error detected on Virtual Channel 3
	unsigned int VC2_ERR_CRC           ; //26 // Checksum Error detected on Virtual Channel 2
	unsigned int VC1_ERR_CRC           ; //25 // Checksum Error detected on Virtual Channel 1
	unsigned int VC0_ERR_CRC           ; //24 // Checksum Error detected on Virtual Channel 0
	unsigned int ERR_I_SEQ_DI3         ; //23 // Error in the sequence of lines for vc3 and dt3
	unsigned int ERR_I_SEQ_DI2         ; //22 // Error in the sequence of lines for vc2 and dt2
	unsigned int ERR_I_SEQ_DI1         ; //21 // Error in the sequence of lines for vc1 and dt1
	unsigned int ERR_I_SEQ_DI0         ; //20 // Error in the sequence of lines for vc0 and dt0
	unsigned int ERR_I_BNDRY_MATCH_DI3 ; //19 // Error matching Line Start with Line End for vc3 and dt3
	unsigned int ERR_I_BNDRY_MATCH_DI2 ; //18 // Error matching Line Start with Line End for vc2 and dt2
	unsigned int ERR_I_BNDRY_MATCH_DI1 ; //17 // Error matching Line Start with Line End for vc1 and dt1
	unsigned int ERR_I_BNDRY_MATCH_DI0 ; //16 // Error matching Line Start with Line End for vc0 and dt0
	unsigned int ERR_FRAME_DATA_VC3    ; //15 // Last received frame in Virtual Channel 3 had at least one CRC error
	unsigned int ERR_FRAME_DATA_VC2    ; //14 // Last received frame in Virtual Channel 2 had at least one CRC error
	unsigned int ERR_FRAME_DATA_VC1    ; //13 // Last received frame in Virtual Channel 1 had at least one CRC error
	unsigned int ERR_FRAME_DATA_VC0    ; //12 // Last received frame in Virtual Channel 0 had at least one CRC error
	unsigned int ERR_F_SEQ_VC3         ; //11 // Incorrect Frame Sequence detected in Virtual Channel 3
	unsigned int ERR_F_SEQ_VC2         ; //10 // Incorrect Frame Sequence detected in Virtual Channel 2
	unsigned int ERR_F_SEQ_VC1         ; //9  // Incorrect Frame Sequence detected in Virtual Channel 1
	unsigned int ERR_F_SEQ_VC0         ; //8  // Incorrect Frame Sequence detected in Virtual Channel 0
	unsigned int ERR_F_BNDRY_MATCH_VC3 ; //7  // Error matching Frame Start with Frame End for Virtual Channel 3
	unsigned int ERR_F_BNDRY_MATCH_VC2 ; //6  // Error matching Frame Start with Frame End for Virtual Channel 2
	unsigned int ERR_F_BNDRY_MATCH_VC1 ; //5  // Error matching Frame Start with Frame End for Virtual Channel 1
	unsigned int ERR_F_BNDRY_MATCH_VC0 ; //4  // Error matching Frame Start with Frame End for Virtual Channel 0
	unsigned int PHY_ERRSOTSYNCHS_3    ; //3  // Start of Transmission Error on data lane 3
	unsigned int PHY_ERRSOTSYNCHS_2    ; //2  // Start of Transmission Error on data lane 2
	unsigned int PHY_ERRSOTSYNCHS_1    ; //1  // Start of Transmission Error on data lane 1
	unsigned int PHY_ERRSOTSYNCHS_0    ; //0  // Start of Transmission Error on data lane 0
// ERR2
	unsigned int ERROR2_COUNT          ;
	unsigned int ERR_I_SEQ_DI7         ; //23 // Error in the sequence of lines for vc7 and dt7
	unsigned int ERR_I_SEQ_DI6         ; //22 // Error in the sequence of lines for vc6 and dt6
	unsigned int ERR_I_SEQ_DI5         ; //21 // Error in the sequence of lines for vc5 and dt5
	unsigned int ERR_I_SEQ_DI4         ; //20 // Error in the sequence of lines for vc4 and dt4
	unsigned int ERR_I_BNDRY_MATCH_DI7 ; //19 // Error matching Line Start with Line End for vc7 and dt7
	unsigned int ERR_I_BNDRY_MATCH_DI6 ; //18 // Error matching Line Start with Line End for vc6 and dt6
	unsigned int ERR_I_BNDRY_MATCH_DI5 ; //17 // Error matching Line Start with Line End for vc5 and dt5
	unsigned int ERR_I_BNDRY_MATCH_DI4 ; //16 // Error matching Line Start with Line End for vc4 and dt4
	unsigned int ERR_ID_VC3            ; //15 // Unrecognized or unimplemented data type detected in Virtual Channel 3
	unsigned int ERR_ID_VC2            ; //14 // Unrecognized or unimplemented data type detected in Virtual Channel 2
	unsigned int ERR_ID_VC1            ; //13 // Unrecognized or unimplemented data type detected in Virtual Channel 1
	unsigned int ERR_ID_VC0            ; //12 // Unrecognized or unimplemented data type detected in Virtual Channel 0
	unsigned int VC3_ERR_ECC_CORRECTED ; //11 // Header error detected and corrected on Virtual Channel 3
	unsigned int VC2_ERR_ECC_CORRECTED ; //10 // Header error detected and corrected on Virtual Channel 2
	unsigned int VC1_ERR_ECC_CORRECTED ; //9  // Header error detected and corrected on Virtual Channel 1
	unsigned int VC0_ERR_ECC_CORRECTED ; //8  // Header error detected and corrected on Virtual Channel 0
	unsigned int PHY_ERRSOTHS_3        ; //7  // Start of Transmission Error on data lane 3
	unsigned int PHY_ERRSOTHS_2        ; //6  // Start of Transmission Error on data lane 2
	unsigned int PHY_ERRSOTHS_1        ; //5  // Start of Transmission Error on data lane 1
	unsigned int PHY_ERRSOTHS_0        ; //4  // Start of Transmission Error on data lane 0
	unsigned int PHY_ERRESC_3          ; //3  // Escape Entry Error (ULPM) on data lane 3
	unsigned int PHY_ERRESC_2          ; //2  // Escape Entry Error (ULPM) on data lane 2
	unsigned int PHY_ERRESC_1          ; //1  // Escape Entry Error (ULPM) on data lane 1
	unsigned int PHY_ERRESC_0          ; //0  // Escape Entry Error (ULPM) on data lane 0
};

/* driver private data */
struct mipi_csi2_info {
	bool		mipi_en;
	int		ipu_id;
	unsigned int	csi_id;
	unsigned int	v_channel;
	unsigned int	lanes;
	unsigned int	datatype;
	unsigned int	gated;
	unsigned int	pll;
	unsigned int	isr_enable;
	struct clk	*cfg_clk;
	struct clk	*dphy_clk;
	struct clk	*pixel_clk;
	void __iomem	*mipi_csi2_base;
	struct platform_device	*pdev;

	spinlock_t irq_lock;

	unsigned int last_err1;
	unsigned int last_err2;

	struct mutex mutex_lock;

	struct mipi_csi2_error errors;
};

#endif
