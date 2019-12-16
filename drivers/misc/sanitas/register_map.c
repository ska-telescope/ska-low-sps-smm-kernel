#include "register_map.h"
#include "linux/io.h"

/*
 * SPI FUNCTIONS
 */

size_t Registers_SPIDump8(Register_SPIBusOps8* ops, const Register* registers[], char* buffer, size_t bufferSize) {
	u32 i = 0;
	size_t len = 0;
	const Register* r = registers[i];


	while(r) {
		u32 tmp;

		Register_SPIRead8(ops, r, &tmp);
//		len += snprintf(buffer + len, bufferSize - len, "%03d: %s: [%08x] %d\n", i, r->label, tmp, tmp);
		len += snprintf(buffer + len, bufferSize - len, "%s: [%08x] %d\n", r->label, tmp, tmp);

		i++;
		r = registers[i];
	}

	return len;
}

void Register_SPIRead8(Register_SPIBusOps8* ops, const Register* r, u32* out) {
	u32 i = 0;

	BitMixingCommand c = r->commands[i];

	u32 y = 0x00000000;

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u8 v = 0x00;
		ops->read(ops->dev, c.address, &(v));
		u32 x = (u32) (v);

		u32 mask = (0xffffffff >> (32 - c.length));

		x = x >> c.x_offset;
		x = x & mask;

		x = x << c.y_offset;
		mask = mask << c.y_offset;

		y = y & (~mask);
		y = y | x;

		i++;
		c = r->commands[i];
	}

	*out = y;
}

void Register_SPIWrite8(Register_SPIBusOps8* ops, const Register* r, u32 in) {
	u32 i = 0;

	BitMixingCommand c = r->commands[i];

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u32 y = in;
		u8 x = 0x00;

		if (c.length != 8) { // Read-Modify-Write
			ops->read(ops->dev, c.address, &(x));
		}

		u32 mask = (0xffffffff >> (32 - c.length));

		y = y >> c.y_offset;
		y = y & mask;

		y = y << c.x_offset;
		mask = mask << c.x_offset;

		x = x & (~mask);
		x = x | y;

		ops->write(ops->dev, c.address, x);

		i++;
		c = r->commands[i];
	}
}

/* I2C FUNCTIONS*/

size_t Registers_I2CDump8(Register_I2CBusOps8* ops, const Register* registers[], char* buffer, size_t bufferSize) {
	u32 i = 0;
	size_t len = 0;
	const Register* r = registers[i];


	while(r) {
		u32 tmp;

		Register_I2CRead8(ops, r, &tmp);
//		len += snprintf(buffer + len, bufferSize - len, "%03d: %s: [%08x] %d\n", i, r->label, tmp, tmp);
		len += snprintf(buffer + len, bufferSize - len, "%s: [%08x] %d\n", r->label, tmp, tmp);

		i++;
		r = registers[i];
	}

	return len;
}


void Register_I2CRead8(Register_I2CBusOps8* ops, const Register* r, u32* out) {
u32 i = 0;

	BitMixingCommand c = r->commands[i];

	u32 y = 0x00000000;

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u8 v = 0x00;
		ops->read(ops->dev, c.address, &(v));
		u32 x = (u32) (v);

		u32 mask = (0xffffffff >> (32 - c.length));

		x = x >> c.x_offset;
		x = x & mask;

		x = x << c.y_offset;
		mask = mask << c.y_offset;

		y = y & (~mask);
		y = y | x;

		i++;
		c = r->commands[i];
	}

	*out = y;
}

void Register_I2CWrite8(Register_I2CBusOps8* ops, const Register* r, u32 in) {
	u32 i = 0;

	BitMixingCommand c = r->commands[i];

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u32 y = in;
		u8 x = 0x00;

		if (c.length != 8) { // Read-Modify-Write
			ops->read(ops->dev, c.address, &(x));
		}

		u32 mask = (0xffffffff >> (32 - c.length));

		y = y >> c.y_offset;
		y = y & mask;

		y = y << c.x_offset;
		mask = mask << c.x_offset;

		x = x & (~mask);
		x = x | y;

		ops->write(ops->dev, c.address, x);

		i++;
		c = r->commands[i];
	}
}



