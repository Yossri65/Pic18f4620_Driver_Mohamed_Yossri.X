/* 
 * File:   mcal_interrupt_config.h
 * Author: Yossri
 *
 * Created on July 20, 2023, 1:29 AM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H
/* ------------------------------------Includes--------------------------------------*/
#include "pic18f4620.h"
#include "mcal_interrupt_gen_cfg.h"
/* ------------------------------------Macro Declarations--------------------------- */
#define INTERRUPT_ENABLE    1
#define INTERRUPT_DISABLE   0

#define INTERRUPT_PRIORITY_ENABLE   1
#define INTERRUPT_PRIORITY_DISABLE  0

#define INTERRUPT_OCCURE      1
#define INTERRUPT_NOT_OCCURE  0
/* ------------------------------------Macro Function Declarations------------------ */
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define INTERRUPT_PriorityLevelsEnable()   (RCONbits.IPEN = 1)

#define INTERRUPT_HighPriorityEnable()  (INTCONbits.GIEH = 1)
#define INTERRUPT_HighPriorityDisable() (INTCONbits.GIEH = 0)

#define INTERRUPT_LowPriorityEnable()   (INTCONbits.GIEL = 1)
#define INTERRUPT_LowPriorityDisable()  (INTCONbits.GIEL = 0)

#else
#define INTERRUPT_PriorityLevelsDisable()  (RCONbits.IPEN = 0)

#define INTERRUPT_PeripheralInterruptEnable()   (INTCONbits.PEIE = 1)
#define INTERRUPT_PeripheralInterruptDisable()  (INTCONbits.PEIE = 0)

#define INTERRUPT_AllInterruptEnable()  (INTCONbits.GIE = 1)
#define INTERRUPT_AllInterruptDisable() (INTCONbits.GIE = 0)
#endif
/* ------------------------------------Data Type Declarations----------------------- */
typedef void (*interruptHandler) (void);

typedef enum 
{
    High_Priority = 0 ,
    Low_Priority
}Interrupt_Priority;
/* ------------------------------------Software Interface Declarations-------------- */

#endif	/* MCAL_INTERRUPT_CONFIG_H */

