/* 
 * File:   mcal_internal_interrupt.h
 * Author: Yossri
 *
 * Created on July 20, 2023, 1:26 AM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* ------------------------------------Includes--------------------------------------*/
#include "mcal_interrupt_config.h"
#include "pic18f4620.h"
#include "../std_libraries.h"
#include "../Device_config.h"
/* ------------------------------------Macro Declarations--------------------------- */

/*====================================ADC====================================*/
#ifdef ADC_INTERRUPT_FEATURE_ENABLE
#define ADC_INTERRUPT_Enable()   (PIE1bits.ADIE = 1)
#define ADC_INTERRUPT_Disable()  (PIE1bits.ADIE = 0)

#define ADC_INTERRUPT_Clear_Flag()  ( PIR1bits.ADIF = 0)
/*priority feature*/
#ifdef ADC_INTERRUPT_PRIORITY_LEVELS_ENABLE

#define ADC_INTERRUPT_Priority_High()   (IPR1bits.ADIP = 1)
#define ADC_INTERRUPT_Priority_Low()    (IPR1bits.ADIP = 0)

#endif
#endif

/*====================================TIMER0====================================*/
#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE

#define TIMER0_INTERRUPT_Enable()   (INTCONbits.TMR0IE = 1)
#define TIMER0_INTERRUPT_Disable()  (INTCONbits.TMR0IE = 0)

#define TIMER0_INTERRUPT_Clear_Flag()  (INTCONbits.TMR0IF = 0)
/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define TIMER0_INTERRUPT_Priority_High()   (INTCON2bits.TMR0IP = 1)
#define TIMER0_INTERRUPT_Priority_Low()    (INTCON2bits.TMR0IP = 0)
#endif
#endif

/*====================================TIMER1====================================*/
#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE

#define TIMER1_INTERRUPT_Enable()   (PIE1bits.TMR1IE = 1)
#define TIMER1_INTERRUPT_Disable()  (PIE1bits.TMR1IE = 0)

#define TIMER1_INTERRUPT_Clear_Flag()  (PIR1bits.TMR1IF = 0)
/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define TIMER1_INTERRUPT_Priority_High()   (IPR1bits.TMR1IP = 1)
#define TIMER1_INTERRUPT_Priority_Low()    (IPR1bits.TMR1IP = 0)
#endif
#endif

/*====================================TIMER2====================================*/
#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE

#define TIMER2_INTERRUPT_Enable()   (PIE1bits.TMR2IE = 1)
#define TIMER2_INTERRUPT_Disable()  (PIE1bits.TMR2IE = 0)

#define TIMER2_INTERRUPT_Clear_Flag()  (PIR1bits.TMR2IF = 0)
/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define TIMER2_INTERRUPT_Priority_High()   (IPR1bits.TMR2IP = 1)
#define TIMER2_INTERRUPT_Priority_Low()    (IPR1bits.TMR2IP = 0)
#endif
#endif
/*====================================TIMER3====================================*/
#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE

#define TIMER3_INTERRUPT_Enable()   (PIE2bits.TMR3IE = 1)
#define TIMER3_INTERRUPT_Disable()  (PIE2bits.TMR3IE = 0)

#define TIMER3_INTERRUPT_Clear_Flag()  (PIR2bits.TMR3IF = 0)
/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define TIMER3_INTERRUPT_Priority_High()   (IPR2bits.TMR3IP = 1)
#define TIMER3_INTERRUPT_Priority_Low()    (IPR2bits.TMR3IP = 0)
#endif
#endif

/*====================================CCP1====================================*/
#ifdef CCP1_INTERRUPT_FEATURE_ENABLE

#define CCP1_INTERRUPT_Enable()   (PIE1bits.CCP1IE = 1)
#define CCP1_INTERRUPT_Disable()  (PIE1bits.CCP1IE = 0)

