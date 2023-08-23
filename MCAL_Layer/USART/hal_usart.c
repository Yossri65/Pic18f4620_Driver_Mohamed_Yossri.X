/* 
 * File:   hal_usart.c
 * Author: Yossri
 *
 * Created on August 11, 2023, 9:01 PM
 */
#include "hal_usart.h"

#ifdef USART_TX_INTERRUPT_FEATURE_ENABLE
   interruptHandler USART_TX_IntterruptHandeler_ = NULL;
#endif
#ifdef USART_RX_INTERRUPT_FEATURE_ENABLE
   interruptHandler USART_RX_IntterruptHandeler_ = NULL;
   interruptHandler EUSART_FRAMINGERRORDefaultHandler_ = NULL;
   interruptHandler EUSART_OVERRUNERRORDefaultHandler_ = NULL;
#endif
static void EUSART_Baud_Rate_Calculation(const USART_CONFIG_t *_usart);
static void EUSART_ASYNC_TX_CONFIG(const USART_CONFIG_t *_usart);
static void EUSART_ASYNC_RX_CONFIG(const USART_CONFIG_t *_usart);

Std_ReturnType USART_ASYNC_Intialization(const USART_CONFIG_t *_usart)
{
    Std_ReturnType ret = E_OK;
    if(_usart == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE;
        EUSART_Baud_Rate_Calculation(_usart);
        EUSART_ASYNC_TX_CONFIG(_usart);
        EUSART_ASYNC_RX_CONFIG(_usart);
        TRISCbits.RC7 = 1 ;
        TRISCbits.RC6 = 1 ;
        RCSTAbits.SPEN = EUSART_MODULE_ENABLE;
    }
    return ret;
}
Std_ReturnType USART_ASYNC_DeIntialization(const USART_CONFIG_t *_usart)
{
    Std_ReturnType ret = E_OK;
    if(_usart == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE;
    }
    return ret;
}

Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data)
{
    Std_ReturnType ret = E_OK;
    if(_data == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        while(!PIR1bits.RC1IF);
        *_data = RCREG;
    }
    return ret;
}
Std_ReturnType EUSART_ASYNC_ReadByteNoBlocking(uint8 *_data)
{
    Std_ReturnType ret = E_OK;
    if(1 == PIR1bits.RC1IF) 
    {
        *_data = RCREG;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}
Std_ReturnType EUSART_ASYNC_RX_Restart(void){
    Std_ReturnType ret = E_OK;
    RCSTAbits.CREN = 0; /* Disables receiver */
    RCSTAbits.CREN = 1; /* Enables receiver */
    return ret;
}

Std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data)
{
    Std_ReturnType ret = E_OK;
    while(!TXSTAbits.TRMT);
#ifdef USART_TX_INTERRUPT_FEATURE_ENABLE
    PIE1bits.TXIE = EUSART_ASYNCHRONOUS_TX_INTERRUPT_ENABLE;
#endif
    TXREG = _data;
    return ret;
}
Std_ReturnType EUSART_ASYNC_WriteStringBlocking(uint8 *_data ,uint16 str_len)
{
    uint16 str_count =0;
    for(str_count = 0 ;str_count <str_len ;str_count++)
    {
        EUSART_ASYNC_WriteByteBlocking(_data[str_count]);
    }
}

