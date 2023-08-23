/* 
 * File:   hal_eccp.h
 * Author: Yossri
 *
 * Created on August 9, 2023, 7:43 PM
 */

//#ifndef HAL_ECCP_H
#define	HAL_ECCP_H

/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../std_libraries.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"
/* ------------------------------------Macro Declarations--------------------------- */

#define ECCP_Disable  0x00
#define PWM_mode_P1A_P1C_active_high_P1B_P1D_active_high  0x0C
#define PWM_mode_P1A_P1C_active_high_P1B_P1D_active_low   0x0D
#define PWM_mode_P1A_P1C_active_low_P1B_P1D_active_high   0x0E
#define PWM_mode_P1A_P1C_active_low_P1B_P1D_active_low    0x0F

#define PWM_Single_Output_P1A                            0
#define PWM_Full_Birdge_Forward_P1D_Modulated_P1A_Active 1
#define PWM_Half_Birdge_Forward_P1A_P1B__Modulated_P1A_Active 2
#define PWM_Full_Birdge_Reverse_P1B_Modulated_P1C_Active      3

/*PWM Restart Enable bit  PRSEN*/
#define auto_shutdown_ECCPASE_bit_clears_automatically 1
#define auto_shutdown_ECCPASE_bit_clears_in_Software   0

/*PSSBD1:PSSBD0 Pins B and D Shutdown State Control bits*/
#define PWM_auto_shutdown_Pins_B_D_tri_state  2
#define PWM_auto_shutdown_Drive_B_D_to_1      1
#define PWM_auto_shutdown_Drive_B_D_to_0      0

/*PSSAC1:PSSAC0 Pins A and C Shutdown State Control bits*/
#define PWM_auto_shutdown_Pins_A_C_tri_state  2
#define PWM_auto_shutdown_Drive_A_C_to_1      1
#define PWM_auto_shutdown_Drive_A_C_to_0      0

/*ECCPASE: ECCP Auto-Shutdown Event Status bit*/
#define PWM_auto_shutdown_Enable  1
#define PWM_auto_shutdown_Disable 0

/* Timer2 Input Clock Post-scaler */
#define CCP_TIMER2_POSTSCALER_DIV_BY_1       1
#define CCP_TIMER2_POSTSCALER_DIV_BY_2       2
#define CCP_TIMER2_POSTSCALER_DIV_BY_3       3
#define CCP_TIMER2_POSTSCALER_DIV_BY_4       4
#define CCP_TIMER2_POSTSCALER_DIV_BY_5       5
#define CCP_TIMER2_POSTSCALER_DIV_BY_6       6
#define CCP_TIMER2_POSTSCALER_DIV_BY_7       7
#define CCP_TIMER2_POSTSCALER_DIV_BY_8       8
#define CCP_TIMER2_POSTSCALER_DIV_BY_9       9
#define CCP_TIMER2_POSTSCALER_DIV_BY_10      10
#define CCP_TIMER2_POSTSCALER_DIV_BY_11      11
#define CCP_TIMER2_POSTSCALER_DIV_BY_12      12
#define CCP_TIMER2_POSTSCALER_DIV_BY_13      13
#define CCP_TIMER2_POSTSCALER_DIV_BY_14      14
#define CCP_TIMER2_POSTSCALER_DIV_BY_15      15
#define CCP_TIMER2_POSTSCALER_DIV_BY_16      16

/* Timer2 Input Clock Pre-scaler */
#define CCP_TIMER2_PRESCALER_DIV_BY_1        1
#define CCP_TIMER2_PRESCALER_DIV_BY_4        4
#define CCP_TIMER2_PRESCALER_DIV_BY_16       16


/* ------------------------------------Macro Function Declarations------------------ */
#define ECCP_PWM_SET_MODE(_MODE_)  (CCP1CONbits.CCP1M = _MODE_)
#define PWM_Pins_Mode(_MODE_)  (CCP1CONbits.P1M = _MODE_)

/* ------------------------------------Data Type Declarations----------------------- */
/*ECCPAS2:ECCPAS0: ECCP Auto-Shutdown Source Select bits*/
typedef enum
{
    Auto_shutdown_is_disabled = 0,
    Comparator1_output ,
    Comparator2_output ,
    Either_Comparator1_or2,
    FLT0,
    FLT0_or_Comparator1,
    FLT0_or_Comparator2,
    FLT0_or_Comparator1_or_Comparator2
}Auto_ShutDown_Sourse_Select_Bit_t;

typedef struct
{
    uint8 ECCP_PWM_SET_MODE;
    uint8 PWM_Pins_Mode;
    uint32 delay;
    Pin_Config_t eccp_pinA;
    Pin_Config_t eccp_pinB;
    Pin_Config_t eccp_pinC;
    Pin_Config_t eccp_pinD;
    uint32 PWM_Frequncy;
    uint8 Postscaler_Select ;
    uint8 Prescaler_Select;
    
    uint8 PWM_Restart_Enable_bit;
    uint8 Pins_B_D_Shutdown_State;
    uint8 Pins_A_C_Shutdown_State;
    Auto_ShutDown_Sourse_Select_Bit_t Auto_ShutDown_Sourse_Select_Bit;
    uint8 ECCP_Auto_Shutdown_Event_Status_bit;
    
#ifdef ECCP_INTERRUPT_FEATURE_ENABLE
    interruptHandler ECCP_IntterruptHandeler ;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority CCP1_priority ;
#endif
}ECCP_CONFIG_t;

/* ------------------------------------Software Interface Declarations-------------- */
Std_ReturnType ECCP_intialize(const ECCP_CONFIG_t *_ECCP_);
Std_ReturnType ECCP_Deintialize(const ECCP_CONFIG_t *_ECCP_);

Std_ReturnType ECCP_PWM_Set_Duty(const ECCP_CONFIG_t *_ECCP_ ,const uint8 _duty);
Std_ReturnType ECCP_PWM_Start(const ECCP_CONFIG_t *_ECCP_);
Std_ReturnType ECCP_PWM_Stop(const ECCP_CONFIG_t *_ECCP_);
#endif	/* HAL_ECCP_H */

