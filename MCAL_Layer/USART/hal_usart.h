/* 
 * File:   hal_usart.h
 * Author: Yossri
 *
 * Created on August 11, 2023, 9:01 PM
 */

#ifndef HAL_USART_H
#define	HAL_USART_H

/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../std_libraries.h"
#include "../Device_config.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "../GPIO/hal_GPIO.h"
#include "hal_usart_cfg.h"
/* ------------------------------------Macro Declarations--------------------------- */

/* Enable / Disable EUSART Module */
#define EUSART_MODULE_ENABLE   1
#define EUSART_MODULE_DISABLE  0
/* Baud Rate Generator Register Size */
#define UART_16_BIT_BUAD_RATE_GENERATOR   1
#define UART_8_BIT_BUAD_RATE_GENERATOR    0

/*EUSART Mode Select bit*/
#define EUART_SYNCHRONOUS_MODE   1
#define EUART_ASYNCHRONOUS_MODE  0

/* Baud Rate Generator Asynchronous Speed Mode */
#define EUSART_ASYNCHRONOUS_HIGH_SPEED  1
#define EUSART_ASYNCHRONOUS_LOW_SPEED  	0

/*TX enable & Disable bit*/
#define EUSART_ASYNCHRONOUS_TX_ENABLE  1
#define EUSART_ASYNCHRONOUS_TX_DISABLE 0

/* EUSART Transmit Interrupt Enable */
#define EUSART_ASYNCHRONOUS_TX_INTERRUPT_ENABLE   1
#define EUSART_ASYNCHRONOUS_TX_INTERRUPT_DISABLE  0

/*9-Bit Transmit Enable bit*/
#define EUART_ASYNCHRONOUS_TX_9BIT_ENABLE 1
#define EUART_ASYNCHRONOUS_TX_9BIT_DISABLE 0

/*TX enable & Disable bit*/
#define EUSART_ASYNCHRONOUS_RX_ENABLE  1
#define EUSART_ASYNCHRONOUS_RX_DISABLE 0

/* EUSART Transmit Interrupt Enable */
#define EUSART_ASYNCHRONOUS_RX_INTERRUPT_ENABLE  1
#define EUSART_ASYNCHRONOUS_RX_INTERRUPT_DISABLE  0

/*9-Bit Transmit Enable bit*/
#define EUART_ASYNCHRONOUS_RX_9BIT_ENABLE 1
#define EUART_ASYNCHRONOUS_RX_9BIT_DISABLE 0

/*framing error*/
#define EUART_ASYNCHRONOUS_RX_FRAMING_ERROR_SET   1
#define EUART_ASYNCHRONOUS_RX_FRAMING_ERROR_CLEAR 0

/*overrun error*/
#define EUART_ASYNCHRONOUS_RX_FRAMING_OVERRUN_SET   1
#define EUART_ASYNCHRONOUS_RX_FRAMING_OVERRUN_CLEAR 0

/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */
typedef enum
{
    BAUDRATE_ASYN_8BIT_lOW_SPEED = 0,
    BAUDRATE_ASYN_8BIT_HIGH_SPEED,
    BAUDRATE_ASYN_16BIT_lOW_SPEED,
    BAUDRATE_ASYN_16BIT_HIGH_SPEED,
    BAUDRATE_SYN_16BIT,
    BAUDRATE_SYN_8BIT,
}baudrate_gen_t;

typedef struct
{
    uint8 TX_Enable:1;
    uint8 TX_Interrupt_Enable:1;
    uint8 TX_9Bit_Enable:1;
}UART_TX_Enable_t;

typedef struct
{
    uint8 reversed:5;
    uint8 RX_Enable:1;
    uint8 RX_Interrupt_Enable:1;
    uint8 RX_9Bit_Enable:1;
}UART_RX_Enable_t;
typedef union
{
    struct
    {
        uint8 reversed:6;
        uint8 RX_FERR:1;
        uint8 RX_OERR:1;
    };
    uint8 RX_error;
}RX_Error_Status_t;

typedef struct
{
    uint32 baudrate;
    baudrate_gen_t buad_rate_gen;
    UART_TX_Enable_t UART_TX_Enable;
    UART_RX_Enable_t UART_RX_Enable;
    RX_Error_Status_t RX_Error_Status;
    interruptHandler EUSART_TxDefaultInterruptHandler;
    interruptHandler EUSART_RXDefaultInterruptHandler;
    interruptHandler EUSART_FRAMINGERRORDefaultHandler;
    interruptHandler EUSART_OVERRUNERRORDefaultHandler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    Interrupt_Priority priority ;
#endif
    uint8 sync_async_mode:1;
}USART_CONFIG_t;

/* ------------------------------------Software Interface Declarations-------------- */
Std_ReturnType USART_ASYNC_Intialization(const USART_CONFIG_t *_usart);
Std_ReturnType USART_ASYNC_DeIntialization(const USART_CONFIG_t *_usart);

Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_ReadByteNoBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_RX_Restart(void);

Std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data);
Std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data ,uint16 str_len);

Std_ReturnType EUSART_ASYNC_WriteByteNoBlocking(uint8 _data);
Std_ReturnType EUSART_ASYNC_WriteStringNoBlocking(uint8 *_data ,uint16 str_len);
#endif	/* HAL_USART_H */

