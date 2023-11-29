#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "DIO_inteface.h"
#include "Timer_0_interface.h"
#include "TIMER_1_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"

#define MCU_CLOCK     8000000
#define HIGH_LEVEL   0
#define LOW_LEVEL    1
#define FALLING      2
#define RISING       3

void ICU_HW(void);

static  u8  Check_Edge     = LOW_LEVEL;
static  u16 PeriodTicks    = 0;
static  u16 OnTicks        = 0;
static  u64 Frequency      = 0;
static  u32 DutyCycle      = 0;
static  u8  Counter        = 0;
static  u8  Counter_3      = 0;
static  u8  OC_Value       = 128;

// Draw Pattern of Signal
u8  RISING_Pattern[8]  = {0b00000,0b00111,0b00100,0b00100,0b00100,0b00100,0b11100,0b00000};
u8  Falling_Pattern[8] = {0b00000,0b11100,0b00100,0b00100,0b00100,0b00100,0b00111,0b00000};
u8  HIGH_Pattern[8]    = {0b00000,0b11111,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};
u8  LOW_Pattern[8]     = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111,0b00000};



int main(void)
{

    //Initialize Compare Match Value
    Timer0_voidSetCompareMatch(OC_Value);

	//Initialize Timer_0
	Timer0_voidInit();

	//Initialize Timer_1
	Timer1_voidInit();

	//Set CallBack Function for ICU
	ICU_SetCallBack(&ICU_HW);

	//Initialize ICU
	ICU_voidInit();

	//Enable Global Interrupt
	GIE_voidEnable();

	//Initialize port
    PORT_voidInit();

    //Initialize CLCD
    CLCD_voidInit();


    CLCD_voidWriteSpecialCharater(LOW_Pattern,0,3,Counter_3++);

    //Used to Read Status of 2 Buttons Used for Change DutyCycle
    u8 Status_1;
    u8 Status_2;

	while(1)
	{
		//Busy Waiting until Period Ticks and on Ticks Measured
		if(Counter == 1)
		{
			CLCD_GoToXY(0,0);
			CLCD_voidSendString("F:");
			CLCD_voidWriteNumber(Frequency);
			CLCD_voidSendString("KHz");
			CLCD_GoToXY(0,11);
			CLCD_voidSendString("Duty:");
			CLCD_voidWriteNumber(DutyCycle);
			CLCD_voidSendData('%');
			CLCD_GoToXY(1,4);
			CLCD_voidSendString("Time:");
			CLCD_voidWriteNumber(PeriodTicks);
			CLCD_voidSendData(230);
			CLCD_voidSendString("Sec");
			Counter++;
		}

		CLCD_GoToXY(0,16);
		CLCD_voidWriteNumber(DutyCycle);

		//Draw Signal
		if(Check_Edge == FALLING)
		{
			CLCD_voidWriteSpecialCharater(Falling_Pattern,0,3,Counter_3++);
			while(Check_Edge == FALLING)
				  CLCD_voidWriteSpecialCharater(LOW_Pattern,1,3,Counter_3++);

		}

		else if(Check_Edge == RISING)
		{
		    CLCD_voidWriteSpecialCharater(RISING_Pattern,2,3,Counter_3++);
			while(Check_Edge == RISING)
				  CLCD_voidWriteSpecialCharater(HIGH_Pattern,3,3,Counter_3++);

		}

        if( Counter_3 > 19)
        {
           Counter_3 = 0;
           CLCD_GoToXY(3,0);
   		   CLCD_voidSendString("                    ");
        }


        DIO_GetPinValue(DIO_u8PORTB,DIO_u8PIN4,&Status_1);
        DIO_GetPinValue(DIO_u8PORTB,DIO_u8PIN5,&Status_2);
        if(Status_1 == 0)
        {
        	OC_Value += 10;
            Timer0_voidSetCompareMatch(OC_Value);

        }
        else if (Status_2 == 0)
        {
        	OC_Value -= 10;
            Timer0_voidSetCompareMatch(OC_Value);

        }

	}


}


void ICU_HW(void)
{
    static u16 Reading1 , Reading2 , Reading3;
    static u8 Local_u8Counter = 0 ;
    static u8 Check_Calc = 0 ;
    Local_u8Counter++;

    if(Local_u8Counter == 1)
    {
    	Reading1 = ICU_u16ReadInputCapture();
    	ICU_u8SetTriggerEdge(0);
        Check_Edge = RISING;
    }

    else if (Local_u8Counter == 2)
    {
    	Reading2 = ICU_u16ReadInputCapture();
    	OnTicks = Reading2 - Reading1;;
    	ICU_u8SetTriggerEdge(1);
    	Check_Edge = FALLING;
    	if(Check_Calc == 1)
    	{
            DutyCycle = (OnTicks*100)/PeriodTicks;
        	Local_u8Counter = 0;
    	}
    }

    else if (Local_u8Counter == 3 && Check_Calc == 0)
    {

    	Reading3 = ICU_u16ReadInputCapture();
    	PeriodTicks = Reading3 - Reading1;
    	DutyCycle = (OnTicks*100)/PeriodTicks;
    	Frequency = (MCU_CLOCK / PeriodTicks)/1000;
    	Check_Calc = 1;
    	Counter = 1;
    	Local_u8Counter = 0;
    }

}

