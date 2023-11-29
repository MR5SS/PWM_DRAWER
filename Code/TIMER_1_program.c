/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: Timer_1           **************/
/***************  Version: 1.00           *************/
/******************************************************/

/******************* Include Library *******************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*******************************************************/

/******************* Include MCAL **********************/
#include "TIMER_1_Register.h"
#include "TIMER_1_interface.h"
#include "TIMER_1_private.h"
#include "TIMER_1_config.h"
/*******************************************************/

//Intailize Global Pointers
static void(*Timer1_pvSetcallback)(void) = Null;
static void(*ICR_pvSetCallback)(void)    = Null;

//Timer 1 Fucntions
void Timer1_voidInit(void)
{

	   //Select Wave Form Generation Mode
	   #if  Wave_FormGen_Mode_T1  == CTC
		   CLR_BIT(TCCR1A,TCCR1A_WEM10);
		   CLR_BIT(TCCR1A,TCCR1A_WEM11);
		   SET_BIT(TCCR1B,TCCR1B_WEM12);
		   CLR_BIT(TCCR1B,TCCR1B_WEM13);

	   #elif  Wave_FormGen_Mode_T1  == Normal
		   CLR_BIT(TCCR1A,TCCR1A_WEM10);
		   CLR_BIT(TCCR1A,TCCR1A_WEM11);
		   CLR_BIT(TCCR1B,TCCR1B_WEM12);
		   CLR_BIT(TCCR1B,TCCR1B_WEM13);

	   #elif Wave_FormGen_Mode_T1  == PWM_PhaseCorrect
		   SET_BIT(TCCR1A,TCCR1A_WEM10);
		   CLR_BIT(TCCR1A,TCCR1A_WEM11);
		   CLR_BIT(TCCR1B,TCCR1B_WEM12);
		   CLR_BIT(TCCR1B,TCCR1B_WEM13);


	   #elif Wave_FormGen_Mode_T1  == Fast_PWM
		   CLR_BIT(TCCR1A,TCCR1A_WEM10);
		   SET_BIT(TCCR1A,TCCR1A_WEM11);
		   SET_BIT(TCCR1B,TCCR1B_WEM12);
		   SET_BIT(TCCR1B,TCCR1B_WEM13);


	   #else
	     #error"Wrong Configuration For WFG"

	#endif


		//Select Compare Match OutputMode

	  #if Compare_MatchOutput_Mode_A == Disconnected
		   CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		   CLR_BIT(TCCR1A,TCCR1A_COM1A1);

	  #elif Compare_MatchOutput_Mode_A == Toggle
		   SET_BIT(TCCR1A,TCCR1A_COM1A0);
		   CLR_BIT(TCCR1A,TCCR1A_COM1A1);

	  #elif Compare_MatchOutput_Mode_A == Set
		   SET_BIT(TCCR1A,TCCR1A_COM1A0);
		   SET_BIT(TCCR1A,TCCR1A_COM1A1);

	  #elif Compare_MatchOutput_Mode_A == Clear
		   CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		   SET_BIT(TCCR1A,TCCR1A_COM1A1);

	  #else
	      #error"Wrong Configuration For CMOM Channel A"

	#endif


		#if Compare_MatchOutput_Mode_B == Disconnected
			   CLR_BIT(TCCR1A,TCCR1A_COM1B0);
			   CLR_BIT(TCCR1A,TCCR1A_COM1B1);

		#elif Compare_MatchOutput_Mode_B == Toggle
			   SET_BIT(TCCR1A,TCCR1A_COM1B0);
			   CLR_BIT(TCCR1A,TCCR1A_COM1B1);

		#elif Compare_MatchOutput_Mode_B == Set
			   SET_BIT(TCCR1A,TCCR1A_COM1B0);
			   SET_BIT(TCCR1A,TCCR1A_COM1B1);

		#elif Compare_MatchOutput_Mode_B == Clear
			   CLR_BIT(TCCR1A,TCCR1A_COM1B0);
			   SET_BIT(TCCR1A,TCCR1A_COM1B1);

		#else
			#error"Wrong Configuration For CMOM Channel B"

	#endif


	   //Set Prescalar (Enable Timer)
	    TCCR1B  &= Prescalar_Mask;
	    TCCR1B  |= TimerClock;


}
void Timer1_voidSetValue(u16 Copy_u16TCNT_Value)
{
	TCNTLH = Copy_u16TCNT_Value;
}
u16  Timer1_GetTimerReading(void)
{
	return TCNTLH;
}
void Timer1_voidSetChannelACompareMatch(u16 Copy_u16_CompValue)
{
	OCR1ALH = Copy_u16_CompValue;
}
void Timer1_voidSetChannelBCompareMatch(u16 Copy_u16_CompValue)
{
	OCR1BLH = Copy_u16_CompValue;
}
void Timer1_voidSetICR(u16 Copy_u16ICRValue)
{
	ICR1LH = Copy_u16ICRValue;
}
u8 Timer1_SetCallBack(void (*Copy_pvSetCallBack)(void))
{
	u8 Local_u8ErrorState = OK;

	if(Copy_pvSetCallBack != Null)
	{
		Timer1_pvSetcallback = Copy_pvSetCallBack;
	}

	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;

}

//ICU Functions
void ICU_voidInit(void)
{
	//Set trigger source to rising edge
	SET_BIT(TCCR1B,TCCR1B_ICES1);

   //Enable Input Capture Register Interrupt
	SET_BIT(TIMSK1,TIMSK1_TICIE1);
}
u8 ICU_u8SetTriggerEdge(ICU_EDGE Edge)
{
	u8 Local_u8ErrorState = OK;
	switch(Edge)
	{
		 case FALLING_EDGE:CLR_BIT(TCCR1B,TCCR1B_ICES1);break;
		 case  RISING_EDGE: SET_BIT(TCCR1B,TCCR1B_ICES1);break;
		 default : Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
u16 ICU_u16ReadInputCapture(void)
{
	return ICR1LH;
}
void ICU_EnableInerrupt(void)
{
	//Enable Input Capture Register Interrupt
		SET_BIT(TIMSK1,TIMSK1_TICIE1);
}
void ICU_DisableInterrupt(void)
{
	//Disable Input Capture Register Interrupt
		CLR_BIT(TIMSK1,TIMSK1_TICIE1);
}

u8 ICU_SetCallBack(void (*Copy_pvCallBack)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvCallBack != Null)
	{
	 ICR_pvSetCallback = Copy_pvCallBack;
    }
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}


//ISR of Timer_1 OverFlow
void __vector_9 (void)   __attribute__((signal));
void __vector_9 (void)
{
	if(Timer1_pvSetcallback != Null)
	{
	  Timer1_pvSetcallback();
	}
	else
	{
		//do nothing
	}
}


//ISR OF ICR
void __vector_6 (void)  __attribute__((signal));
void __vector_6(void)
{
	if(ICR_pvSetCallback != Null)
		ICR_pvSetCallback();
}

