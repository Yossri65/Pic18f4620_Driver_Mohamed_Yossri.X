/* 
 * File:   ecu_relay.c
 * Author: Yossri
 *
 * Created on July 11, 2023, 9:33 PM
 */
#include "ecu_relay.h" 

/**
 * @brief intialize relay
 * @param _relay_ is pointer to point @ref Relay_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Relay_Intialize( const Relay_t *_relay_)
{
    Std_ReturnType ret = E_NOT_OK ;
    if(_relay_ == NULL)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        Pin_Config_t _pin_config =
        {
          .port =  _relay_->port_name ,
          .pin = _relay_->pin_name ,
          .logic = _relay_->relay_status ,
          .direction = Direction_Outpt 
        };
        
        ret = GPIO_Pin_Intialize(&_pin_config);
        ret = E_OK ;
    }
    return ret;
}

/**
 * @brief turn on relay
 * @param _relay_ is pointer to point @ref Relay_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Relay_Turn_On( const Relay_t *_relay_)
{
    Std_ReturnType ret = E_NOT_OK ;
    if(_relay_ == NULL)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        Pin_Config_t _pin_config =
        {
          .port =  _relay_->port_name ,
          .pin = _relay_->pin_name ,
          .logic = _relay_->relay_status ,
          .direction = Direction_Outpt 
        };
        
        ret = GPIO_Pin_Write_Logic(&_pin_config ,Logic_High);
        ret = E_OK ;
    }
    return ret;
}
/**
 * @brief turn off relay
 * @param _relay_ is pointer to point @ref Relay_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Relay_Turn_Off( const Relay_t *_relay_)
{
    Std_ReturnType ret = E_NOT_OK ;
    Logic_t logic = Logic_Low;
    if(_relay_ == NULL)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        Pin_Config_t _pin_config =
        {
          .port =  _relay_->port_name ,
          .pin = _relay_->pin_name ,
          .logic = _relay_->relay_status ,
          .direction = Direction_Outpt 
        };
        ret = GPIO_Pin_Write_Logic(&_pin_config ,logic);
        ret = E_OK ;
    }
    return ret;
}
