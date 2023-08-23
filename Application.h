/* 
 * File:   Application.h
 * Author: Yossri
 *
 * Created on July 7, 2023, 8:08 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/* ------------------------------------Includes--------------------------------------*/
#include "ECU_Layer/ecu_intialize.h"
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"
#include "MCAL_Layer/Interrupt/mcal_internal_interrupt.h"
#include "MCAL_Layer/EEPROM/mcal_eeprom.h"
#include "MCAL_Layer/MCAL_ADC/mcal_adc.h"

#include "MCAL_Layer/Timer0/mcal_timer0.h"
#include "MCAL_Layer/Timer1/mcal_timer1.h"
#include "MCAL_Layer/Timer2/mcal_timer2.h"
#include "MCAL_Layer/Timer3/mcal_timer3.h"
#include "MCAL_Layer/CCP1/hal_ccp.h"
#include "MCAL_Layer/ECCP/hal_eccp.h"
#include "MCAL_Layer/USART/hal_usart.h"
#include "MCAL_Layer/SPI/hal_spi.h"
#include "MCAL_Layer/I2C/hal_i2c.h"
/* ------------------------------------Macro Declarations--------------------------- */
/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */
extern Ch_LCD lcd1;
extern Key_Pad_t key_pad1;
/* ------------------------------------Software Interface Declarations-------------- */



#endif	/* APPLICATION_H */