Std_ReturnType EUSART_ASYNC_WriteByteNoBlocking(uint8 _data)
{
    Std_ReturnType ret = E_OK;
    if(1 == TXSTAbits.TRMT) 
    {
#ifdef USART_TX_INTERRUPT_FEATURE_ENABLE
        PIE1bits.TXIE = EUSART_ASYNCHRONOUS_TX_INTERRUPT_ENABLE;
#endif
        TXREG = _data;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}
Std_ReturnType EUSART_ASYNC_WriteStringNoBlocking(uint8 *_data ,uint16 str_len)
{
    Std_ReturnType ret = E_OK;
    uint16 str_count =0;
    for(str_count = 0 ;str_count <str_len ;str_count++)
    {
        EUSART_ASYNC_WriteByteNoBlocking(_data[str_count]);
    }
   return ret;
}

static void EUSART_Baud_Rate_Calculation(const USART_CONFIG_t *_usart)
{
    float baudrate_temp =0; 
    switch(_usart->buad_rate_gen)
    {
        case BAUDRATE_ASYN_8BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = UART_8_BIT_BUAD_RATE_GENERATOR;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            baudrate_temp = ((_XTAL_FREQ /(float)_usart->baudrate)/64) - 1;
        break;
        case BAUDRATE_ASYN_8BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = UART_8_BIT_BUAD_RATE_GENERATOR;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            baudrate_temp = ((_XTAL_FREQ /(float)_usart->baudrate)/16.0) - 1;
            
        break;
        case BAUDRATE_ASYN_16BIT_lOW_SPEED :
            TXSTAbits.SYNC = EUART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = UART_16_BIT_BUAD_RATE_GENERATOR;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            baudrate_temp = ((_XTAL_FREQ /(float)_usart->baudrate)/16.0) - 1;
        break;
        case BAUDRATE_ASYN_16BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUART_ASYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = UART_8_BIT_BUAD_RATE_GENERATOR;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            baudrate_temp = ((_XTAL_FREQ /(float)_usart->baudrate)/4) - 1;
        break;
        case BAUDRATE_SYN_16BIT:
            TXSTAbits.SYNC = EUART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = UART_16_BIT_BUAD_RATE_GENERATOR;
            baudrate_temp = ((_XTAL_FREQ /(float)_usart->baudrate)/4) - 1;
        break;
        case BAUDRATE_SYN_8BIT:
            TXSTAbits.SYNC = EUART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = UART_8_BIT_BUAD_RATE_GENERATOR;
            baudrate_temp = ((_XTAL_FREQ /(float)_usart->baudrate)/4) - 1;
        break;
        default : ; 
    }
    SPBRG =  (uint8)((uint32)baudrate_temp);
    SPBRGH = (uint8)(((uint32)baudrate_temp) >> 8);
}

static void EUSART_ASYNC_TX_CONFIG(const USART_CONFIG_t *_usart)
{
    if(EUSART_ASYNCHRONOUS_TX_ENABLE == _usart->UART_TX_Enable.TX_Enable)
    {
        TXSTAbits.TXEN = EUSART_ASYNCHRONOUS_TX_ENABLE;
        if(EUSART_ASYNCHRONOUS_TX_INTERRUPT_ENABLE == _usart->UART_TX_Enable.TX_Interrupt_Enable)
        {
            PIE1bits.TXIE = EUSART_ASYNCHRONOUS_TX_INTERRUPT_ENABLE;
    #ifdef USART_TX_INTERRUPT_FEATURE_ENABLE
            /*USART_TX interrupt Enable*/
            USART_TX_INTERRUPT_Enable();

            USART_TX_IntterruptHandeler_ = _usart->EUSART_TxDefaultInterruptHandler;
    #ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
            if(High_Priority == _usart->priority)
            {
                INTERRUPT_HighPriorityEnable();
                USART_TX_INTERRUPT_Priority_High();
            }
            else if(Low_Priority == timer0_->priority)
            {
                INTERRUPT_LowPriorityEnable();
                USART_TX_INTERRUPT_Priority_Low();
            }
            else{/*Nothing*/}
    #else
            INTERRUPT_AllInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
    #endif
    #endif
            
        }else if(EUSART_ASYNCHRONOUS_TX_INTERRUPT_DISABLE == _usart->UART_TX_Enable.TX_Interrupt_Enable)
        {
            PIE1bits.TXIE = EUSART_ASYNCHRONOUS_TX_INTERRUPT_DISABLE;
        }else{/*Nothing*/}
        
        if(EUART_ASYNCHRONOUS_TX_9BIT_ENABLE == _usart->UART_TX_Enable.TX_9Bit_Enable)
        {
            TXSTAbits.TX9 = EUART_ASYNCHRONOUS_TX_9BIT_ENABLE;
            
        }else if(EUART_ASYNCHRONOUS_TX_9BIT_DISABLE == _usart->UART_TX_Enable.TX_9Bit_Enable)
        {
            TXSTAbits.TX9 = EUART_ASYNCHRONOUS_TX_9BIT_DISABLE;
            
        }else{/*Nothing*/}
        
    }else{/*Nothing*/}
}
static void EUSART_ASYNC_RX_CONFIG(const USART_CONFIG_t *_usart)
{
    if(EUSART_ASYNCHRONOUS_RX_ENABLE == _usart->UART_RX_Enable.RX_Enable)
    {
        RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_ENABLE;
        if(EUSART_ASYNCHRONOUS_RX_INTERRUPT_ENABLE == _usart->UART_RX_Enable.RX_Interrupt_Enable)
        {
            PIE1bits.RCIE = EUSART_ASYNCHRONOUS_RX_INTERRUPT_ENABLE;
            #ifdef USART_RX_INTERRUPT_FEATURE_ENABLE
            /*USART_RX interrupt Enable*/
            USART_RX_INTERRUPT_Enable();

            USART_RX_IntterruptHandeler_ = _usart->EUSART_RXDefaultInterruptHandler;
            EUSART_FRAMINGERRORDefaultHandler_ =  _usart->EUSART_FRAMINGERRORDefaultHandler;
            EUSART_OVERRUNERRORDefaultHandler_ =  _usart->EUSART_OVERRUNERRORDefaultHandler;
            
    #ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
            if(High_Priority == _usart->priority)
            {
                INTERRUPT_HighPriorityEnable();
                USART_RX_INTERRUPT_Priority_High();
            }
            else if(Low_Priority == timer0_->priority)
            {
                INTERRUPT_LowPriorityEnable();
                USART_RX_INTERRUPT_Priority_Low();
            }
            else{/*Nothing*/}
    #else
            INTERRUPT_AllInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
    #endif
    #endif
            
        }else if(EUSART_ASYNCHRONOUS_RX_INTERRUPT_DISABLE == _usart->UART_RX_Enable.RX_Interrupt_Enable)
        {
            PIE1bits.RCIE = EUSART_ASYNCHRONOUS_RX_INTERRUPT_DISABLE;
        }else{/*Nothing*/}
        
        if(EUART_ASYNCHRONOUS_RX_9BIT_ENABLE == _usart->UART_RX_Enable.RX_9Bit_Enable)
        {
            RCSTAbits.RX9 = EUART_ASYNCHRONOUS_RX_9BIT_ENABLE;
            
        }else if(EUART_ASYNCHRONOUS_RX_9BIT_DISABLE == _usart->UART_RX_Enable.RX_9Bit_Enable)
        {
            RCSTAbits.RX9 = EUART_ASYNCHRONOUS_RX_9BIT_DISABLE;
            
        }else{/*Nothing*/}
        
    }else{/*Nothing*/}
}

void USART_TX_ISR(void)
{
#ifdef USART_TX_INTERRUPT_FEATURE_ENABLE
    /*set call back function*/
    PIE1bits.TXIE = EUSART_ASYNCHRONOUS_TX_INTERRUPT_DISABLE;
    if(NULL == USART_TX_IntterruptHandeler_){}
    else{
        USART_TX_IntterruptHandeler_();
    }
#endif
}
void USART_RX_ISR(void)
{
#ifdef USART_RX_INTERRUPT_FEATURE_ENABLE
    /*set call back function*/
    if(NULL == USART_RX_IntterruptHandeler_){}
    else{
        USART_RX_IntterruptHandeler_ ();
    }
    if(NULL == EUSART_FRAMINGERRORDefaultHandler_){}
    else{
        EUSART_FRAMINGERRORDefaultHandler_ ();
    }
    if(NULL == EUSART_OVERRUNERRORDefaultHandler_){}
    else{
        EUSART_OVERRUNERRORDefaultHandler_ ();
    }
#endif
}