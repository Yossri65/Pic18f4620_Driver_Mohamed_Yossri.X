/* 
 * File:   ecu_ch_lcd.c
 * Author: Yossri
 *
 * Created on July 15, 2023, 4:43 PM
 */
#include <builtins.h>

#include "ecu_ch_lcd.h"

static void lcd_send_4_bit_data(const Ch_LCD *_LCD_ ,uint8 _data_command);
static void lcd_send_enable(const Ch_LCD *_LCD_);

static void lcd_set_cursor(const Ch_LCD *_LCD_ ,uint8 row ,uint8 coulmn);

/**
 * 
 * @param _LCD_
 * @return 
 */
Std_ReturnType lcd_intialize(const Ch_LCD *_LCD_)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == _LCD_)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        uint8 data_pin_counter = 0;
        ret = GPIO_Pin_Intialize(&(_LCD_->EN));
        ret = GPIO_Pin_Intialize(&(_LCD_->RS));
        #ifdef LCD_4_BIT_MODE

        for(data_pin_counter = 0 ; data_pin_counter < FOUR_BIT_MODE ; data_pin_counter++)
        {
            ret = GPIO_Pin_Intialize(&(_LCD_->data_pin[data_pin_counter]));
        }
        __delay_ms(20);
        lcd_send_command(_LCD_ ,LCD_8_BIT_MODE_2_LINE);
        __delay_ms(5);
        lcd_send_command(_LCD_ ,LCD_8_BIT_MODE_2_LINE);
        __delay_ms(150);
        lcd_send_command(_LCD_ ,LCD_8_BIT_MODE_2_LINE);
        
        lcd_send_command(_LCD_ ,LCD_CLEAR);
        lcd_send_command(_LCD_ ,LCD_RETURN_HOME);
        lcd_send_command(_LCD_ ,LCD_INC_SHIFT_OFF);
        lcd_send_command(_LCD_ ,LCD_DISPLAY_ON_CURSORO_oFF_BLOCKCURSOR_OFF);
        lcd_send_command(_LCD_ ,LCD_4_BIT_MODE_2_LINE);
        lcd_send_command(_LCD_ ,LCD_DDRAM_START );

        #endif
        #ifdef LCD_8_BIT_MODE
        for(data_pin_counter = 0 ; data_pin_counter < EIGHT_BIT_MODE ; data_pin_counter++)
        {
            ret = GPIO_Pin_Intialize(&(_LCD_->data_pin[data_pin_counter]));
        }
        __delay_ms(20)
        lcd_send_command(_LCD_ ,LCD_8_BIT_MODE_2_LINE);
        __delay_ms(5);
        lcd_send_command(_LCD_ ,LCD_8_BIT_MODE_2_LINE);
        __delay_ms(150);
        lcd_send_command(_LCD_ ,LCD_8_BIT_MODE_2_LINE);
        
        lcd_send_command(_LCD_ ,LCD_CLEAR);
        lcd_send_command(_LCD_ ,LCD_RETURN_HOME);
        lcd_send_command(_LCD_ ,LCD_RETURN_HOME);
        lcd_send_command(_LCD_ ,LCD_INC_SHIFT_OFF);
        lcd_send_command(_LCD_ ,LCD_DISPLAY_ON_CURSORO_oFF_BLOCKCURSOR_OFF);
        lcd_send_command(_LCD_ ,LCD_8_BIT_MODE_2_LINE);
        lcd_send_command(_LCD_ ,LCD_DDRAM_START );
        #endif
    }
    return ret;
}

Std_ReturnType lcd_send_command(const Ch_LCD *_LCD_ ,uint8 command)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == _LCD_)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        ret = GPIO_Pin_Write_Logic(&(_LCD_->RS) ,Logic_Low);
        #ifdef LCD_4_BIT_MODE
        lcd_send_4_bit_data(_LCD_ ,command >> 4);
        lcd_send_enable(_LCD_);
        lcd_send_4_bit_data(_LCD_ ,command);
        lcd_send_enable(_LCD_);
        #endif
        #ifdef LCD_8_BIT_MODE
        uint8 pin_counter = 0;
        for(pin_counter = 0 ;pin_counter < EIGHT_BIT_MODE ;pin_counter++)
        {
            GPIO_Pin_Write_Logic(&(_LCD_->data_pin[pin_counter]) ,(command >> pin_counter) & (uint8)(0x01));
        }
        lcd_send_enable(_LCD_);
        #endif
    }
    return ret;
}

Std_ReturnType lcd_send_char_data(const Ch_LCD *_LCD_ ,uint8 data)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == _LCD_)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        ret = GPIO_Pin_Write_Logic(&(_LCD_->RS) ,Logic_High);
        #ifdef LCD_4_BIT_MODE
        lcd_send_4_bit_data(_LCD_ ,(data >> 4));
        lcd_send_enable(_LCD_);
        lcd_send_4_bit_data(_LCD_ ,data);
        lcd_send_enable(_LCD_);
        #endif
        #ifdef LCD_8_BIT_MODE
        uint8 pin_counter = 0;
        for(pin_counter = 0 ;pin_counter < EIGHT_BIT_MODE ;pin_counter++)
        {
            GPIO_Pin_Write_Logic(&(_LCD_->data_pin[pin_counter]) ,(data >> pin_counter) & (uint8)(0x01));
        }
        lcd_send_enable(_LCD_);
        #endif
    }
    return ret;
}

