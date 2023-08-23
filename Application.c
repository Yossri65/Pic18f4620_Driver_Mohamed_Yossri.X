/* 
 * File:   Application.c
 * Author: Yossri
 *
 * Created on July 7, 2023, 8:09 PM
 */ 
#include <builtins.h>

#include "Application.h"
Std_ReturnType ret = E_NOT_OK;
void intialization (void);
uint8 slave_ack; 

void send_data_to_slave(uint8 slave_add , uint8 data);
void MSSP_I2C_Read_1_Byte(uint8 slave_add, uint8 *_data);


mssp_i2c_t i2c_obj=
{
  .i2c_clock =100000 ,
  .i2c_cfg.i2c_mode_cfg = I2C_MASTER_MODE_DEFINED_CLOCK,
  .i2c_cfg.i2c_mode = I2C_MSSP_MASTER_MODE ,
  .i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE,
  .i2c_cfg.i2c_SMBus_control = I2C_SMBus_DISABLE ,
  .I2C_DefaultInterruptHandler = NULL
};

int main(void) {
    intialization();
    ret = MSSP_I2C_Master_Send_Start(&i2c_obj);
    ret = MSSP_I2C_Master_Write_Blocking(&i2c_obj ,'a' ,&slave_ack);
    ret = MSSP_I2C_Master_Send_Stop(&i2c_obj);
    while(1)
    {
        
    }
    return (EXIT_SUCCESS);
}

void intialization (void)
{
    ecu_intialize( );
    ret = MSSP_I2C_Init(&i2c_obj);
}
void send_data_to_slave(uint8 slave_add , uint8 data)
{
    ret = MSSP_I2C_Master_Send_Start(&i2c_obj);
    ret = MSSP_I2C_Master_Write_Blocking(&i2c_obj ,slave_add ,&slave_ack);
    ret = MSSP_I2C_Master_Write_Blocking(&i2c_obj ,data ,&slave_ack);
    ret = MSSP_I2C_Master_Send_Stop(&i2c_obj);
}
void MSSP_I2C_Read_1_Byte(uint8 slave_add, uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    ret = MSSP_I2C_Master_Send_Start(&i2c_obj);
    ret = MSSP_I2C_Master_Write_Blocking(&i2c_obj, slave_add, &slave_ack);
    ret = MSSP_I2C_Master_Read_Blocking(&i2c_obj, I2C_MASTER_SEND_NACK, _data);
    ret = MSSP_I2C_Master_Send_Stop(&i2c_obj);
}