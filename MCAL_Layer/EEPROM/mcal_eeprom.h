/* 
 * File:   mcal_eeprom.h
 * Author: Yossri
 *
 * Created on July 22, 2023, 11:58 AM
 */

#ifndef MCAL_EEPROM_H
#define	MCAL_EEPROM_H

/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "../Interrupt/mcal_external_interrupt.h"
#include "../std_libraries.h"
/* ------------------------------------Macro Declarations--------------------------- */
/*flash / eeprom select*/
#define  Access_Flash_program_memory   1
#define  Access_data_EEPROM_memory     0
/*flash or eeprom / config select*/
#define  Access_Configuration_registers        1
#define  Access_Flash_program_or_EEPROM_memory 0
/*write enable*/
#define  Allows_write_cycles_to_Flash_EEPROM   1
#define  Inhibits_write_cycles_to_Flash_EEPROM 0
/*write control*/
#define  Initiates_a_data_EEPROM_erase_write_cycle 1
#define  Write_cycle_to_the_EEPROM_is_complete     0

/*read control*/
#define Initiates_an_EEPROM_read           1
#define Does_Not_Initiates_an_EEPROM_read  0
/* ------------------------------------Macro Function Declarations------------------ */

/* ------------------------------------Data Type Declarations----------------------- */

/* ------------------------------------Software Interface Declarations-------------- */
Std_ReturnType EEPROM_Data_WriteByte(uint16 bAdd ,uint8 bData);
Std_ReturnType EEPROM_Data_ReadByte(uint16 bAdd ,uint8 *bData);

#endif	/* MCAL_EEPROM_H */

