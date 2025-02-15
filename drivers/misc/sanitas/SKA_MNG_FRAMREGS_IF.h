#ifndef SKA_MNG_FRAMREGS_REGISTERS_H_
#define SKA_MNG_FRAMREGS_REGISTERS_H_

#include "register_map.h"

#undef REGISTER_REG_NAME

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "ADT7408 #1 Temperature Value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x14, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Adt1TempValue)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "ADT7408 #2 Temperature Value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x2c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(Adt2TempValue)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Fault Log"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x40, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCFaultLog)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Energy 0 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x78, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCEnergy0)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Energy 1 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x7c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCEnergy1)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Energy 2 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x80, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCEnergy2)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Energy 3 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x84, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCEnergy3)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Energy 4 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x88, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCEnergy4)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Energy 5 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x8c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCEnergy5)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Time Count 0 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x90, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCTimeCount0)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Time Count 1 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x94, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCTimeCount1)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Time Count 2 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x98, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCTimeCount2)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Time Count 3 value"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x9c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCTimeCount3)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Status 0"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xA8, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCStatus0)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 Status 1"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xAC, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCStatus1)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 VGPIO H"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xB0, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCVgpioH)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 VGPIO L"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xB4, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCVgpioL)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 VSOURCE L"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xC8, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCVsourceH)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 VSOURCE L"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xCC, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCVsourceL)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 VSENSE L"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xE0, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCVsenseH)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 VSENSE H"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xE4, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCVsenseL)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 POWER H"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xF8, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCPowerH)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC4281 POWER L"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0xFC, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTCPowerL)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC3676 MSKPG"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x158, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC3676MSKPG)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC3676 IRQSTAT"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x168, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC3676Irq)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "LTC3676 PGSTATRT"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x170, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC3676PgStatRt)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "ADT7408_B_1_capability"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x174, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B1_cap)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_1_configuration"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x178, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B1_cfg)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_1_alarm_temp_up_bound_trip"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x17C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B1_alm_temp_up)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_1_alarm_temp_low_bound_trip"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x180, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B1_alm_temp_low)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_1_critical_temp_trip"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x184, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B1_crit_temp)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_1_temp_val"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x188, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B1_temp)



#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "ADT7408_B_2_capability"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x18C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B2_cap)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_2_configuration"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x190, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B2_cfg)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_2_alarm_temp_up_bound_trip"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x194, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B2_alm_temp_up)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_2_alarm_temp_low_bound_trip"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x198, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B2_alm_temp_low)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_2_critical_temp_trip"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x19C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B2_crit_temp)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_ADT7408_B_2_temp_val"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x200, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(ADT7408_B2_temp)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_1_control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x204, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B1_control)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_1_alert"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x208, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B1_alert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_1_fault_log"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x20C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B1_fault_log)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_1_ilim_adj"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x210, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B1_ilim_adj)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_1_Vsource"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x214, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B1_Vsource)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_1_power"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x218, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B1_power)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_2_control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x21C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B2_control)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_2_alert"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x220, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B2_alert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_2_fault_log"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x224, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B2_fault_log)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_2_ilim_adj"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x228, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B2_ilim_adj)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_2_Vsource"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x22C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B2_Vsource)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_2_power"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x230, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B2_power)



#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_3_control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x234, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B3_control)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_3_alert"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x238, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B3_alert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_3_fault_log"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x23C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B3_fault_log)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_3_ilim_adj"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x240, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B3_ilim_adj)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_3_Vsource"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x244, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B3_Vsource)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_3_power"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x248, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B3_power)



