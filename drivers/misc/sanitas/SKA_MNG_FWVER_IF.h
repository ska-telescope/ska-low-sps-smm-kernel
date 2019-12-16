#ifndef SKA_MNG_FWVER_REGISTERS_H_
#define SKA_MNG_FWVER_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME
#define REGISTER_REG_NAME(__name__) register_fwver_ ## __name__
#undef REGISTER_ATTR_NAME
#define REGISTER_ATTR_NAME(__name__) register_fwver_dev_attr_##__name__

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(FirmwareVersion)

#include "REGISTER_RESET.h"
#define REGISTER_HEX
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(FirmwareBuildLow)

#include "REGISTER_RESET.h"
#define REGISTER_MODE_READ
#define REGISTER_HEX
#define REGISTER_CMDS {0x04, 0, 0, 16}
#include "REGISTER_MAKE.h"
DEFECATE(FirmwareBuildHigh)


#ifdef REGISTER_MAKE_REGISTERS
#undef REGISTER
#define REGISTER(__name__) register_fwver_ ## __name__

static const Register * SKA_MNG_FWVER_registers[] = {
//static const Registers registers = {
	&(REGISTER(FirmwareVersion)),
	&(REGISTER(FirmwareBuildLow)),
	&(REGISTER(FirmwareBuildHigh)),
	NULL
};

#undef REGISTER
#endif

#ifdef REGISTER_MAKE_SYSFS
#undef REGISTER
#define REGISTER(__name__) register_fwver_dev_attr_##__name__.dev_attr.attr
static struct attribute* SKA_MNG_FWVER_attributes[] = {
	&(REGISTER(FirmwareVersion)),
	&(REGISTER(FirmwareBuildLow)),
	&(REGISTER(FirmwareBuildHigh)),
	NULL
};

static const struct attribute_group SKA_MNG_FWVER_sysfs_group = {
	.name  = "parameters",
	.attrs = SKA_MNG_FWVER_attributes,
};
#undef REGISTER
#endif

#endif // ifndef SKA_MNG_FWVER_REGISTERS_H_
