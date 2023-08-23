/* 
 * File:   mcal_eeprom.c
 * Author: Yossri
 *
 * Created on July 22, 2023, 11:58 AM
 */
#include <pic18.h>

#include "mcal_eeprom.h"

Std_ReturnType EEPROM_Data_WriteByte(uint16 bAdd ,uint8 bData)
{
    Std_ReturnType ret = E_OK;
    if(bAdd < 0x000 || bAdd > 0x3ff)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*read interrupt status "enable or disable"*/
        uint8 Global_int_status = INTCONbits.GIE;
        /*update the address register*/
        EEADRH = (uint8) ((bAdd >> 8) & 0x03);
        EEADR = (uint8) (bAdd & 0xFF);
        /*update the data register*/
        EEDATA = bData;
        /*Access data EEPROM memory*/
        EECON1bits.EEPGD = Access_data_EEPROM_memory; /*Access EEPROM Memory at 0 || Flash at 1*/
        /* Access Flash program or data EEPROM memory*/
        EECON1bits.CFGS = Access_Flash_program_or_EEPROM_memory; //Access EEPROM Memory at 0 || Flash at 0 && Configuration bits at 1
        /*the WREN bit in EECON1 must be set to enable writes.*/
        EECON1bits.WREN = Allows_write_cycles_to_Flash_EEPROM;
        /*disable interrupt*/
        INTERRUPT_AllInterruptDisable();
        /*write this seq (write 55h to EECON2, write 0AAh to EECON2)*/
        EECON2 = 0x55;
        EECON2 = 0xAA;
        /*set WR bit*/
        EECON1bits.WR = Initiates_a_data_EEPROM_erase_write_cycle;
        /*check for complete writing in eeprom*/
        while (EECON1bits.WR);
        /*clear  WREN bit in EECON1*/
        EECON1bits.WREN = Inhibits_write_cycles_to_Flash_EEPROM;
        /*restore the status of interrupt*/
        INTCONbits.GIE = Global_int_status; 
    }
    
    return ret;
}

Std_ReturnType EEPROM_Data_ReadByte(uint16 bAdd ,uint8 *bData)
{
    Std_ReturnType ret = E_OK;
    if(NULL == bData)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*update the address register*/
        EEADRH = (uint8) ((bAdd >> 8) & 0x03);
        EEADR = (uint8) (bAdd & 0xFF);
        /*Access data EEPROM memory*/
        EECON1bits.EEPGD = Access_data_EEPROM_memory;
        /* Access Flash program or data EEPROM memory*/
        EECON1bits.CFGS = Access_Flash_program_or_EEPROM_memory;
        /*intiat EEPROM memory to Read*/
        EECON1bits.RD = Initiates_an_EEPROM_read;
        /*2 no operation for high frequncy like 20 or 40 MH*/
        NOP();
        NOP();
        /*read data*/
        *bData = EEDATA;
    }
    
    return ret;
}