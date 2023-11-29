/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: Timer_1           **************/
/***************  Version: 1.00           *************/
/******************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*
 * @brief : Used to Define Input Capture Edge
 */
typedef enum
{
  FALLING_EDGE = 0,
  RISING_EDGE = 1

}ICU_EDGE;

/*
 * @brief : Used to Initialize Timer_1
 * @param : void
 * @return: void
 */
void Timer1_voidInit(void);

/*
 * @brief : Used to Set Value Timer_1
 * @param : Value to Set
 * @return: void
 */
void Timer1_voidSetValue(u16 Copy_u16TCNT_Value);

/*
 * @brief : Used to Get Value of Timer_1
 * @param : void
 * @return: Current Value of Timer
 */
u16  Timer1_GetTimerReading(void);


/*
 * @brief : Used to Set Value of Timer_1 ChannelA Compare Match
 * @param : void
 * @return: void
 */
void Timer1_voidSetChannelACompareMatch(u16 Copy_u16_CompValue);


/*
 * @brief : Used to  Set Value of Timer_1 ChannelB Compare Match
 * @param : void
 * @return: Current Value of Timer
 */
void Timer1_voidSetChannelBCompareMatch(u16 Copy_u16_CompValue);


/*
 * @brief : Used to Set Value of Timer_1 to Over Flow at it
 * @param : Value of OverFlow Timer_1
 * @return: void
 */
void Timer1_voidSetICR(u16 Copy_u16ICRValue);


/*
 * @brief : Used to Initialize Input Capture Unit
 * @param : void
 * @param : void
 */
void ICU_voidInit(void);


/*
 * @brief : Used to Set the Input Capture Edge
 * @param : Type of Edge ( FALLING_EDGE, RISING_EDGE )
 * @return: Status (OK , NOK)
 */
u8 ICU_u8SetTriggerEdge(ICU_EDGE Edge);


/*
 * @brief : Used to Read Input Capture Value
 * @param : void
 * @return: Value of Input Capture
 */
u16 ICU_u16ReadInputCapture(void);


/*
 * @brief : Used to Enable Input Capture Unit
 * @param : void
 * @return: void
 */
void ICU_EnableInerrupt(void);



/*
 * @brief : Used to Disable Input Capture Unit
 * @param : void
 * @return: void
 */
void ICU_DisableInterrupt(void);



/*
 * @brief : Used to Set Input Capture CallBack
 * @param : Pointer to CallBack Function
 * @return: Status(OK, NOK)
 */
u8 ICU_SetCallBack(void (*Copy_pvCallBack)(void));



#endif
