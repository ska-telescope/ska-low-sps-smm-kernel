#ifndef INVENTAMI_GPIO_REGISTERS_H_
#define INVENTAMI_GPIO_REGISTERS_H_

#include "register_map.h"

//#undef REGISTER_REG_NAME
//#define REGISTER_REG_NAME(__name__) register_GPIO_system_ ## __name__
//#undef REGISTER_ATTR_NAME
//#define REGISTER_ATTR_NAME(__name__) register_GPIO_dev_attr_##__name__

#undef REGISTER_REG_NAME


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Enable command - self reset when command end"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "Stop"}, {1, "Running"}
#define REGISTER_CMDS {0x00, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Enable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Polarity control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "Active high"}, {1, "Active low"}
#define REGISTER_CMDS {0x00, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Polarity)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Tristate control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "Output"}, {1, "Tristate"}
#define REGISTER_CMDS {0x00, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Tristate)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Disable command"
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 3, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Disable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Actual GPIO value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x00, 4, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Readout)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PWM frequency divider. F_PWM = F_GPIO / (Divider + 1)"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x02, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(Divider)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PWM dutycicle. Dutycycle(%) = (Dutycicle + 1) / (Divider + 1)"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x04, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(Dutycycle)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Pulse length. T = PulseLength / F_GPIO. PulseLength = 0 for infinite (stop with disable command)"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x06, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(PulseLength)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Select Trigger to be used as enable command"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {0x08, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(TriggerEnableSel)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Select Trigger to be used as disable command"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {0x0a, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(TriggerDisableSel)

//#ifdef REGISTER_MAKE_REGISTERS
//#define REGISTER(__name__) register_GPIO_system_ ## __name__
//static const Register * GPIO_registers[] = {

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * INVENTAMI_GPIO_registers[] = {
		&(REGISTER(Enable)),
		&(REGISTER(Polarity)),
		&(REGISTER(Tristate)),
		&(REGISTER(Disable)),
		&(REGISTER(Readout)),
		&(REGISTER(Divider)),
		&(REGISTER(Dutycycle)),
		&(REGISTER(PulseLength)),
		&(REGISTER(TriggerEnableSel)),
		&(REGISTER(TriggerDisableSel)),
		NULL
};

#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

//#ifdef REGISTER_MAKE_SYSFS
//#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
//static struct attribute* GPIO_attributes[] = {



#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* INVENTAMI_GPIO_attributes[] = {
		&(REGISTER(Enable)),
		&(REGISTER(Polarity)),
		&(REGISTER(Tristate)),
		&(REGISTER(Disable)),
		&(REGISTER(Readout)),
		&(REGISTER(Divider)),
		&(REGISTER(Dutycycle)),
		&(REGISTER(PulseLength)),
		&(REGISTER(TriggerEnableSel)),
		&(REGISTER(TriggerDisableSel)),
		NULL
};

static const struct attribute_group INVENTAMI_GPIO_sysfs_group = {
	.name  = "GPIO",
	.attrs = INVENTAMI_GPIO_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef INVENTAMI_REGISTERS_H_
