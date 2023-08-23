/* 
 * File:   mcal_timer1.h
 * Author: Yossri
 *
 * Created on July 27, 2023, 6:51 PM
 */

#ifndef MCAL_TIMER1_H
#define	MCAL_TIMER1_H

/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../Device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../std_libraries.h"
/* ------------------------------------Macro Declarations--------------------------- */
#define TIMER1_COUNTER_MODE_ 1
#define TIMER1_TIMER_MODE_   0

#define TIMER1_SYNC_COUNTER_MODE_  0
#define TIMER1_ASYNC_TIMER_MODE_   1

#define TIMER1_PRESCALER_ENABLE_    0
#define TIMER1_PRESCALER_DISABLE_   1

#define Timer1_Oscillator_Enable_   1
#define Timer1_Oscillator_Disable_  0

#define TIMER1_RW_REG_MODE_16BIT     1
#define TIMER1_RW_REG_MODE_8BIT      0

#define TIMER1_8BIT_READ_    1
#define TIMER1_16BIT_READ_   0
/* ------------------------------------Macro Function Declarations------------------ */

#define TIMER1_ENABLE()  (T1CONbits.TMR1ON = 1)
#define TIMER1_DISABLE() (T1CONbits.TMR1ON = 0)

#define Timer1_Oscillator_Enable()   (T1CONbits.T1OSCEN = 1)
#define Timer1_Oscillator_Disable()  (T1CONbits.T1OSCEN = 0)

#define TIMER1_COUNTER_MODE()  (T1CONbits.TMR1CS = 1)
#define TIMER1_TIMER_MODE()    (T1CONbits.TMR1CS = 0)

#define TIMER1_SYNC_COUNTER_MODE()    (T1CONbits.T1SYNC = 0)
#define TIMER1_ASYNC_TIMER_MODE()     (T1CONbits.T1SYNC = 1)

#define Timer1_Read_Clock_Status()     (T1CONbits.T1RUN)

#define TIMER1_8BIT_READ()                      (T1CONbits.RD16 = 1)          
#define TIMER1_16BIT_READ()                     (T1CONbits.RD16 = 0) 


#define Timer1_Prescaler_Select(_pre_scaler_)   (T1CONbits.T1CKPS = _pre_scaler_)
/* ------------------------------------Data Type Declarations----------------------- */
typedef enum
{
    TIMER1_PRESCALER_DIV_BY_1 = 0,
    TIMER1_PRESCALER_DIV_BY_2 ,
    TIMER1_PRESCALER_DIV_BY_4 ,
    TIMER1_PRESCALER_DIV_BY_8 ,
}Timer1_Prescaler_Select_t;

typedef struct 
{
#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
    interruptHandler TIMER1_IntterruptHandeler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority priority ;
#endif
#endif
    Timer1_Prescaler_Select_t Prescaler_Select ;
    uint16 TIMER1_PRE_LOAD_VALUE;
    uint8 Timer1_Mode:1;
    uint8 Timer1_Counter_Sync_Mode:1;
    uint8 Timer1_Osc_Cfg:1;
    uint8 Timer1_SELECT_BIT_Mode:1;
    uint8 Timer1_Resreved:4;
}Timer1_conf_t; 
/* ------------------------------------Software Interface Declarations-------------- */
Std_ReturnType Timer1_Intialization(const Timer1_conf_t *timer1_);

Std_ReturnType Timer1_DeIntialization(const Timer1_conf_t *timer1_);

Std_ReturnType Timer1_Write_Value(const Timer1_conf_t *timer1_ ,uint16 value);

Std_ReturnType Timer1_Read_Value(const Timer1_conf_t *timer1_ ,uint16 *value);
#endif	/* MCAL_TIMER1_H */

