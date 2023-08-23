/* 
 * File:   mcal_interrupt_manager.c
 * Author: Yossri
 *
 * Created on July 20, 2023, 1:28 AM
 */
#include "mcal_interrupt_manager.h"

static volatile uint8 RB4_flag = 1;
static volatile uint8 RB5_flag = 1;
static volatile uint8 RB6_flag = 1;
static volatile uint8 RB7_flag = 1;


#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
  
void __interrupt() InterruptManagerHigh(void)
{
    if ((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCURE == INTCONbits.INT0IF)) {
        INT0_ISR();
    } else {
        /*Nothing*/
    }

}

void __interrupt(low_priority) InterruptManagerLow(void)
{
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCURE == INTCON3bits.INT2IF))
    {
       INT2_ISR();
    }
    else{/*Nothing*/}
    if ((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCURE == INTCON3bits.INT1IF)) {
        INT1_ISR();
    } else {
        /*Nothing*/
    }
}
#else
void __interrupt() InterruptManagerHigh(void)
{
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCURE == INTCONbits.INT0IF))
    {
       INT0_ISR();
    }
    else {/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCURE == INTCON3bits.INT1IF))
    {
       INT1_ISR();
    }
    else {/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCURE == INTCON3bits.INT2IF))
    {
       INT2_ISR();
    }
    
    /*=============================================port B==========================================*/
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURE == INTCONbits.RBIF) 
            && (PORTBbits.RB4 == Logic_High) && RB4_flag == 1)
    {
        RB4_flag = 0; 
       RB4_ISR(0); /*for high state*/
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURE == INTCONbits.RBIF) 
            && (PORTBbits.RB5 == Logic_Low)&& RB4_flag == 0)
    {
        RB4_flag = 1; 
       RB4_ISR(1); /*for low state*/
    }
    else{/*Nothing*/}
     if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURE == INTCONbits.RBIF) 
             && (PORTBbits.RB5 == Logic_High)&& RB5_flag == 1)
    {
         RB5_flag = 0; 
       RB5_ISR(0); /*for high state*/
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURE == INTCONbits.RBIF) 
            && (PORTBbits.RB5 == Logic_Low)&& RB5_flag == 0)
    {
        RB5_flag = 1; 
       RB5_ISR(1); /*for low state*/
    }
    else{/*Nothing*/}
   if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURE == INTCONbits.RBIF) 
             && (PORTBbits.RB6 == Logic_High)&& RB6_flag == 1)
    {
         RB6_flag = 0; 
       RB6_ISR(0); /*for high state*/
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURE == INTCONbits.RBIF) 
            && (PORTBbits.RB6 == Logic_Low)&& RB6_flag == 0)
    {
        RB6_flag = 1; 
       RB6_ISR(1); /*for low state*/
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURE == INTCONbits.RBIF) 
             && (PORTBbits.RB7 == Logic_High)&& RB7_flag == 1)
    {
         RB7_flag = 0; 
       RB7_ISR(0); /*for high state*/
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCURE == INTCONbits.RBIF) 
            && (PORTBbits.RB7 == Logic_Low)&& RB7_flag == 0)
    {
        RB7_flag = 1; 
       RB7_ISR(1); /*for low state*/
    }
    /*=============================================ADC==========================================*/
    if((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCURE == PIR1bits.ADIF) )
    {
       ADC_ISR();
    }
    
    /*=============================================TIMER0==========================================*/
    if((INTERRUPT_ENABLE == INTCONbits.TMR0IE) && (INTERRUPT_OCCURE == INTCONbits.TMR0IF) )
    {
       TIMER0_ISR();
    }
    /*=============================================TIMER1==========================================*/
    if((INTERRUPT_ENABLE == PIE1bits.TMR1IE) && (INTERRUPT_OCCURE == PIR1bits.TMR1IF) )
    {
       TIMER1_ISR();
    }
    /*=============================================TIMER2==========================================*/
    if((INTERRUPT_ENABLE == PIE1bits.TMR2IE) && (INTERRUPT_OCCURE == PIR1bits.TMR2IF) )
    {
       TIMER2_ISR();
    }
    /*=============================================TIMER3==========================================*/
    if((INTERRUPT_ENABLE == PIE2bits.TMR3IE) && (INTERRUPT_OCCURE == PIR2bits.TMR3IF) )
    {
       TIMER3_ISR();
    }
    /*=============================================CCP1==========================================*/
    if((INTERRUPT_ENABLE == PIE1bits.CCP1IE) && (INTERRUPT_OCCURE == PIR1bits.CCP1IF) )
    {
       CCP1_ISR();
    }
    /*=============================================CCP2==========================================*/
    if((INTERRUPT_ENABLE == PIE2bits.CCP2IE) && (INTERRUPT_OCCURE == PIR2bits.CCP2IF) )
    {
       CCP2_ISR();
    }
    /*=============================================ECCP==========================================*/
    if((INTERRUPT_ENABLE == PIE1bits.CCP1IE) && (INTERRUPT_OCCURE == PIR1bits.CCP1IF) )
    {
       ECCP_ISR();
    }
    /*=============================================Usart_TX==========================================*/
    if((INTERRUPT_ENABLE == PIE1bits.TXIE) && (INTERRUPT_OCCURE == PIR1bits.TXIF) )
    {
       USART_TX_ISR();
    }
    /*=============================================Usart_RX==========================================*/
    if((INTERRUPT_ENABLE == PIE1bits.RCIE) && (INTERRUPT_OCCURE == PIR1bits.RCIF) )
    {
       USART_RX_ISR();
    }
    /*=============================================SPI==========================================*/
    if((INTERRUPT_ENABLE == PIE1bits.SSPIE) && (INTERRUPT_OCCURE == PIR1bits.SSPIF) )
    {
       SPI_ISR();
    }
    /*=============================================I2C==========================================*/
    if((INTERRUPT_ENABLE == PIE1bits.SSPIE) && (INTERRUPT_OCCURE == PIR1bits.SSPIF) )
    {
       MSSP_I2C_ISR();
    }
    /*=============================================I2C_BUS_COl==========================================*/
    if((INTERRUPT_ENABLE == PIE2bits.BCLIE) && (INTERRUPT_OCCURE == PIR2bits.BCLIF) )
    {
       MSSP_I2C_BC_ISR();
    }
}
#endif
