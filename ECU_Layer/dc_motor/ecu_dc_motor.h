/* 
 * File:   ecu_dc_motor.h
 * Author: Yossri
 *
 * Created on July 12, 2023, 4:58 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* ------------------------------------Includes--------------------------------------*/
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
/* ------------------------------------Macro Declarations--------------------------- */

/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */
typedef enum
{
    MOTOR_OFF =0 ,
    MOTOR_ON
}Dc_Motor_Status_t;

typedef struct 
{
    Pin_Config_t pin[2];
}Dc_Motor_t;
/* ------------------------------------Software Interface Declarations-------------- */

/**
 * @brief intialize dc motor
 * @param _dc_motor is pointer to point @ref Dc_Motor_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Dc_Motor_Intialize(const Dc_Motor_t *_dc_motor);



/**
 * @brief turn dc motor right
 * @param _dc_motor is pointer to point @ref Dc_Motor_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Dc_Motor_Turn_Right(const Dc_Motor_t *_dc_motor);


/**
 * @brief turn dc motor left
 * @param _dc_motor is pointer to point @ref Dc_Motor_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Dc_Motor_Turn_Left(const Dc_Motor_t *_dc_motor);


/**
 * @brief stop dc motor
 * @param _dc_motor is pointer to point @ref Dc_Motor_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Dc_Motor_Stop(const Dc_Motor_t *_dc_motor);
#endif	/* ECU_DC_MOTOR_H */

