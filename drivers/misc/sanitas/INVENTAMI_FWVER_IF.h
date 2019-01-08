#ifndef INVENTAMI_FWVER_REGISTERS_H_
#define INVENTAMI_FWVER_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_fwver_ ## __name__
#undef REGISTER_ATTR_NAME
#define REGISTER_ATTR_NAME(__name__) register_fwver_dev_attr_##__name__

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x00, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(FirmwareVersion)

#include "REGISTER_RESET.h"
#define REGISTER_HEX
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x02, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(BuildYear)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x04, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(BuildMonthDay)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x06, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(BuildTime)


#ifdef REGISTER_MAKE_REGISTERS
#undef REGISTER
#define REGISTER(__name__) register_fwver_ ## __name__

static const Register * INVENTAMI_FWVER_registers[] = {
//static const Registers registers = {
	&(REGISTER(FirmwareVersion)),
	&(REGISTER(BuildYear)),
	&(REGISTER(BuildMonthDay)),
	&(REGISTER(BuildTime)),
	NULL
};

#undef REGISTER
#endif

#ifdef REGISTER_MAKE_SYSFS
#undef REGISTER
#define REGISTER(__name__) register_fwver_dev_attr_##__name__.dev_attr.attr
static struct attribute* INVENTAMI_FWVER_attributes[] = {
	&(REGISTER(FirmwareVersion)),
	&(REGISTER(BuildYear)),
	&(REGISTER(BuildMonthDay)),
	&(REGISTER(BuildTime)),
	NULL
};

static const struct attribute_group INVENTAMI_FWVER_sysfs_group = {
	.name  = "parameters",
	.attrs = INVENTAMI_FWVER_attributes,
};
#undef REGISTER
#endif

#endif // ifndef INVENTAMI_FWVER_REGISTERS_H_
