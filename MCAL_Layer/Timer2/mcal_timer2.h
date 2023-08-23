/* 
 * File:   mcal_timer2.h
 * Author: Yossri
 *
 * Created on July 29, 2023, 3:25 PM
 */

#ifndef MCAL_TIMER2_H
#define	MCAL_TIMER2_H
/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../Device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../std_libraries.h"
/* ------------------------------------Macro Declarations--------------------------- */

/* ------------------------------------Macro Function Declarations------------------ */
#define TIMER2_ENABLE()  (T2CONbits.TMR2ON = 1)
#define TIMER2_DISABLE() (T2CONbits.TMR2ON = 0)

#define Timer2_Postscaler_Select_(_post_scaler_) (T2CONbits.T2CKPS = _post_scaler_)
#define Timer2_Prescaler_Select_(_pre_scaler_)   (T2CONbits.TOUTPS = _pre_scaler_)
/* ------------------------------------Data Type Declarations----------------------- */
typedef enum
{
    TIMER2_POSTSCALER_DIV_BY_1 = 0,
    TIMER2_POSTSCALER_DIV_BY_2 ,
    TIMER2_POSTSCALER_DIV_BY_3 ,
    TIMER2_POSTSCALER_DIV_BY_4 ,
    TIMER2_POSTSCALER_DIV_BY_5 ,
    TIMER2_POSTSCALER_DIV_BY_6 ,
    TIMER2_POSTSCALER_DIV_BY_7 ,
    TIMER2_POSTSCALER_DIV_BY_8 ,
    TIMER2_POSTSCALER_DIV_BY_9 ,
    TIMER2_POSTSCALER_DIV_BY_10 ,
    TIMER2_POSTSCALER_DIV_BY_11 ,
    TIMER2_POSTSCALER_DIV_BY_12 ,
    TIMER2_POSTSCALER_DIV_BY_13 ,
    TIMER2_POSTSCALER_DIV_BY_14,
    TIMER2_POSTSCALER_DIV_BY_15 ,
    TIMER2_POSTSCALER_DIV_BY_16 ,
}Timer2_Postscaler_Select_t;


typedef enum
{
    TIMER2_PRESCALER_DIV_BY_1 = 0,
    TIMER2_PRESCALER_DIV_BY_4 ,
    TIMER2_PRESCALER_DIV_BY_16 
}Timer2_Prescaler_Select_t;

typedef struct 
{
#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE
    interruptHandler TIMER2_IntterruptHandeler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority priority ;
#endif
#endif 
    uint8 TIMER2_PRE_LOAD_VALUE;
    Timer2_Postscaler_Select_t Postscaler_Select ;
    Timer2_Prescaler_Select_t Prescaler_Select;
}Timer2_conf_t; 
/* ------------------------------------Software Interface Declarations-------------- */
Std_ReturnType Timer2_Intialization(const Timer2_conf_t *timer2_);

Std_ReturnType Timer2_DeIntialization(const Timer2_conf_t *timer2_);

Std_ReturnType Timer2_Write_Value(const Timer2_conf_t *timer2_ ,uint8 value);

Std_ReturnType Timer2_Read_Value(const Timer2_conf_t *timer2_ ,uint8 *value);

#endif	/* MCAL_TIMER2_H */

