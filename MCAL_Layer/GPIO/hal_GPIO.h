/* 
 * File:   hal_GPIO.h
 * Author: Yossri
 *
 * Created on July 8, 2023, 2:08 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../std_libraries.h"
#include "../Device_config.h"

/* ------------------------------------Macro Declarations--------------------------- */
#define BIT_MASK                 (uint8)1

#define PORT_PIN_MAX_SIZE        (uint8)8
#define PORT_MAX_SIZE            (uint8)5
/* ------------------------------------Macro Function Declarations------------------ */


#define SET_BIT(PORT ,PIT_POSN)      (PORT|=(BIT_MASK <<PIT_POSN))
#define CLEAR_BIT(PORT ,PIT_POSN)    (PORT&= ~(BIT_MASK <<PIT_POSN))
#define TOGGLE_BIT(PORT ,PIT_POSN)   (PORT^=(BIT_MASK <<PIT_POSN))
#define READ_BIT(PORT, PIT_POSN)     (PORT&(BIT_MASK << PIT_POSN))

/* ------------------------------------Data Type Declarations----------------------- */

typedef enum
{
    Direction_Outpt = 0 ,
    Direction_input
}Direction_t;

typedef enum
{
    Logic_Low = 0 ,
    Logic_High
}Logic_t;

typedef enum
{
    pin0 = 0 ,
    pin1 ,
    pin2 ,
    pin3 ,
    pin4 ,
    pin5 ,
    pin6 ,
    pin7
            
}Pin_Index_t;

typedef enum 
{
    PortA_Index = 0 ,
    PortB_Index ,
    PortC_Index ,
    PortD_Index ,
    PortE_Index ,
            
}Port_Index_t;

typedef struct 
{
    uint8 port : 3;        /*@ref Port_Index_t*/
    uint8 pin : 3;         /*@ref Pin_Index_t*/
    uint8 direction : 1;   /*@ref Direction_t*/
    uint8 logic : 1;       /*@ref Logic_t*/
    
}Pin_Config_t;

/* ------------------------------------Software Interface Declarations-------------- */

Std_ReturnType GPIO_Pin_Direction_Intialize(const Pin_Config_t  *_Pin_Config_);

Std_ReturnType GPIO_Pin_Get_Direction_Status(const Pin_Config_t  *_Pin_Config_ ,Direction_t *Dir_Status);

Std_ReturnType GPIO_Pin_Write_Logic(const Pin_Config_t *_Pin_Config_ ,Logic_t Logic);

Std_ReturnType GPIO_Pin_Read_Logic(const Pin_Config_t  *_Pin_Config_ ,Logic_t *Logic);

Std_ReturnType GPIO_Pin_Toggle_Logic(const Pin_Config_t  *_Pin_Config_  );

Std_ReturnType GPIO_Pin_Intialize(const Pin_Config_t  *_Pin_Config_);


Std_ReturnType GPIO_Port_Direction_Intialize(Port_Index_t _Port_Index_ ,Direction_t Dir_Status);

Std_ReturnType GPIO_Port_Get_Direction_Status(Port_Index_t _Port_Index_ ,Direction_t *Dir_Status);

Std_ReturnType GPIO_Port_Write_Logic(Port_Index_t _Port_Index_ ,Logic_t Logic);

Std_ReturnType GPIO_Port_Read_Logic(Port_Index_t _Port_Index_ ,Logic_t *Logic);

Std_ReturnType GPIO_Port_Toggle_Logic(Port_Index_t _Port_Index_);

#endif	/* HAL_GPIO_H */

