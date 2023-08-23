/* 
 * File:   hal_eccp.c
 * Author: Yossri
 *
 * Created on August 9, 2023, 7:43 PM
 */
#include "hal_eccp.h"
#ifdef ECCP_INTERRUPT_FEATURE_ENABLE
   interruptHandler ECCP_IntterruptHandeler_ = NULL;
#endif

static void ECCP_Interrupt_Config(const ECCP_CONFIG_t *_ECCP_);

Std_ReturnType ECCP_intialize(const ECCP_CONFIG_t *_ECCP_)
{
    Std_ReturnType ret = E_OK;
    if(_ECCP_ == NULL) 
    {
        ret = E_NOT_OK;
    }
    else{
            ECCP_PWM_SET_MODE(ECCP_Disable);
            ECCP_PWM_SET_MODE(_ECCP_->ECCP_PWM_SET_MODE);
            PWM_Pins_Mode(_ECCP_->PWM_Pins_Mode);
            ret = GPIO_Pin_Intialize(&(_ECCP_->eccp_pinA));
            ret = GPIO_Pin_Intialize(&(_ECCP_->eccp_pinB));
            ret = GPIO_Pin_Intialize(&(_ECCP_->eccp_pinC));
            ret = GPIO_Pin_Intialize(&(_ECCP_->eccp_pinD));
            ECCP_Interrupt_Config(_ECCP_);
            PR2 = (uint8)((_XTAL_FREQ / ((_ECCP_->PWM_Frequncy) * 4.0 * (_ECCP_->Postscaler_Select) * (_ECCP_->Prescaler_Select))) - 1.0);
            PWM1CONbits.PDC = _ECCP_->delay /(4.0 *_XTAL_FREQ) ;
            ECCP1ASbits.ECCPASE = PWM_auto_shutdown_Disable;
            PWM1CONbits.PRSEN = 1 ;
            ECCP1ASbits.PSSBD = _ECCP_->Pins_B_D_Shutdown_State;
            ECCP1ASbits.PSSAC = _ECCP_->Pins_A_C_Shutdown_State ;  
            ECCP1ASbits.ECCPAS =_ECCP_->Auto_ShutDown_Sourse_Select_Bit;
            ECCP1ASbits.ECCPASE = PWM_auto_shutdown_Enable;
            
            ECCP_PWM_SET_MODE(ECCP_Disable);
    }
    return ret;
}
Std_ReturnType ECCP_Deintialize(const ECCP_CONFIG_t *_ECCP_)
{
     Std_ReturnType ret = E_OK;
    if(_ECCP_ == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        ECCP_PWM_SET_MODE(ECCP_Disable);
#ifdef CCP1_INTERRUPT_FEATURE_ENABLE
            CCP1_INTERRUPT_Disable();
#endif
        
    }
     return ret;
}

Std_ReturnType ECCP_PWM_Set_Duty(const ECCP_CONFIG_t *_ECCP_ ,const uint8 _duty)
{
    Std_ReturnType ret = E_OK;
    uint16 l_duty_temp = 0 ;
    if (_ECCP_ == NULL) {
        ret = E_NOT_OK;
    } else {
        l_duty_temp = (uint16)((PR2 + 1)*(_duty/100.0)*4);
            CCP1CONbits.DC1B = (uint8)(l_duty_temp & 0x0003);
            CCPR1L = (uint8)(l_duty_temp >> 2);
    }
    return ret;
}
Std_ReturnType ECCP_PWM_Start(const ECCP_CONFIG_t *_ECCP_)
{
    Std_ReturnType ret = E_OK;
        if (_ECCP_ == NULL) {
         ret = E_NOT_OK;
        } else {
            CCP1CONbits.CCP1M = _ECCP_->ECCP_PWM_SET_MODE;
            ECCP1ASbits.ECCPASE=0;
        }
        return ret;
}
Std_ReturnType ECCP_PWM_Stop(const ECCP_CONFIG_t *_ECCP_)
{
    Std_ReturnType ret = E_OK;
        if (_ECCP_ == NULL) {
         ret = E_NOT_OK;
        } else {
            CCP1CONbits.CCP1M = ECCP_Disable;
        }
        return ret;
}

static void ECCP_Interrupt_Config(const ECCP_CONFIG_t *_ECCP_) {
#ifdef ECCP_INTERRUPT_FEATURE_ENABLE
        /*CCP1 interrupt Enable*/
        CCP1_INTERRUPT_Enable();
        /*CCP1 clear flag*/
        CCP1_INTERRUPT_Clear_Flag();

        ECCP_IntterruptHandeler_ = _ECCP_->ECCP_IntterruptHandeler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
        if (High_Priority == _ECCP_->CCP1_priority) {
            INTERRUPT_HighPriorityEnable();
            CCP1_INTERRUPT_Priority_High();
        } else if (Low_Priority == _ECCP_->CCP1_priority) {
            INTERRUPT_LowPriorityEnable();
            CCP1_INTERRUPT_Priority_Low();
        } else {
            /*Nothing*/
        }
#else
        INTERRUPT_AllInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
}

void ECCP_ISR(void){
    CCP1_INTERRUPT_Clear_Flag();
    if(ECCP_IntterruptHandeler_){
        ECCP_IntterruptHandeler_();
    }
}