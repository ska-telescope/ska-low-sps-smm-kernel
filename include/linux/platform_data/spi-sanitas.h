#ifndef __SPI_SANITAS_H_
#define __SPI_SANITAS_H_

#define SANITAS_SPI_POLLING

#ifndef DOXYGEN

#if 0

#define BITFIELD_BEGIN(__name__) struct Bitfield__##__name__; typedef struct Bitfield__##__name__ __name__; struct Bitfield__##__name__ {
#define BITFIELD_END };

#define BITS(__name__, __width__, __access__) unsigned __name__ : __width__;
#define FILL(__name__, __width__) unsigned __##__name__ : __width__;

#define REGISTER_DEFINE(__name__) \
   typedef union { \
	  __name__ bits; \
	  uint32_t value; \
   } Register__##__name__;

#define REGISTER_OFFSET_DEFINE(__name__, __offset__) \
   typedef union { \
	  __name__ bits; \
	  uint32_t value; \
   } Register__##__name__;

#define REGISTER_(__name__) Register__##__name__
#define REGISTER(__name__, __variable__) Register__##__name__ __variable__;

#define REGISTER_READ(__b, __r, __v) __v.value = readl (__b->base + offsetof(InventamiSPI_Registers, __r )); printk(KERN_WARNING "R: %08x -> %08x\n", __b->base + offsetof(InventamiSPI_Registers, __r ), __v.value)
#define REGISTER_RAW_READ(__b, __r, __v) __v = readl (__b->base + offsetof(InventamiSPI_Registers, __r ))
#define REGISTER_WRITE(__b, __r, __v) printk(KERN_WARNING "W: %08x -> %08x\n", __v.value , __b->base + offsetof(InventamiSPI_Registers, __r )); writel (__v.value, __b->base + offsetof(InventamiSPI_Registers, __r ))

#define REGISTER_BANK_BEGIN(__name__) struct RegisterBank__##__name__; typedef struct RegisterBank__##__name__ __name__; struct RegisterBank__##__name__ {
#define REGISTER_BANK_END };

#endif

#else

#define BITFIELD_BEGIN(__name__) struct __name__ {
#define BITFIELD_END };

#define BITS(__name__, __width__, __access__) unsigned __name__ : __width__;
#define FILL(__name__, __width__) unsigned _##__name__##_padding : __width__;

#define REGISTER_DEFINE(__name__) \
   typedef union { \
	  __name__ bits; \
	  uint32_t value; \
   } Register__##__name__;

#define REGISTER_OFFSET_DEFINE(__name__, __offset__) \
   typedef union { \
	  __name__ bits; \
	  uint32_t value; \
   } Register__##__name__;

#define REGISTER_(__name__) Register__##__name__
#define REGISTER(__name__, __variable__) Register__##__name__ __variable__;

#define REGISTER_READ(__b, __r, __v) __v.value = readl(&(__b->registers->__r))
#define REGISTER_WRITE(__b, __r, __v) writel (__v.value, &(__b->registers->__r))

#define REGISTER_BANK_BEGIN(__name__) struct RegisterBank__##__name__; typedef struct RegisterBank__##__name__ __name__; struct RegisterBank__##__name__ {
#define REGISTER_BANK_END };
#endif


#define INVENTAMI_SPI_CS_OW_ADD 0x00
#define INVENTAMI_SPI_CS_OW_LEN 1
#define INVENTAMI_SPI_CS_OW_CS_OFF 0

#define INVENTAMI_SPI_CHIP_SELECTS_ADD 0x00
#define INVENTAMI_SPI_CHIP_SELECTS_LEN 1
#define INVENTAMI_SPI_CHIP_SELECTS_OFF 0

#define INVENTAMI_SPI_CMD_TX_ADD 0x04
#define INVENTAMI_SPI_CMD_TX_LEN 12
#define INVENTAMI_SPI_CMD_TX_OFF 0

#define INVENTAMI_SPI_CMD_RX_ADD 0x08
#define INVENTAMI_SPI_CMD_RX_LEN 12
#define INVENTAMI_SPI_CMD_RX_OFF 0

#define INVENTAMI_SPI_TXFIFO_SIZE_ADD 0xC
#define INVENTAMI_SPI_TXFIFO_SIZE_LEN 16
#define INVENTAMI_SPI_TXFIFO_SIZE_OFF 0

#define INVENTAMI_SPI_RXFIFO_SIZE_ADD 0x10
#define INVENTAMI_SPI_RXFIFO_SIZE_LEN 16
#define INVENTAMI_SPI_RXFIFO_SIZE_OFF 0

#define INVENTAMI_SPI_FIFO_PTR_ADD 0x14
#define INVENTAMI_SPI_FIFO_PTR_LEN 16
#define INVENTAMI_SPI_FIFO_PTR_OFF 0

#define INVENTAMI_SPI_MUX_ADD 0x18
#define INVENTAMI_SPI_MUX_LEN 1
#define INVENTAMI_SPI_MUX_OFF 0

#if 0
/*! \brief Chip Selects
 * 
 * Setup the number of the Chip Select to be used for the SPI transfer.
 * 
 * \post When data is \c 0x00000000, loopback device is selected.
 */
BITFIELD_BEGIN(InventamiSPI_ChipSelects)
	FILL(0,29)
	BITS(cs, 3, RW) //!< [W] Number of the CS
BITFIELD_END

/*! \brief Command and Status
 * 
 * Exec and transfer command of a given number of byte.
 * Read the number of byte already to be transmitted/received
 * \post
 */
BITFIELD_BEGIN(InventamiSPI_CmdStatus)
	FILL(0,7)
	BITS(tx_byte, 9, RW) //!< [RW] Transmit the given number of byte from the FIFO
	FILL(1,7)
	BITS(rx_byte, 9, R) //!< [R] Give the number of byte not yet transmitted/received (\c 0 stand for transmition accomplished)
BITFIELD_END

/*! \brief TX/RX data FIFOs sizes
 * 
 * Sizes of the FIFOs.
 */
BITFIELD_BEGIN(InventamiSPI_FIFOSizes)
	BITS(tx, 16, R) //!< [R] Size in bytes of the TX FIFO
	BITS(rx, 16, R) //!< [R] Size in bytes of the RX FIFO
BITFIELD_END

/*! \brief Tx/Rx FIFO address pointer
 * 
 * Write to \c 0 to reset address of FIFO when tx upload or rx download is needed.
 * 
 */
BITFIELD_BEGIN(InventamiSPI_FIFOAddrPtr)
	FILL(0,16)
	BITS(addr, 16, R) //!< [R] Address pointer in byte
BITFIELD_END

REGISTER_DEFINE(InventamiSPI_ChipSelects)
REGISTER_DEFINE(InventamiSPI_CmdStatus)
REGISTER_DEFINE(InventamiSPI_FIFOSizes)
REGISTER_DEFINE(InventamiSPI_FIFOAddrPtr)

REGISTER_BANK_BEGIN(InventamiSPI_Registers)
	REGISTER(InventamiSPI_ChipSelects, chipSelects)
	REGISTER(InventamiSPI_CmdStatus,   cmdStatus)
	REGISTER(InventamiSPI_FIFOSizes,   fifoSizes)
	REGISTER(InventamiSPI_FIFOAddrPtr, fifoAddrPtr)
REGISTER_BANK_END
#endif

struct spi_sanitas_master {
   int* chipselect;
   int  num_chipselect;
};

#endif // ifndef __SPI_SANITAS_H_
