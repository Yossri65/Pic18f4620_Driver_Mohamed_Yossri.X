/* 
 * File:   hal_ccp1.c
 * Author: Yossri
 *
 * Created on August 7, 2023, 1:16 PM
 */
#include "hal_ccp.h"
#ifdef CCP1_INTERRUPT_FEATURE_ENABLE
   interruptHandler CCP1_IntterruptHandeler = NULL;
#endif
#ifdef CCP2_INTERRUPT_FEATURE_ENABLE
   interruptHandler CCP2_IntterruptHandeler = NULL;
#endif
static void CCP_Interrupt_Config(const CCP_config_t *_CCP_ );
static void CCP_PWM_Config(const CCP_config_t *_CCP_ );

static void CCP_capture_Mode_Config_(const CCP_config_t *_CCP_);
static void CCP_Compare_Mode_Config_(const CCP_config_t *_CCP_);
static void CCP_Capture_Compare_Timer_Selection(const CCP_config_t *_CCP_);
   
   
Std_ReturnType CCP_intialize(const CCP_config_t *_CCP_)
{
     Std_ReturnType ret = E_OK;
    if(_CCP_ == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        if (CCP1_SELECT == _CCP_->CCP_Select) 
        {
                CCP1_SET_MODE(CCP_Disable);
        }
        else
        {
            CCP2_SET_MODE(CCP_Disable);
        }
        if(CCP_Capture_Mode_ == _CCP_->CCP_Mode)
        {
            CCP_capture_Mode_Config_(_CCP_);
        }   
        else if(CCP_Compare_Mode_ == _CCP_->CCP_Mode)
        {
            CCP_Compare_Mode_Config_(_CCP_);
        }
        else if(CCP_PWM_Mode_Select == _CCP_->CCP_Mode)
        {
            CCP_PWM_Config(_CCP_);
            
        }else{/*Nothing*/}
        ret = GPIO_Pin_Intialize(&(_CCP_->CCP_pin));
        /*INT CONFIG*/
        CCP_Interrupt_Config(_CCP_);
    }
     return ret;
}
Std_ReturnType CCP_Deintialize(const CCP_config_t *_CCP_)
{
    Std_ReturnType ret = E_OK;
    if(_CCP_ == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        if (CCP1_SELECT == _CCP_->CCP_Select) 
        {
            CCP1_SET_MODE(CCP_Disable);
#ifdef CCP1_INTERRUPT_FEATURE_ENABLE
            CCP1_INTERRUPT_Disable();
#endif
        }
        else
        {
            CCP2_SET_MODE(CCP_Disable);
#ifdef CCP2_INTERRUPT_FEATURE_ENABLE
            CCP2_INTERRUPT_Disable();
#endif 
        }
    }
     return ret;
}

#ifdef CCP_Capture_Mode
    Std_ReturnType CCP_Capture_Is_Ready(const CCP_config_t *_CCP_, uint8 *Capture_Status)
    {
      Std_ReturnType ret = E_OK;
        if (Capture_Status == NULL || NULL ==_CCP_) {
         ret = E_NOT_OK;
        } else 
        {
            if (CCP1_SELECT == _CCP_->CCP_Select) {
                if(PIR1bits.CCP1IF == CPP_CAPTURE_READY){
                    *Capture_Status = CPP_CAPTURE_READY;
                }else{
                    *Capture_Status = CPP_CAPTURE_NOT_READY;
                }
            }else if (CCP2_SELECT == _CCP_->CCP_Select){
                if(PIR2bits.CCP2IF == CPP_CAPTURE_READY){
                    *Capture_Status = CPP_CAPTURE_READY;
                }else{
                    *Capture_Status = CPP_CAPTURE_NOT_READY;
                }
            }else{/*Nothing*/}
            
        }
        return ret;
    }
    Std_ReturnType CCP_Capture_Read_Value(const CCP_config_t *_CCP_ ,uint16 *Capture_Value)
    {
        Std_ReturnType ret = E_OK;
        CCP_Priod_REG_t priod ={.ccpr_low = 0 ,.ccpr_high = 0 ,.ccpr16bit = 0}; 
        if (Capture_Value == NULL || NULL ==_CCP_) {
         ret = E_NOT_OK;
        } else {
            if (CCP1_SELECT == _CCP_->CCP_Select) {
                priod.ccpr_low = CCPR1L;
                priod.ccpr_high = CCPR1H;

                *Capture_Value = priod.ccpr16bit;
            }else if (CCP2_SELECT == _CCP_->CCP_Select){
                priod.ccpr_low = CCPR2L;
                priod.ccpr_high = CCPR2H;

                *Capture_Value = priod.ccpr16bit;
            }
            
        }
        return ret;
    }
