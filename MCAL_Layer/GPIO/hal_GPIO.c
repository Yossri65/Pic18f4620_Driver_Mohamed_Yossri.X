/* 
 * File:   hal_GPIO.c
 * Author: Yossri
 *
 * Created on July 8, 2023, 2:08 AM
 */

#include "hal_GPIO.h"
volatile uint8 *Tris_Reg[] ={&TRISA ,&TRISB ,&TRISC ,&TRISD ,&TRISE};
volatile uint8 *Lat_Reg[] ={&LATA ,&LATB ,&LATC ,&LATD ,&LATE};
volatile uint8 *Port_Reg[] ={&PORTA ,&PORTB ,&PORTC ,&PORTD ,&PORTE};



/**
 * @brief intialize pin on gpio module
 * @param _Pin_Config_is a pointer point to configurations @ref  Pin_Config_t
 * @return  Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Pin_Direction_Intialize(const Pin_Config_t  *_Pin_Config_)
{
    Std_ReturnType ret = E_OK;
    if(_Pin_Config_ == NULL || _Pin_Config_-> pin > PORT_PIN_MAX_SIZE -1)  /*_Pin_Config_->pin > PORT_PIN_MAX_SIZE -1  (8-1 = 7)(check if the user enter number greater than 7 because port have 8 pin from 0 to 7) */
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(_Pin_Config_->direction )
        {
            case Direction_Outpt :  /*CLEAR TRIS = 0  */
                CLEAR_BIT(*Tris_Reg[_Pin_Config_->port] ,_Pin_Config_->pin);
                break;
            case Direction_input : /*SET TRIS = 1  */
                SET_BIT(*Tris_Reg[_Pin_Config_->port] ,_Pin_Config_->pin);
                break;
            default : ret= E_NOT_OK;  
        }
    }
    return ret;
}

/**
 * @brief get direction status on gpio module
 * @param _Pin_Config_is a pointer point to configurations @ref  Pin_Config_t
 * @param Dir_Status is a pointer to store the direction of the pin
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Pin_Get_Direction_Status(const Pin_Config_t  *_Pin_Config_ ,Direction_t *Dir_Status)
{
        Std_ReturnType ret = E_OK;
    if(_Pin_Config_ == NULL || Dir_Status == NULL || _Pin_Config_-> pin > PORT_PIN_MAX_SIZE -1) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *Dir_Status = READ_BIT(*Tris_Reg[_Pin_Config_->port] ,_Pin_Config_->pin);
    }
    return ret;
}

/**
 * @brief write logic on pin on gpio module
 * @param _Pin_Config_is a pointer point to configurations @ref  Pin_Config_t
 * @param Logic is a varible contain the logic of the pin 
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Pin_Write_Logic(const Pin_Config_t *_Pin_Config_ ,Logic_t Logic)
{
        Std_ReturnType ret = E_NOT_OK;
    if(_Pin_Config_ == NULL || _Pin_Config_-> pin > PORT_PIN_MAX_SIZE -1) 
    {
        ret = E_OK ;
    }
    else
    {
        switch(Logic )
        {
            case Logic_Low :  /*CLEAR LAT = 0  */
                CLEAR_BIT(*Lat_Reg[_Pin_Config_->port] ,_Pin_Config_->pin);
                break;
            case Logic_High : /*SET LAT = 1  */
                SET_BIT(*Lat_Reg[_Pin_Config_->port] ,_Pin_Config_->pin);
                break;
            default : ret= E_NOT_OK;  
        }
    }
    return ret;
}

/**
 * @brief read logic on pin on gpio module
 * @param _Pin_Config_is a pointer point to configurations @ref  Pin_Config_t
 * @param Logic is pointer to store the logic off the pin
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Pin_Read_Logic(const Pin_Config_t  *_Pin_Config_ ,Logic_t *Logic)
{
    Std_ReturnType ret = E_OK;
    if(_Pin_Config_ == NULL || Logic == NULL || _Pin_Config_-> pin > PORT_PIN_MAX_SIZE -1) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *Logic = READ_BIT(*Port_Reg[_Pin_Config_->port] ,_Pin_Config_->pin);
    }
    return ret;
}
/**
 * @brief toggle logic on pin on gpio module
 * @param _Pin_Config_is a pointer point to configurations @ref  Pin_Config_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Pin_Toggle_Logic(const Pin_Config_t  *_Pin_Config_  )
{
    Std_ReturnType ret = E_OK;
    if(_Pin_Config_ == NULL || _Pin_Config_-> pin > PORT_PIN_MAX_SIZE -1) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        TOGGLE_BIT(*Lat_Reg[_Pin_Config_->port] ,_Pin_Config_->pin);
    }
    return ret;
}

/**
 * @brief intialize pin with logic low on pin on gpio module
 * @param _Pin_Config_is a pointer point to configurations @ref  Pin_Config_t
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Pin_Intialize(const Pin_Config_t  *_Pin_Config_)
{ 
    Std_ReturnType ret = E_OK;
    if(_Pin_Config_ == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = GPIO_Pin_Direction_Intialize(_Pin_Config_);
        ret = GPIO_Pin_Write_Logic(_Pin_Config_ ,_Pin_Config_->logic);   
    }
    return ret;
}





/**
 * 
 * @param _Port_Index_
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Port_Direction_Intialize(Port_Index_t _Port_Index_ ,Direction_t Dir_Status)
{
    Std_ReturnType ret = E_OK;
    if(_Port_Index_ > PORT_MAX_SIZE -1) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
       *Tris_Reg[_Port_Index_] = Dir_Status ; 
    }
    return ret;
}
/**
 * 
 * @param _Port_Index_
 * @param Dir_Status
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Port_Get_Direction_Status(Port_Index_t _Port_Index_ ,Direction_t *Dir_Status)
{
        Std_ReturnType ret = E_OK;
    if(_Port_Index_ > PORT_MAX_SIZE -1 || Dir_Status == NULL) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
       *Dir_Status = *Tris_Reg[_Port_Index_] ; 
    }
    return ret;
}
/**
 * 
 * @param _Port_Index_
 * @param Logic
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Port_Write_Logic(Port_Index_t _Port_Index_ ,Logic_t Logic)
{
    Std_ReturnType ret = E_OK;
    if(_Port_Index_ > PORT_MAX_SIZE -1) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *Lat_Reg[_Port_Index_] = Logic;
    }
    return ret;
}
/**
 * 
 * @param _Port_Index_
 * @param Logic
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Port_Read_Logic(Port_Index_t _Port_Index_ ,Logic_t *Logic)
{
    Std_ReturnType ret = E_OK;
    if(_Port_Index_ > PORT_MAX_SIZE -1 || Logic == NULL) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
       *Logic = *Port_Reg[_Port_Index_] ;
    }
    return ret;
}
/**
 * 
 * @param _Port_Index_
 * @param Logic
 * @return Std_ReturnType status of the function 
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function fail
 */
Std_ReturnType GPIO_Port_Toggle_Logic(Port_Index_t _Port_Index_)
{
    Std_ReturnType ret = E_OK;
    if(_Port_Index_ > PORT_MAX_SIZE -1) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
       *Lat_Reg[_Port_Index_] ^= 0x55;
    }
    return ret;
}
