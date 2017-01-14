/*
 * kwp_usart.h
 *
 *  Created on: 2016年12月22日
 *      Author: Topon-Edison
 */
#ifndef DRIVERS_INC_KWP_USART_H_
#define DRIVERS_INC_KWP_USART_H_
#include <cstdint>

#define RX_BUFFER_LENGTH  256

class UART;
struct  RINGBUFF_T;

class KWP_UART
{
public:
	static KWP_UART * Instance();
	static void  Kwp_RX_Callback(char ch);     // callback for uart1
	void Send(char * str,int length);          // send string use kwp uart
	bool Read(char * data);                           // read char from the _rx_ringbuffer of kwp uart
	void Is_Rx_Ringbuff_Empty();               // is the _rx_ringbuff empty

private:
	KWP_UART();
	UART * _pUsart;
    char buffer[256];
	RINGBUFF_T _rx_ringbuff;
};




#endif /* DRIVERS_INC_KWP_USART_H_ */
