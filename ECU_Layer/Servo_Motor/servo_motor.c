/* 
 * File:   servo_motor.c
 * Author: Yossri
 *
 * Created on September 10, 2023, 3:02 PM
 */
#include "servo_motor.h"
#ifdef CCP_PWM_Mode

Std_ReturnType servo_motor_intialize(const servo_cfg *servo){
    Std_ReturnType ret = E_OK;
    if (servo == NULL) {
      ret = E_NOT_OK;
    } else {
        Timer2_conf_t timer_2={
       .Postscaler_Select = TIMER2_POSTSCALER_DIV_BY_1,
       .Prescaler_Select = TIMER2_PRESCALER_DIV_BY_16,
       .TIMER2_PRE_LOAD_VALUE = 0,

     };
        ret = Timer2_Intialization(&timer_2);
        if(servo->ccp_selection == CCP1_SELECT){
               CCP_config_t PWM ={
             .CCP1_IntterruptHandeler = NULL ,
             .CCP_Mode = CCP_PWM_Mode_Select , 
             .CCP_Select = CCP1_SELECT , 
             .ccp_mode_varient = CCP_PWM_Mode_ ,
             .CCP_pin.port = PortC_Index ,

             .CCP_pin.direction = Direction_Outpt ,
             .CCP_pin.pin = pin2 ,
             .PWM_Frequncy = 50,
             .Postscaler_Select = CCP_POSTSCALER_DIV_BY_1  ,
             .Prescaler_Select = CCP_PRESCALER_DIV_BY_16
            };
               ret = CCP_intialize(&PWM);
        }else{
          CCP_config_t PWM ={
         .CCP1_IntterruptHandeler = NULL ,
         .CCP_Mode = CCP_PWM_Mode_Select , 
         .CCP_Select = CCP2_SELECT , 
         .ccp_mode_varient = CCP_PWM_Mode_ ,
         .CCP_pin.port = PortC_Index ,

         .CCP_pin.direction = Direction_Outpt ,
         .CCP_pin.pin = pin1 ,
         .PWM_Frequncy = 50,
         .Postscaler_Select = CCP_POSTSCALER_DIV_BY_1 ,
         .Prescaler_Select = CCP_PRESCALER_DIV_BY_16

        };
          ret = CCP_intialize(&PWM);
        }
        
        
    }
    return ret;
}
Std_ReturnType servo_motor_set_angle(const servo_cfg *servo , sint8 angle){
    Std_ReturnType ret = E_OK;
    float _duty = 0;
    uint8 range_of_angle = 180;
    float range = 1; /*range in ms*/
    float rate = 0;
    float T_on = 0;
    if (servo == NULL) {
      ret = E_NOT_OK;
    } else {
        if(servo->ccp_selection == CCP1_SELECT){
               CCP_config_t PWM ={
             .CCP1_IntterruptHandeler = NULL ,
             .CCP_Mode = CCP_PWM_Mode_Select , 
             .CCP_Select = CCP1_SELECT , 
             .ccp_mode_varient = CCP_PWM_Mode_ ,
             .CCP_pin.port = PortC_Index ,

             .CCP_pin.direction = Direction_Outpt ,
             .CCP_pin.pin = pin2 ,
             .PWM_Frequncy = 50,
             .Postscaler_Select = CCP_POSTSCALER_DIV_BY_1  ,
             .Prescaler_Select = CCP_PRESCALER_DIV_BY_16
            };
            rate = ((angle + error_rate) + 90) / (float)range_of_angle;
            T_on = (rate /(float) range) + 1;/* +1 to make the range between 1 --> 2*/
            _duty = (T_on / (float)20) * 100;
            ret = CCP_PWM_Set_Duty(&PWM , _duty );
            ret = CCP_PWM_Start(&PWM);
        }else{
          CCP_config_t PWM ={
         .CCP1_IntterruptHandeler = NULL ,
         .CCP_Mode = CCP_PWM_Mode_Select , 
         .CCP_Select = CCP2_SELECT , 
         .ccp_mode_varient = CCP_PWM_Mode_ ,
         .CCP_pin.port = PortC_Index ,

         .CCP_pin.direction = Direction_Outpt ,
         .CCP_pin.pin = pin1 ,
         .PWM_Frequncy = 50,
         .Postscaler_Select = CCP_POSTSCALER_DIV_BY_1 ,
         .Prescaler_Select = CCP_PRESCALER_DIV_BY_16

        };
        rate = (angle + 90) / (float)range_of_angle;
            T_on = (rate /(float) range) + 1;
            _duty = (T_on / (float)20) * 100;
            ret = CCP_PWM_Set_Duty(&PWM , _duty);
            ret = CCP_PWM_Start(&PWM);
        }
       
    }
}

#endif