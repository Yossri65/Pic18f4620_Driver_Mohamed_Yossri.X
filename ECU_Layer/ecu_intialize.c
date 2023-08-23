/* 
 * File:   ecu_intialize.c
 * Author: Yossri
 *
 * Created on July 13, 2023, 5:35 PM
 */

#include "ecu_intialize.h"


Key_Pad_t key_pad1 =
{
  .Key_Pad_Rows[0].port = PortD_Index ,
  .Key_Pad_Rows[0].pin = pin0 ,
  .Key_Pad_Rows[0].logic = Logic_Low ,
  .Key_Pad_Rows[0].direction = Direction_Outpt ,
  
    .Key_Pad_Rows[1].port = PortD_Index ,
  .Key_Pad_Rows[1].pin = pin1 ,
  .Key_Pad_Rows[1].logic = Logic_Low ,
  .Key_Pad_Rows[1].direction = Direction_Outpt ,
  
    .Key_Pad_Rows[2].port = PortD_Index ,
  .Key_Pad_Rows[2].pin = pin2 ,
  .Key_Pad_Rows[2].logic = Logic_Low ,
  .Key_Pad_Rows[2].direction = Direction_Outpt ,
  
    .Key_Pad_Rows[3].port = PortD_Index ,
  .Key_Pad_Rows[3].pin = pin3 ,
  .Key_Pad_Rows[3].logic = Logic_Low ,
  .Key_Pad_Rows[3].direction = Direction_Outpt ,

    .Key_Pad_Coulmns[0].port = PortD_Index ,
  .Key_Pad_Coulmns[0].pin = pin4 ,
  .Key_Pad_Coulmns[0].logic = Logic_Low ,
  .Key_Pad_Coulmns[0].direction = Direction_input ,
  
    .Key_Pad_Coulmns[1].port = PortD_Index ,
  .Key_Pad_Coulmns[1].pin = pin5 ,
  .Key_Pad_Coulmns[1].logic = Logic_Low ,
  .Key_Pad_Coulmns[1].direction = Direction_input ,
  
    .Key_Pad_Coulmns[2].port = PortD_Index ,
  .Key_Pad_Coulmns[2].pin = pin6 ,
  .Key_Pad_Coulmns[2].logic = Logic_Low ,
  .Key_Pad_Coulmns[2].direction = Direction_input ,
  
    .Key_Pad_Coulmns[3].port = PortD_Index ,
  .Key_Pad_Coulmns[3].pin = pin7 ,
  .Key_Pad_Coulmns[3].logic = Logic_Low ,
  .Key_Pad_Coulmns[3].direction = Direction_input ,
};



Ch_LCD lcd1 =
{
  .RS.port =PortC_Index ,
  .RS.pin = pin0,
  .RS.logic =Logic_Low ,
  .RS.direction = Direction_Outpt ,
  .EN.port =PortC_Index ,
  .EN.pin = pin1,
  .EN.logic =Logic_Low ,
  .EN.direction = Direction_Outpt ,
  
  .data_pin[0].port = PortC_Index ,
  .data_pin[0].pin = pin2 ,
  .data_pin[0].logic =Logic_Low ,
  .data_pin[0].direction = Direction_Outpt ,
  
  .data_pin[1].port = PortC_Index ,
  .data_pin[1].pin = pin3 ,
  .data_pin[1].logic =Logic_Low ,
  .data_pin[1].direction = Direction_Outpt ,
  
  .data_pin[2].port = PortC_Index ,
  .data_pin[2].pin = pin4 ,
  .data_pin[2].logic =Logic_Low ,
  .data_pin[2].direction = Direction_Outpt ,
  
  .data_pin[3].port = PortC_Index ,
  .data_pin[3].pin = pin5 ,
  .data_pin[3].logic =Logic_Low ,
  .data_pin[3].direction = Direction_Outpt ,
  
  
};




Std_ReturnType ecu_intialize()
{
    Std_ReturnType ret =E_NOT_OK;
    //ret = Led_Intialize(&led1);
    ret = lcd_intialize(&lcd1);
    ret = Key_Pad_Intialize(&key_pad1);
    
    return ret;
}