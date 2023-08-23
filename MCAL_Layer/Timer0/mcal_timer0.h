/* 
 * File:   mcal_timer0.h
 * Author: Yossri
 *
 * Created on July 26, 2023, 3:49 PM
 */

#ifndef MCAL_TIMER0_H
#define	MCAL_TIMER0_H

/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../Device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../std_libraries.h"
/* ------------------------------------Macro Declarations--------------------------- */
#define TIMER0_PRESCALER_ENABLE_    0
#define TIMER0_PRESCALER_DISABLE_   1

#define TIMER0_FALING_EDGE_  1
#define TIMER0_RAISING_EDGE_ 0

#define TIMER0_COUNTER_MODE_ 1
#define TIMER0_TIMER_MODE_   0

#define TIMER0_8_BIT_MODE_   1
#define TIMER0_16_BIT_MODE_  1
/* ------------------------------------Macro Function Declarations------------------ */

#define TIMER0_ENABLE()  (T0CONbits.TMR0ON = 1)
#define TIMER0_DISABLE() (T0CONbits.TMR0ON = 0)

#define TIMER0_PRESCALER_ENABLE()  (T0CONbits.PSA = 0)
#define TIMER0_PRESCALER_DISABLE() (T0CONbits.PSA = 1)

#define TIMER0_FALING_EDGE_SELECT()   (T0CONbits.T0SE = 1)
#define TIMER0_RAISING_EDGE_SELECT()  (T0CONbits.T0SE = 0)

#define TIMER0_COUNTER_MODE()  (T0CONbits.T0CS = 1)
#define TIMER0_TIMER_MODE()    (T0CONbits.T0CS = 0)

#define TIMER0_8_BIT_MODE()  (T0CONbits.T08BIT = 1)
#define TIMER0_16_BIT_MODE()  (T0CONbits.T08BIT = 0) 

/* ------------------------------------Data Type Declarations----------------------- */
typedef enum
{
    TIMER0_PRESCALER_DIV_BY_2 = 0,
    TIMER0_PRESCALER_DIV_BY_4 ,
    TIMER0_PRESCALER_DIV_BY_8 ,
    TIMER0_PRESCALER_DIV_BY_16 ,
    TIMER0_PRESCALER_DIV_BY_32 ,
    TIMER0_PRESCALER_DIV_BY_64 ,
    TIMER0_PRESCALER_DIV_BY_128 ,
    TIMER0_PRESCALER_DIV_BY_256 ,
}Timer0_Prescaler_Select_t;

typedef struct 
{
#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
    interruptHandler TIMER0_IntterruptHandeler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority priority ;
#endif
#endif
    Timer0_Prescaler_Select_t Prescaler_Select ;
    uint16 TIMER0_PRE_LOAD_VALUE;
    uint8 TIMER0_PRESCALER_STATUS:1 ;
    uint8 Timer0_Source_Edge:1;
    uint8 Timer0_Mode:1;
    uint8 Timer0_SELECT_BIT_Mode:1;
    uint8 Timer0_Resreved: 4;
}Timer0_conf_t; 
/* ------------------------------------Software Interface Declarations-------------- */
Std_ReturnType Timer0_Intialization(const Timer0_conf_t *timer0_);

Std_ReturnType Timer0_DeIntialization(const Timer0_conf_t *timer0_);

Std_ReturnType Timer0_Write_Value(const Timer0_conf_t *timer0_ ,uint16 value);

Std_ReturnType Timer0_Read_Value(const Timer0_conf_t *timer0_ ,uint16 *value);
#endif	/* MCAL_TIMER0_H */

