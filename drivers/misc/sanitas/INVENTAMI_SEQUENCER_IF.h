/*  COPYRIGHT (c) 2015-2016 by Sanitas EG
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 *
 * Author: Davide Rizzi (davide.rizzi@sanitaseg.it)
 */

#ifndef INVENTAMI_SEQUENCER_REGISTERS_H_
#define INVENTAMI_SEQUENCER_REGISTERS_H_

//! \cond REGISTERS

#include "register_map.h"

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_Sequencer_system_ ## __name__

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Enable command (set 0 to skip this command)"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "Skip"}, {1, "Enable"}
#define REGISTER_CMDS {0x00, 3, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(Enable)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Trigger polarity - 1 wait for rising edge trigger, 0 wait for falling edge trigger (if any selected in TriggerSel"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "Falling"}, {1, "Rising"}
#define REGISTER_CMDS {0, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(TriggerRise)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Marker control - if enabled the timestamp/encoder marker is requested after the command is executed."
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_ENUM {0, "none"}, {1, "Mark"}
#define REGISTER_CMDS {0, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(MarkerFlag)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "We flag enable if command to be performed is a write access"
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(WeFlag)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "HW Address where to perform access"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {4, 0, 16, 16}, {6, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(Address)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Value to be written (don't care for read operation)"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {10, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(Value)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Select the triggers enabled (leave to 0 for uncoditionated commands, typically all command after the first)"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {12, 0, 16, 16}, {14, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(TriggerSel)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Pause length in Sequencer ClockFrequency units (pause start when access start so in case of long access command like on sensor the access could be longer and so the effective pause is longer"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_HEX
#define REGISTER_CMDS {16, 0, 16, 16}, {18, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(PauseLength)

#include "REGISTER_RESET.h"

//! \endcond REGISTERS

#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_Sequencer_system_ ## __name__

static const Register * Sequencer_registers[] = {
	&(REGISTER(Enable)),
	&(REGISTER(TriggerRise)),
	&(REGISTER(MarkerFlag)),
	&(REGISTER(WeFlag)),
	&(REGISTER(Address)),
	&(REGISTER(Value)),
	&(REGISTER(TriggerSel)),
	&(REGISTER(PauseLength)),
	NULL
};

#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS

#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* Sequencer_attributes[] = {
	&(REGISTER(Enable)),
	&(REGISTER(TriggerRise)),
	&(REGISTER(MarkerFlag)),
	&(REGISTER(WeFlag)),
	&(REGISTER(Address)),
	&(REGISTER(Value)),
	&(REGISTER(TriggerSel)),
	&(REGISTER(PauseLength)),
	NULL
};

static const struct attribute_group Sequencer_sysfs_group = {
	.name  = "parameters",
	.attrs = Sequencer_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS

#endif //ifndef INVENTAMI_SEQUENCER_REGISTERS_H_
