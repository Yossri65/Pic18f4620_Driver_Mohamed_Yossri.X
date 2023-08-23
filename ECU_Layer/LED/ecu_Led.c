/* 
 * File:   ecu_Led.c
 * Author: Yossri
 *
 * Created on July 8, 2023, 2:18 AM
 */

#include "ecu_Led.h"

/**
 * @brief intialize the led
 * @param Led is a pointer point to configurations @ref Led_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Led_Intialize(const Led_t *Led)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == Led)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        Pin_Config_t _pin_config_ = 
        {
          .port = Led->Port_Name ,
          .pin = Led->Pin_Name ,
          .direction = Direction_Outpt ,
          .logic = Led->Led_Status 
        };
        ret = GPIO_Pin_Intialize(&_pin_config_);
    }
    return ret;
}

/**
 * @brief led turn on
 * @param Led  is a pointer point to configurations @ref   
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Led_Turn_On(const Led_t *Led)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == Led)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        Pin_Config_t _pin_config_ = 
        {
          .port = Led->Port_Name ,
          .pin = Led->Pin_Name ,
          .direction = Direction_Outpt ,
          .logic = Led->Led_Status 
        };
        ret = GPIO_Pin_Write_Logic(&_pin_config_ ,Logic_High);
    }
    return ret;
}

/**
 * @brief led turn off
 * @param Led is a pointer point to configurations @ref Led_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Led_Turn_Off(const Led_t *Led)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == Led)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        Pin_Config_t _pin_config_ = 
        {
          .port = Led->Port_Name ,
          .pin = Led->Pin_Name ,
          .direction = Direction_Outpt ,
          .logic = Led->Led_Status 
        };
        ret = GPIO_Pin_Write_Logic(&_pin_config_ ,Logic_Low);
    }
    return ret;
}

/**
 * @brief toggle led
 * @param Led is a pointer point to configurations @ref Led_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Led_Toggle(const Led_t *Led)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == Led)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        Pin_Config_t _pin_config_ = 
        {
          .port = Led->Port_Name ,
          .pin = Led->Pin_Name ,
          .direction = Direction_Outpt ,
          .logic = Led->Led_Status 
        };
        ret = GPIO_Pin_Toggle_Logic(&_pin_config_);
    }
    return ret;
}