#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_4_control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x24C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B4_control)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_4_alert"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x250, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B4_alert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_4_fault_log"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x254, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B4_fault_log)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_4_ilim_adj"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x258, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B4_ilim_adj)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_4_Vsource"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x25C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B4_Vsource)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_4_power"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x260, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B4_power)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_5_control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x264, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B5_control)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_5_alert"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x268, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B5_alert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_5_fault_log"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x26c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B5_fault_log)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_5_ilim_adj"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x270, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B5_ilim_adj)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_5_Vsource"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x274, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B5_Vsource)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_5_power"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x278, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B5_power)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_6_control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x27C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B6_control)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_6_alert"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x280, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B6_alert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_6_fault_log"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x284, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B6_fault_log)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_6_ilim_adj"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x288, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B6_ilim_adj)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_6_Vsource"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x28C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B6_Vsource)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_6_power"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x290, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B6_power)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_7_control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x294, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B7_control)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_7_alert"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x298, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B7_alert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_7_fault_log"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x29C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B7_fault_log)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_7_ilim_adj"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x300, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B7_ilim_adj)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_7_Vsource"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x304, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B7_Vsource)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_7_power"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x308, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B7_power)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_8_control"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x30C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B8_control)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_8_alert"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x310, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B8_alert)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_8_fault_log"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x314, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B8_fault_log)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_8_ilim_adj"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x318, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B8_ilim_adj)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_8_Vsource"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x31C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B8_Vsource)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "fram_LTC4281_B_8_power"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x320, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(LTC4281_B8_power)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_Vout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x324, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_Vout)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_Iout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x328, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_Iout)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_Vin"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x32C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_Vin)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_Iin"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x330, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_Iin)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_Status_Vout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x334, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_Status_Vout)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_Status_Iout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x338, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_Status_Iout)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_Fan_Speed"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x33C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_Fan_Speed)



#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_Vout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x340, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_Vout)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_Iout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x344, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_Iout)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_Vin"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x348, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_Vin)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_Iin"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x34C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_Iin)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_Status_Vout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x350, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_Status_Vout)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_Status_Iout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x354, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_Status_Iout)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_Fan_Speed"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x358, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_Fan_Speed)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Fan PWM"
#define REGISTER_MODE_READ
#define REGISTER_MODE_WRITE
#define REGISTER_CMDS {0x35C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(FAN_PWM)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Fan1 TACH"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x360, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(FAN1_TACH)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Fan2 TACH"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x364, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(FAN2_TACH)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Fan3 TACH"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x368, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(FAN3_TACH)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "Fan4 TACH"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x36C, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(FAN4_TACH)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "TPM SUPPLY STATUS"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x370, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(TPM_SUPPLY_STATUS)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_status"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x384, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_status)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_temp1"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x388, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_temp1)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_temp2"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x38c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_temp2)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_temp3"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x390, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_temp3)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_Pout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x394, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_Pout)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU0_Pin"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x398, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU0_Pin)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_status"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x39c, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_status)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_temp1"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x3a0, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_temp1)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_temp2"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x3a4, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_temp2)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_temp3"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x3a8, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_temp3)


#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_Pout"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x3ac, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_Pout)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU1_Pin"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x3b0, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU1_Pin)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU_ioexp_pre"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x3b4, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU_ioexp_pre)

#include "REGISTER_RESET.h"
#define REGISTER_DESCRIPTION "PSU_ioexp_post"
#define REGISTER_MODE_READ
#define REGISTER_CMDS {0x3b8, 0, 0, 32}
#include "REGISTER_MAKE.h"
DEFECATE(PSU_ioexp_post)




