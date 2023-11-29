/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: DIO               **************/
/***************  Version: 1.00          **************/
/******************************************************/
/******************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define PORTA  *((volatile u8*) 0x3b)                  //Register Used to Set Value of Pin for PORTA 
#define PINA   *((volatile u8*) 0x39)                  //Register Used to Read Value of Pin for PORTA

#define PORTB  *((volatile u8*) 0x38)                  //Register Used to Set Value of Pin for PORTB
#define PINB   *((volatile u8*) 0x36)                  //Register Used to Read Value of Pin for PORTB

#define PORTC  *((volatile u8*) 0x35)                  //Register Used to Set Value of Pin for PORTC
#define PINC   *((volatile u8*) 0x33)                  //Register Used to Read Value of Pin for PORTC

#define PORTD  *((volatile u8*) 0x32)                  //Register Used to Set Value of Pin for PORTD
#define PIND   *((volatile u8*) 0x30)                  //Register Used to Read Value of Pin for PORTD




#endif // DIO_REGISTER_H
