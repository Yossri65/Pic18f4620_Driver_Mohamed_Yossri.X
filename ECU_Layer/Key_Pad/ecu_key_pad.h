/* 
 * File:   ecu_key_pad.h
 * Author: Yossri
 *
 * Created on July 13, 2023, 1:24 PM
 */

#ifndef ECU_KEY_PAD_H
#define	ECU_KEY_PAD_H

/* ------------------------------------Includes--------------------------------------*/
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
/* ------------------------------------Macro Declarations--------------------------- */
#define KEY_PAD_ROWS    4
#define KEY_PAD_COULMNS  4
/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */
typedef struct
{
    Pin_Config_t Key_Pad_Rows[KEY_PAD_ROWS];
    Pin_Config_t Key_Pad_Coulmns[KEY_PAD_COULMNS];
}Key_Pad_t;
/* ------------------------------------Software Interface Declarations-------------- */

Std_ReturnType Key_Pad_Intialize(const Key_Pad_t *_key_pad);

Std_ReturnType Key_Pad_Get_Value(const Key_Pad_t *_key_pad ,uint8 *value);
#endif	/* ECU_KEY_PAD_H */

