/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: PORT              **************/
/***************  Version: 1.00           *************/
/******************************************************/
/******************************************************/

#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H

#define DDRA   *((volatile u8*) 0x3a)           /* Register Used to Set Direction of Pin (Input or Output) in PORTA */
#define PORTA  *((volatile u8*) 0x3b)           /* Register Used to Set Value of Pin (LOW or HIGH) in PORTA */

                                           
#define DDRB   *((volatile u8*) 0x37)           /* Register Used to Set Direction of Pin (Input or Output) in PORTB */  
#define PORTB  *((volatile u8*) 0x38)           /* Register Used to Set Value of Pin (LOW or HIGH) in PORTB */

                                                
#define DDRC   *((volatile u8*) 0x34)           /* Register Used to Set Direction of Pin (Input or Output) in PORTC */
#define PORTC  *((volatile u8*) 0x35)           /* Register Used to Set Value of Pin (LOW or HIGH) in PORTC */

                                                 
#define DDRD   *((volatile u8*) 0x31)           /* Register Used to Set Direction of Pin (Input or Output) in PORTD */
#define PORTD  *((volatile u8*) 0x32)           /* Register Used to Set Value of Pin (LOW or HIGH) in PORTD */


#endif //PORT_REGISTER_H
