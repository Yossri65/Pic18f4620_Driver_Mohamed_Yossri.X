/* 
 * File:   std_libraries.h
 * Author: Yossri
 *
 * Created on July 8, 2023, 2:16 AM
 */

#ifndef STD_LIBRARIES_H
#define	STD_LIBRARIES_H

/* ------------------------------------Includes--------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------Data Type Declarations----------------------- */
typedef unsigned char uint8;
//const CCP_config_t *_CCP_ ;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef unsigned Std_ReturnType;

/* ------------------------------------Macro Declarations--------------------------- */
#define STD_HIGH        0x01u
#define STD_LOW         0x00u

#define STD_ACTIVE      0x01u
#define STD_IDLE        0x00u

#define STD_ON          0x01u  
#define STD_OFF         0x00u

#define E_OK            (Std_ReturnType)0x01
#define E_NOT_OK        (Std_ReturnType)0x00

#define _XTAL_FREQ       8000000UL

/* ------------------------------------Macro Function Declarations------------------ */


/* ------------------------------------Software Interface Declarations-------------- */

#endif	/* STD_LIBRARIES_H */

