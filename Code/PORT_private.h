/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: PORT              **************/
/***************  Version: 1.00           *************/
/******************************************************/
/******************************************************/

#ifndef PORT_PRIVATE_H
#define PORT_PRIVATE_H

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)   CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_DIR   CONC(PORTA_PIN7_DIR ,PORTA_PIN6_DIR ,PORTA_PIN5_DIR ,PORTA_PIN4_DIR ,PORTA_PIN3_DIR ,PORTA_PIN2_DIR ,PORTA_PIN1_DIR ,PORTA_PIN0_DIR )
#define PORTB_DIR   CONC(PORTB_PIN7_DIR ,PORTB_PIN6_DIR ,PORTB_PIN5_DIR ,PORTB_PIN4_DIR ,PORTB_PIN3_DIR ,PORTB_PIN2_DIR ,PORTB_PIN1_DIR ,PORTB_PIN0_DIR )
#define PORTC_DIR   CONC(PORTC_PIN7_DIR ,PORTC_PIN6_DIR ,PORTC_PIN5_DIR ,PORTC_PIN4_DIR ,PORTC_PIN3_DIR ,PORTC_PIN2_DIR ,PORTC_PIN1_DIR ,PORTC_PIN0_DIR )
#define PORTD_DIR   CONC(PORTD_PIN7_DIR ,PORTD_PIN6_DIR ,PORTD_PIN5_DIR ,PORTD_PIN4_DIR ,PORTD_PIN3_DIR ,PORTD_PIN2_DIR ,PORTD_PIN1_DIR ,PORTD_PIN0_DIR )

#define PORTA_VALUES CONC(PORTA_PIN7_Value ,PORTA_PIN6_Value ,PORTA_PIN5_Value ,PORTA_PIN4_Value ,PORTA_PIN3_Value ,PORTA_PIN2_Value ,PORTA_PIN1_Value ,PORTA_PIN0_Value )
#define PORTB_VALUES CONC(PORTB_PIN7_Value ,PORTB_PIN6_Value ,PORTB_PIN5_Value ,PORTB_PIN4_Value ,PORTB_PIN3_Value ,PORTB_PIN2_Value ,PORTB_PIN1_Value ,PORTB_PIN0_Value )
#define PORTC_VALUES CONC(PORTC_PIN7_Value ,PORTC_PIN6_Value ,PORTC_PIN5_Value ,PORTC_PIN4_Value ,PORTC_PIN3_Value ,PORTC_PIN2_Value ,PORTC_PIN1_Value ,PORTC_PIN0_Value )
#define PORTD_VALUES CONC(PORTD_PIN7_Value ,PORTD_PIN6_Value ,PORTD_PIN5_Value ,PORTD_PIN4_Value ,PORTD_PIN3_Value ,PORTD_PIN2_Value ,PORTD_PIN1_Value ,PORTD_PIN0_Value )

#endif //PORT_PRIVATE_H
