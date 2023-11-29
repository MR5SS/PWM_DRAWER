/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: Timer             **************/
/***************  Version: 1.00           *************/
/******************************************************/

/************************ Include Libraries *************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/*******************************************************************/

/*********************** Include MCAL ******************************/
#include "Timer_0_register.h"
#include "Timer_0_interface.h"
#include "Timer_0_private.h"
#include "Timer_0_config.h"
/*******************************************************************/

//Intailize Global Pointers
static void(*Timer0_pvSetcallback)(void) = Null;
static void(*Timer0_CTC_pvSetCallback)(void) = Null;




//Timer 0 Functions
void Timer0_voidInit(void)
{
   //Select Wave Form Generation Mode
   #if Wave_FormGen_Mode == CTC
	   SET_BIT(TCCR0,TCCR0_WGM1);
	   CLR_BIT(TCCR0,TCCR0_WGM0);

   #elif Wave_FormGen_Mode == Normal
	   CLR_BIT(TCCR0,TCCR0_WGM1);
	   CLR_BIT(TCCR0,TCCR0_WGM0);

   #elif Wave_FormGen_Mode == PWM_PhaseCorrect
	   CLR_BIT(TCCR0,TCCR0_WGM1);
	   SET_BIT(TCCR0,TCCR0_WGM0);

   #elif  Wave_FormGen_Mode == Fast_PWM
	   SET_BIT(TCCR0,TCCR0_WGM1);
	   SET_BIT(TCCR0,TCCR0_WGM0);

   #else
     #error"Wrong Configuration For WFG"

#endif


	//Select Compare Match OutputMode

  #if Compare_MatchOutput_Mode == Disconnected
	   CLR_BIT(TCCR0,TCCR0_COM00);
	   CLR_BIT(TCCR0,TCCR0_COM01);

  #elif Compare_MatchOutput_Mode == Toggle
	   SET_BIT(TCCR0,TCCR0_COM00);
       CLR_BIT(TCCR0,TCCR0_COM01);

  #elif Compare_MatchOutput_Mode == Set
       SET_BIT(TCCR0,TCCR0_COM00);
       SET_BIT(TCCR0,TCCR0_COM01);

  #elif Compare_MatchOutput_Mode == Clear
       CLR_BIT(TCCR0,TCCR0_COM00);
       SET_BIT(TCCR0,TCCR0_COM01);

  #elif Compare_MatchOutput_Mode == COCSOT
       CLR_BIT(TCCR0,TCCR0_COM00);
       SET_BIT(TCCR0,TCCR0_COM01);

  #elif Compare_MatchOutput_Mode == SOCCOT
      SET_BIT(TCCR0,TCCR0_COM00);
      SET_BIT(TCCR0,TCCR0_COM01);

  #else
      #error"Wrong Configuration For CMOM"

#endif


   //Set Prescalar (Enable Timer)
    TCCR0  &= Prescalar_Mask;
    TCCR0  |= TimerClock;



}



u8 Timer0_OverFlow_u8SetCallBack(void(*Copy_pvSetcallBack)(void))
{
   u8 Local_u8ErrorStatus = OK;

   if(Copy_pvSetcallBack != Null)
   {
	   Timer0_pvSetcallback = Copy_pvSetcallBack;
   }

   else
   {
	   Local_u8ErrorStatus = NULL_Pointer;
   }

   return Local_u8ErrorStatus;
}


u8 Timer0_CTC_u8SetCallBack(void(*Copy_pvSetcallBack)(void))
{
   u8 Local_u8ErrorStatus = OK;

   if(Copy_pvSetcallBack != Null)
   {
	 Timer0_CTC_pvSetCallback = Copy_pvSetcallBack;
   }

   else
   {
	   Local_u8ErrorStatus = NULL_Pointer;
   }

   return Local_u8ErrorStatus;
}


void Timer0_EnableOverFlowInterrupt()
{

	SET_BIT(TIMSK,0);

}


void Timer0_DisableOverFlowInterrupt()
{

	CLR_BIT(TIMSK,0);

}


void Timer0_voidSetCompareMatch(u8 value)
{
	OCR0 = value;
}


void Timer0_EnableCompareMatchInterrupt()
{

	SET_BIT(TIMSK,1);
}


void Timer0_DisableCompareMatchInterrupt()
{

	CLR_BIT(TIMSK,1);
}


//ISR OF Timer 0 Overflow
void __vector_11 (void)   __attribute__((signal));
void __vector_11 (void)
{

	if(Timer0_pvSetcallback != Null)
	{
		Timer0_pvSetcallback();
	}

}

//ISR OF Timer 0 CTC
void __vector_10 (void)   __attribute__((signal));
void __vector_10 (void)
{

	if(Timer0_CTC_pvSetCallback != Null)
	{
		Timer0_CTC_pvSetCallback();
	}

}
