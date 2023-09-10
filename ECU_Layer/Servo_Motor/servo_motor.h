/* 
 * File:   servo_motor.h
 * Author: Yossri
 *
 * Created on September 10, 2023, 3:02 PM
 */

#ifndef SERVO_MOTOR_H
#define	SERVO_MOTOR_H

/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../../MCAL_Layer/Device_config.h"
//#include "../GPIO/hal_GPIO.h"
#include "../../MCAL_Layer/Timer2/mcal_timer2.h" 
#include "../../MCAL_Layer/CCP1/hal_ccp.h"
/* ------------------------------------Macro Declarations--------------------------- */
#define error_rate 5
/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */

typedef struct {
    CCP_SELECTION_T ccp_selection;
}servo_cfg;
/* ------------------------------------Software Interface Declarations-------------- */
Std_ReturnType servo_motor_intialize(const servo_cfg *servo);
Std_ReturnType servo_motor_set_angle(const servo_cfg *servo , sint8 angle);
#endif	/* SERVO_MOTOR_H */

