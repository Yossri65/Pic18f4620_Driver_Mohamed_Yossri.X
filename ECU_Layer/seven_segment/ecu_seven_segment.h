/* 
 * File:   ecu_seven_segment.h
 * Author: Yossri
 *
 * Created on July 13, 2023, 2:34 AM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

/* ------------------------------------Includes--------------------------------------*/
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
/* ------------------------------------Macro Declarations--------------------------- */
#define SEG_PIN_ONE    0
#define SEG_PIN_TWO    1
#define SEG_PIN_THREE  2
#define SEG_PIN_FOUR   3

#define MASK           0x01
/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */
typedef enum 
{
    Common_Cathode = 0,
    Common_Anode
}seven_segment_type;

typedef struct
{
    Pin_Config_t segment_pin[4];
    seven_segment_type segment_type;
}Segment_t;
/* ------------------------------------Software Interface Declarations-------------- */

/**
 * @brief intialize seven segment
 * @param segment is a pointer point to configuration @ref Segment_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Segment_Intialize(const Segment_t *segment);

/**
 * @brief write number on seven segment
 * @param segment is a pointer point to configuration @ref Segment_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType Segment_Write_Number(const Segment_t *segment ,uint8 number);
#endif	/* ECU_SEVEN_SEGMENT_H */