#ifdef REGISTER_MAKE_REGISTERS
#define REGISTER(__name__) register_ ## __name__
static const Register * SKA_MNG_FRAMREGS_registers[] = {
	//static const Registers registers = {
	&(REGISTER(Adt1TempValue)),
	&(REGISTER(Adt2TempValue)),
	&(REGISTER(LTCFaultLog)),
	&(REGISTER(LTCEnergy0)),
	&(REGISTER(LTCEnergy1)),
	&(REGISTER(LTCEnergy2)),
	&(REGISTER(LTCEnergy3)),
	&(REGISTER(LTCEnergy4)),
	&(REGISTER(LTCEnergy5)),
	&(REGISTER(LTCTimeCount0)),
	&(REGISTER(LTCTimeCount1)),
	&(REGISTER(LTCTimeCount2)),
	&(REGISTER(LTCTimeCount3)),
	&(REGISTER(LTCStatus0)),
	&(REGISTER(LTCStatus1)),
	&(REGISTER(LTCVgpioH)),
	&(REGISTER(LTCVgpioL)),
	&(REGISTER(LTCVsourceH)),
	&(REGISTER(LTCVsourceL)),
	&(REGISTER(LTCVsenseH)),
	&(REGISTER(LTCVsenseL)),
	&(REGISTER(LTCPowerH)),
	&(REGISTER(LTCPowerL)),
	&(REGISTER(LTC3676MSKPG)),
	&(REGISTER(LTC3676Irq)),
	&(REGISTER(LTC3676PgStatRt)),
	&(REGISTER(ADT7408_B1_cap)),
	&(REGISTER(ADT7408_B1_cfg)),
	&(REGISTER(ADT7408_B1_alm_temp_up)),
	&(REGISTER(ADT7408_B1_alm_temp_low)),
	&(REGISTER(ADT7408_B1_crit_temp)),
	&(REGISTER(ADT7408_B1_temp)),
	&(REGISTER(ADT7408_B2_cap)),
	&(REGISTER(ADT7408_B2_cfg)),
	&(REGISTER(ADT7408_B2_alm_temp_up)),
	&(REGISTER(ADT7408_B2_alm_temp_low)),
	&(REGISTER(ADT7408_B2_crit_temp)),
	&(REGISTER(ADT7408_B2_temp)),
	&(REGISTER(LTC4281_B1_control)),
	&(REGISTER(LTC4281_B1_alert)),
	&(REGISTER(LTC4281_B1_fault_log)),
	&(REGISTER(LTC4281_B1_ilim_adj)),
	&(REGISTER(LTC4281_B1_Vsource)),
	&(REGISTER(LTC4281_B1_power)),
	&(REGISTER(LTC4281_B2_control)),
	&(REGISTER(LTC4281_B2_alert)),
	&(REGISTER(LTC4281_B2_fault_log)),
	&(REGISTER(LTC4281_B2_ilim_adj)),
	&(REGISTER(LTC4281_B2_Vsource)),
	&(REGISTER(LTC4281_B2_power)),
	&(REGISTER(LTC4281_B3_control)),
	&(REGISTER(LTC4281_B3_alert)),
	&(REGISTER(LTC4281_B3_fault_log)),
	&(REGISTER(LTC4281_B3_ilim_adj)),
	&(REGISTER(LTC4281_B3_Vsource)),
	&(REGISTER(LTC4281_B3_power)),
	&(REGISTER(LTC4281_B4_control)),
	&(REGISTER(LTC4281_B4_alert)),
	&(REGISTER(LTC4281_B4_fault_log)),
	&(REGISTER(LTC4281_B4_ilim_adj)),
	&(REGISTER(LTC4281_B4_Vsource)),
	&(REGISTER(LTC4281_B4_power)),
	&(REGISTER(LTC4281_B5_control)),
	&(REGISTER(LTC4281_B5_alert)),
	&(REGISTER(LTC4281_B5_fault_log)),
	&(REGISTER(LTC4281_B5_ilim_adj)),
	&(REGISTER(LTC4281_B5_Vsource)),
	&(REGISTER(LTC4281_B5_power)),
	&(REGISTER(LTC4281_B6_control)),
	&(REGISTER(LTC4281_B6_alert)),
	&(REGISTER(LTC4281_B6_fault_log)),
	&(REGISTER(LTC4281_B6_ilim_adj)),
	&(REGISTER(LTC4281_B6_Vsource)),
	&(REGISTER(LTC4281_B6_power)),
	&(REGISTER(LTC4281_B7_control)),
	&(REGISTER(LTC4281_B7_alert)),
	&(REGISTER(LTC4281_B7_fault_log)),
	&(REGISTER(LTC4281_B7_ilim_adj)),
	&(REGISTER(LTC4281_B7_Vsource)),
	&(REGISTER(LTC4281_B7_power)),
	&(REGISTER(LTC4281_B8_control)),
	&(REGISTER(LTC4281_B8_alert)),
	&(REGISTER(LTC4281_B8_fault_log)),
	&(REGISTER(LTC4281_B8_ilim_adj)),
	&(REGISTER(LTC4281_B8_Vsource)),
	&(REGISTER(LTC4281_B8_power)),
	&(REGISTER(PSU0_Vout)),
	&(REGISTER(PSU0_Iout)),
	&(REGISTER(PSU0_Vin)),
	&(REGISTER(PSU0_Iin)),
	&(REGISTER(PSU0_Status_Vout)),
	&(REGISTER(PSU0_Status_Iout)),
	&(REGISTER(PSU0_Fan_Speed)),
	&(REGISTER(PSU1_Vout)),
	&(REGISTER(PSU1_Iout)),
	&(REGISTER(PSU1_Vin)),
	&(REGISTER(PSU1_Iin)),
	&(REGISTER(PSU1_Status_Vout)),
	&(REGISTER(PSU1_Status_Iout)),
	&(REGISTER(PSU1_Fan_Speed)),
	&(REGISTER(FAN_PWM)),
	&(REGISTER(FAN1_TACH)),
	&(REGISTER(FAN2_TACH)),
	&(REGISTER(FAN3_TACH)),
	&(REGISTER(FAN4_TACH)),
	&(REGISTER(TPM_SUPPLY_STATUS)),
	&(REGISTER(PSU0_status)),
	&(REGISTER(PSU0_temp1)),
	&(REGISTER(PSU0_temp2)),
	&(REGISTER(PSU0_temp3)),
	&(REGISTER(PSU0_Pout)),
	&(REGISTER(PSU0_Pin)),
	&(REGISTER(PSU1_status)),
	&(REGISTER(PSU1_temp1)),
	&(REGISTER(PSU1_temp2)),
	&(REGISTER(PSU1_temp3)),
	&(REGISTER(PSU1_Pout)),
	&(REGISTER(PSU1_Pin)),
	&(REGISTER(PSU_ioexp_pre)),
	&(REGISTER(PSU_ioexp_post)),
	NULL
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_REGISTERS
#ifdef REGISTER_MAKE_SYSFS

#define REGISTER(__name__) register_dev_attr_ ## __name__.dev_attr.attr
static struct attribute* SKA_MNG_FRAMREGS_attributes[] = {
		&(REGISTER(Adt1TempValue)),
		&(REGISTER(Adt2TempValue)),
		&(REGISTER(LTCFaultLog)),
		&(REGISTER(LTCEnergy0)),
		&(REGISTER(LTCEnergy1)),
		&(REGISTER(LTCEnergy2)),
		&(REGISTER(LTCEnergy3)),
		&(REGISTER(LTCEnergy4)),
		&(REGISTER(LTCEnergy5)),
		&(REGISTER(LTCTimeCount0)),
		&(REGISTER(LTCTimeCount1)),
		&(REGISTER(LTCTimeCount2)),
		&(REGISTER(LTCTimeCount3)),
		&(REGISTER(LTCStatus0)),
		&(REGISTER(LTCStatus1)),
		&(REGISTER(LTCVgpioH)),
		&(REGISTER(LTCVgpioL)),
		&(REGISTER(LTCVsourceH)),
		&(REGISTER(LTCVsourceL)),
		&(REGISTER(LTCVsenseH)),
		&(REGISTER(LTCVsenseL)),
		&(REGISTER(LTCPowerH)),
		&(REGISTER(LTCPowerL)),
		&(REGISTER(LTC3676MSKPG)),
		&(REGISTER(LTC3676Irq)),
		&(REGISTER(LTC3676PgStatRt)),
		&(REGISTER(ADT7408_B1_cap)),
		&(REGISTER(ADT7408_B1_cfg)),
		&(REGISTER(ADT7408_B1_alm_temp_up)),
		&(REGISTER(ADT7408_B1_alm_temp_low)),
		&(REGISTER(ADT7408_B1_crit_temp)),
		&(REGISTER(ADT7408_B1_temp)),
		&(REGISTER(ADT7408_B2_cap)),
		&(REGISTER(ADT7408_B2_cfg)),
		&(REGISTER(ADT7408_B2_alm_temp_up)),
		&(REGISTER(ADT7408_B2_alm_temp_low)),
		&(REGISTER(ADT7408_B2_crit_temp)),
		&(REGISTER(ADT7408_B2_temp)),
		&(REGISTER(LTC4281_B1_control)),
		&(REGISTER(LTC4281_B1_alert)),
		&(REGISTER(LTC4281_B1_fault_log)),
		&(REGISTER(LTC4281_B1_ilim_adj)),
		&(REGISTER(LTC4281_B1_Vsource)),
		&(REGISTER(LTC4281_B1_power)),
		&(REGISTER(LTC4281_B2_control)),
		&(REGISTER(LTC4281_B2_alert)),
		&(REGISTER(LTC4281_B2_fault_log)),
		&(REGISTER(LTC4281_B2_ilim_adj)),
		&(REGISTER(LTC4281_B2_Vsource)),
		&(REGISTER(LTC4281_B2_power)),
		&(REGISTER(LTC4281_B3_control)),
		&(REGISTER(LTC4281_B3_alert)),
		&(REGISTER(LTC4281_B3_fault_log)),
		&(REGISTER(LTC4281_B3_ilim_adj)),
		&(REGISTER(LTC4281_B3_Vsource)),
		&(REGISTER(LTC4281_B3_power)),
		&(REGISTER(LTC4281_B4_control)),
		&(REGISTER(LTC4281_B4_alert)),
		&(REGISTER(LTC4281_B4_fault_log)),
		&(REGISTER(LTC4281_B4_ilim_adj)),
		&(REGISTER(LTC4281_B4_Vsource)),
		&(REGISTER(LTC4281_B4_power)),
		&(REGISTER(LTC4281_B5_control)),
		&(REGISTER(LTC4281_B5_alert)),
		&(REGISTER(LTC4281_B5_fault_log)),
		&(REGISTER(LTC4281_B5_ilim_adj)),
		&(REGISTER(LTC4281_B5_Vsource)),
		&(REGISTER(LTC4281_B5_power)),
		&(REGISTER(LTC4281_B6_control)),
		&(REGISTER(LTC4281_B6_alert)),
		&(REGISTER(LTC4281_B6_fault_log)),
		&(REGISTER(LTC4281_B6_ilim_adj)),
		&(REGISTER(LTC4281_B6_Vsource)),
		&(REGISTER(LTC4281_B6_power)),
		&(REGISTER(LTC4281_B7_control)),
		&(REGISTER(LTC4281_B7_alert)),
		&(REGISTER(LTC4281_B7_fault_log)),
		&(REGISTER(LTC4281_B7_ilim_adj)),
		&(REGISTER(LTC4281_B7_Vsource)),
		&(REGISTER(LTC4281_B7_power)),
		&(REGISTER(LTC4281_B8_control)),
		&(REGISTER(LTC4281_B8_alert)),
		&(REGISTER(LTC4281_B8_fault_log)),
		&(REGISTER(LTC4281_B8_ilim_adj)),
		&(REGISTER(LTC4281_B8_Vsource)),
		&(REGISTER(LTC4281_B8_power)),
		&(REGISTER(PSU0_Vout)),
		&(REGISTER(PSU0_Iout)),
		&(REGISTER(PSU0_Vin)),
		&(REGISTER(PSU0_Iin)),
		&(REGISTER(PSU0_Status_Vout)),
		&(REGISTER(PSU0_Status_Iout)),
		&(REGISTER(PSU0_Fan_Speed)),
		&(REGISTER(PSU1_Vout)),
		&(REGISTER(PSU1_Iout)),
		&(REGISTER(PSU1_Vin)),
		&(REGISTER(PSU1_Iin)),
		&(REGISTER(PSU1_Status_Vout)),
		&(REGISTER(PSU1_Status_Iout)),
		&(REGISTER(PSU1_Fan_Speed)),
		&(REGISTER(FAN_PWM)),
		&(REGISTER(FAN1_TACH)),
		&(REGISTER(FAN2_TACH)),
		&(REGISTER(FAN3_TACH)),
		&(REGISTER(FAN4_TACH)),
		&(REGISTER(TPM_SUPPLY_STATUS)),
		&(REGISTER(PSU0_status)),
		&(REGISTER(PSU0_temp1)),
		&(REGISTER(PSU0_temp2)),
		&(REGISTER(PSU0_temp3)),
		&(REGISTER(PSU0_Pout)),
		&(REGISTER(PSU0_Pin)),
		&(REGISTER(PSU1_status)),
		&(REGISTER(PSU1_temp1)),
		&(REGISTER(PSU1_temp2)),
		&(REGISTER(PSU1_temp3)),
		&(REGISTER(PSU1_Pout)),
		&(REGISTER(PSU1_Pin)),
		&(REGISTER(PSU_ioexp_pre)),
		&(REGISTER(PSU_ioexp_post)),
		NULL
};
static const struct attribute_group SKA_MNG_FRAMREGS_sysfs_group = {
	.name = "parameters",
	.attrs = SKA_MNG_FRAMREGS_attributes,
};
#undef REGISTER
#endif // ifdef REGISTER_MAKE_SYSFS
#endif // ifndef SANITASEG_SKA_MNG_FRAM_REGISTERS_H_