size_t Registers_SPIDump16(Register_SPIBusOps16* ops, const Register* registers[], char* buffer, size_t bufferSize) {
	u32 i = 0;
	size_t len = 0;
	const Register* r = registers[i];


	while(r) {
		u32 tmp;

		Register_SPIRead16(ops, r, &tmp);
//		len += snprintf(buffer + len, bufferSize - len, "%03d: %s: [%08x] %d\n", i, r->label, tmp, tmp);
		len += snprintf(buffer + len, bufferSize - len, "%s: [%08x] %d\n", r->label, tmp, tmp);

		i++;
		r = registers[i];
	}

	return len;
}

void Register_SPIRead16(Register_SPIBusOps16* ops, const Register* r, u32* out) {
	u32 i = 0;

	BitMixingCommand c = r->commands[i];

	u32 y = 0x00000000;

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u16 v = 0x0000;
		ops->read(ops->dev, c.address, &(v));
		u32 x = (u32) (v);

		u32 mask = (0xffffffff >> (32 - c.length));

		x = x >> c.x_offset;
		x = x & mask;

		x = x << c.y_offset;
		mask = mask << c.y_offset;

		y = y & (~mask);
		y = y | x;

		i++;
		c = r->commands[i];
	}

	*out = y;
}

void Register_SPIWrite16(Register_SPIBusOps16* ops, const Register* r, u32 in) {
	u32 i = 0;

	BitMixingCommand c = r->commands[i];

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u32 y = in;
		u16 x = 0x0000;

		if (c.length != 16) { // Read-Modify-Write
			ops->read(ops->dev, c.address, &(x));
		}

		u32 mask = (0xffffffff >> (32 - c.length));

		y = y >> c.y_offset;
		y = y & mask;

		y = y << c.x_offset;
		mask = mask << c.x_offset;

		x = x & (~mask);
		x = x | y;

		ops->write(ops->dev, c.address, x);

		i++;
		c = r->commands[i];
	}
}
/*
 * MEMORY FUNCTIONS
 */

int writeRawRegister32_memory(void* address, u32 value) {
//	printk(KERN_INFO "WriteRawRegister32_memory: %08X, %08X\n", address, value);

	writel(value, address);

	return 0;
}

int readRawRegister32_memory(void* address, u32* value) {
	*value = readl(address);

//	printk(KERN_INFO "ReadRawRegister32_memory: %08X, %08X\n", address, *value);

	return 0;
}

void Register_MemoryRead32(void* base, const Register* r, u32* out) {
	u32 i = 0;

	BitMixingCommand c = r->commands[i];

	u32 y = 0x00000000;

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u32 v = 0x00;
		readRawRegister32_memory(base + c.address, &(v));
		u32 x = (u32) (v);

		u32 mask = (0xffffffff >> (32 - c.length));

		x = x >> c.x_offset;
		x = x & mask;

		x = x << c.y_offset;
		mask = mask << c.y_offset;

		y = y & (~mask);
		y = y | x;

		i++;
		c = r->commands[i];
	}

	*out = y;
}

void Register_MemoryWrite32(void* base, const Register* r, u32 in) {
	u32 i = 0;

	BitMixingCommand c = r->commands[i];

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u32 y = in;
		u32 x = 0x00;

		if (c.length != 32) { // Read-Modify-Write
			readRawRegister32_memory(base + c.address, &(x));
		}

		u32 mask = (0xffffffff >> (32 - c.length));

		y = y >> c.y_offset;
		y = y & mask;

		y = y << c.x_offset;
		mask = mask << c.x_offset;

		x = x & (~mask);
		x = x | y;

		writeRawRegister32_memory(base + c.address, x);

		i++;
		c = r->commands[i];
	}
}

int writeRawRegister16_memory(void* address, u16 value) {
//	printk(KERN_INFO "WriteRawRegister16_memory: %08X <- %04X\n", address, value);

	writew(value, address);

	return 0;
}

int readRawRegister16_memory(void* address, u16* value) {
	*value = readw(address);

//	printk(KERN_INFO "ReadRawRegister16_memory: %08X, %04X\n", address, *value);

	return 0;
}

void Register_MemoryRead16(void* base, const Register* r, u16* out) {
	u32 i = 0;

	BitMixingCommand c = r->commands[i];

	u32 y = 0x00000000;

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u16 v = 0x00;
		readRawRegister16_memory(base + c.address, &(v));
		u32 x = (u32) (v);

		u32 mask = (0xffffffff >> (32 - c.length));

		x = x >> c.x_offset;
		x = x & mask;

		x = x << c.y_offset;
		mask = mask << c.y_offset;

		y = y & (~mask);
		y = y | x;

		i++;
		c = r->commands[i];
	}

	*out = (u16)y;
}

