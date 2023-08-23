/* 
 * File:   mcal_external_interrupt.h
 * Author: Yossri
 *
 * Created on July 20, 2023, 1:27 AM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* ------------------------------------Includes--------------------------------------*/
#include "mcal_interrupt_config.h"
#include "pic18f4620.h"
#include "../std_libraries.h"
#include "../Device_config.h"
#include "../GPIO/hal_GPIO.h"
/* ------------------------------------Macro Declarations--------------------------- */

/* ------------------------------------Macro Function Declarations------------------ */
#ifdef EXT_INTERRUPT_INTX_FEATURE_ENABLE
/*INT0 configuration*/
#define EXT_INTERRUPT_INT0_Enable()   (INTCONbits.INT0IE = 1)
#define EXT_INTERRUPT_INT0_Disable()  (INTCONbits.INT0IE = 0)

#define EXT_INTERRUPT_INT0_Clear_Flag()  (INTCONbits.INT0IF = 0)

#define EXT_INTERRUPT_INT0_Rising_Edge()   (INTCON2bits.INTEDG0 = 1)
#define EXT_INTERRUPT_INT0_Falling_Edge()  (INTCON2bits.INTEDG0 = 0)
/*INT1 configuration*/
#define EXT_INTERRUPT_INT1_Enable()   (INTCON3bits.INT1IE = 1)
#define EXT_INTERRUPT_INT1_Disable()  (INTCON3bits.INT1IE = 0)

#define EXT_INTERRUPT_INT1_Clear_Flag()  (INTCON3bits.INT1F = 0)

#define EXT_INTERRUPT_INT1_Rising_Edge()   (INTCON2bits.INTEDG0 = 1)
#define EXT_INTERRUPT_INT1_Falling_Edge()  (INTCON2bits.INTEDG0 = 0)
/*INT2 configuration*/
#define EXT_INTERRUPT_INT2_Enable()   (INTCON3bits.INT2IE = 1)
#define EXT_INTERRUPT_INT2_Disable()  (INTCON3bits.INT2IE = 0)

#define EXT_INTERRUPT_INT2_Clear_Flag()  (INTCON3bits.INT2F = 0)

#define EXT_INTERRUPT_INT2_Rising_Edge()   (INTCON2bits.INTEDG0 = 1)
#define EXT_INTERRUPT_INT2_Falling_Edge()  (INTCON2bits.INTEDG0 = 0)

/*priority feature*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define EXT_INTERRUPT_INT1_Priority_High()   (INTCON3bits.INT1IP = 1)
#define EXT_INTERRUPT_INT1_Priority_Low()    (INTCON3bits.INT1IP = 0)

#define EXT_INTERRUPT_INT2_Priority_High()   (INTCON3bits.INT2IP = 1)
#define EXT_INTERRUPT_INT2_Priority_Low()    (INTCON3bits.INT2IP = 0)
#endif

#endif

#ifdef EXT_INTERRUPT_ON_CHANGE_FEATURE_ENABLE

#define EXT_INTERRUPT_RBX_Enable()   (INTCONbits.RBIE = 1)
#define EXT_INTERRUPT_RBX_Disable()  (INTCONbits.RBIE = 0)

#define EXT_INTERRUPT_RBX_Clear_Flag()  (INTCONbits.RBIF = 0)


#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define EXT_INTERRUPT_RBX_Priority_High()   (INTCON2bits.RBIP = 1)
#define EXT_INTERRUPT_RBX_Priority_Low()    (INTCON2bits.RBIP = 0)

#endif

#endif


/* ------------------------------------Data Type Declarations----------------------- */
typedef enum 
{
    EXT_INT0 = 0 ,
    EXT_INT1 ,
    EXT_INT2
}EXT_INTX_SRC; 

typedef enum 
{
    EXT_INT_Faling_Edge = 0 ,
    EXT_INT_Raising_Edge
}EXT_INTX_EDGE;

typedef struct
{
    void (* Interrupt_Handler)(void); /*for call back function*/
    Pin_Config_t EXT_pin;
    EXT_INTX_SRC source;
    EXT_INTX_EDGE edge;
    Interrupt_Priority priority;
}EXT_INTX_t;

typedef struct
{
    void (*Interrupt_Handler_High) (void); 
    void (*Interrupt_Handler_Low) (void); /*for call back function*/
    Pin_Config_t EXT_pin;
    Interrupt_Priority priority;
}EXT_RBX_t;
/* ------------------------------------Software Interface Declarations-------------- */

Std_ReturnType EXT_INTX_Intialize(const EXT_INTX_t *int_obj);
Std_ReturnType EXT_INTX_DE_Intialize(const EXT_INTX_t *int_obj);

Std_ReturnType EXT_RBX_Intialize(const EXT_RBX_t *int_obj);
Std_ReturnType EXT_RBX_DE_Intialize(const EXT_RBX_t *int_obj);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

