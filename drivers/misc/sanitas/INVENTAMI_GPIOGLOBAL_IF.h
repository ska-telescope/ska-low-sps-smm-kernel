#ifndef INVENTAMI_GPIOGLOBAL_REGISTERS_H_
#define INVENTAMI_GPIOGLOBAL_REGISTERS_H_

#include "register_map.h"

//#undef REGISTER_REG_NAME
//#define REGISTER_REG_NAME(__name__) register_GPIOGLOBAL_system_ ## __name__
//#undef REGISTER_ATTR_NAME
//#define REGISTER_ATTR_NAME(__name__) register_GPIOGLOBAL_dev_attr_##__name__

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Synchronous Enable command - self reset when command end"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {0x00, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(Enable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Synchronous Polarity control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {0x02, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(Polarity)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Synchronous Tristate control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {0x04, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(Tristate)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Synchronous Disable command"
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {0x06, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(Disable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Gpio clock frequency [10 KHz]"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x08, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(ClockFrequency)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Number of implemented gpio"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x0a, 8, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(GpioNumber)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Number of implemented trigger"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x0a, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(TriggerNumber)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Pulse length in bits"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x0c, 8, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(PulseBits)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Divider length in bits (for PWM frequency and dutycycle)"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x0c, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(DividerBits)

#include "REGISTER_RESET.h"

//! \endcond REGISTERS

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Actual GPIO value"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x0e, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(Readout)


//#ifdef REGISTER_MAKE_REGISTERS
//#define REGISTER(__name__) register_GPIOGLOBAL_system_ ## __name__
//static const Register * GPIOGLOBAL_registers[] = {

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * INVENTAMI_GPIOGLOBAL_registers[] = {
		&(REGISTER(Enable)),
		&(REGISTER(Polarity)),
		&(REGISTER(Tristate)),
		&(REGISTER(Disable)),
		&(REGISTER(ClockFrequency)),
		&(REGISTER(GpioNumber)),
		&(REGISTER(TriggerNumber)),
		&(REGISTER(PulseBits)),
		&(REGISTER(DividerBits)),
		&(REGISTER(Readout)),
		NULL
};

#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

//#ifdef REGISTER_MAKE_SYSFS
//#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
//static struct attribute* GPIOGLOBAL_attributes[] = {

#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* INVENTAMI_GPIOGLOBAL_attributes[] = {
		&(REGISTER(Enable)),
		&(REGISTER(Polarity)),
		&(REGISTER(Tristate)),
		&(REGISTER(Disable)),
		&(REGISTER(ClockFrequency)),
		&(REGISTER(GpioNumber)),
		&(REGISTER(TriggerNumber)),
		&(REGISTER(PulseBits)),
		&(REGISTER(DividerBits)),
		&(REGISTER(Readout)),
		NULL
};

static const struct attribute_group INVENTAMI_GPIOGLOBAL_sysfs_group = {
	.name  = "GPIOGLOBAL",
	.attrs = INVENTAMI_GPIOGLOBAL_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef INVENTAMI_GPIOGLOBAL_REGISTERS_H_
