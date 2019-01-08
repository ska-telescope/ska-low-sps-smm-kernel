#ifndef REGISTER_MAP_H_
#define REGISTER_MAP_H_

#include <linux/types.h>
#include <linux/spi/spi.h>
#include <linux/device.h>
#include <linux/i2c.h>

#ifndef NULL
  #define NULL nullptr
#endif

#ifdef __linux__
  #define MAX_COMMANDS 16
  #define MAX_ENUM_ENTRIES 16
  #define MAX_CATEGORIES   4
#endif

#ifdef _WIN32
  #define MAX_COMMANDS 16
  #define MAX_ENUM_ENTRIES
  #define MAX_CATEGORIES
#endif

typedef enum RegisterFlags {
	REGISTERFLAG_NONE                = 0x00000000,
	REGISTERFLAG_INITIALIZE          = 0x00000001,
	REGISTERFLAG_READ                = 0x00000200,
	REGISTERFLAG_WRITE               = 0x00000400,
	REGISTERFLAG_VISIBILITY_HIDE     = 0x00010000,
	REGISTERFLAG_VISIBILITY_ADVANCED = 0x00020000,
} RegisterFlags;

typedef enum RegisterType {
	REGISTERTYPE_UNSIGNED = 0x00000000,
	REGISTERTYPE_HEX      = 0x00000010,
	REGISTERTYPE_SIGNED   = 0x00000001,
	REGISTERTYPE_FLOAT    = 0x00000002,
	REGISTERTYPE_ENUM     = 0x00000004,
} RegisterType;

typedef struct {
	u32 address;
	u8 x_offset;
	u8 y_offset;
	u8 length;
} BitMixingCommand;

typedef struct {
	uint32_t    value;
	const char* label;
} RegisterEnumEntry;

typedef struct {
	RegisterType      type;
	const char*       label;
	uint32_t          initializeWith;
	uint32_t          min;
	uint32_t          max;
	uint32_t          flags;
	const char*       description;
	BitMixingCommand  commands[MAX_COMMANDS];
	RegisterEnumEntry enumEntries[MAX_ENUM_ENTRIES];
} Register;

typedef enum {
	REGISTERWIDTH_8BIT = 0,
	REGISTERWIDTH_16BIT
} RegisterWidth;

typedef struct {
	struct spi_device* dev;
	int (*write)(struct spi_device* dev, u32 reg, u8 data);
	int (*read)(struct spi_device* dev, u32 reg, u8* data);
} Register_SPIBusOps8;

typedef struct {
	struct i2c_device* dev;
	int (*write)(struct i2c_device* dev, u32 reg, u8 data);
	int (*read)(struct  i2c_device* dev, u32 reg, u8* data);
} Register_I2CBusOps8;

typedef struct {
	struct spi_device* dev;
	int (*write)(struct spi_device* dev, u32 reg, u16 data);
	int (*read)(struct spi_device* dev, u32 reg, u16* data);
} Register_SPIBusOps16;

size_t Registers_List(const Register* registers[], char* buffer, size_t bufferSize);

void Register_I2CWrite8(Register_I2CBusOps8* ops, const Register* r, u32 in);
void Register_I2CRead8(Register_I2CBusOps8* ops, const Register* r, u32* out);
size_t Registers_I2CDump8(Register_I2CBusOps8* ops, const Register* registers[], char* buffer, size_t bufferSize);

void Register_SPIWrite8(Register_SPIBusOps8* ops, const Register* r, u32 in);
void Register_SPIRead8(Register_SPIBusOps8* ops, const Register* r, u32* out);
size_t Registers_SPIDump8(Register_SPIBusOps8* ops, const Register* registers[], char* buffer, size_t bufferSize);

void Register_SPIWrite16(Register_SPIBusOps16* ops, const Register* r, u32 in);
void Register_SPIRead16(Register_SPIBusOps16* ops, const Register* r, u32* out);
size_t Registers_SPIDump16(Register_SPIBusOps16* ops, const Register* registers[], char* buffer, size_t bufferSize);

void Register_MemoryWrite32(void* base, const Register* r, u32 in);
void Register_MemoryRead32(void* base, const Register* r, u32* out);
size_t Registers_MemoryDump32(void* base, const Register* registers[], char* buffer, size_t bufferSize);

void Register_MemoryWrite16(void* base, const Register* r, u32 in);
void Register_MemoryRead16(void* base, const Register* r, u32* out);
size_t Registers_MemoryDump16(void* base, const Register* registers[], char* buffer, size_t bufferSize);

#ifdef REGISTER_MAKE_SYSFS

struct register_device_attribute {
	struct device_attribute dev_attr;
	const Register* reg;
};

#define to_register_dev_attr(_dev_attr) container_of(_dev_attr, struct register_device_attribute, dev_attr)

#endif

#endif /* REGISTER_MAP_H_ */