void Register_MemoryWrite16(void* base, const Register* r, u32 in) {
	u32 i = 0;

	BitMixingCommand c = r->commands[i];

	while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0)	&& (c.address == 0))) {
		u32 y = in;
		u16 x = 0x00;

		if (c.length != 16) { // Read-Modify-Write
			readRawRegister16_memory(base + c.address, &(x));
		}

		//u16 mask = (0xffff >> (16 - c.length));
		u32 mask = (0xffffffff >> (32 - c.length));

		y = y >> c.y_offset;
		y = y & mask;

		y = y << c.x_offset;
		mask = mask << c.x_offset;

		x = x & (~mask);
		//x = x | (u16)y;
		x = x | y;

		writeRawRegister16_memory(base + c.address, x);

		i++;
		c = r->commands[i];
	}
}

size_t Registers_MemoryDump16(void* base, const Register* registers[], char* buffer, size_t bufferSize) {
	u32 i = 0;
	size_t len = 0;
	const Register* r = registers[i];


	while(r) {
		u16 tmp;

		Register_MemoryRead16(base, r, &tmp);
		if(r->commands[0].length>16)
			len += snprintf(buffer + len, bufferSize - len, "%03d: %s: [%08x] %d\n", i, r->label, tmp, tmp);
		else
			len += snprintf(buffer + len, bufferSize - len, "%s: [%04x] %d\n", r->label, tmp, tmp);


		i++;
		r = registers[i];
	}

	return len;
}


size_t Registers_MemoryDump32(void* base, const Register* registers[], char* buffer, size_t bufferSize) {
	u32 i = 0;
	size_t len = 0;
	const Register* r = registers[i];


	while(r) {
		u32 tmp;

		Register_MemoryRead32(base, r, &tmp);
//		len += snprintf(buffer + len, bufferSize - len, "%03d: %s: [%08x] %d\n", i, r->label, tmp, tmp);
		len += snprintf(buffer + len, bufferSize - len, "%s: [%08x] %d\n", r->label, tmp, tmp);

		i++;
		r = registers[i];
	}

	return len;
}

size_t Registers_List( const Register* registers[], char* buffer, size_t bufferSize) {
	u32 i = 0;
	size_t len = 0;

	const Register* r = registers[i];
	while(r) {
//		len += snprintf(buffer + len, bufferSize - len, "%03d: [%s%s] %s", i, (r->flags & REGISTERFLAG_READ ? "R" : "-"), (r->flags & REGISTERFLAG_WRITE ? "W" : "-"), r->label);
		len += snprintf(buffer + len, bufferSize - len, "[%s%s] %s", (r->flags & REGISTERFLAG_READ ? "R" : "-"), (r->flags & REGISTERFLAG_WRITE ? "W" : "-"), r->label);

		if(r->flags & REGISTERFLAG_INITIALIZE) {
//			len += snprintf(buffer + len, bufferSize - len, " - PRELOAD %3d", r->initializeWith);
			len += snprintf(buffer + len, bufferSize - len, " (%3d)", r->initializeWith);
		}

		//printf("\n");

		u32 j = 0;

		BitMixingCommand c = r->commands[j];
		while (!((c.length == 0) && (c.y_offset == 0) && (c.x_offset == 0) && (c.address == 0))) {
			if(c.length > 1) {
//				len += snprintf(buffer + len, bufferSize - len, "     %03d [%d:%d]->[%d:%d]\n", c.address, c.x_offset + c.length - 1, c.x_offset, c.y_offset + c.length - 1, c.y_offset);
				len += snprintf(buffer + len, bufferSize - len, " %03d:[%d:%d]->[%d:%d]", c.address, c.x_offset + c.length - 1, c.x_offset, c.y_offset + c.length - 1, c.y_offset);
			} else {
//				len += snprintf(buffer + len, bufferSize - len, "     %03d [%d]->[%d]\n", c.address, c.x_offset, c.y_offset);
				len += snprintf(buffer + len, bufferSize - len, " %03d:[%d]->[%d]", c.address, c.x_offset, c.y_offset);
			}
			j++;

			c = r->commands[j];
		}

		len += snprintf(buffer + len, bufferSize - len, "\n", c.address, c.x_offset, c.y_offset);
		//printf("----------------------------------\n");
		i++;
		r = registers[i];
	}

	return len;
	////printf("--------------------\n");
}
