/* 
 * File:   mcal_adc.c
 * Author: Yossri
 *
 * Created on July 24, 2023, 6:25 PM
 */
#include "mcal_adc.h"

#ifdef ADC_INTERRUPT_FEATURE_ENABLE
static interruptHandler ADC_interruptHandler = NULL;
#endif

static void ADC_Set_Channel_As_Inbut(ADC_Channel_Selection_t channel);
static void ADC_Select_format_status(const ADC_Conf_t *adc_ );
static void ADC_Select_Voltage_Reference(const ADC_Conf_t *adc_ );

/**

@brief Initializes the ADC module with the given configuration parameters.
@param adc_ Pointer to ADC configuration structure.
@return Standard return type indicating success or failure of the function.
Copy
     E_OK if successful, E_NOT_OK if there is an error 
@note This function initializes the ADC module with the given configuration parameters.

     It disables the ADC module, configures the [acquisition time]
 * , conversion clock, default channel, interrupt, result format, and voltage reference.
     Finally, it enables the ADC module.
*/
Std_ReturnType ADC_Intialization(const ADC_Conf_t *adc_)
{
   Std_ReturnType ret = E_OK ;
    if(NULL == adc_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*Disable The ADC*/
        ADC_Converter_Disable();
        /*configure Acquisition Time*/
        ADCON2bits.ACQT = adc_->ADC_Acquisition_Time;
        /*configure  Conversion Clock*/
         ADCON2bits.ADCS = adc_->ADC_Conversion_Clock;
        /*configure Default Channel*/
        ADCON0bits.CHS =  adc_->ADC_Channel;
        ADC_Set_Channel_As_Inbut(adc_->ADC_Channel);
        /*configure The interrupt*/
#ifdef ADC_INTERRUPT_FEATURE_ENABLE
        /*ADC interrupt Enable*/
        ADC_INTERRUPT_Enable();
        /*ADC clear flag*/
        ADC_INTERRUPT_Clear_Flag();
#ifdef ADC_INTERRUPT_PRIORITY_LEVELS_ENABLE
        
        if(High_Priority == adc_->priority)
        {
            INTERRUPT_HighPriorityEnable();
            ADC_INTERRUPT_Priority_High();
        }
        else if(Low_Priority == adc_->priority)
        {
            INTERRUPT_LowPriorityEnable();
            ADC_INTERRUPT_Priority_Low();
        }
        else{/*Nothing*/}
#else
        INTERRUPT_AllInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
        ADC_interruptHandler = adc_->ADC_IntterruptHandeler;
#endif
        /*Configure The Result Format*/
        ADC_Select_format_status(adc_);
        /*Configure The Voltage Reference*/
        ADC_Select_Voltage_Reference(adc_);
        /*Enable The ADC*/
        ADC_Converter_Enable();
    }
    return ret; 
}

/**

@brief De-initializes the ADC module by disabling it.
@param adc_ Pointer to ADC configuration structure.
@return Standard return type indicating success or failure of the function.
     E_OK if successful, E_NOT_OK if there is an error 
@note This function de-initializes the ADC module by disabling it.
*/
Std_ReturnType ADC_DeIntialization(const ADC_Conf_t *adc_)
{
   Std_ReturnType ret = E_OK ;
    if(NULL == adc_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*Disable The ADC*/
        ADC_Converter_Disable();
        /*configure The interrupt*/
#ifdef ADC_INTERRUPT_FEATURE_ENABLE
        /*ADC interrupt disable*/
        ADC_INTERRUPT_Disable();
#endif
    }
    return ret; 
}


/**

@brief Selects the ADC channel for conversion.
@param adc_ Pointer to ADC configuration structure.
@param channel ADC channel to select.
@return Standard return type indicating success or failure of the function.
Copy
     E_OK if successful, E_NOT_OK if there is an error 
@note This function selects the ADC channel for conversion by setting the CHS bits of the ADCON0 register.

     It also sets the selected channel as an input by calling the ADC_Set_Channel_As_Inbut() function.
*/
Std_ReturnType ADC_Channel_Selection(const ADC_Conf_t *adc_,ADC_Channel_Selection_t channel)
{
   Std_ReturnType ret = E_OK ;
    if(NULL == adc_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        ADCON0bits.CHS = channel;
        ADC_Set_Channel_As_Inbut(adc_->ADC_Channel);
    }
    return ret; 
}

