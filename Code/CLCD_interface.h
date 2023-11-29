/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  HAL            **************/
/***************  SWC: CLCD              **************/
/***************  Version: 1.00           *************/
/******************************************************/
/******************************************************/


#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
/*
*@brief:used to send command to lcd 
*@param: copy_u8Command: byte of data to send as command to lcd 
*@return: void
*/
void CLCD_voidSendCommand(u8 Copy_u8Command);


/*
*@brief:used to send data to lcd 
*@param: copy_u8Data: byte of data to send as data to lcd 
*@return: void
*/
void CLCD_voidSendData(u8 Copy_u8Data);


/*
*@brief:used to Initialize lcd  
*@param: void 
*@return: void
*/
void CLCD_voidInit(void);



/*
*@brief:used to send string to lcd 
*@param: copy_pcString: pointer to array of char 
*@return: void
*/
void CLCD_voidSendString(const char* Copy_pcString);



/*
*@brief:used to put poistion of char  
*@param: copy_u8XPos: poistion of X (0..1) , copy_u8YPos: position of Y (0..15) 
*@return: void
*/
void CLCD_GoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);



/*
*@brief:used to write special pattern in lcd 
*@param: copy_u8Pattern: array of bytes of Pattern , copy_u8PatternNumber: (0..7)
*@return: void
*/
void CLCD_voidWriteSpecialCharater(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber,u8 XPos , u8 YPos);



/*
*@brief: used to write any number to lcd 
*@param: copy_u32Number : positive 32 bit number
*@return: void
*/
void CLCD_voidWriteNumber(u32 Copy_u32Number);

/*
*@brief:used to clear lcd and write 2 lines in _16X2 lcd Type 
*@param: Line1 , Line2
*@return: void
*/
void CLCD_voidWrite_2Lines(const char*Line1,const char*Line2);


/*
*@brief:used to clear lcd and write 3 lines in _16*4 or _20X4 lcd Type 
*@param: Line1 , Line2 , Line3
*@return: void
*/
void CLCD_voidWrite_3Lines(const char*Line1,const char*Line2,const char*Line3);



/*
*@brief:used to clear lcd and write 4 lines in _16*4 or _20X4 lcd Type 
*@param: Line1 , Line2 , Line3, Line4
*@return: void
*/
void CLCD_voidWrite_4Lines(const char*Line1,const char*Line2,const char*Line3,const char*Line4);


#endif
