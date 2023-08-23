/* 
 * File:   ecu_dc_motor.c
 * Author: Yossri
 *
 * Created on July 12, 2023, 4:58 PM
 */

#include "ecu_dc_motor.h"



/**
 * @brief intialize dc motor
 * @param _dc_motor is pointer to point @ref Dc_Motor_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Dc_Motor_Intialize(const Dc_Motor_t *_dc_motor)
{
    Std_ReturnType ret = E_NOT_OK ;
    if(_dc_motor == NULL)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = GPIO_Pin_Intialize(&(_dc_motor->pin[0]));
        ret = GPIO_Pin_Intialize(&(_dc_motor->pin[1]));
        ret = E_OK ;
    }
    return ret;
}
/**
 * @brief turn dc motor right
 * @param _dc_motor is pointer to point @ref Dc_Motor_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Dc_Motor_Turn_Right(const Dc_Motor_t *_dc_motor)
{
    Std_ReturnType ret = E_NOT_OK ;
    if(_dc_motor == NULL)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = GPIO_Pin_Write_Logic(&(_dc_motor->pin[0]) ,Logic_High);
        ret = GPIO_Pin_Write_Logic(&(_dc_motor->pin[1]) ,Logic_Low);
        ret = E_OK ;
    }
    return ret;
}

/**
 * @brief turn dc motor left
 * @param _dc_motor is pointer to point @ref Dc_Motor_t
 * @return  * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Dc_Motor_Turn_Left(const Dc_Motor_t *_dc_motor)
{
    Std_ReturnType ret = E_NOT_OK ;
    if(_dc_motor == NULL)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = GPIO_Pin_Write_Logic(&(_dc_motor->pin[0]) ,Logic_Low);
        ret = GPIO_Pin_Write_Logic(&(_dc_motor->pin[1]) ,Logic_High);
        ret = E_OK ;
    }
    return ret;
}

Std_ReturnType Dc_Motor_Stop(const Dc_Motor_t *_dc_motor)
{
    Std_ReturnType ret = E_NOT_OK ;
    if(_dc_motor == NULL)
    {
        ret = E_NOT_OK ;
    }
    else
    {

        ret = GPIO_Pin_Write_Logic(&(_dc_motor->pin[0]) ,Logic_Low);
        ret = GPIO_Pin_Write_Logic(&(_dc_motor->pin[1]) ,Logic_Low);
        ret = E_OK ;
    }
    return ret;
}
