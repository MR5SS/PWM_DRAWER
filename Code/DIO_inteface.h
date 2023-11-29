/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: DIO               **************/
/***************  Version: 1.00          **************/
/******************************************************/
/******************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "DIO_private.h"


/******************************************************************/
/** Description: Function Used to Set Pin Value of Specific Port **/
/** Parameter: Copy_u8Port:  DIO_u8PORTA -> DIO_u8PORTD          **/
/** Parameter: Copy_u8Pin:   DIO_u8PIN0  -> DIO_u8PIN7           **/
/** Parameter: Copy_u8Value: DIO_u8PIN_HIGH , DIO_u8PIN_LOW      **/
/** Return:    DIO_OK: NO Error , DIO_NOK: Error Occur           **/
/******************************************************************/  
                                               
u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);




/******************************************************************/
/** Description: Function Used to Set  Value of Specific Port    **/
/** Parameter: Copy_u8Port:  DIO_u8PORTA -> DIO_u8PORTD          **/
/** Parameter: Copy_u8Value: DIO_u8PIN_HIGH , DIO_u8PIN_LOW      **/
/** Return:    DIO_OK: NO Error , DIO_NOK: Error Occur           **/
/******************************************************************/  
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);



/******************************************************************/
/** Description: Function Used to Set Pin Value of Specific Port **/
/** Parameter: Copy_u8Port:  DIO_u8PORTA -> DIO_u8PORTD          **/
/** Parameter: Copy_u8Pin:   DIO_u8PIN0  -> DIO_u8PIN7           **/
/** Parameter: Copy_u8PinValue: Pointer to hold Pin Value        **/
/** Return:    DIO_OK: NO Error , DIO_NOK: Error Occur           **/
/******************************************************************/  
u8 DIO_GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 *Copy_u8PinValue);


#endif //DIO_INTERFACE_H_
