#ifndef SKA_MNG_FPGA_SPI_REGISTERS_H_
#define SKA_MNG_FPGA_SPI_REGISTERS_H_

#include "register_map.h"


/*

	<node id="spi_cs_ow"            	address="0x0800"    mask="0x00000001" permission="rw"   									hw_rst="0x00000000" 	description="SPI CS OW"/>
	<node id="spi_cs0"              	address="0x0804"    mask="0x00000001" permission="rw"   									hw_rst="0x00000000" 	description="SPI CS"/>
	<node id="spi_tx_byte"          	address="0x0808"    mask="0x000007ff" permission="rw"   									hw_rst="0x00000000" 	description="SPI TX Byte"/>
	<node id="spi_rx_byte"          	address="0x080c"    mask="0x000007ff" permission="r"    hw_permission= "w"  										description="SPI RX Byte"/>
	<node id="spi_tx_buf_len"       	address="0x0810"    mask="0x0000ffff" permission="r"    hw_permission= "w"  										description="SPI TX Buffer length"/>
	<node id="spi_rx_buf_len"       	address="0x0814"    mask="0x0000ffff" permission="r"    hw_permission= "w"  										description="SPI RX Buffer length"/>
	<node id="spi_fifo_addr"        	address="0x0818"    mask="0x000007ff" permission="rw"   									hw_rst="0x00000000" 	description="SPI Fifo Address"/>
	<node id="spi_mux"              	address="0x081c"    mask="0x00000001" permission="rw"   									hw_rst="0x00000000" 	description="SPI Mux"/>

 */


#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "SPI CS OW"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(spi_cs_ow)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "SPI CS"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x04, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(spi_cs0)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "TX Byte"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(spi_tx_byte)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "RX Byte"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0xC, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(spi_rx_byte)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "SPI TX Buffer length"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x10, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(spi_tx_buf_len)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "SPI RX Buffer length"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x14, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(spi_rx_buf_len)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "SPI RX Buffer length"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x18, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(spi_fifo_addr)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "SPI Mux"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x1c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(spi_mux)





#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_FPGA_SPI_registers[] = {
	//static const Registers registers = {
	&(REGISTER(spi_cs_ow)),
	&(REGISTER(spi_cs0)),
	&(REGISTER(spi_tx_byte)),
	&(REGISTER(spi_rx_byte)),
	&(REGISTER(spi_tx_buf_len)),
	&(REGISTER(spi_rx_buf_len)),
	&(REGISTER(spi_fifo_addr)),
	&(REGISTER(spi_mux)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_FPGA_SPI_attributes[] = {
		&(REGISTER(spi_cs_ow)),
		&(REGISTER(spi_cs0)),
		&(REGISTER(spi_tx_byte)),
		&(REGISTER(spi_rx_byte)),
		&(REGISTER(spi_tx_buf_len)),
		&(REGISTER(spi_rx_buf_len)),
		&(REGISTER(spi_fifo_addr)),
		&(REGISTER(spi_mux)),
	NULL
};
static const struct attribute_group SKA_MNG_FPGA_SPI_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_FPGA_SPI_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_FPGA_SPI_REGISTERS_H_
