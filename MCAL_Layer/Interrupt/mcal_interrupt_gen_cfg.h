/* 
 * File:   mcal_interrupt_gen_cfg.h
 * Author: Yossri
 *
 * Created on July 20, 2023, 1:06 PM
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H



//#define INTERRUPT_PRIORITY_LEVELS_ENABLE

#define EXT_INTERRUPT_INTX_FEATURE_ENABLE
#define EXT_INTERRUPT_ON_CHANGE_FEATURE_ENABLE

//#define ADC_INTERRUPT_FEATURE_ENABLE

#define TIMER0_INTERRUPT_FEATURE_ENABLE

#define TIMER1_INTERRUPT_FEATURE_ENABLE

//#define TIMER2_INTERRUPT_FEATURE_ENABLE

#define TIMER3_INTERRUPT_FEATURE_ENABLE

#define CCP1_INTERRUPT_FEATURE_ENABLE
#define CCP2_INTERRUPT_FEATURE_ENABLE

#define ECCP_INTERRUPT_FEATURE_ENABLE

#define USART_TX_INTERRUPT_FEATURE_ENABLE
#define USART_RX_INTERRUPT_FEATURE_ENABLE

#define SPI_INTERRUPT_FEATURE_ENABLE
#define I2C_INTERRUPT_FEATURE_ENABLE
#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