#define CCP1_INTERRUPT_Clear_Flag()  (PIR1bits.CCP1IF = 0)
/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define CCP1_INTERRUPT_Priority_High()   (IPR1bits.CCP1IP = 1)
#define CCP1_INTERRUPT_Priority_Low()    (IPR1bits.CCP1IP = 0)
#endif
#endif
/*====================================CCP2====================================*/
#ifdef CCP2_INTERRUPT_FEATURE_ENABLE

#define CCP2_INTERRUPT_Enable()   (PIE2bits.CCP2IE = 1)
#define CCP2_INTERRUPT_Disable()  (PIE2bits.CCP2IE = 0)

#define CCP2_INTERRUPT_Clear_Flag()  (PIR2bits.CCP2IF = 0)
/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define CCP1_INTERRUPT_Priority_High()   (IPR2bits.CCP2IP = 1)
#define CCP1_INTERRUPT_Priority_Low()    (IPR2bits.CCP2IP = 0)
#endif
#endif

/*====================================USART_TX====================================*/
#ifdef USART_TX_INTERRUPT_FEATURE_ENABLE

#define USART_TX_INTERRUPT_Enable()   (PIE1bits.TXIE = 1)
#define USART_TX_INTERRUPT_Disable()  (PIE1bits.TXIE = 0)

/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define USART_TX_INTERRUPT_Priority_High()   (IPR1bits.TXIP = 1)
#define USART_TX_INTERRUPT_Priority_Low()    (IPR1bits.TXIP = 0)
#endif
#endif

/*====================================USART_RX====================================*/
#ifdef USART_RX_INTERRUPT_FEATURE_ENABLE

#define USART_RX_INTERRUPT_Enable()   (PIE1bits.RCIE = 1)
#define USART_RX_INTERRUPT_Disable()  (PIE1bits.RCIE = 0)

/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define USART_RX_INTERRUPT_Priority_High()   (IPR1bits.RCIP = 1)
#define USART_RX_INTERRUPT_Priority_Low()    (IPR1bits.RCIP = 0)
#endif
#endif

/*====================================SPI====================================*/
#ifdef SPI_INTERRUPT_FEATURE_ENABLE

#define SPI_INTERRUPT_Enable()   (PIE1bits.SSPIE = 1)
#define SPI_INTERRUPT_Disable()  (PIE1bits.SSPIE = 0)

#define SPI_INTERRUPT_Clear_Flag()  (PIR1bits.SSPIF = 0)
/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define SPI_INTERRUPT_Priority_High()   (IPR1bits.SSPIP = 1)
#define SPI_INTERRUPT_Priority_Low()    (IPR1bits.SSPIP = 0)
#endif
#endif

/*====================================I2C====================================*/
#ifdef I2C_INTERRUPT_FEATURE_ENABLE

#define I2C_INTERRUPT_Enable()   (PIE1bits.SSPIE = 1)
#define I2C_INTERRUPT_Disable()  (PIE1bits.SSPIE = 0)

#define I2C_Bus_Col_INTERRUPT_Enable()   (PIE2bits.BCLIE = 1)
#define I2C_Bus_Col_INTERRUPT_Disable()  (PIE2bits.BCLIE = 0)

#define I2C_INTERRUPT_Clear_Flag()  (PIR1bits.SSPIF = 0)

#define I2C_Bus_Col_INTERRUPT_Clear_Flag()  (PIR2bits.BCLIF = 0)
/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define I2C_INTERRUPT_Priority_High()   (IPR1bits.SSPIP = 1)
#define I2C_INTERRUPT_Priority_Low()    (IPR1bits.SSPIP = 0)

#define I2C_Bus_Col_INTERRUPT_Priority_High()   (IPR2bits.BCLIP = 1)
#define I2C_Bus_Col_INTERRUPT_Priority_Low()    (IPR2bits.BCLIP = 0)
#endif
#endif
/* ------------------------------------Macro Function Declarations------------------ */


/* ------------------------------------Data Type Declarations----------------------- */

/* ------------------------------------Software Interface Declarations-------------- */

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

