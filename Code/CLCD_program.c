/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  HAL            **************/
/***************  SWC: CLCD              **************/
/***************  Version: 1.00           *************/
/******************************************************/
/******************************************************/

/********************* Include Library ****************/
#include<util/delay.h>
#include <stdlib.h>
#include"STD_TYPES.h"
/******************************************************/

/******************** Include MCAL *******************/
#include"DIO_private.h"
#include"DIO_inteface.h"
/*****************************************************/

/******************* Include HAL ********************/
#include"CLCD_config.h"
#include"CLCD_private.h"
#include"CLCD_interface.h"
/****************************************************/


void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	// set RS pin low for command
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	// set RW Pin low for Write
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	// Send command Data
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);


	// set enable pulse
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_LOW);

}

void CLCD_voidSendData(u8 Copy_u8Data)
{

	// set RS pin High for Data
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	// set RW Pin low for Write
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	// Send  Data
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	// set enable pulse
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidInit(void)
{
	// wait for more than 30ms
	_delay_ms(40);

	// function set command : 1 Lines ,5*8 FontSize
#if LCD_TYPE == _16X1
	CLCD_voidSendCommand(0b00110000);
#endif

	// function set command : 2 Lines ,5*8 FontSize
#if LCD_TYPE == _16X2
	CLCD_voidSendCommand(0b00111000);
#endif

	// function set command : 2 Lines ,5*8 FontSize
#if LCD_TYPE == _20X4
	CLCD_voidSendCommand(0b00111000);
#endif

	// function Display on / off : enable display , disable cursor, disable blink
	CLCD_voidSendCommand(0b00001100);

	// function clear Display
	CLCD_voidSendCommand(0b0000001);

}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 i = 0;

	while(Copy_pcString[i]!='\0')
	{
		CLCD_voidSendData(Copy_pcString[i]);
		i++;
	}
}

void CLCD_GoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Adress;
	if(Copy_u8XPos == 0)
	{
		Local_u8Adress = Copy_u8YPos;
	}

	else if (Copy_u8XPos == 1)
	{
		Local_u8Adress = Copy_u8YPos + 0x40;
	}

	else if (Copy_u8XPos == 2)
	{
		Local_u8Adress = Copy_u8YPos + 0x14;
	}

	else if (Copy_u8XPos == 3)
	{
		Local_u8Adress = Copy_u8YPos + 0x54;
	}

	CLCD_voidSendCommand(Local_u8Adress+128);
}


void CLCD_voidWriteSpecialCharater(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber,u8 XPos , u8 YPos)
{
	u8 Local_u8CGRAMAddress = 0, Local_u8Iterator;

	/* Calculate CGRAM Address */
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8 ;

	/* Send  CGRAM Address command to  LCD  */
	CLCD_voidSendCommand(Local_u8CGRAMAddress + 64);

	/* Write Pattern in CGRAM */
	for(Local_u8Iterator = 0 ; Local_u8Iterator<8 ; Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_u8Pattern[Local_u8Iterator]);
	}

	/* GO back to DDRAM */
	CLCD_GoToXY(XPos,YPos);

	/* Display Pattern Written in CGRAM */
	CLCD_voidSendData(Copy_u8PatternNumber);
}


void CLCD_voidWriteNumber(u32 Copy_u32Number)
{
	u8 index = 14 ;
	u8 *ptr = (u8*)calloc(15,1);
	u8 number = 0;
	while(Copy_u32Number != 0)
	{
		number =  Copy_u32Number % 10 ;
		ptr[index--] =  number + 48;
		Copy_u32Number = Copy_u32Number/10;
	}


	for(index = 0 ; index <15 ; index++)
	{
		if(ptr[index]==0)
			continue;
		else
			CLCD_voidSendData(ptr[index]);

	}

	free(ptr);
}


void CLCD_voidWrite_2Lines(const char*Line1,const char*Line2)
{
	CLCD_voidSendCommand(0b0000001);

	CLCD_GoToXY(0,0);
	CLCD_voidSendString(Line1);

	CLCD_GoToXY(1,0);
	CLCD_voidSendString(Line2);

}

void CLCD_voidWrite_3Lines(const char*Line1,const char*Line2,const char*Line3)
{
	CLCD_voidSendCommand(0b0000001);

	CLCD_GoToXY(0,0);
	CLCD_voidSendString(Line1);

	CLCD_GoToXY(1,0);
	CLCD_voidSendString(Line2);

	CLCD_GoToXY(2,0);
	CLCD_voidSendString(Line3);

}


void CLCD_voidWrite_4Lines(const char*Line1,const char*Line2,const char*Line3,const char*Line4)
{
	CLCD_voidSendCommand(0b0000001);

	CLCD_GoToXY(0,0);
	CLCD_voidSendString(Line1);

	CLCD_GoToXY(1,0);
	CLCD_voidSendString(Line2);

	CLCD_GoToXY(2,0);
	CLCD_voidSendString(Line3);

	CLCD_GoToXY(3,0);
	CLCD_voidSendString(Line4);

}

