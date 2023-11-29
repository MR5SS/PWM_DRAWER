/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: GLOBAL Interuppt  **************/
/***************  Version: 1.00           *************/
/******************************************************/


/**************** INCLUDE LIBRARYS ***********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************************************************/


/***************** INCLUDE MCAL **************************/
#include "GIE_register.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"
/*********************************************************/


void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_GIE_I);

}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_GIE_I);
}


void GIE_voidReadStatus(u8 *Copy_u8Status)
{
	
	GET_BIT(SREG,SREG_GIE_I);
}