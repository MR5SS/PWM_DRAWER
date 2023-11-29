/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: GLOBAL Interuppt  **************/
/***************  Version: 1.00          **************/
/******************************************************/

#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

// Enable GLobal Interuppt
#define SREG              *((volatile u8*)0x5F)
#define SREG_GIE_I          7


#endif //GIE_REGISTER_H_
