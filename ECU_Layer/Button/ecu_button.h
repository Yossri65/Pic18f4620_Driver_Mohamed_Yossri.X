/* 
 * File:   ecu_button.h
 * Author: Yossri
 *
 * Created on July 11, 2023, 4:14 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* ------------------------------------Includes--------------------------------------*/
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
/* ------------------------------------Macro Declarations--------------------------- */

/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */
typedef enum 
{
    BUTTON_RELEASED =0 ,
    BUTTON_PRESSED
}button_status_t;


typedef enum 
{
    BUTTON_ACTIVE_HIGH = 0 ,
    BUTTON_ACTIVE_LOW
}button_active_t;


typedef struct
{
    Pin_Config_t button_pin ;             /*@ref button_config_t*/
    uint8 button_status ;       /*@ref button_status_t*/
    button_active_t button_connection;    /*@ref button_active_t*/
}button_config_t;
/* ------------------------------------Software Interface Declarations-------------- */

/**
 * @brief intialize the button 
 * @param _button_  is a pointer point to configuration @ref button_config_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Button_Initialize(const button_config_t  *_button_);

Std_ReturnType Button_Read_Status(const button_config_t  *_button_ ,button_status_t *btn_status);

#endif	/* ECU_BUTTON_H */

