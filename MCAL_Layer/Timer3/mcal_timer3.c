/* 
 * File:   mcal_timer3.C
 * Author: Yossri
 *
 * Created on August 5, 2023, 3:15 PM
 */
#include "mcal_timer3.h"
static inline void Timer3_mode_select(const timer3_t *_timer);

#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE
static void(*TIMER3_InterruptHandler)(void) = NULL;
#endif

static uint16 timer3_preload_value = 0;

/**
 * @brief : initialize timer3
 * @param _timer
 * @return return 1 if initialization made successfully or 0.
 */
Std_ReturnType timer3_init(const timer3_t *_timer){
    Std_ReturnType ret = E_OK;
    if(_timer == NULL) ret = E_NOT_OK;
    else{
        /*disable timer3*/
        TIMER3_DISABLE_MODULE();
        /*Prescaler config*/
        T3CONbits.T3CKPS = (_timer->timer3_prescaler);
        /*timer3 mode select*/
        Timer3_mode_select(_timer);
        /* preload value */
        TMR3H = (_timer->timer3_preload_value) >> 8;
        TMR3L = (uint8)(_timer->timer3_preload_value);
        timer3_preload_value = (_timer->timer3_preload_value);
        /*________ Interrupt ______*/
#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE
        /*Timer1 interrupt Enable*/
        TIMER3_INTERRUPT_Enable();
        /*Timer1 clear flag*/
        TIMER3_INTERRUPT_Clear_Flag();
        
        TIMER3_InterruptHandler = _timer->TIMER3_InterruptHandler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
        if(High_Priority == timer3_t->priority)
        {
            INTERRUPT_HighPriorityEnable();
            TIMER1_INTERRUPT_Priority_High();
        }
        else if(Low_Priority == timer3_t->priority)
        {
            INTERRUPT_LowPriorityEnable();
            TIMER1_INTERRUPT_Priority_Low();
        }
        else{/*Nothing*/}
#else
        INTERRUPT_AllInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        /*enable timer3*/
        TIMER3_ENABLE_MODULE();
    }
    return ret;
}


/**
 * @brief : De initialize timer3
 * @param _timer
 * @return return 1 if initialization made successfully or 0.
 */
Std_ReturnType timer3_Deinit(const timer3_t *_timer){
    Std_ReturnType ret = E_OK;
    if(_timer == NULL) ret = E_NOT_OK;
    else{
        /* disable timer3*/
        TIMER3_DISABLE_MODULE();
        /*disable interrupt*/
#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE
        TIMER3_INTERRUPT_Disable();
#endif
    }
    return ret;
}


/**
 * @brief : write value at counter of timer3
 * @param _timer & value
 * @return return 1 if initialization made successfully or 0.
 */
Std_ReturnType timer3_write_value(const timer3_t *_timer, uint16 _value){
    Std_ReturnType ret = E_OK;
    if(_timer == NULL) ret = E_NOT_OK;
    else{
        TMR3H = (_value) >> 8;
        TMR3L = (uint8)(_value);
    }
    return ret;
}



/**
 * @brief : read value from counter of timer3
 * @param _timer & pointer of value
 * @return return 1 if initialization made successfully or 0.
 */
Std_ReturnType timer3_read_value(const timer3_t *_timer, uint16 *_value){
    Std_ReturnType ret = E_OK;
    uint8 tmr3_low = 0, tmr3_high  = 0;
    if(_timer == NULL || _value == NULL) ret = E_NOT_OK;
    else{
        tmr3_low = TMR3L;
        tmr3_high = TMR3H;
        (*_value) = (uint16)(tmr3_high << 8) + (tmr3_low);
    }
    return ret;
}




/*_____Function of interrupt____*/
void TIMER3_ISR(void){
    TIMER3_INTERRUPT_Clear_Flag();
    TMR3H = (timer3_preload_value) >> 8;
    TMR3L = (uint8)(timer3_preload_value);
    if(TIMER3_InterruptHandler){
        TIMER3_InterruptHandler();
    }
}



/*____timer mode select & edge____*/
static inline void Timer3_mode_select(const timer3_t *_timer){
    if((_timer->timer3_mode) == TIMER3_SOURCE_TIMER_MOD){
        TIMER3_SOURCE_TIMER_MODE();
    }else{
        TIMER3_SOURCE_COUNTER_MODE();
        if((_timer->timer3_counter_mode) == TIMER3_SYNC_COUNTER_MOD){
            TIMER3_SYNC_COUNTER_MODE();
        }else{
            TIMER3_ASYNC_COUNTER_MODE();
        }
    }
}
