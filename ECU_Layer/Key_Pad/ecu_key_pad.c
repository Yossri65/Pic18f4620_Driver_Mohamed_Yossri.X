/* 
 * File:   ecu_key_pad.c
 * Author: Yossri
 *
 * Created on July 13, 2023, 1:24 PM
 */

#include "ecu_key_pad.h"

static const uint8 Key_Pad_Array[KEY_PAD_ROWS][KEY_PAD_COULMNS] ={{'7' ,'8' ,'9' ,'/'} ,
                                                                  {'4' ,'5' ,'6' ,'*'} , 
                                                                  {'1' ,'2' ,'3' ,'-'} ,
                                                                  {'@' ,'0' ,'=' ,'+'} };


Std_ReturnType Key_Pad_Intialize(const Key_Pad_t *_key_pad)
{
    Std_ReturnType ret = E_NOT_OK ;
    if(_key_pad == NULL)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        uint8 counter =0;
        for(counter =0 ;counter < KEY_PAD_ROWS ;counter++)
        {
            ret =GPIO_Pin_Intialize(&(_key_pad->Key_Pad_Rows[counter]));
            ret =GPIO_Pin_Intialize(&(_key_pad->Key_Pad_Coulmns[counter]));
        }
        ret = E_OK ;
    }
    return ret;
}

Std_ReturnType Key_Pad_Get_Value(const Key_Pad_t *_key_pad ,uint8 *value)
{
    Std_ReturnType ret = E_NOT_OK ;
    if(_key_pad == NULL)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        Logic_t coulmns_logic = Logic_Low;
        uint8 rows =0 ,coulmns = 0 ;
        for(rows =0 ;rows < KEY_PAD_ROWS ;rows++)
        {
            for(coulmns =0 ;coulmns < KEY_PAD_COULMNS ;coulmns++)
            {
                ret =GPIO_Pin_Write_Logic(&(_key_pad->Key_Pad_Rows[coulmns]) ,Logic_Low);
            }
            ret =GPIO_Pin_Write_Logic(&(_key_pad->Key_Pad_Rows[rows]) ,Logic_High);
            
            for(coulmns =0 ;coulmns < KEY_PAD_COULMNS ;coulmns++)
            {
                ret =GPIO_Pin_Read_Logic(&(_key_pad->Key_Pad_Coulmns[coulmns]) ,&coulmns_logic);
                if(coulmns_logic !=Logic_Low)
                {
                   *value = Key_Pad_Array[rows][coulmns] ;
                }
            }
        }
        ret = E_OK ;
    }
    return ret;
}