Std_ReturnType lcd_send_ATpos_char_data(const Ch_LCD *_LCD_ ,uint8 row ,
                                             uint8 coulmns , uint8 data)
{
     Std_ReturnType ret = E_OK ;
    if(NULL == _LCD_)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        lcd_set_cursor(_LCD_ , row ,coulmns);
        lcd_send_char_data(_LCD_ ,data);
    }
    return ret;
}

Std_ReturnType lcd_send_string_data(const Ch_LCD *_LCD_ ,uint8 *str)
{
     Std_ReturnType ret = E_OK ;
    if(NULL == _LCD_ || NULL == str)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        while(*str != NULL)
        {
            ret = lcd_send_char_data(_LCD_ ,*str);
            str++;
        }
    }
    return ret;
}

Std_ReturnType lcd_send_ATpos_string_data(const Ch_LCD *_LCD_ ,uint8 row ,
                                             uint8 coulmns , uint8 *str)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == _LCD_ || NULL == str)
    {
        ret = E_NOT_OK;
    }
    else 
    {
       lcd_set_cursor(_LCD_ , row ,coulmns);
       ret= lcd_send_string_data(_LCD_ ,str);
    }
    return ret;
}

Std_ReturnType lcd_send_custom_char(const Ch_LCD *_LCD_ ,uint8 row ,uint8 coulmns ,
                                         const uint8 _char[]  ,uint8 mem_pos)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == _LCD_)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        uint8 bit_counter = 0;
        ret = lcd_send_command(_LCD_ ,(0x40 + (mem_pos *8)));
        for(bit_counter = 0 ;bit_counter < 8 ;bit_counter++)
        {
            ret = lcd_send_char_data(_LCD_ ,_char[bit_counter]);
        }
        ret = lcd_send_ATpos_char_data(_LCD_ ,row ,coulmns ,mem_pos);
    }
    return ret;
}



Std_ReturnType convert_byte_to_string(uint8 value ,uint8 *str)
{
     Std_ReturnType ret = E_OK ;
    uint8 l_str[4] = {0};
    uint8 counter = 0;
    if(NULL == str)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        memset(str ,' ' ,3);
        str[3] ='\0';
        sprintf(l_str ,"%i" ,value);
        while(l_str[counter] != '\0')
        {
            str[counter] = l_str[counter];
            counter++;
        }
    }
    return ret;
}

Std_ReturnType convert_short_to_string(uint16 value ,uint8 *str)
{
    Std_ReturnType ret = E_OK ;
    uint8 l_str[6] = {0};
    uint8 counter = 0;
    if(NULL == str)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        memset(str ,' ' ,5);
        str[5] ='\0';
        sprintf(l_str ,"%i" ,value);
        while(l_str[counter] != '\0')
        {
            str[counter] = l_str[counter];
            counter++;
        }
    }
    return ret;
}

Std_ReturnType convert_int_to_string(uint32 value ,uint8 *str)
{
   Std_ReturnType ret = E_OK ;
    uint8 l_str[11] = {0};
    uint8 counter = 0;
    if(NULL == str)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        memset(str ,' ' ,11);
        str[11] ='\0';
        sprintf(l_str ,"%i" ,value);
        while(l_str[counter] != '\0')
        {
            str[counter] = l_str[counter];
            counter++;
        }
    }
    return ret;
}

static void lcd_send_4_bit_data(const Ch_LCD *_LCD_ ,uint8 _data_command)
{
    uint8 pin_counter = 0 ;
    for(pin_counter =0 ;pin_counter < FOUR_BIT_MODE  ;pin_counter++)
    {
        GPIO_Pin_Write_Logic(&(_LCD_->data_pin[pin_counter]) ,(_data_command >> pin_counter) & (uint8)(0x01));
    }
}

static void lcd_send_enable(const Ch_LCD *_LCD_)
{
    GPIO_Pin_Write_Logic(&(_LCD_->EN) ,Logic_High);
    __delay_us(5);
    GPIO_Pin_Write_Logic(&(_LCD_->EN) ,Logic_Low);
}

static void lcd_set_cursor(const Ch_LCD *_LCD_ ,uint8 row ,uint8 coulmn)
{
    coulmn--;
    switch(row)
    {
        case ROW1  :
            lcd_send_command(_LCD_ ,(0x80 +coulmn));
            break;
        case ROW2  :
            lcd_send_command(_LCD_ ,(0xc0 +coulmn));
            break;
        case ROW3  :
            lcd_send_command(_LCD_ ,(0x94 +coulmn));
            break;
        case ROW4  :
            lcd_send_command(_LCD_ ,(0xd4 +coulmn));
            break;
        default:  ;
    }
}
