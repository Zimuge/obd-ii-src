/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/


#include <cr_section_macros.h>
//#include <cstdint>

// TODO: insert other include files here
#include "board_configure.h"
#include "timer.h"
#include "led.h"

// TODO: insert other definitions and declarations here

void LongTimer_Callback();


int main(void)
{

    // TODO: insert code here

	//Board_Init();
    Board_Configure::instance()->Configure();

    uint32_t MianClock = Board_Configure::instance()->Get_MainClockRate();

    Timer * pled_blink_timer = Timer::Instance(Timer0);
    Led * pled = Led::instance();
    LongTimer * plongtimer = LongTimer::Instance(LongTimer_Callback);
    //LongTimer * longtimer = LongTimer::Instance(0);

    pled->Lighten_Led_TX();
    pled->Lighten_Led_RX();

    pled->Off_Led_TX();
    //Led::instance()->Off_Led_RX();
    pled->Toggle_Led_TX();
    pled->Toggle_Led_RX();

    // Force the counter to be placed into memory*/
	volatile static uint32_t i = 0 ;

    // Enter an infinite loop, just incrementing a counter

	/* the MRT timer can maximum delay the timer for 233ms */
	//led_blink_timer->Start_Millisecond(200);

	plongtimer->Start_Millisecond(1000);
    while(1)
    {

    	/*if(led_blink_timer->IsExpired())
    	{
    		i++ ;
    		led_blink_timer->Start_Millisecond(200);
    	}
    	if(i == 5)// 1 second
    	{
    		i = 0;
    		led->Toggle_Led_TX();
    		led->Toggle_Led_RX();
    	}*/
    	if(plongtimer->IsExpired())
    	{
    		//LongTimer_Callback();
    		plongtimer->Start_Millisecond(1000);
    		pled->Blink_Led_RX();
    		pled->Blink_Led_TX();
    	}
    	i++;
    }
    return 0 ;
}


void LongTimer_Callback()
{
	Led * led = Led::instance();
	led->Toggle_Led_TX();
	led->Toggle_Led_RX();
}
