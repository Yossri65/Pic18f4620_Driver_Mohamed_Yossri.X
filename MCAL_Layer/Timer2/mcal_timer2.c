/* 
 * File:   mcal_timer2.c
 * Author: Yossri
 *
 * Created on July 29, 2023, 3:25 PM
 */

#include "mcal_timer2.h"
#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE
   interruptHandler TIMER2_IntterruptHandeler_ = NULL;
#endif
static volatile uint16 pre_load = 0; 


Std_ReturnType Timer2_Intialization(const Timer2_conf_t *timer2_)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer2_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*Disable The Timer0*/
        TIMER2_DISABLE();
        /*prescaler confg*/
        Timer2_Prescaler_Select_(timer2_->Prescaler_Select);
        /*postscaler confg*/
        Timer2_Postscaler_Select_(timer2_->Postscaler_Select);
        TMR2 = (timer2_->TIMER2_PRE_LOAD_VALUE);
        pre_load = timer2_->TIMER2_PRE_LOAD_VALUE;
        /*configure The interrupt*/
#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE
        /*Timer0 interrupt Enable*/
        TIMER2_INTERRUPT_Enable();
        /*Timer0 clear flag*/
        TIMER2_INTERRUPT_Clear_Flag();
        
        TIMER2_IntterruptHandeler_ =timer2_->TIMER2_IntterruptHandeler;
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
        /*Enable The Timer2*/
        TIMER2_ENABLE();
    }
     return ret; 
}
Std_ReturnType Timer2_DeIntialization(const Timer2_conf_t *timer2_)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer2_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*Disable The Timer0*/
        TIMER2_DISABLE();
        /*configure The interrupt*/
#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE
       TIMER2_INTERRUPT_Disable();
#endif
        
    }
    return ret;
}

Std_ReturnType Timer2_Write_Value(const Timer2_conf_t *timer2_ ,uint8 value)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer2_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        TMR2 = value ;
    }
    return ret;
}

Std_ReturnType Timer2_Read_Value(const Timer2_conf_t *timer2_ ,uint8 *value)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == timer2_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        *value = TMR2;
    }
    return ret;
}

/*_____Function of interrupt____*/

   void TIMER2_ISR(void){
#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE
    TIMER2_INTERRUPT_Clear_Flag();
    TMR2 = (uint8)(pre_load);
    if(TIMER2_IntterruptHandeler_){
        TIMER2_IntterruptHandeler_();
    }
#endif
}
