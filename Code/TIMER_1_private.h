/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: Timer             **************/
/***************  Version: 1.00           *************/
/******************************************************/

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_




//Wave Generation Mode options
#define Normal                1
#define PWM_PhaseCorrect      2
#define CTC                   3
#define Fast_PWM              4

//Compare Match OutputMode options
#define Disconnected          1
#define Toggle                2
#define Clear                 3
#define Set                   4
#define COCSOT                5
#define SOCCOT                6

//Clock Select
#define  No_Clock_Source    0b00000000
#define  System_Clock       0b00000001
#define  DivisionBy_8       0b00000010
#define  DivisionBy_64      0b00000011
#define  DivisionBy_256     0b00000100
#define  DivisionBy_1024    0b00000101
#define  ExternalClock_F    0b00000110
#define  ExternalClock_R    0b00000111
#define  Prescalar_Mask     0b11111000


#endif
