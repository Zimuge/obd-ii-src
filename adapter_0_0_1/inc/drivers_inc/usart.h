/*
 * bluetooth_usart.h
 *
 *  Created on: 2016年12月22日
 *      Author: Topon-Edison
 */

#ifndef DRIVERS_INC_USART_H_
#define DRIVERS_INC_USART_H_
#include <cstdint>



struct  RINGBUFF_T;
struct  LPC_USART_T;
struct  UART_CONFIG_T;

typedef void *UART_HANDLE_T;
typedef void (*RX_CALLBACK_T)(char);

const int TX_BUFFER_LEN = 256;
const int UART_Handle_MEM_LEN = 40;




enum UART_TYPE
{
	LPC_UART0_CHANNEL = 0,
	LPC_UART1_CHANNEL,
	LPC_UART2_CHANNEL
};

class UART
{
public:
	static UART * Instance(UART_TYPE uart_t);
    void  Uart_Init(const UART_CONFIG_T* pUart_cfg);
	void Set_RX_Callback(RX_CALLBACK_T irq_callback);


	void Send(const char * str,int lenght);
	void Isr_Handle();

private:
	UART(LPC_USART_T* pUSARTn);         // constructor

	void tx_irq_handler();                 // use for transfer interrupt handle
	void rx_irq_handler();                 // use for receive  interrupt handle
	RX_CALLBACK_T rx_callback_;        // callback pointer of call by the rx_handler



	LPC_USART_T* uart_channel_;        // the pointer to uart channel
	uint8_t uart_mem_[UART_Handle_MEM_LEN];        // memory for uart instance
	UART_HANDLE_T uart_handle_;                    // the uart rom api instance's handle

	UART_CONFIG_T uart_cfg_;                       // the configuration value of the uart
	IRQn_Type     uart_irqn_;                      // the uart interrupt slot

	char tx_buffer_[TX_BUFFER_LEN];    // the buffer for ring buffer data
	RINGBUFF_T  tx_ring_buffer_;       // the ring buffer pointer.


};



#endif /* DRIVERS_INC_USART_H_ */
