/*
 * bluetooth_usart.cpp
 *
 *  Created on: 2016年12月22日
 *      Author: Topon-Edison
 *
 *
 */

#include "chip.h"
#include "adapter_board.h"
#include "usart.h"
#include "led.h"
#include "timer.h"



/* @brief Constructor, configure the uart channel, use the rom api uart_setup
 *        to setup the uart instance use the corresponding  channel indicated by
 *        uart_channel and initialize the RingBuffer
 * @param pUSARTn the pointer to the USART channel
 */
UART::UART(LPC_USART_T* pUSARTn):uart_channel_(pUSARTn)
{
	/* Set the interrupt slot of the uart*/
	if(uart_channel_ == LPC_USART0)
		uart_irqn_ = UART0_IRQn;
	if(uart_channel_ == LPC_USART1)
		uart_irqn_ = UART1_IRQn;
	if(uart_channel_ == LPC_USART2)
		uart_irqn_ = UART2_IRQn;

	/* Setup the USART and create the instance,it can only be use in the constructor for one time, because the
	 * USART can only have one instance
	 */
	uint32_t size = LPC_UARTD_API->uart_get_mem_size();
	uart_handle_ = LPC_UARTD_API->uart_setup(reinterpret_cast<uint32_t>(uart_channel_), uart_mem_);

	/* Initialize the RingBuffer tx_ring_buffer using of tx_buffer, and the TX_BUFFER_LEN must be
	*  power of 2
	*/
	RingBuffer_Init(&tx_ring_buffer_,tx_buffer_,1,TX_BUFFER_LEN);

}


/* @brief The factory to return the singleton instrance's pointer according to the
 *        uart_t
 */
UART* UART::Instance(UART_TYPE uart_t)
{
	static UART UART0(LPC_USART0);// set the uart0 for bluetooth uart
	static UART UART1(LPC_USART1);      // set the uart1 for kwp uart
	static UART UART2(LPC_USART2);  // set the uart2 for default uart

	// according to the uart_t to return the instance
	switch (uart_t)
	{
	case LPC_UART0_CHANNEL:
		return &UART0;
	case LPC_UART1_CHANNEL:
		return &UART1;
	case LPC_UART2_CHANNEL:
		return &UART2;
	default:
		return 0;

	}
}


/* @brief The function use to initialize the USART instance by the uart_init()
 *        the pUart_cfg contains the parameter for initialize the USART,
 *        at the end of the function enable the interrupt of the USART, enable
 *        interrupt source RX.
 */
void UART::Uart_Init(const UART_CONFIG_T * pUart_cfg)
{


  /*Disable the uart interrupt */
  NVIC_DisableIRQ(uart_irqn_);

  /* setup the uart_cfg_ for the uart API uart_init() */
  uart_cfg_.sys_clk_in_hz = 14976000; // the clock of the USART clock
  uart_cfg_.baudrate_in_hz = pUart_cfg->baudrate_in_hz;
  uart_cfg_.config = pUart_cfg->config;
  uart_cfg_.sync_mod = pUart_cfg->sync_mod;
  uart_cfg_.error_en = pUart_cfg->error_en;

  /* Configure the uart basic property use the uart_cfg, such as the baudrate,mode and so on */
  LPC_UARTD_API->uart_init( uart_handle_, &uart_cfg_);

  /* Every time initialize the USART, clear the buffer
   */
  RingBuffer_Flush(&tx_ring_buffer_);

  /* Enable the uart interrupt slot */
  NVIC_EnableIRQ(uart_irqn_);

  /* Enable the uart RX interrupt source */
  Chip_UART_IntEnable(uart_channel_, UART_INTEN_RXRDY);
}



/* @brief Set the callback for RX interrupt handle, when the
 *        USART RX generate a interrupt the interrupt routine
 *        call the RX interrupt handleand the interrupt handle
 *        call the callback function
 */

void UART::Set_RX_Callback(RX_CALLBACK_T rx_callback)
{
	rx_callback_ = rx_callback;
}



/* @brief Push the str to the tx_ring_buffer for transmit data
 * and enable TX interrupt
 */
void UART::Send(const char *str,int length)
{
	Chip_UART_IntEnable(uart_channel_,UART_INTEN_TXRDY);
	/* Wait until there is enough space for new data */
	while(RingBuffer_GetFree(&tx_ring_buffer_) < length)
	{

	}

	/* Push the data to the ring buffer */
	RingBuffer_InsertMult(&tx_ring_buffer_,str,length);

	/* Enable the UART TX interrupt */
	Chip_UART_IntEnable(uart_channel_,UART_INTEN_TXRDY);
}


/* @brief Interrupt handle for UART */
void  UART::Isr_Handle()
{

	if(Chip_UART_GetIntStatus(uart_channel_)& UART_STAT_TXRDY)
	{
		tx_irq_handler();
		Led::instance()->Blink_Led_TX();

	}
	if(Chip_UART_GetIntStatus(uart_channel_) & UART_STAT_RXRDY)
	{
		rx_irq_handler();
	}
}


void UART::tx_irq_handler()
{
	Timer::Instance(Timer1)->Stop();
	if(RingBuffer_IsEmpty(&tx_ring_buffer_))// the ring buffer is empty
	{
		/* Ring buffer is empty, disable the TX interrupt
		 * cause of there is no data to be transmit
		 */
		Chip_UART_IntDisable(uart_channel_,UART_INTEN_TXRDY);
	}
	else
	{
		if(Chip_UART_GetStatus(uart_channel_) & UART_STAT_TXRDY)
		{
			char ch;

			/* Pop the first element of ring buffer to ch */
			RingBuffer_Pop(&tx_ring_buffer_,&ch);

			/* tansfer the data */
			Chip_UART_SendByte(uart_channel_,ch);
		}
	}
	Timer::Instance(Timer1)->Start_Millisecond(100);
}


void UART::rx_irq_handler()
{
	if(Chip_UART_GetStatus(uart_channel_) & UART_STAT_RXRDY)
	{
		char ch = (uint8_t)Chip_UART_ReadByte(uart_channel_);
		if(rx_callback_)
		{
			(*rx_callback_)(ch);
		}
	}
}


extern "C" void UART0_IRQHandler(void)
{
	UART * pUart = UART::Instance(LPC_UART0_CHANNEL);
	if(pUart)
	{
		pUart->Isr_Handle();
	}
}

extern "C" void UART1_IRQHandler(void)
{
	UART * pUart = UART::Instance(LPC_UART1_CHANNEL);
	if(pUart)
	{
		pUart->Isr_Handle();
	}
}


extern "C" void UART2_IRQHandler(void)
{
	UART * pUart = UART::Instance(LPC_UART2_CHANNEL);
	if(pUart)
	{
		pUart->Isr_Handle();
	}
}