#endif

#ifdef CCP_Compare_Mode
    Std_ReturnType CCP_Compare_Is_Complete(const CCP_config_t *_CCP_ ,uint8 *Comapre_Status)
    {
        Std_ReturnType ret = E_OK;
        if (Comapre_Status == NULL || NULL ==_CCP_) {
         ret = E_NOT_OK;
        } else {
            if (CCP1_SELECT == _CCP_->CCP_Select) {
                if(PIR1bits.CCP1IF == CPP_COMPARE_READY){
                    *Comapre_Status = CPP_COMPARE_READY;
                }else{
                    *Comapre_Status = CPP_COMPARE_NOT_READY;
                }
            }else if (CCP2_SELECT == _CCP_->CCP_Select){
                if(PIR2bits.CCP2IF == CPP_COMPARE_READY){
                    *Comapre_Status = CPP_COMPARE_READY;
                }else{
                    *Comapre_Status = CPP_COMPARE_NOT_READY;
                }
            }
        }
        return ret;
    }
    Std_ReturnType CCP_Compare_Set_Value(const CCP_config_t *_CCP_ ,uint16 Compare_Value)
    {
        Std_ReturnType ret = E_OK;
        if(Compare_Value == NULL || NULL ==_CCP_)
        {
            ret = E_NOT_OK;
        }
        else
        {
           CCP_Priod_REG_t priod ={.ccpr_low = 0 ,.ccpr_high = 0 ,.ccpr16bit = 0}; 
           priod.ccpr16bit = Compare_Value;
           if (CCP1_SELECT == _CCP_->CCP_Select) {
               CCPR1L = priod.ccpr_low;
               CCPR1H = priod.ccpr_high; 
            }else if (CCP2_SELECT == _CCP_->CCP_Select){
               CCPR2L = priod.ccpr_low;
               CCPR2H = priod.ccpr_high; 
            }
           
        }
         
        return ret;
    }
#endif

#ifdef CCP_PWM_Mode
    Std_ReturnType CCP_PWM_Set_Duty(const CCP_config_t *_CCP_ ,const float _duty)
    {
         Std_ReturnType ret = E_OK;
         uint16 l_duty_temp = 0 ;
        if (_CCP_ == NULL) {
         ret = E_NOT_OK;
        } else {
            l_duty_temp = (float)((float)4 * ((float)PR2 + 1.0) * ((float)_duty / 100.0)); 
            if(CCP1_SELECT == _CCP_->CCP_Select)
            {
                CCP1CONbits.DC1B = (uint8)(l_duty_temp & 0x0003);
                CCPR1L = (uint8)(l_duty_temp >> 2);
            }
            else if(CCP2_SELECT == _CCP_->CCP_Select)
            {
                CCP2CONbits.DC2B = (uint8)(l_duty_temp & 0x0003);
                CCPR2L = (uint8)(l_duty_temp >> 2);
            }    
        }
        return ret;
         
        
    }
    Std_ReturnType CCP_PWM_Start(const CCP_config_t *_CCP_)
    {
        Std_ReturnType ret = E_OK;
        if (_CCP_ == NULL) {
         ret = E_NOT_OK;
        } else {
            if(CCP1_SELECT == _CCP_->CCP_Select)
            {
                CCP1CONbits.CCP1M = CCP_PWM_Mode_;
            }
            else if(CCP2_SELECT == _CCP_->CCP_Select)
            {
                CCP2CONbits.CCP2M = CCP_PWM_Mode_;
            }    
        }
        return ret;
    }
    Std_ReturnType CCP_PWM_Stop(const CCP_config_t *_CCP_)
    {
        Std_ReturnType ret = E_OK;
        if (_CCP_ == NULL) {
         ret = E_NOT_OK;
        } else {
            if(CCP1_SELECT == _CCP_->CCP_Select)
            {
                CCP2CONbits.CCP2M = CCP_Disable;
            }
            else if(CCP2_SELECT == _CCP_->CCP_Select)
            {
                CCP2CONbits.CCP2M = CCP_Disable;
            }    
        }
        return ret;
    }
