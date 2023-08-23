/* 
 * File:   ecu_ch_lcd.h
 * Author: Yossri
 *
 * Created on July 15, 2023, 4:43 PM
 */

#ifndef ECU_CH_LCD_H
#define	ECU_CH_LCD_H

/* ------------------------------------Includes--------------------------------------*/
#include "../../MCAL_Layer/GPIO/hal_GPIO.h"
#include <stdio.h>
#include <string.h>
#include "../../MCAL_Layer/std_libraries.h"

/* ------------------------------------Macro Declarations--------------------------- */


#define LCD_4_BIT_MODE
//#define LCD_8_BIT_MODE

#define FOUR_BIT_MODE   (uint8)4
#define EIGHT_BIT_MODE  (uint8)8

/*command of character lcd*/

#define LCD_CLEAR               0x01   /*using in intialize*/
#define LCD_RETURN_HOME         0x02   /*using in intialize*/

#define LCD_DEC_SHIFT_OFF       0x04
#define LCD_DEC_SHIFT_ON        0x05   
#define LCD_INC_SHIFT_OFF       0x06  /*using in intialize*/
#define LCD_INC_SHIFT_ON        0x07

#define LCD_DISPLAY_ON_CURSORO_ON_BLOCKCURSOR_ON   0X0F          
#define LCD_DISPLAY_ON_CURSORO_ON_BLOCKCURSOR_OFF  0X0E
#define LCD_DISPLAY_ON_CURSORO_oFF_BLOCKCURSOR_ON  0X0D
#define LCD_DISPLAY_ON_CURSORO_oFF_BLOCKCURSOR_OFF 0X0C

#define LCD_DISPLAY_OFF_CURSORO_ON_BLOCKCURSOR_ON   0x0B        
#define LCD_DISPLAY_OFF_CURSORO_ON_BLOCKCURSOR_OFF  0x0A
#define LCD_DISPLAY_OFF_CURSORO_oFF_BLOCKCURSOR_ON  0x09
#define LCD_DISPLAY_OFF_CURSORO_oFF_BLOCKCURSOR_OFF 0x08

#define LCD_SHIFT_DISPLAY_RIGHT_SHIFT               0X1C
#define LCD_SHIFT_DISPLAY_LEFT_SHIFT                0X18
#define LCD_MOVE_CURSOR_RIGHT_SHIFT                 0X14
#define LCD_MOVE_CURSOR_LEFT_SHIFT                  0X10

#define LCD_8_BIT_MODE_2_LINE                       0x38
#define LCD_4_BIT_MODE_2_LINE                       0x28
#define LCD_CGRAM_START                             0x40
#define LCD_DDRAM_START                             0x80

#define ROW1       (uint8)1
#define ROW2       (uint8)2
#define ROW3       (uint8)3
#define ROW4       (uint8)4

/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */
typedef struct
{
    Pin_Config_t RS ;
    Pin_Config_t EN;
#ifdef LCD_4_BIT_MODE
    Pin_Config_t data_pin[4];
#endif
#ifdef LCD_8_BIT_MODE
    Pin_Config_t data_pin[8];
#endif
}Ch_LCD;
/* ------------------------------------Software Interface Declarations-------------- */

Std_ReturnType convert_byte_to_string(uint8 value ,uint8 *str);
Std_ReturnType convert_short_to_string(uint16 value ,uint8 *str);
Std_ReturnType convert_int_to_string(uint32 value ,uint8 *str);

                               /*four or eight bit functions*/
Std_ReturnType lcd_intialize(const Ch_LCD *_LCD_);

Std_ReturnType lcd_send_command(const Ch_LCD *_LCD_ ,uint8 command);

Std_ReturnType lcd_send_char_data(const Ch_LCD *_LCD_ ,uint8 data);

Std_ReturnType lcd_send_ATpos_char_data(const Ch_LCD *_LCD_ ,uint8 row ,uint8 coulmns , uint8 data);

Std_ReturnType lcd_send_string_data(const Ch_LCD *_LCD_ ,uint8 *str);

Std_ReturnType lcd_send_ATpos_string_data(const Ch_LCD *_LCD_ ,uint8 row ,uint8 coulmns , uint8 *str);

Std_ReturnType lcd_send_custom_char(const Ch_LCD *_LCD_ ,uint8 row ,uint8 coulmns ,
                                         const uint8 _char[]  ,uint8 mem_pos);


#endif	/* ECU_CH_LCD_H */

