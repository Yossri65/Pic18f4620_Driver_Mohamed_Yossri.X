/* 
 * File:   mcal_timer3.h
 * Author: Yossri
 *
 * Created on August 5, 2023, 3:15 PM
 */

#ifndef MCAL_TIMER3_H
#define	MCAL_TIMER3_H
/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../Device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../std_libraries.h"
/* ------------------------------------Macro Declarations--------------------------- */
/*Timer3 configuration*/
#define TIMER3_SOURCE_COUNTER_MOD          1
#define TIMER3_SOURCE_TIMER_MOD            0

/*Sync Counter of TIMER3*/
#define TIMER3_ASYNC_COUNTER_MOD           1
#define TIMER3_SYNC_COUNTER_MOD            0

/*Timer3 8bit of 16bit MOD*/
#define TIMER3_RW_REG_MODE_16BIT           1
#define TIMER3_RW_REG_MODE_8BIT            0


/*Pre-Scalar of TIMER3*/
#define TIMER3_PRESCALER_DIV_BY_1          0
#define TIMER3_PRESCALER_DIV_BY_2          1
#define TIMER3_PRESCALER_DIV_BY_4          2
#define TIMER3_PRESCALER_DIV_BY_8          3

/* ------------------------------------Macro Function Declarations------------------ */
#define TIMER3_ENABLE_MODULE()                  (T3CONbits.TMR3ON = 1)
#define TIMER3_DISABLE_MODULE()                 (T3CONbits.TMR3ON = 0)


#define TIMER3_SOURCE_COUNTER_MODE()            (T3CONbits.TMR3CS = 1)          
#define TIMER3_SOURCE_TIMER_MODE()              (T3CONbits.TMR3CS = 0)  

#define TIMER3_ASYNC_COUNTER_MODE()             (T3CONbits.T3SYNC = 1) 
#define TIMER3_SYNC_COUNTER_MODE()              (T3CONbits.T3SYNC = 0) 


#define TIMER3_8BIT_READ()                      (T3CONbits.RD16 = 0)          
#define TIMER3_16BIT_READ()                     (T3CONbits.RD16 = 1)  

/* ------------------------------------Data Type Declarations----------------------- */
typedef struct{
#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE
    interruptHandler TIMER3_InterruptHandler;
    Interrupt_Priority priority;
    #endif 
    uint16 timer3_preload_value;
    uint8 timer3_prescaler: 2;
    uint8 timer3_mode: 1;
    uint8 timer3_counter_mode: 1;
    uint8 timer3_reg_rw_mode: 1;
    uint8 timer3_reserved: 3;
}timer3_t;

/* ------------------------------------Software Interface Declarations-------------- */
/**
 * @brief : initialize timer3
 * @param _timer
 * @return return 1 if initialization made successfully or 0.
 */
Std_ReturnType timer3_init(const timer3_t *_timer);


/**
 * @brief : De initialize timer3
 * @param _timer
 * @return return 1 if initialization made successfully or 0.
 */
Std_ReturnType timer3_Deinit(const timer3_t *_timer);


/**
 * @brief : write value at counter of timer3
 * @param _timer & value
 * @return return 1 if initialization made successfully or 0.
 */
Std_ReturnType timer3_write_value(const timer3_t *_timer, uint16 _value);



/**
 * @brief : read value from counter of timer3
 * @param _timer & pointer of value
 * @return return 1 if initialization made successfully or 0.
 */
Std_ReturnType timer3_read_value(const timer3_t *_timer, uint16 *_value);
#endif	/* MCAL_TIMER3_H */

