#ifndef SKA_MNG_HKREGS_REGISTERS_H_
#define SKA_MNG_HKREGS_REGISTERS_H_

#include "register_map.h"

/*
		<node id="prsnt_mux"           		address="0x0500"    mask="0x00000007" permission="rw"    	 								hw_rst="0x00000000"		description="TPMs Present SingleWire Mux"/>
		<node id="prsnt_tpm"           		address="0x0504"    mask="0x000000ff" permission="r"    hw_permission= "we" 					 			    	description="TPMs Present"/>
		<node id="pps_mux"             		address="0x0508"    mask="0x00000003" permission="rw"      									hw_rst="0x00000000" 	description="PPS Mux ('0' = External '1' = Internal)"/>
		<node id="hkt"                 		address="0x0600">
			<node id="temp1"           		                    mask="0x00000001" permission="r"    hw_permission= "w" 					 						description="Temperature Alarm 1"/>
			<node id="temp2"           		                    mask="0x00000002" permission="r"    hw_permission= "w" 					 						description="Temperature Alarm 2"/>
		</node>
		<node id="hkv"                 		address="0x0604">
			<node id="pwrin_alert"     		                    mask="0x00000001" permission="r"    hw_permission= "w" 					 						description="Hot Swap Controller Pwrin Alert (Active Low)"/>
			<node id="buck1_irq"       		                    mask="0x00000002" permission="r"    hw_permission= "w" 					 						description="Buck 1 IRQ"/>
			<node id="vin_pgood"       		                    mask="0x00000004" permission="r"    hw_permission= "w" 					 						description="Step Down Power Good"/>
			<node id="buck1_pgood"     		                    mask="0x00000008" permission="r"    hw_permission= "w" 					 						description="Buck 1 Power Good"/>
			<node id="buck1_rsto"      		                    mask="0x00000010" permission="r"    hw_permission= "w" 					 						description="Buck 1 Reset Output (Active Low)"/>
			<node id="buck2_pgood"     		                    mask="0x00000020" permission="r"    hw_permission= "w" 					 						description="Buck 2 Power Good"/>
			<node id="vi15_pgood"      		                    mask="0x00000040" permission="r"    hw_permission= "w" 					 						description="1V5 Power Good"/>
		</node>
		<node id="hkf"                 		address="0x0608">
			<node id="fana_alert"      		                    mask="0x00000001" permission="r"    hw_permission= "w" 					 						description="Fan A Alert"/>
			<node id="fanb_alert"      		                    mask="0x00000002" permission="r"    hw_permission= "w" 					 						description="Fan B Alert"/>
			<node id="tpma_alertn"     		                    mask="0x00000004" permission="r"    hw_permission= "w" 					 						description="Fan Alert"/>
			<node id="tpmb_alertn"     		                    mask="0x00000008" permission="r"    hw_permission= "w" 					 						description="Fan TPM A Alert"/>
			<node id="fan_alert"       		                    mask="0x00000010" permission="r"    hw_permission= "w" 					 						description="Fan TPM B Alert"/>
		</node>
		<node id="hk_flash_wp"         		address="0x060c"    mask="0x00000001" permission="rw"   									hw_rst="0x00000001" 	description="HK Flash Write Protect"/>
		<node id="switch_reset"             address="0x0700"    mask="0x00000001" permission="rw"   									hw_rst="0x00000001" 	description="Switch Reset Status"/>


*/

#undef REGISTER_REG_NAME
#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Present MUX"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x00, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PsntMux)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "TPMs Present"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x04, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(TPMsPresent)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PPS MUX"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x08, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PPSMux)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "House Keeping Temperature Register"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x100, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(HKTempReg)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Temperature Alarm 2"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x100, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(TempAlarm2)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Temperature Alarm 1"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x100, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(TempAlarm1)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "House Keeping Voltages Register"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x104, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(HKVoltagesReg)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "1V5 Power Good"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x104, 6, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PowerGood1V5)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Buck 2 Power Good"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x104, 5, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PowerGoodBuck2)



#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Buck 1 Reset Output (Active Low)"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x104, 4, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(ResetOutputBuck1)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Buck 1 Power Good"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x104, 3, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PowerGoodBuck1)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Step Down Power Good"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x104, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(PowerGoodStepDown)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Buck 1 IRQ"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x104, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(IRQBuck1)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Hot Swap Controller Power In Alert (Active Low)"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x104, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(HSwapCtrlPowerinAlert)



#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "House Keeping Fan Register"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x108, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(HKFanReg)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Fan A alert bit"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x108, 0, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(FanAAlert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Fan B alert bit"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x108, 1, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(FanBAlert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "TPM A alert bit"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x108, 2, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(TPMAAlert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "TPM B alert bit"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x108, 3, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(TPMBAlert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "TPM Fan B alert bit"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x108, 4, 0, 1}
#include "REGISTER_MAKE.h"
DEFECATE(TPMFanAlert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "House Keeping Flash Register"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x10C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(HKFlashReg)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Present MUX"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x200, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(SwitcReset)








#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_HKREGS_registers[] = {
	//static const Registers registers = {
	&(REGISTER(PsntMux)),
	&(REGISTER(TPMsPresent)),
	&(REGISTER(PPSMux)),
	&(REGISTER(HKTempReg)),
	&(REGISTER(TempAlarm2)),
	&(REGISTER(TempAlarm1)),
	&(REGISTER(HKVoltagesReg)),
	&(REGISTER(PowerGoodBuck2)),
	&(REGISTER(PowerGood1V5)),
	&(REGISTER(ResetOutputBuck1)),
	&(REGISTER(PowerGoodBuck1)),
	&(REGISTER(PowerGoodStepDown)),
	&(REGISTER(IRQBuck1)),
	&(REGISTER(HSwapCtrlPowerinAlert)),

	&(REGISTER(HKFanReg)),
	&(REGISTER(FanAAlert)),
	&(REGISTER(FanBAlert)),
	&(REGISTER(TPMAAlert)),
	&(REGISTER(TPMBAlert)),
	&(REGISTER(TPMFanAlert)),


	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS
#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_HKREGS_attributes[] = {
		&(REGISTER(PsntMux)),
		&(REGISTER(TPMsPresent)),
		&(REGISTER(PPSMux)),
		&(REGISTER(HKTempReg)),
		&(REGISTER(TempAlarm2)),
		&(REGISTER(TempAlarm1)),
		&(REGISTER(HKVoltagesReg)),
		&(REGISTER(PowerGoodBuck2)),
		&(REGISTER(PowerGood1V5)),
		&(REGISTER(ResetOutputBuck1)),
		&(REGISTER(PowerGoodBuck1)),
		&(REGISTER(PowerGoodStepDown)),
		&(REGISTER(IRQBuck1)),
		&(REGISTER(HSwapCtrlPowerinAlert)),

		&(REGISTER(HKFanReg)),
		&(REGISTER(FanAAlert)),
		&(REGISTER(FanBAlert)),
		&(REGISTER(TPMAAlert)),
		&(REGISTER(TPMBAlert)),
		&(REGISTER(TPMFanAlert)),




	NULL
};
static const struct attribute_group SKA_MNG_HKREGS_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_HKREGS_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_HKREGS_REGISTERS_H_
