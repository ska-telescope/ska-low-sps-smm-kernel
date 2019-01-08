/*  COPYRIGHT (c) 2015-2016 by Sanitas EG
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 *
 * Author: Davide Rizzi (davide.rizzi@sanitaseg.it)
 */

#ifndef INVENTAMI_SEQUENCERGLOBAL_REGISTERS_H_
#define INVENTAMI_SEQUENCERGLOBAL_REGISTERS_H_

//! \cond REGISTERS

#include "register_map.h"

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_SequencerGlobal_system_ ## __name__

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Enable Sequencer"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Enable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Enable free running sequencer modality"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(FreeRunning)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Fire Software trigger"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(SwTrigger)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Number of sequencer command available"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x02, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(CommandLength)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Gpio clock frequency [10 KHz]"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x04, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(ClockFrequency)

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_SequencerGlobal_system_ ## __name__

static const Register * SequencerGlobal_registers[] = {
	&(REGISTER(Enable)),
	&(REGISTER(FreeRunning)),
	&(REGISTER(SwTrigger)),
	&(REGISTER(CommandLength)),
    &(REGISTER(ClockFrequency)),
	NULL
};

#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SequencerGlobal_attributes[] = {
	&(REGISTER(Enable)),
	&(REGISTER(FreeRunning)),
	&(REGISTER(SwTrigger)),
	&(REGISTER(CommandLength)),
    &(REGISTER(ClockFrequency)),
	NULL
};

static const struct attribute_group SequencerGlobal_sysfs_group = {
	.name  = "parameters",
	.attrs = SequencerGlobal_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif // ifndef INVENTAMI_SEQUENCERGLOBAL_REGISTERS_H_
