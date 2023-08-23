/* 
 * File:   ecu_Led.h
 * Author: Yossri
 *
 * Created on July 8, 2023, 2:18 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* ------------------------------------Includes--------------------------------------*/
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"

/* ------------------------------------Macro Declarations--------------------------- */

/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */
typedef enum
{
    LED_OFF = 0,
    LED_ON
}Led_Status_t;

typedef struct 
{
    uint8 Port_Name :3 ;   /*@ref Port_Index_t*/
    uint8 Pin_Name :3 ;    /*@ref Pin_Index_t*/
    uint8 Led_Status :1;   /*@ref Led_Status_t*/
}Led_t;

/* ------------------------------------Software Interface Declarations-------------- */

/**
 * @brief intialize the led
 * @param Led is a pointer point to configurations @ref Led_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Led_Intialize(const Led_t *Led);

/**
 * @brief led turn on
 * @param Led  is a pointer point to configurations @ref   
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */

Std_ReturnType Led_Turn_On(const Led_t *Led);

/**
 * @brief led turn off
 * @param Led is a pointer point to configurations @ref Led_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Led_Turn_Off(const Led_t *Led);

/**
 * @brief toggle led
 * @param Led is a pointer point to configurations @ref Led_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Led_Toggle(const Led_t *Led);
#endif	/* ECU_LED_H */