/**

@brief Starts an ADC conversion.
@param adc_ Pointer to ADC configuration structure.
@return Standard return type indicating success or failure of the function.
     E_OK if successful, E_NOT_OK if there is an error
@note This function starts an ADC conversion by calling the ACD_Start_Conversion() function.
*/
Std_ReturnType ADC_Start_Conversion(const ADC_Conf_t *adc_)
{
   Std_ReturnType ret = E_OK ;
    if(NULL == adc_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        ACD_Start_Conversion();
    }
    return ret; 
}
/**
@brief Checks if ADC conversion is done and returns the conversion status.
@param adc_ Pointer to ADC configuration structure.
@param conversion_status Pointer to variable to store the conversion status.
@return Standard return type indicating success or failure of the function.
     E_OK if successful, E_NOT_OK if there is an error
@note This function checks the ADC conversion status using the ACD_Read_Conversion_Status() function.
     If the conversion is done, the conversion status is FALSE. Otherwise, the conversion status is TRUE.
*/
Std_ReturnType ADC_Is_Conversion_Done(const ADC_Conf_t *adc_ ,uint8 *conversion_status)
{
   Std_ReturnType ret = E_OK ;
    if(NULL == adc_ || NULL == conversion_status)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        if(ACD_Read_Conversion_Status() == 1)
        {
            *conversion_status = FALSE;
        }
        else
        {
            *conversion_status = TRUE;
        }
    }
    return ret; 
}

/**
@brief Gets the ADC conversion result stored in ADRESH and ADRESL registers.
@param adc_ Pointer to ADC configuration structure.
@param conversion_Result Pointer to variable to store the conversion result.
@return Standard return type indicating success or failure of the function.
     E_OK if successful, E_NOT_OK if there is an error 
@note This function retrieves the ADC conversion result stored in the ADRESH and ADRESL registers and stores it in the conversion_Result variable.

     The format of the result depends on the format_status field of the [ADC configuration structure] 
 *  (ADC_RIGHT_JUSTIFIED, ADC_LEFT_JUSTIFIED, or ADC_FOURTEEN_BIT_MODE).
*/
Std_ReturnType ADC_Get_Conversion_Result(const ADC_Conf_t *adc_ ,uint16 *conversion_Result)
{
   Std_ReturnType ret = E_OK ;
    if(NULL == adc_ || NULL == conversion_Result)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        if (ADC_RIGHT_JUSTIFIED == adc_->format_status) 
        {
            *conversion_Result = (uint16)((ADRESH << 8) + ADRESL);
        } 
        else if (ADC_LEFT_JUSTIFIED == adc_->format_status) {
            *conversion_Result = (uint16)(((ADRESH << 8) + ADRESL)>> 6);
        } 
        else {
            *conversion_Result = (uint16)((ADRESH >> 8) + ADRESL);
        }
    }
    return ret; 
}

/**
@brief Gets the ADC conversion result in blocking mode for a specific channel.
@param adc_ Pointer to ADC configuration structure.
@param conversion_Result Pointer to variable to store the conversion result.
@param channel ADC channel selection.
@return Standard return type indicating success or failure of the function.
     E_OK if successful, E_NOT_OK if there is an error 
@note This function selects an ADC channel using ADC_Channel_Selection(), 
 * starts the conversion using ADC_Start_Conversion(),waits for the conversion to complete 
 * using ACD_Read_Conversion_Status(), and then gets the conversion result using ADC_Get_Conversion_Result().
Copy
     The result is stored in the conversion_Result variable.
*/
Std_ReturnType ADC_Get_Conversion_Blocking_Mode(const ADC_Conf_t *adc_ ,uint16 *conversion_Result
                                  ,ADC_Channel_Selection_t channel)
  {
   Std_ReturnType ret = E_OK ;
    if(NULL == adc_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*select channel*/
        ret = ADC_Channel_Selection(adc_ , channel);
        /*start the conversion*/
        ret =ADC_Start_Conversion(adc_);
        /*write the result*/
        while(ACD_Read_Conversion_Status());
        ret = ADC_Get_Conversion_Result(adc_ , conversion_Result);
    }
    return ret; 
}