#endif
    
static void CCP_Interrupt_Config(const CCP_config_t *_CCP_ ) {
    if (CCP1_SELECT == _CCP_->CCP_Select) {
#ifdef CCP1_INTERRUPT_FEATURE_ENABLE
        /*CCP1 interrupt Enable*/
        CCP1_INTERRUPT_Enable();
        /*CCP1 clear flag*/
        CCP1_INTERRUPT_Clear_Flag();

        CCP1_IntterruptHandeler = _CCP_->CCP1_IntterruptHandeler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
        if (High_Priority == -_CCP1_->CCP1_priority) {
            INTERRUPT_HighPriorityEnable();
            CCP1_INTERRUPT_Priority_High();
        } else if (Low_Priority == -_CCP_->CCP1_priority) {
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
    } else if (CCP2_SELECT == _CCP_->CCP_Select) {
#ifdef CCP2_INTERRUPT_FEATURE_ENABLE
        /*CCP2 interrupt Enable*/
        CCP2_INTERRUPT_Enable();
        /*CCP2 clear flag*/
        CCP1_INTERRUPT_Clear_Flag();

        CCP2_IntterruptHandeler = _CCP_->CCP2_IntterruptHandeler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
        if (High_Priority == -_CCP_->CCP2_priority) {
            INTERRUPT_HighPriorityEnable();
            CCP2_INTERRUPT_Priority_High();
        } else if (Low_Priority == -_CCP_->CCP2_priority) {
            INTERRUPT_LowPriorityEnable();
            CCP2_INTERRUPT_Priority_Low();
        } else {
            /*Nothing*/
        }
#else
        INTERRUPT_AllInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
    }
}
static void CCP_PWM_Config(const CCP_config_t *_CCP_ )
{
    if (CCP1_SELECT == _CCP_->CCP_Select) {
        if (CCP_PWM_Mode_ == _CCP_->ccp_mode_varient) {
            CCP1_SET_MODE(CCP_PWM_Mode_);
        } else {
            /*Nothing*/
        }
    } else if (CCP2_SELECT == _CCP_->CCP_Select) {
        if (CCP_PWM_Mode_ == _CCP_->ccp_mode_varient) {
            CCP2_SET_MODE(CCP_PWM_Mode_);
        } else {
            /*Nothing*/
        }
    }
#ifdef CCP_PWM_Mode
    PR2 = (uint8) ((_XTAL_FREQ / ((float)(_CCP_->PWM_Frequncy) * 4.0 * (float)(_CCP_->Postscaler_Select) * (float)(_CCP_->Prescaler_Select))) - 1.0);
#endif
}

static void CCP_Capture_Compare_Timer_Selection(const CCP_config_t *_CCP_)
{
    if(CCP1_CCP2_Timer3 == _CCP_->Capture_Timer)
    {
        T3CONbits.T3CCP1 = 0;
        T3CONbits.T3CCP2 = 1;
    }else if(CCP1_Timer1_CCP2_Timer2 == _CCP_->Capture_Timer)
    {
        T3CONbits.T3CCP1 = 1;
        T3CONbits.T3CCP2 = 0;
    }else if(CCP1_CCP2_Timer1 == _CCP_->Capture_Timer)
    {
        T3CONbits.T3CCP1 = 0;
        T3CONbits.T3CCP2 = 0;
    }else{/*Nothing*/}
}

static void CCP_capture_Mode_Config_(const CCP_config_t *_CCP_)
{
    if (CCP1_SELECT == _CCP_->CCP_Select) 
            {
                switch(_CCP_->ccp_mode_varient)
                {
                    case CCP_Capture_Mode_1_Falling_Edge: 
                        CCP1_SET_MODE(CCP_Capture_Mode_1_Falling_Edge);
                    break;
                    case CCP_Capture_Mode_1_Raising_Edge: 
                        CCP1_SET_MODE(CCP_Capture_Mode_1_Raising_Edge);
                    break;
                    case CCP_Capture_Mode_4_Raising_Edge: 
                        CCP1_SET_MODE(CCP_Capture_Mode_4_Raising_Edge);
                    break;
                    case CCP_Capture_Mode_16_Raising_Edge: 
                        CCP1_SET_MODE(CCP_Capture_Mode_16_Raising_Edge);
                    break;
                    
                }
            }
            else if (CCP2_SELECT == _CCP_->CCP_Select) 
            {
                switch(_CCP_->ccp_mode_varient)
                {
                    case CCP_Capture_Mode_1_Falling_Edge: 
                        CCP2_SET_MODE(CCP_Capture_Mode_1_Falling_Edge);
                    break;
                    case CCP_Capture_Mode_1_Raising_Edge: 
                        CCP2_SET_MODE(CCP_Capture_Mode_1_Raising_Edge);
                    break;
                    case CCP_Capture_Mode_4_Raising_Edge: 
                        CCP2_SET_MODE(CCP_Capture_Mode_4_Raising_Edge);
                    break;
                    case CCP_Capture_Mode_16_Raising_Edge: 
                        CCP2_SET_MODE(CCP_Capture_Mode_16_Raising_Edge);
                    break;
                }
            }
            CCP_Capture_Compare_Timer_Selection(_CCP_);
}

static void CCP_Compare_Mode_Config_(const CCP_config_t *_CCP_)
{
    if (CCP1_SELECT == _CCP_->CCP_Select) 
            {
                switch(_CCP_->ccp_mode_varient)
                {
                    case CCP_Compare_Mode_Set_Pin_Low: 
                        CCP1_SET_MODE(CCP_Compare_Mode_Set_Pin_Low);
                    break;
                    case CCP_Compare_Mode_Set_Pin_High: 
                        CCP1_SET_MODE(CCP_Compare_Mode_Set_Pin_High);
                    break;
                    case CCP_Compare_Mode_Toggle_On_Match: 
                        CCP1_SET_MODE(CCP_Compare_Mode_Toggle_On_Match);
                    break;
                    case CCP_Compare_Mode_Gen_SW_INT: 
                        CCP1_SET_MODE(CCP_Compare_Mode_Gen_SW_INT);
                    break;
                    case CCP_Compare_Mode_Gen_Event: 
                        CCP1_SET_MODE(CCP_Compare_Mode_Gen_Event);
                    break;
                }
            }
            else if (CCP2_SELECT == _CCP_->CCP_Select) 
            {
                    switch(_CCP_->ccp_mode_varient)
                 {
                     case CCP_Compare_Mode_Set_Pin_Low: 
                         CCP2_SET_MODE(CCP_Compare_Mode_Set_Pin_Low);
                     break;
                     case CCP_Compare_Mode_Set_Pin_High: 
                         CCP2_SET_MODE(CCP_Compare_Mode_Set_Pin_High);
                     break;
                     case CCP_Compare_Mode_Toggle_On_Match: 
                         CCP2_SET_MODE(CCP_Compare_Mode_Toggle_On_Match);
                     break;
                     case CCP_Compare_Mode_Gen_SW_INT: 
                         CCP2_SET_MODE(CCP_Compare_Mode_Gen_SW_INT);
                     break;
                     case CCP_Compare_Mode_Gen_Event: 
                         CCP2_SET_MODE(CCP_Compare_Mode_Gen_Event);
                     break;
                 }
            }
            CCP_Capture_Compare_Timer_Selection(_CCP_);
}

void CCP1_ISR(void){
    CCP1_INTERRUPT_Clear_Flag();
    if(CCP1_IntterruptHandeler){
        CCP1_IntterruptHandeler();
    }
}
void CCP2_ISR(void){
    CCP2_INTERRUPT_Clear_Flag();
    if(CCP2_IntterruptHandeler){
       CCP2_IntterruptHandeler();
    }
}