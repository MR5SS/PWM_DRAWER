/******************************************************/
/******************************************************/
/***************  Author:Mazen Ibrahim   **************/
/***************  Layer:  MCAL           **************/
/***************  SWC: Timer             **************/
/***************  Version: 1.00           *************/
/******************************************************/

#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/*
 options:
    1-Normal
    2-PWM_PhaseCorrect
    3-CTC
    4-Fast_PWM:
      1- clear on top ,set on comp(inverted)
      2- set on top , clear on comp

 */

#define Wave_FormGen_Mode     Fast_PWM

/*
 options:
    1-Disconnected
    2-Toggle
    3-Clear
    4-Set
    5-COCSOT(Fast PWM Only)
    6-SOCCOT(Fast PWM only)
*/
#define Compare_MatchOutput_Mode  COCSOT

/*
 options:
    1-No_Clock_Source
    2-System_Clock
    3-DivisionBy_8
    4-DivisionBy_64
    5-DivisionBy_256
    6-DivisionBy_1024
    7-ExternalClock_F
    8-ExternalClock_R
*/

#define TimerClock     DivisionBy_8


// Range(0-255)
#define Compare_Match_Value   125



#endif