Std_ReturnType ADC_Start_Conversion_Interrupt_Mode(const ADC_Conf_t *adc_,ADC_Channel_Selection_t channel)
  {
   Std_ReturnType ret = E_OK ;
    if(NULL == adc_ )
    {
        ret = E_NOT_OK;
    }
    else 
    {
        /*select channel*/
        ret = ADC_Channel_Selection(adc_ , channel);
        /*start the conversion*/
        ret =ADC_Start_Conversion(adc_);
    }
    return ret; 
}
static void ADC_Set_Channel_As_Inbut(ADC_Channel_Selection_t channel)
{
    switch(channel)
    {
        case ADC_CHANNEL_AN0 : SET_BIT(TRISA ,_TRISA_RA0_LENGTH); break;
        case ADC_CHANNEL_AN1 : SET_BIT(TRISA, _TRISA_RA1_POSN);  break; 
        case ADC_CHANNEL_AN2 : SET_BIT(TRISA, _TRISA_RA2_POSN);  break;    
        case ADC_CHANNEL_AN3 : SET_BIT(TRISA, _TRISA_RA3_POSN);  break;   
        case ADC_CHANNEL_AN4 : SET_BIT(TRISA, _TRISA_RA5_POSN);  break;   
        case ADC_CHANNEL_AN5 : SET_BIT(TRISE, _TRISE_RE0_POSN);  break;   
        case ADC_CHANNEL_AN6 : SET_BIT(TRISE, _TRISE_RE1_POSN);  break;    
        case ADC_CHANNEL_AN7 : SET_BIT(TRISE, _TRISE_RE2_POSN);  break;    
        case ADC_CHANNEL_AN8 : SET_BIT(TRISB, _TRISB_RB2_POSN);  break;  
        case ADC_CHANNEL_AN9 : SET_BIT(TRISB, _TRISB_RB3_POSN);  break;   
        case ADC_CHANNEL_AN10 :SET_BIT(TRISB, _TRISB_RB1_POSN);  break;   
        case ADC_CHANNEL_AN11 :SET_BIT(TRISB, _TRISB_RB4_POSN);  break;    
        case ADC_CHANNEL_AN12 :SET_BIT(TRISB, _TRISB_RB0_POSN);  break;  
    }
}

static void ADC_Select_format_status(const ADC_Conf_t *adc_ )
{
    if(ADC_RIGHT_JUSTIFIED == adc_->format_status)
    {
        ADC_Result_Format_Right_justified();
    }
    else if(ADC_LEFT_JUSTIFIED == adc_->format_status)
    {
        ADC_Result_Format_Left_justified();
    }
    else
    {
        ADC_Result_Format_Right_justified();
    }
}
static void ADC_Select_Voltage_Reference(const ADC_Conf_t *adc_ )
{
    if(ADC_VOLTAGE_REF_ENABLE == adc_->voltage_ref)
    {
        ADC_Voltage_Reference_ENABLE;
    }
    else if(ADC_VOLTAGE_REF_DISABLE == adc_->voltage_ref)
    {
        ADC_Voltage_Reference_Disable;
    }
    else
    {
        ADC_Voltage_Reference_ENABLE;
    }
}


void ADC_ISR(void)
{
    #ifdef ADC_INTERRUPT_FEATURE_ENABLE
     /*Clear Flag*/
    ADC_INTERRUPT_Clear_Flag();
    /*code*/
    
    /*set call back function*/
    if(NULL == ADC_interruptHandler){}
    else{
        ADC_interruptHandler ();
    }
#endif
}