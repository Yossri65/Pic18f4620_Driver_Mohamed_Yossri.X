/* 
 * File:   hal_spi.c
 * Author: Yossri
 *
 * Created on August 15, 2023, 11:56 AM
 */
#include "hal_spi.h"

#ifdef SPI_INTERRUPT_FEATURE_ENABLE
    interruptHandler MSSP_SPI_IntterruptHandeler = NULL;
#endif

static void MSSP_SPI_Msster_Mode_GPIO_PIN_Configurations();
static void MSSP_SPI_Slave_Mode_GPIO_PIN_Configurations(const SPI_Config *_SPI_);

static void MSSP_SPI_Interrupt_ModeN_Configurations(const SPI_Config *_SPI_);

Std_ReturnType SPI_Init(const SPI_Config *_SPI_)
{
    Std_ReturnType ret = E_OK;
    if(_SPI_ == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        SPI_DISABLE_MODULE();
        /*spi set mode*/
        SSPCON1bits.SSPM = _SPI_->spi_serial_clk_mod_select;
        
        if(SPI_MASTER_FOSC_DIV4 == _SPI_->spi_serial_clk_mod_select ||
                SPI_MASTER_FOSC_DIV16 == _SPI_->spi_serial_clk_mod_select ||
                SPI_MASTER_FOSC_DIV64 == _SPI_->spi_serial_clk_mod_select ||
                SPI_MASTER_FOSC_TMR2  == _SPI_->spi_serial_clk_mod_select)
        {
            MSSP_SPI_Msster_Mode_GPIO_PIN_Configurations();
        }
        else if(SPI_SLAVE_SS_ENABLE ==  _SPI_->spi_serial_clk_mod_select || 
                SPI_SLAVE_SS_DISABLE == _SPI_->spi_serial_clk_mod_select)
        {
            MSSP_SPI_Slave_Mode_GPIO_PIN_Configurations(_SPI_);
        }else{/*Nothing*/}
        /* Clock Polarity Select */
        SSPCON1bits.CKP = _SPI_->spi_control.ClockPolarity;
        /* SPI Clock Select */
        SSPSTATbits.CKE = _SPI_->spi_control.ClockSelect;
        /* SPI Sample Select */
        SSPSTATbits.SMP = _SPI_->spi_control.SampleSelect;
#ifdef SPI_INTERRUPT_FEATURE_ENABLE
        MSSP_SPI_Interrupt_ModeN_Configurations(_SPI_);
#endif
        SPI_ENABLE_MODULE();
    }
}

Std_ReturnType SPI_DeInit(const SPI_Config *_SPI_)
{
    Std_ReturnType ret = E_OK;
    if(_SPI_ == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        /* Disable SPI Module */
        SPI_DISABLE_MODULE();
/* Interrupt Configurations */        
#ifdef SPI_INTERRUPT_FEATURE_ENABLE
        SPI_INTERRUPT_Disable();
#endif
    }
}

Std_ReturnType SPI_Send_Byte( const uint8 _data)
{
    Std_ReturnType ret = E_OK;
    SSPBUF = _data;
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF = 0;
}
Std_ReturnType SPI_SendString(uint8 *_data ,uint16 str_len)
{
    uint16 str_count =0;
    for(str_count = 0 ;str_count <str_len ;str_count++)
    {
        SPI_Send_Byte(_data[str_count]);
    }
}

Std_ReturnType SPI_Read_Byte(const SPI_Config *_SPI_, uint8 *_data)
{
    Std_ReturnType ret = E_OK;
    if(_SPI_ == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        while(!SSPSTATbits.BF);
        *_data = SSPBUF ;
    }
}

Std_ReturnType SPI_Send_Byte_NonBlocking(const SPI_Config *_SPI_, const uint8 _data)
{
    Std_ReturnType ret = E_OK;
    if(_SPI_ == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType SPI_Read_Byte_NonBlocking(const SPI_Config *_SPI_, uint8 *_data)
{
    Std_ReturnType ret = E_OK;
    if(_SPI_ == NULL) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
}

static void MSSP_SPI_Msster_Mode_GPIO_PIN_Configurations()
{
    Std_ReturnType ret = E_NOT_OK;
    Pin_Config_t SPI_SDO = {.port = PortC_Index ,.pin = pin5 ,.direction = Direction_Outpt}; 
    Pin_Config_t SPI_SDI = {.port = PortC_Index ,.pin = pin4 ,.direction = Direction_input}; 
    Pin_Config_t SPI_SCK = {.port = PortC_Index ,.pin = pin3 ,.direction = Direction_Outpt}; 
    
    ret = GPIO_Pin_Direction_Intialize(&SPI_SDO);
    ret = GPIO_Pin_Direction_Intialize(&SPI_SDI);
    ret = GPIO_Pin_Direction_Intialize(&SPI_SCK);
}

static void MSSP_SPI_Slave_Mode_GPIO_PIN_Configurations(const SPI_Config *_SPI_)
{
    Std_ReturnType ret = E_NOT_OK;
    Pin_Config_t SPI_SDO = {.port = PortC_Index ,.pin = pin5 ,.direction = Direction_Outpt}; 
    Pin_Config_t SPI_SDI = {.port = PortC_Index ,.pin = pin4 ,.direction = Direction_input}; 
    Pin_Config_t SPI_SCK = {.port = PortC_Index ,.pin = pin3 ,.direction = Direction_input}; 
    Pin_Config_t SPI_SS = {.port = PortA_Index ,.pin = pin5 ,.direction = Direction_input}; 
    
    ret = GPIO_Pin_Direction_Intialize(&SPI_SDO);
    ret = GPIO_Pin_Direction_Intialize(&SPI_SDI);
    ret = GPIO_Pin_Direction_Intialize(&SPI_SCK);  
    ret = GPIO_Pin_Direction_Intialize(&SPI_SCK);
    
     if(SPI_SLAVE_SS_ENABLE == _SPI_->spi_serial_clk_mod_select){
        ret = GPIO_Pin_Direction_Intialize(&SPI_SS);
    }
}

static void MSSP_SPI_Interrupt_ModeN_Configurations(const SPI_Config *_SPI_)
{
    SPI_INTERRUPT_Enable();
    SPI_INTERRUPT_Clear_Flag();
    MSSP_SPI_IntterruptHandeler = _SPI_->SPI_IntterruptHandeler;
    
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
    INTERRUPT_PriorityLevelsEnable();
    if(High_Priority == _SPI_->priority)
    {
        INTERRUPT_HighPriorityEnable();
        SPI_INTERRUPT_Priority_High();
    }
    else if(Low_Priority == _SPI_->priority)
    {
        INTERRUPT_LowPriorityEnable();
        SPI_INTERRUPT_Priority_Low();
    }else{/*Nothing*/}
#else
    INTERRUPT_AllInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
#endif

}

void SPI_ISR(void)
{
#ifdef SPI_INTERRUPT_FEATURE_ENABLE
    SPI_INTERRUPT_Clear_Flag();
    if(MSSP_SPI_IntterruptHandeler){
        MSSP_SPI_IntterruptHandeler();
    }
#endif
}