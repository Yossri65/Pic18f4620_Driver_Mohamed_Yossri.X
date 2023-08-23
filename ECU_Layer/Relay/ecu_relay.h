/* 
 * File:   ecu_relay.h
 * Author: Yossri
 *
 * Created on July 11, 2023, 9:33 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* ------------------------------------Includes--------------------------------------*/
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
/* ------------------------------------Macro Declarations--------------------------- */

/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */
typedef enum
{
    RELAY_OFF =0 ,
    RELAY_ON
}Relay_Status_t;

typedef struct
{
    uint8 port_name ;
    uint8 pin_name;
    Relay_Status_t relay_status ; 
}Relay_t;
/* ------------------------------------Software Interface Declarations-------------- */

/**
 * @brief intialize relay
 * @param _relay_ is pointer to point @ref Relay_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Relay_Intialize( const Relay_t *_relay_);

/**
 * @brief turn on relay
 * @param _relay_ is pointer to point @ref Relay_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Relay_Turn_On( const Relay_t *_relay_);

/**
 * @brief turn off relay
 * @param _relay_ is pointer to point @ref Relay_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Relay_Turn_Off( const Relay_t *_relay_);
#endif	/* ECU_RELAY_H */

