/* 
 * File:   mcal_timer1.c
 * Author: Yossri
 *
 * Created on July 27, 2023, 6:51 PM
 */

#include "mcal_timer1.h"
#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
   interruptHandler TIMER1_IntterruptHandeler = NULL;
#endif
static void Timer1_Mode_Select(const Timer1_conf_t *timer1_);

static volatile uint16 pre_load = 0; 


Std_ReturnType Timer1_Intialization(const Timer1_conf_t *timer1_)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer1_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*Disable The Timer0*/
        TIMER1_DISABLE();
        /*prescaler confg*/
        Timer1_Prescaler_Select(timer1_->Prescaler_Select);
        /*Select mode*/
        Timer1_Mode_Select(timer1_);
        
        TMR0H = ((timer1_->TIMER1_PRE_LOAD_VALUE)>>8);
        TMR0L = (uint8)(timer1_->TIMER1_PRE_LOAD_VALUE);
        pre_load = timer1_->TIMER1_PRE_LOAD_VALUE;
        /*configure The interrupt*/
#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
        /*Timer1 interrupt Enable*/
        TIMER1_INTERRUPT_Enable();
        /*Timer1 clear flag*/
        TIMER1_INTERRUPT_Clear_Flag();
        
        TIMER1_IntterruptHandeler = timer1_->TIMER1_IntterruptHandeler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
        if(High_Priority == timer1_->priority)
        {
            INTERRUPT_HighPriorityEnable();
            TIMER1_INTERRUPT_Priority_High();
        }
        else if(Low_Priority == timer1_->priority)
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
        /*Enable The Timer1*/
        TIMER1_ENABLE();
    }
    return ret; 
}

Std_ReturnType Timer1_DeIntialization(const Timer1_conf_t *timer1_)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer1_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*Disable The Timer0*/
        TIMER1_DISABLE();
        /*configure The interrupt*/
#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
       TIMER1_INTERRUPT_Disable();
#endif
        
    }
    return ret;
}

Std_ReturnType Timer1_Write_Value(const Timer1_conf_t *timer1_ ,uint16 value)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer1_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        TMR1H = (value>>8);
        TMR1L = (uint8)(value);
    }
    return ret;
}

Std_ReturnType Timer1_Read_Value(const Timer1_conf_t *timer1_ ,uint16 *value)
{
    Std_ReturnType ret = E_OK ;
    uint8 l_tmr1l = 0 ,l_tmr1h = 0;
    if(NULL == timer1_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        l_tmr1l = TMR1L;
        l_tmr1h = TMR1H;
        
        *value = (uint16)(l_tmr1h << 8) + l_tmr1l;
    }
    return ret;
}

static void Timer1_Mode_Select(const Timer1_conf_t *timer1_)
{
    if(TIMER1_TIMER_MODE_  == timer1_->Timer1_Mode)
    {
        TIMER1_TIMER_MODE();    
    }
    else if(TIMER1_COUNTER_MODE_ == timer1_->Timer1_Mode)
    {
        TIMER1_COUNTER_MODE();
        if (TIMER1_SYNC_COUNTER_MODE_ == timer1_->Timer1_Counter_Sync_Mode) {
            TIMER1_SYNC_COUNTER_MODE();
        } else if (TIMER1_ASYNC_TIMER_MODE_ == timer1_->Timer1_Counter_Sync_Mode) {
            TIMER1_ASYNC_TIMER_MODE();
        } else {
            /*Nothing*/
        }
        
    }
    else{/*Nothing*/}
}

void TIMER1_ISR(void)
{
    #ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
     /*Clear Flag*/
    
    /*code*/
    TMR1H = (pre_load>>8);
    TMR1L = (uint8)(pre_load);
    /*set call back function*/
    if(NULL == TIMER1_IntterruptHandeler){}
    else{
        TIMER1_IntterruptHandeler ();
    }
#endif
}