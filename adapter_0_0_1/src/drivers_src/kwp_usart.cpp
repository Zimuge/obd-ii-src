/*
 * kwp_usart.cpp
 *
 *  Created on: 2017年1月12日
 *      Author: cheri
 */


#include "chip.h"
#include "usart.h"
#include "kwp_usart.h"




KWP_UART * KWP_UART::Instance()
{
	static KWP_UART kwp_uart;
	return &kwp_uart;
}

KWP_UART::KWP_UART():_pUsart(UART::Instance(LPC_UART1_CHANNEL))
{
     _pUsart->Set_RX_Callback(&KWP_UART::Kwp_RX_Callback);

}



void KWP_UART::Send(char *str,int length)
{
	_pUsart->Send(str,length);
}

void KWP_UART:: Kwp_RX_Callback(char ch)
{

}



