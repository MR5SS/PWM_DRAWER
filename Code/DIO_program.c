/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: DIO               **************/
/***************  Version: 1.00           *************/
/******************************************************/
/******************************************************/


/******************************************************
****************  Include Libraries  ******************                     
*******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************
****************  Include MCAL       ******************                     
*******************************************************/
#include "DIO_register.h"
#include "DIO_inteface.h"
#include "DIO_config.h"
#include "DIO_private.h"



u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_ErrorState = DIO_OK;

	if(Copy_u8Pin<=DIO_u8PIN7)
	{
		if(Copy_u8Value == DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin); break;
				default:Local_ErrorState = DIO_NOK;

			}
		}

		else if(Copy_u8Value == DIO_u8PIN_LOW)
		{

			switch(Copy_u8Port)
			{
				case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin);break;
				case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);break;
				case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);break;
				case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);break;
				default:Local_ErrorState = DIO_NOK;
			}


		}

		else
		{
			Local_ErrorState = DIO_NOK;
		}


	}

	else
	{
		Local_ErrorState = DIO_NOK;

	}



	return Local_ErrorState;

}

u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	u8 Local_ErrorState = DIO_OK;
   
	switch(Copy_u8Port)
	{
		case DIO_u8PORTA : PORTA = Copy_u8Value ; break;
		case DIO_u8PORTB : PORTB = Copy_u8Value ; break;
		case DIO_u8PORTC : PORTC = Copy_u8Value ; break;
		case DIO_u8PORTD : PORTD = Copy_u8Value ; break;
		default : Local_ErrorState = DIO_NOK;

	}


	return Local_ErrorState;


}

u8 DIO_GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 *Copy_pu8Value)
{
	u8 Local_ErrorState = DIO_OK ;

	if((Copy_pu8Value != Null) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		switch(Copy_u8Port)
		{
			case DIO_u8PORTA : *Copy_pu8Value = GET_BIT(PINA  , Copy_u8Pin); break;
			case DIO_u8PORTB : *Copy_pu8Value = GET_BIT(PINB  , Copy_u8Pin); break;
			case DIO_u8PORTC : *Copy_pu8Value = GET_BIT(PINC  , Copy_u8Pin); break;
			case DIO_u8PORTD : *Copy_pu8Value = GET_BIT(PIND  , Copy_u8Pin); break;
			default : Local_ErrorState = DIO_NOK;

		}
	}
	
	else
	{
		Local_ErrorState = DIO_NOK;
	}

	return Local_ErrorState ;


}
