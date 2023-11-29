/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: GLOBAL Interuppt  **************/
/***************  Version: 1.00          **************/
/******************************************************/


#ifndef GIE_INTERFACE_H
#define GIE_INTERFACE_H

/*
Description: Function Used To Enable Global Interrupt for all peripherals
Parameter:void
Return:void
*/
void GIE_voidEnable(void);


/*
Description: Function Used To Disable Global Interrupt for all peripherals
Parameter:void
Return:void
*/
void GIE_voidDisable(void);


/*
Description: Function Used To Read Global Interrupt Bit in Processor Status Register
Parameter:Pointer to Variable to Hold status of Bit 
Return:void
*/
void GIE_voidReadStatus(u8 *Copy_u8Status);


#endif //GIE_INTERFACE_H
