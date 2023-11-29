/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer: MCAL            **************/
/***************  SWC:Timer_0            **************/
/***************  Version: 1.00          *************/
/******************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_
//--------------------------------------------------------------------------------
//**************************** Timer 0 Registers ********************************
//--------------------------------------------------------------------------------
#define TCCR0            *((volatile u8*)0x53)   //Timer Control Register
#define TCCR0_FOCO         7                     //Force output compare match bit
#define TCCR0_WGM0         6                     //Wave Gen Mode Bit 0
#define TCCR0_WGM1         3                     //Wave Gen Mode Bit 1
#define TCCR0_COM01        5                     //Compare match output mode bit 1
#define TCCR0_COM00        4                     //Compare match output mode bit 0
#define TCCR0_CS02         2                     //Timer0 Clock Select bit 2
#define TCCR0_CS01         1                     //Timer0 Clock Select bit 1
#define TCCR0_CS00         0                     //Timer0 Clock Select bit 0
#define TCNT0           *((volatile u8*)0x52)    //Timer/Counter Register
#define OCR0            *((volatile u8*)0x5C)    //Output Compare Register
#define TIMSK           *((volatile u8*)0x59)    //Timer/Counter Interrupt Mask Register
#define TIMSK_OCIE         1                     //Output Compare Match Interrupt Enable
#define TIMSK_TOIE         0                     //Overflow Interrupt Enable
//--------------------------------------------------------------------------------

#endif
