/* 
 * File:   hal_ccp1.h
 * Author: Yossri
 *
 * Created on August 7, 2023, 1:16 PM
 */

#ifndef HAL_CCP1_H
#define	HAL_CCP1_H
/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../std_libraries.h"
#include "../Device_config.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../GPIO/hal_GPIO.h"
#include "ccp_cfg.h"
#include "../Timer2/mcal_timer2.h" 
/* ------------------------------------Macro Declarations--------------------------- */
/*======================MODE SELECT======================*/
#define CCP_Disable  0x00
#define CCP_Capture_Mode_1_Falling_Edge  0x04
#define CCP_Capture_Mode_1_Raising_Edge  0x05
#define CCP_Capture_Mode_4_Raising_Edge  0x06
#define CCP_Capture_Mode_16_Raising_Edge 0x07
#define CCP_Compare_Mode_Set_Pin_Low     0x08
#define CCP_Compare_Mode_Set_Pin_High    0x09
#define CCP_Compare_Mode_Toggle_On_Match 0x02
#define CCP_Compare_Mode_Gen_SW_INT      0x0A
#define CCP_Compare_Mode_Gen_Event       0x0B
#define CCP_PWM_Mode_                    0x0C

/*======================CCP1 Capture Mode State======================*/
#define CPP_CAPTURE_NOT_READY  0x00 
#define CPP_CAPTURE_READY      0x01 
/*======================CCP1 Compare Mode State======================*/
#define CPP_COMPARE_NOT_READY  0x00 
#define CPP_COMPARE_READY      0x01 
/* ------------------------------------Macro Function Declarations------------------ */

#define CCP1_SET_MODE(_MODE_) (CCP1CONbits.CCP1M =_MODE_)
#define CCP2_SET_MODE(_MODE_) (CCP2CONbits.CCP2M =_MODE_)
/* ------------------------------------Data Type Declarations----------------------- */
typedef enum
{
    CCP_POSTSCALER_DIV_BY_1 = 0,
    CCP_POSTSCALER_DIV_BY_2 ,
    CCP_POSTSCALER_DIV_BY_3 ,
    CCP_POSTSCALER_DIV_BY_4 ,
    CCP_POSTSCALER_DIV_BY_5 ,
    CCP_POSTSCALER_DIV_BY_6 ,
    CCP_POSTSCALER_DIV_BY_7 ,
    CCP_POSTSCALER_DIV_BY_8 ,
    CCP_POSTSCALER_DIV_BY_9 ,
    CCP_POSTSCALER_DIV_BY_10 ,
    CCP_POSTSCALER_DIV_BY_11 ,
    CCP_POSTSCALER_DIV_BY_12 ,
    CCP_POSTSCALER_DIV_BY_13 ,
    CCP_POSTSCALER_DIV_BY_14,
    CCP_POSTSCALER_DIV_BY_15 ,
    CCP_POSTSCALER_DIV_BY_16 ,
}CCP_Timer2_Postscaler_Select_t;


typedef enum
{
    CCP_PRESCALER_DIV_BY_1 = 0,
    CCP_PRESCALER_DIV_BY_4 ,
    CCP_PRESCALER_DIV_BY_16 
}CCP_Timer2_Prescaler_Select_t;

typedef enum
{
    CCP1_SELECT= 0,
    CCP2_SELECT       
}CCP_SELECTION_T;

typedef union
{
    struct 
    {
        uint8 ccpr_low;
        uint8 ccpr_high;
    };
    struct 
    {
        uint16 ccpr16bit;
    };
}CCP_Priod_REG_t;
typedef enum
{
    CCP_Capture_Mode_ =0,
    CCP_Compare_Mode_,
    CCP_PWM_Mode_Select
}Mode_Selection_t;

typedef enum
{
    CCP1_CCP2_Timer3 = 0 ,
    CCP1_Timer1_CCP2_Timer2,
    CCP1_CCP2_Timer1
}CCP_Capture_Timer_Select;

typedef struct
{
    CCP_SELECTION_T CCP_Select;
    Mode_Selection_t CCP_Mode;
    uint8 ccp_mode_varient;
    Pin_Config_t CCP_pin;
    CCP_Capture_Timer_Select Capture_Timer;
#ifdef CCP_PWM_Mode
    uint32 PWM_Frequncy;
    CCP_Timer2_Postscaler_Select_t Postscaler_Select ;
    CCP_Timer2_Prescaler_Select_t Prescaler_Select;
#endif
#ifdef CCP1_INTERRUPT_FEATURE_ENABLE
    interruptHandler CCP1_IntterruptHandeler ;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority CCP1_priority ;
#endif
#ifdef CCP2_INTERRUPT_FEATURE_ENABLE
    interruptHandler CCP2_IntterruptHandeler ;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority CCP2_priority ;
#endif  
#endif
#endif
}CCP_config_t;
/* ------------------------------------Software Interface Declarations-------------- */

Std_ReturnType CCP_intialize(const CCP_config_t *_CCP_);
Std_ReturnType CCP_Deintialize(const CCP_config_t *_CCP_);

#ifdef CCP_Capture_Mode
    Std_ReturnType CCP_Capture_Is_Ready(const CCP_config_t *_CCP_ ,uint8 *Capture_Status);
    Std_ReturnType CCP_Capture_Read_Value(const CCP_config_t *_CCP_, uint16 *Capture_Value);
#endif

#ifdef CCP_Compare_Mode
    Std_ReturnType CCP_Compare_Is_Complete(const CCP_config_t *_CCP_ ,uint8 *Comapre_Status);
    Std_ReturnType CCP_Compare_Set_Value(const CCP_config_t *_CCP_ ,uint16 Compare_Value);
#endif

#ifdef CCP_PWM_Mode
    Std_ReturnType CCP_PWM_Set_Duty(const CCP_config_t *_CCP_ ,const uint8 _duty);
    Std_ReturnType CCP_PWM_Start(const CCP_config_t *_CCP_);
    Std_ReturnType CCP_PWM_Stop(const CCP_config_t *_CCP_);
#endif
#endif	/* HAL_CCP1_H */

