/* 
 * File:   ecu_button.c
 * Author: Yossri
 *
 * Created on July 11, 2023, 4:14 AM
 */
#include "ecu_button.h"

/**
 * @brief intialize the button 
 * @param _button_  is a pointer point to configuration @ref button_config_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Button_Initialize(const button_config_t  *_button_)
{
    Std_ReturnType ret = E_OK ;
    if(_button_ == NULL )
    {
        ret =E_NOT_OK;
    }
    else
    {
        ret =GPIO_Pin_Direction_Intialize(&(_button_->button_pin)); 
    }
    return ret;
}

/**
 * @brief read status of the button 
 * @param _button_  is a pointer point to configuration @ref button_config_t
 * @param btn_status is apointer point to configuration @ref button_status_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Button_Read_Status(const button_config_t  *_button_ ,button_status_t *btn_status)
{
    Std_ReturnType ret = E_OK ;
    Logic_t logic = Logic_Low ;
    if(_button_ == NULL || btn_status == NULL)
    {
        ret =E_NOT_OK;
    }
    else
    {
        ret =GPIO_Pin_Read_Logic(&(_button_->button_pin) ,&logic);
        if(BUTTON_ACTIVE_HIGH == _button_->button_connection)
        {
            if(Logic_High == logic)
            {
                *btn_status = BUTTON_PRESSED;
            }
            else
            {
                *btn_status = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == _button_->button_connection)
        {
            if(Logic_High == logic)
            {
                *btn_status = BUTTON_RELEASED;
            }
            else
            {
                *btn_status = BUTTON_PRESSED;
            }
        }
        else{ /*Nothing*/ }

    }
    return ret;
}