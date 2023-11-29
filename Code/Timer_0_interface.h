/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: Timer_0           **************/
/***************  Version: 1.00          *************/
/******************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_



/*
Description: Function Used to Intialize Timer0 Based on Configuration on Config File.
Parameters: void
Return: void
*/
void Timer0_voidInit(void);


/*
Description: Function Used to Set Value of Compare match Register.
Parameters: Value of Compare match Register (0-255)
Return: void
*/
void Timer0_voidSetCompareMatch(u8 value);


/*
Description: Function Used to Enable OverFlow Interrupt.
Parameters: void
Return: void
*/
void Timer0_EnableOverFlowInterrupt();


/*
Description: Function Used to Disable OverFlow Interrupt.
Parameters: void
Return: void
*/
void Timer0_DisableOverFlowInterrupt();


/*
Description: Function Used to Enable Compare match Interrupt.
Parameters: void
Return: void
*/
void Timer0_EnableCompareMatchInterrupt();


/*
Description: Function Used to Disable Compare match Interrupt.
Parameters: void
Return: void
*/
void Timer0_DisableCompareMatchInterrupt();



/*
Description: Function Used to Set CallBack Function to Execute when Timer overflow Happen
Parameters: pointer to callBack Function
Return: 
    1-OK
	2-NULL_Pointer
*/
u8 Timer0_CTC_u8SetCallBack(void(*Copy_pvSetcallBack)(void));



/*
Description: Function Used to Set CallBack Function to Execute when  Compare match Happen
Parameters: pointer to callBack Function
Return: 
    1-OK
	2-NULL_Pointer
*/
u8 Timer0_OverFlow_u8SetCallBack(void(*Copy_pvSetcallBack)(void));


#endif
