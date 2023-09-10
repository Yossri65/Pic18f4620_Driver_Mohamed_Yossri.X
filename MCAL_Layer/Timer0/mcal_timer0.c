/* 
 * File:   mcal_timer0.c
 * Author: Yossri
 *
 * Created on July 26, 2023, 3:49 PM
 */
#include "mcal_timer0.h"

#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
   interruptHandler TIMER0_IntterruptHandeler = NULL;
#endif
static void Timer0_Prescaler_Config(const Timer0_conf_t *timer0_);
static void Timer0_Mode_Select(const Timer0_conf_t *timer0_);
static void Timer0_Bit_Mode_Select(const Timer0_conf_t *timer0_);   

static volatile uint16 pre_load = 0; 

Std_ReturnType Timer0_Intialization(const Timer0_conf_t *timer0_)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer0_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*Disable The Timer0*/
        TIMER0_DISABLE();
        /*prescaler confg*/
        Timer0_Prescaler_Config(timer0_);
        /*Select mode*/
        Timer0_Mode_Select(timer0_);
        /*Select bit mode*/
        Timer0_Bit_Mode_Select(timer0_);
        
        TMR0H = ((timer0_->TIMER0_PRE_LOAD_VALUE)>>8);
        TMR0L = (uint8)(timer0_->TIMER0_PRE_LOAD_VALUE);
        pre_load = timer0_->TIMER0_PRE_LOAD_VALUE;
        /*configure The interrupt*/
#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
        /*Timer0 interrupt Enable*/
        TIMER0_INTERRUPT_Enable();
        /*Timer0 clear flag*/
        TIMER0_INTERRUPT_Clear_Flag();
        
        TIMER0_IntterruptHandeler = timer0_->TIMER0_IntterruptHandeler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
        if(High_Priority == timer0_->priority)
        {
            INTERRUPT_HighPriorityEnable();
            TIMER0_INTERRUPT_Priority_High();
        }
        else if(Low_Priority == timer0_->priority)
        {
            INTERRUPT_LowPriorityEnable();
            TIMER0_INTERRUPT_Priority_Low();
        }
        else{/*Nothing*/}
#else
        INTERRUPT_AllInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        /*Enable The Timer0*/
        TIMER0_ENABLE();
    }
    return ret; 
}

Std_ReturnType Timer0_DeIntialization(const Timer0_conf_t *timer0_)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer0_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*Disable The Timer0*/
        TIMER0_DISABLE();
        /*configure The interrupt*/
#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
       TIMER0_INTERRUPT_Disable();
#endif
        
    }
    return ret;
}

Std_ReturnType Timer0_Write_Value(const Timer0_conf_t *timer0_ ,uint16 value)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer0_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        TMR0H = (value>>8);
        TMR0L = (uint8)(value);
    }
    return ret;
}

Std_ReturnType Timer0_Read_Value(const Timer0_conf_t *timer0_ ,uint16 *value)
{
    Std_ReturnType ret = E_OK ;
    uint8 l_tmr0l = 0 ,l_tmr0h = 0;
    if(NULL == timer0_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        l_tmr0l = TMR0L;
        l_tmr0h = TMR0H;
        
        *value = (uint16)((l_tmr0h << 8) + l_tmr0l);
    }
    return ret;
}



static void Timer0_Prescaler_Config(const Timer0_conf_t *timer0_)
{
    if(TIMER0_PRESCALER_ENABLE_  == timer0_->TIMER0_PRESCALER_STATUS)
    {
        TIMER0_PRESCALER_ENABLE();
        T0CONbits.T0PS =  timer0_->Prescaler_Select;
    }
    else if(TIMER0_PRESCALER_DISABLE_  == timer0_->TIMER0_PRESCALER_STATUS)
    {
        TIMER0_PRESCALER_DISABLE();
    }
    else{/*Nothing*/}
}

static void Timer0_Mode_Select(const Timer0_conf_t *timer0_)
{
    if(TIMER0_TIMER_MODE_  == timer0_->Timer0_Mode)
    {
        TIMER0_TIMER_MODE();    
    }
    else if(TIMER0_COUNTER_MODE_ == timer0_->Timer0_Mode)
    {
        TIMER0_COUNTER_MODE();
        if (TIMER0_FALING_EDGE_ == timer0_->Timer0_counter_mode_Source_Edge) {
            TIMER0_FALING_EDGE_SELECT();
        } else if (TIMER0_RAISING_EDGE_ == timer0_->Timer0_counter_mode_Source_Edge) {
            TIMER0_RAISING_EDGE_SELECT();
        } else {
            /*Nothing*/
        }
        
    }
    else{/*Nothing*/}
}

static void Timer0_Bit_Mode_Select(const Timer0_conf_t *timer0_)
{
    if(TIMER0_8_BIT_MODE_  == timer0_->Timer0_SELECT_BIT_Mode)
    {
        TIMER0_8_BIT_MODE();    
    }
    else if(TIMER0_16_BIT_MODE_ == timer0_->Timer0_SELECT_BIT_Mode)
    {
        TIMER0_16_BIT_MODE();
    }
    else{/*Nothing*/}
}

void TIMER0_ISR(void)
{
    #ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
     /*Clear Flag*/
    TIMER0_INTERRUPT_Clear_Flag();
    /*code*/
    TMR0H = (pre_load>>8);
    TMR0L = (uint8)(pre_load);
    /*set call back function*/
    if(NULL == TIMER0_IntterruptHandeler){}
    else{
        TIMER0_IntterruptHandeler ();
    }
#endif
}