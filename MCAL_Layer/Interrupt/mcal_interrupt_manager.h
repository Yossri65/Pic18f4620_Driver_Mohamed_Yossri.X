/* 
 * File:   mcal_interrupt_manager.h
 * Author: Yossri
 *
 * Created on July 20, 2023, 1:28 AM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* ------------------------------------Includes--------------------------------------*/
#include "mcal_interrupt_config.h"
#include "pic18f4620.h"
#include "../std_libraries.h"
#include "../Device_config.h"
#include "../GPIO/hal_GPIO.h"
/* ------------------------------------Macro Declarations--------------------------- */

/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */

/* ------------------------------------Software Interface Declarations-------------- */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void RB4_ISR(uint8 state);
void RB5_ISR(uint8 state);
void RB6_ISR(uint8 state);
void RB7_ISR(uint8 state);

void ADC_ISR(void);

void TIMER0_ISR(void);
void TIMER1_ISR(void);
void TIMER2_ISR(void);
void TIMER3_ISR(void);

void CCP1_ISR(void);
void CCP2_ISR(void);

void ECCP_ISR(void);

void USART_TX_ISR(void);
void USART_RX_ISR(void);

void SPI_ISR(void);

void MSSP_I2C_ISR(void);
void MSSP_I2C_BC_ISR(void);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

