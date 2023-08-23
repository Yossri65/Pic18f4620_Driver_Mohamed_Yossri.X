/* 
 * File:   ecu_seven_segment.c
 * Author: Yossri
 *
 * Created on July 13, 2023, 2:34 AM
 */

#include "ecu_seven_segment.h"

/**
 * @brief intialize seven segment
 * @param segment is a pointer point to configuration @ref Segment_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */

Std_ReturnType Segment_Intialize(const Segment_t *segment)
{
       Std_ReturnType ret = E_OK ;
    if(NULL == segment)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        ret = GPIO_Pin_Intialize(&(segment->segment_pin[SEG_PIN_ONE]));
        ret = GPIO_Pin_Intialize(&(segment->segment_pin[SEG_PIN_TWO]));
        ret = GPIO_Pin_Intialize(&(segment->segment_pin[SEG_PIN_THREE]));
        ret = GPIO_Pin_Intialize(&(segment->segment_pin[SEG_PIN_FOUR])); 
    }
    return ret;
}

/**
 * @brief write number on seven segment
 * @param segment is a pointer point to configuration @ref Segment_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Segment_Write_Number(const Segment_t *segment ,uint8 number)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == segment || number >9)
    {
        ret = E_NOT_OK;
    }
    else 
    {                                                                          // 0101
        ret = GPIO_Pin_Write_Logic(&(segment->segment_pin[SEG_PIN_ONE]) ,(number & MASK));  // i want pin 0 mask by & operator  
        ret = GPIO_Pin_Write_Logic(&(segment->segment_pin[SEG_PIN_TWO]) ,((number >>1) & MASK));                
        ret = GPIO_Pin_Write_Logic(&(segment->segment_pin[SEG_PIN_THREE]) ,((number >>2) & MASK));
        ret = GPIO_Pin_Write_Logic(&(segment->segment_pin[SEG_PIN_FOUR]) ,((number >>3) & MASK)); 
    }
    return ret;
}