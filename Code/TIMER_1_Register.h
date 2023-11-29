/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: Timer_1           **************/
/***************  Version: 1.00           *************/
/******************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_
//--------------------------------------------------------------------------------
                            //Timer 1 Registers
//--------------------------------------------------------------------------------
#define TCCR1A            *((volatile u8*)0x4F)   //Timer control Register 1
#define TCCR1A_WEM10       0                      //Wave Generation Mode Bit 0
#define TCCR1A_WEM11       1                      //Wave Generation Mode Bit 1
#define TCCR1A_FOC1B       2                      //Force output compare match bit
#define TCCR1A_FOC1A       3                      //Force output compare match bit
#define TCCR1A_COM1B0      4                      //Compare match output mode bit B0
#define TCCR1A_COM1B1      5                      //Compare match output mode bit B1
#define TCCR1A_COM1A0      6                      //Compare match output mode bit A0
#define TCCR1A_COM1A1      7                      //Compare match output mode bit A1
#define TCCR1B            *((volatile u8*)0x4E)   //Timer Control Register 2
#define TCCR1B_ICNC1       7                      //Input Capture Noise canceler Bit
#define TCCR1B_ICES1       6                      //Input capture Edge select Bit
#define TCCR1B_WEM13       4                      //Wave Generation Mode Bit 3
#define TCCR1B_WEM12       3                      //Wave Generation Mode Bit 2
#define TCCR1B_CS12        2                      //Timer1 Clock Select Bit 2
#define TCCR1B_CS11        1                      //Timer1 Clock Select bit 1
#define TCCR1B_CS10        0                      //Timer1 Clock Select bit 0
#define TCNT1H           *((volatile u8*)0x4D)    //Timer1 / Counter1 H   Register
#define TCNT1L           *((volatile u8*)0x4C)    //Timer1 / Counter1 L   Register
#define TCNTLH           *((volatile u16*)0x4C)   //Timer1 / Counter1 LH  Register
#define OCR1AH           *((volatile u8*)0x4B)    //Output Compare Register AH
#define OCR1AL           *((volatile u8*)0x4A)    //Output Compare Register AL
#define OCR1ALH          *((volatile u16*)0x4A)   //Output Compare Register ALH
#define OCR1BH           *((volatile u8*)0x49)    //Output Compare Register BH
#define OCR1Bl           *((volatile u8*)0x48)    //Output Compare Register BL
#define OCR1BLH          *((volatile u16*)0x48)   //Output Compare Register BLH
#define ICR1H            *((volatile u8*)0x47)    //Input Capture Register 1H
#define ICR1L            *((volatile u8*)0x46)    //Input Capture Register 1L
#define ICR1LH           *((volatile u16*)0x46)   //Input Capture Register 1LH
#define TIMSK1           *((volatile u8*)0x59)    //Timer1 Counter Interrupt Mask
#define TIMSK1_TICIE1     5                       //Input capture Interrupt Enable
#define TIMSK1_OCIE1A     4                       //Output Compare A Match Interuppt Enable
#define TIMSK1_OCIE1B     3                       //Output Compare B Match Interuppt Enable
#define TIMSK1_TOIE1      2                       //Timer 1 overflow Interuppt Enable
#define TIFR1            *((volatile u8*)0x58)    //Timer 1 / Counter Interuppt Flag
#define TIFR1_ICF1        5                       //Timer/Counter1, Input Capture Flag
#define TIFR1_OCF1A       4                       //Timer/Counter1, Output Compare A Match Flag
#define TIFR1_OCF1B       3                       //Timer/Counter1, Output Compare B Match Flag
#define TIFR1_TOV         2                       //Overflow Flag
//--------------------------------------------------------------------------------



#endif
