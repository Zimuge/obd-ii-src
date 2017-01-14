/*
 *
 * led.h
 *
 *  Created on: 2016年12月22日
 *      Author: Topon-Edison
 *      */


/**
 * @brief The class for adapter's led which are
 * used for indicating the communication between
 * adapter and ECUS
 *
 */

#ifndef DRIVERS_INC_LED_H_
#define DRIVERS_INC_LED_H_


#include <cstdint>

class LedTimer; // declaration of the LedTimer;
typedef void (*Led_Callback_T) ();// define the callback function type

const uint32_t lighten_minimum_gap = 10; // the minimum gap of the blink longeverty
const uint32_t gap_num = 5;             // the gap_num for the blink

using namespace std;

class Led
{
public:

	static Led* instance();
    void Start_Timer();
    void Stop_Timer();
    void Lighten_Led_TX();
    void Lighten_Led_RX();
    void Blink_Led_TX();
    void Blink_Led_RX();
	void Off_Led_TX();
	void Off_Led_RX();
	void Toggle_Led_TX();
	void Toggle_Led_RX();

	~Led();
private:
	Led();
	static void Led_Callback(); // the callback function need be defined before the led_timer_
	LedTimer * led_timer_;     // reduce the
	volatile static uint32_t tx_count_;
	volatile static uint32_t rx_count_;
	//friend void callback();
};






#endif /* DRIVERS_INC_LED_H_ */
