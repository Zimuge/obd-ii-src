/*
 * board.h
 *
 *  Created on: 2016年12月20日
 *      Author: Topon-Edison
 */


/*
 *
 *
 * @brief this file is for the board layer, including the bindings for peripheral pins,
 *
 * the basic configuration for peripheral and IO, configuration for clock, power management and etc.
 *
 * For instance the UARTs' TX and RX pins binding，The clock frequency
 *
 *
 */


#ifndef DRIVERS_INC_BOARD_BOARD_H_
#define DRIVERS_INC_BOARD_BOARD_H_


/**
 *
 * @brief definitions of the USARTS for driver's layer
 *
 */

#define BLUETOOTH_USART       LPC_USART0         /*!< Using the usart0 for the bluetooth usart to communicate with bluetooth */
#define KWP_USART             LPC_USART1         /*!< Using the usart1 for the KWP2000 protocol device */
#define CAN                   LPC_CAN            /*!< Using the C_CAN0 for the CAN protocol device */


/**
 *
 * @brief definitions for the pin of the peripheral
 *
 */
#define TX_LED_PORT                     0            /*!< LED port for indicating transmit data to ECU */
#define TX_LED_PIN                      24           /*!< LED pin for indicating transmit data to ECU */
#define RX_LED_PORT                     0            /*!< LED port for indicating transmit to board */
#define RX_LED_PIN                      25           /*!< LED pin for indicating transmit to board */

#define KWP_TX_PORT                     0            /*!< Kwp2000's  TX PORT */
#define KWP_TX_PIN                      22           /*!< Kwp2000's  TX PIN */
#define KWP_RX_PORT                     0            /*!< Kwp2000's  RX PORT */
#define KWP_RX_PIN                      23           /*!< Kwp2000's  RX PORT */

#define CAN_TX_PORT                     0            /*!< CAN's TX PORT */
#define CAN_TX_PIN                      26           /*!< CAN's TX PIN */
#define CAN_RX_PORT                     0            /*!< CAN's RX PORT */
#define CAN_RX_PIN                      27           /*!< CAN's TX PIN */


#define BLUETOOTH_TX_PORT               0            /*!< Bluetooth's TX PORT */
#define BLUETOOTH_TX_PIN                1            /*!< Bluetooth's TX PIN */
#define BLUETOOTH_RX_PORT               0            /*!< Bluetooth's RX PORT */
#define BLUETOOTH_RX_PIN                0            /*!< Bluetooth's RX PIN */


typedef enum PLL_TYPE
{
	SYSTEM_PLL = 0,    /*!< System PLL type */
	USB_PLL = 0,       /*!< USB PLL type */
	SCT_PLL = 0        /*!< SCT PLL type */
}PLL_TYPE;




/**
 * @brief  Initialize the board
 * @return none
 * @note   board initialization base on the circuit
 */
void Board_Init();


/**
 * @brief  Deinitialize the board
 * @return none
 * @note   reset the register and disable the clock
 */
void Board_Deinit();

/**
 * @brief  Configure the  main clock for the MCU's core, peripheral,memory
 * @return none
 * @note   configure the register of the system to define frequency of main clock.
 */
void Board_Configure_Main_Clock();



/**
 * @brief  Configure the  main clock for the MCU's IO
 * @return none
 * @note   configure the register of the system to define frequency of IO clock.
 */
void Board_Configure_IO_Clock();


/**
 * @brief  Enable clock for the individual system and peripheral blocks
 * @return none
 * @note   use the chip function to enable the clock
 */
void Board_Enable_PeriphClock();



/**
 * @brief  Configure the  main clock for the CAN core
 * @return none
 * @note   configure the register of the CAN to define frequency of CAN clock.
 */
void Board_Configure_CAN_Clock();



/**
 * @brief  Configure the  main clock for the USART
 * @return none
 * @note   configure the register of the system to define frequency of USART clock.
 */
void Board_Configure_USART_Clock();



/** @brief  Configure the system PLL
 *  @return none
 *  @note configure the system PLL for the main clock, when configured, power up
 *  the PLL and wait for 100us at least,then select the system PLL for the
 *  main clock
 */
void Board_Setup_System_PLL();



/** @brief  Configure the USB PLL
 *  @return none
 *  @note configure the system PLL for the USB clock, when configured, power up
 *  the PLL and wait for 100us at least
 *
 */
void Board_Setup_USB_PLL();



/** @brief  Configure the SCT PLL
 *  @return none
 *  @note configure the system PLL for the main clock, when configured, power up
 *  the PLL and wait for 100us at least
 */
void Board_Setup_SCT_PLL();



/** @brief  Configure the  PLL
 *  @return none
 *  @note configure the  PLL accordign to the pll_type
 */
void Board_Setup_PLL(PLL_TYPE pll_type);




/**
 * @brief Setup the system oscillator
 * @return none
 * @note setup the system oscillator for the USB PLL, SCT PLL, system PLL,
 * main clock source.
 */
void Board_Setup_System_Oscillator();




/**
 * @brief  Configure the IO for the peripherals
 * @return none
 * @note   configure the register of the IO for CAN,LED,KWP_USART,BLUEBOOTH and etc
 */
void Board_Configure_IO();




/**
 * @brief Configure the bluetooth USART IO
 * @return none
 */
void Board_Configure_Bluetooth_USART_IO();



/**
 * @brief Configure the KWP2000 USART IO
 * @return none
 */
void Board_Configure_KWP_USART_IO();



/**
 * @brief Configure the CAN IO
 * @return none
 */
void Board_Configure_CAN_IO();



/**
 * @brief Configure the LED IO
 * @return none
 */
void Board_Configure_LED_IO();


/**
 * @brief  Lighten the TX led
 * @return none
 */
void Board_Lighten_TX_LED();


/**
 * @brief  Lighten the RX led
 * @return none
 */
void Board_Lighten_RX_LED();


/**
 * @brief  Off the TX led
 * @return none
 */
void Board_Off_TX_LED();



/**
 * @brief  Off the RX led
 * @return none
 */
void Board_Off_RX_LED();



/**
 * @brief  Toggle the TX led
 * @return none
 */
void Board_Toggle_TX_LED();



/**
 * @brief  Toggle the RX led
 * @return none
 */
void Board_Toggle_RX_LED();





#endif /* DRIVERS_INC_BOARD_BOARD_H_ */
