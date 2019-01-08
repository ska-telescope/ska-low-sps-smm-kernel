/*
 * EXPARTIC_I2CCTRL_IF.h
 *
 *  Created on: 04 dic 2015
 *      Author: sanitas
 */

#ifndef EXPARTIC_I2CCTRL_REGISTER_H_
#define EXPARTIC_I2CCTRL_REGISTER_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Enable_led)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PWM)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x01, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Freq_Cyc)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x02, 0, 0, 8}
#include "REGISTER_MAKE.h"
DEFECATE(Duty_Cyc)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x03, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Reset_Req)


#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * EXPARTIC_I2CCTRL_registers[] = {
	//static const Registers registers = {
	&(REGISTER(Enable_led)),
	&(REGISTER(PWM)),
	&(REGISTER(Freq_Cyc)),
	&(REGISTER(Duty_Cyc)),
	&(REGISTER(Reset_Req)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* EXPARTIC_I2CCTRL_attributes[] = {
		&(REGISTER(Enable_led)),
		&(REGISTER(PWM)),
		&(REGISTER(Freq_Cyc)),
		&(REGISTER(Duty_Cyc)),
		&(REGISTER(Reset_Req)),
	NULL
};
static const struct attribute_group EXPARTIC_I2CCTRL_sysfsRegisters_group = {
	.name = "parameters",
	.attrs = EXPARTIC_I2CCTRL_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS



#endif /* DRIVERS_MISC_SANITAS_EXPARTIC_I2CCTRL_IF_H_ */
