/* 
 * File:   mcal_adc.h
 * Author: Yossri
 *
 * Created on July 24, 2023, 6:25 PM
 */

#ifndef MCAL_ADC_H
#define	MCAL_ADC_H

/* ------------------------------------Includes--------------------------------------*/
#include "mcal_adc_cfg.h"
#include "pic18f4620.h"
#include "../Device_config.h"
#include "../GPIO/hal_GPIO.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../std_libraries.h"
/* ------------------------------------Macro Declarations--------------------------- */
#define ADC_AN0_ANALOG_FUNCTANILITY  0x0E
#define ADC_AN1_ANALOG_FUNCTANILITY  0x0D
#define ADC_AN2_ANALOG_FUNCTANILITY  0x0C
#define ADC_AN3_ANALOG_FUNCTANILITY  0x0B
#define ADC_AN4_ANALOG_FUNCTANILITY  0x0A
#define ADC_AN5_ANALOG_FUNCTANILITY  0x09
#define ADC_AN6_ANALOG_FUNCTANILITY  0x08
#define ADC_AN7_ANALOG_FUNCTANILITY  0x07
#define ADC_AN8_ANALOG_FUNCTANILITY  0x06
#define ADC_AN9_ANALOG_FUNCTANILITY  0x05
#define ADC_AN10_ANALOG_FUNCTANILITY 0x04
#define ADC_AN11_ANALOG_FUNCTANILITY 0x03
#define ADC_AN12_ANALOG_FUNCTANILITY 0x02

#define ADC_ALL_ANALOG_FUNCTANILITY  0x0F
#define ADC_ALL_DIGITAL_FUNCTANILITY 0x00


#define ADC_RIGHT_JUSTIFIED  1
#define ADC_LEFT_JUSTIFIED   0

#define ADC_VOLTAGE_REF_ENABLE            0x01U
#define ADC_VOLTAGE_REF_DISABLE           0x00U

#define ADC_CONVERSION_COMPELETE   1
#define ADC_CONVERSION_INPROGRESS  0

#define FALSE 0
#define TRUE  1
/* ------------------------------------Macro Function Declarations------------------ */
#define ADC_Converter_Enable()    (ADCON0bits.ADON = 1)
#define ADC_Converter_Disable()   (ADCON0bits.ADON = 0)

#define ACD_Read_Conversion_Status()   (ADCON0bits.GODONE)
#define ACD_Start_Conversion()         (ADCON0bits.GODONE = 1)

#define ADC_Result_Format_Right_justified()  (ADCON2bits.ADFM = 1)
#define ADC_Result_Format_Left_justified()   (ADCON2bits.ADFM = 0)


#define ADC_Voltage_Reference_ENABLE     do{ADCON1bits.VCFG0 = 1;\
                                            ADCON1bits.VCFG1 = 1;\
                                           }while(0);

#define ADC_Voltage_Reference_Disable    do{ADCON1bits.VCFG0 = 0;\
                                            ADCON1bits.VCFG1 = 0;\
                                           }while(0);

/* CONFIG MY FUCTIONALITY OF BITS */
#define ADC_BIT_CONFIGRATION_FUNCTANILITY(_CONFIG)          (ADCON1bits.PCFG = _CONFIG)
/* ------------------------------------Data Type Declarations----------------------- */
typedef enum 
{
    ADC_CHANNEL_AN0 = 0 ,
    ADC_CHANNEL_AN1 ,
    ADC_CHANNEL_AN2 ,
    ADC_CHANNEL_AN3 ,
    ADC_CHANNEL_AN4 ,
    ADC_CHANNEL_AN5 ,
    ADC_CHANNEL_AN6 ,
    ADC_CHANNEL_AN7 ,
    ADC_CHANNEL_AN8 ,
    ADC_CHANNEL_AN9 ,
    ADC_CHANNEL_AN10 ,
    ADC_CHANNEL_AN11 ,
    ADC_CHANNEL_AN12 ,
}ADC_Channel_Selection_t;

typedef enum 
{
    ADC_0_TAD = 0 ,
    ADC_2_TAD ,   
    ADC_4_TAD ,   
    ADC_6_TAD ,   
    ADC_8_TAD ,   
    ADC_12_TAD ,   
    ADC_16_TAD ,   
    ADC_20_TAD 
}ADC_Acquisition_Time_Select_t;
/*Acquisition_Time + Conversion_Clock = SAMPLING TIME*/
typedef enum 
{
    ADC_CONVERSION_CLOCK_FOSC_DIV_2 = 0,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,  
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64,
}ADC_Conversion_Clock_Select_t;

typedef struct 
{
#ifdef ADC_INTERRUPT_FEATURE_ENABLE
    interruptHandler ADC_IntterruptHandeler ;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority priority ;
#endif
#endif
    ADC_Channel_Selection_t  ADC_Channel; /* @ref ADC_Channel_Selection_t */
    ADC_Conversion_Clock_Select_t  ADC_Conversion_Clock;/* @ref ADC_Conversion_Clock_Select_t */
    ADC_Acquisition_Time_Select_t  ADC_Acquisition_Time;/* @ref ADC_Acquisition_Time_Select_t */
    uint8 voltage_ref: 1; /* voltage reference configuration */
    uint8 format_status: 1; /* Format status */
    uint8 ADC_Resreved: 6;  
}ADC_Conf_t;
/* ------------------------------------Software Interface Declarations-------------- */
Std_ReturnType ADC_Intialization(const ADC_Conf_t *adc_);

Std_ReturnType ADC_DeIntialization(const ADC_Conf_t *adc_);

Std_ReturnType ADC_Channel_Selection(const ADC_Conf_t *adc_,ADC_Channel_Selection_t channel);

Std_ReturnType ADC_Start_Conversion(const ADC_Conf_t *adc_);

Std_ReturnType ADC_Is_Conversion_Done(const ADC_Conf_t *adc_ ,uint8 *conversion_status);

Std_ReturnType ADC_Get_Conversion_Result(const ADC_Conf_t *adc_ ,uint16 *conversion_Result);

Std_ReturnType ADC_Get_Conversion_Blocking_Mode(const ADC_Conf_t *adc_ ,uint16 *conversion_Result
                                  ,ADC_Channel_Selection_t channel);
Std_ReturnType ADC_Start_Conversion_Interrupt_Mode(const ADC_Conf_t *adc_,ADC_Channel_Selection_t channel);
#endif	/* MCAL_ADC_H */

