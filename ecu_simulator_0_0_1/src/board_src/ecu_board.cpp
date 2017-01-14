/*
 * board.cpp
 *
 *  Created on: 2016年12月20日
 *      Author: cheri
 */



#include "chip.h"
#include "ecu_board.h"

/**
 *
 * @brief frequency of the different clock sources of the board
 *
 */
const uint32_t OscRateIn = 12000000;      /*!< The frequency of the external crystal 12MHZ */
const uint32_t RTCOscRateIn = 32768;      /*!< The frequency of the RTC internal oscillator 32.76KHZ */




/*****************************************************************************
 * Private functions
 ****************************************************************************/
/* Set up the main clock */
void Board_Configure_Main_Clock()
{
	/* Set main clock source to the system PLL. This will drive 72MHz
	for the main clock */
	Chip_Clock_SetMainClockSource(SYSCTL_MAINCLKSRC_SYSPLLOUT);

	/* Set system clock divider to 1 */
	Chip_Clock_SetSysClockDiv(1);

	/* Setup FLASH access timing for 72MHz */
	Chip_FMC_SetFLASHAccess(SYSCTL_FLASHTIM_72MHZ_CPU);
}

/* Setup the clock for all USART device */
void Board_Configure_USART_Clock()
{
	/* The rate 14976000 is the lowest common multiple(LCM)
	   of 1152000 and 10400(for KWP) */
	uint32_t usart_rate = 14976000;

	/* Set the USART fractional baud rate generator register, to get the frequency
	   14976000 */
	Chip_Clock_SetUARTBaseClockRate(usart_rate,true);
}


/*Setup the clock for can device */
void Board_Configure_CAN_Clock()
{
    LPC_CAN->CANCLKDIV = 0x00000005;
}



/* Set up the system PLL */
void Board_Setup_System_PLL()
{
    /* Set system PLL input to system oscillator */
	Chip_Clock_SetSystemPLLSource(SYSCTL_PLLCLKSRC_SYSOSC);

	/* Power down PLL to change the PLL divider ratio */
	Chip_SYSCTL_PowerDown(SYSCTL_POWERDOWN_SYSPLL_PD);

	/* Setup PLL for main oscillator rate (FCLKIN = 12MHz) * 6 = 72MHz
		MSEL = 5 (this is pre-decremented), PSEL = 1 (for P = 2)
		FCLKOUT = FCLKIN * (MSEL + 1) = 12MHz * 6 = 72MHz
		FCCO = FCLKOUT * 2 * P = 72MHz * 2 * 2 = 288MHz (within FCCO range) */
	Chip_Clock_SetupSystemPLL(5, 1);

	/* Power up system PLL */
	Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_SYSPLL_PD);

	/* Wait for PLL to lock */
	while (!Chip_Clock_IsSystemPLLLocked()) {}
}


/* Setup USB PLL */
void Board_Setup_USB_PLL()
{
    /* Set USB PLL input to system oscillator */
	Chip_Clock_SetUSBPLLSource(SYSCTL_PLLCLKSRC_SYSOSC);

    /* Power down PLL to change the PLL divider ratio */
	Chip_SYSCTL_PowerDown(SYSCTL_POWERDOWN_USBPLL_PD);

    /* Setup PLL for main oscillator rate (FCLKIN = 12MHz) * 4 = 48MHz
	   MSEL = 3 (this is pre-decremented), PSEL = 1 (for P = 2)
	   FCLKOUT = FCLKIN * (MSEL + 1) = 12MHz * 4 = 48MHz
	   FCCO = FCLKOUT * 2 * 2 = 48MHz * 2 * 4 = 192MHz (within FCCO range) */
	Chip_Clock_SetupUSBPLL(3, 1);

    /* Power up USB PLL */
	Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_USBPLL_PD);

    /* Wait for PLL to lock */
	while (!Chip_Clock_IsUSBPLLLocked()) {}

}


/* Setup SCT PLL */
void Board_Setup_SCT_PLL()
{

    /* Set SCT PLL input to system oscillator */
	Chip_Clock_SetSCTPLLSource(SYSCTL_PLLCLKSRC_SYSOSC);

	/* Power down PLL to change the PLL divider ratio */
	Chip_SYSCTL_PowerDown(SYSCTL_POWERDOWN_SCTPLL_PD);

    /* Setup PLL for main oscillator rate (FCLKIN = 12MHz) * 6 = 72MHz
	   MSEL = 5 (this is pre-decremented), PSEL = 1 (for P = 2)
	   FCLKOUT = FCLKIN * (MSEL + 1) = 12MHz * 6 = 72MHz
	   FCCO = FCLKOUT * 2 * P = 72MHz * 2 * 2 = 288MHz (within FCCO range) */
	Chip_Clock_SetupSCTPLL(5, 1);

	/* Powerup SCT PLL */
	Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_SCTPLL_PD);

	/* Wait for PLL to lock */
	while (!Chip_Clock_IsSCTPLLLocked()) {}

}


/* Setup the system oscillator */
void Board_Setup_System_Oscillator()
{
    volatile int i;
	/* Power down the system oscillator to configure it */
	Chip_SYSCTL_PowerDown(SYSCTL_POWERDOWN_SYSOSC_PD);

	/* Disable the system oscillator bypass bit and set
	 * the frequency range lower : 1MHZ - 20MHZ */
    Chip_Clock_Set_SYSOSCCTRL(false,false);

	/* Power up the system oscillator */
	Chip_SYSCTL_PowerUp(SYSCTL_POWERDOWN_SYSOSC_PD);

	/* Wait 200us for OSC to be stablized, no status
		indication, dummy wait. */
	for(i = 0; i < 0x200; ++i){}
}

/* Enable the clock for the device */
void Board_Enable_PeriphClock()
{
	/* Enable the peripheral clock */
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_ROM);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_SRAM1);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_SRAM2);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_FLASH);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_EEPROM);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_SWM);
    Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_IOCON);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_GPIO0);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_GPIO1);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_MRT);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_RIT);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_CAN);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_UART0);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_UART1);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_UART2);
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_MUX);
}


/* Configure the bluetooth USART IO
 * the pins are PIO0_0 and PIO0_1 */
void Board_Configure_Bluetooth_USART_IO()
{
	/* Reset the UART0 */
	Chip_SYSCTL_AssertPeriphReset(RESET_UART0);

	/* Clear the reset bit */
	Chip_SYSCTL_DeassertPeriphReset(RESET_UART0);

	/* Configure the bluetooth TX(PIO0_1)  pin to pull down mode and SMODE_3 */
	Chip_IOCON_PinMuxSet(LPC_IOCON,
			BLUETOOTH_TX_PORT,
			BLUETOOTH_TX_PIN,
			IOCON_MODE_PULLDOWN | IOCON_S_MODE_3CLK);

	/* Configure the bluetooth RX(PIO0_0)  pin to pull down mode and SMODE_3 */
	Chip_IOCON_PinMuxSet(LPC_IOCON,
			BLUETOOTH_RX_PORT,
			BLUETOOTH_RX_PIN,
			IOCON_MODE_PULLDOWN | IOCON_S_MODE_3CLK);

    /* Configure the bluetooth TX pin as the output direction */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO,
			BLUETOOTH_TX_PORT,
			BLUETOOTH_TX_PIN);

    /* Configure the bluetooth RX pin as the input direction */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO,
			BLUETOOTH_RX_PORT,
			BLUETOOTH_RX_PIN);

	/* Assign the USART0 TX's pin to PIO0_1 */
	Chip_SWM_MovablePortPinAssign(SWM_UART0_TXD_O,
			BLUETOOTH_TX_PORT,
			BLUETOOTH_TX_PIN);

	/* Assign the USART0 RX's pin to PIO0_0 */
	Chip_SWM_MovablePortPinAssign(SWM_UART0_RXD_I,
			BLUETOOTH_RX_PORT,
			BLUETOOTH_RX_PIN);


}


/* Configure the KWP2000 USART IO
 * the pins are PIO0_26 and PIN0_27 */
void Board_Configure_KWP_USART_IO()
{
	/* Reset the UART1 */
	Chip_SYSCTL_AssertPeriphReset(RESET_UART1);

	/* Clear the reset bit */
	Chip_SYSCTL_DeassertPeriphReset(RESET_UART1);

	/* Configure the KWP TX(PIO0_27)  pin to pull down mode and SMODE_3 */
	Chip_IOCON_PinMuxSet(LPC_IOCON,
			KWP_TX_PORT,
			KWP_TX_PIN,
			IOCON_MODE_PULLDOWN | IOCON_S_MODE_3CLK);

	/* Configure the KWP RX(PIO0_26)  pin to pull down mode and SMODE_3 */
	Chip_IOCON_PinMuxSet(LPC_IOCON,
			KWP_RX_PORT,
			KWP_RX_PIN,
			IOCON_MODE_PULLDOWN | IOCON_S_MODE_3CLK);

    /* Configure the KWP TX pin as the output direction */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO,
			KWP_TX_PORT,
			KWP_TX_PIN);

    /* Configure the KWP RX pin as the input direction */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO,
			KWP_RX_PORT,
			KWP_RX_PIN);

	/* Assign the USART1 TX's pin to PIO0_27 */
	Chip_SWM_MovablePortPinAssign(SWM_UART1_TXD_O,
			KWP_TX_PORT,
			KWP_TX_PIN);

	/* Assign the USART1 RX's pin to PIO0_26 */
	Chip_SWM_MovablePortPinAssign(SWM_UART1_RXD_I,
			KWP_RX_PORT,
			KWP_RX_PIN);


}


/* Configure the CAN IO
 * the pins are PIO0_23 and PIO0_24 */
void Board_Configure_CAN_IO()
{
	/* Reset the CAN */
	Chip_SYSCTL_AssertPeriphReset(RESET_CAN);

	/* Clear the reset bit */
	Chip_SYSCTL_DeassertPeriphReset(RESET_CAN);

	/* Configure the CAN TX(PIO0_23)  pin to SMODE_3 */
	Chip_IOCON_PinMuxSet(LPC_IOCON,
			CAN_TX_PORT,
			CAN_TX_PIN,
			IOCON_S_MODE_3CLK);

	/* Configure the CAN RX(PIO0_24)  pin to pull down mode and SMODE_3 */
	Chip_IOCON_PinMuxSet(LPC_IOCON,
			CAN_RX_PORT,
			CAN_RX_PIN,
			IOCON_MODE_PULLDOWN | IOCON_S_MODE_3CLK);

    /* Configure the CAN TX pin as the output direction */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO,
			CAN_TX_PORT,
			CAN_TX_PIN);

    /* Configure the CAN RX pin as the input direction */
	Chip_GPIO_SetPinDIRInput(LPC_GPIO,
			CAN_RX_PORT,
			CAN_RX_PIN);

	/* Assign the CAN TX's pin to PIO0_23 */
	Chip_SWM_MovablePortPinAssign(SWM_CAN_TD1_O,
			CAN_TX_PORT,
			CAN_TX_PIN);

	/* Assign the CAN RX's pin to PIO0_24 */
	Chip_SWM_MovablePortPinAssign(SWM_CAN_RD1_I,
			CAN_RX_PORT,
			CAN_RX_PIN);

}


/* Configure the LED IO
 * the pins are PIO0_22 and PIO0_25*/
void Board_Configure_LED_IO()
{
	/* Configure the LED TX(PIO0_22)  pin to SMODE_3 */
	Chip_IOCON_PinMuxSet(LPC_IOCON,
			TX_LED_PORT,
			TX_LED_PIN,
			IOCON_S_MODE_3CLK);

    /* Configure the LED RX(PIO0_25)  pin to pull down mode and SMODE_3 */
	Chip_IOCON_PinMuxSet(LPC_IOCON,
			RX_LED_PORT,
			RX_LED_PIN,
			IOCON_MODE_PULLDOWN | IOCON_S_MODE_3CLK);

    /* Configure the TX_LED pin as the input direction */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO,
			TX_LED_PORT,
			TX_LED_PIN);

    /* Configure the  RX_LED pin as the input direction */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO,
			RX_LED_PORT,
			RX_LED_PIN);

}


/* Configure IO for the board */
void Board_Configure_IO()
{
	/* Reset the IOCON  */
   Chip_SYSCTL_AssertPeriphReset(RESET_IOCON);

   /* Clear the reset bit */
   Chip_SYSCTL_DeassertPeriphReset(RESET_IOCON);

   /* Configure the USART0 for the bluetooth */
   Board_Configure_Bluetooth_USART_IO();

   /* Configure the USART1 for the KWP */
   Board_Configure_KWP_USART_IO();

   /* Configure the CAN's TX and RX pin */
   Board_Configure_CAN_IO();

   /* Configure the LED pins */
   Board_Configure_LED_IO();

   Chip_Clock_DisablePeriphClock(SYSCTL_CLOCK_SWM);
}

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* Initialize the board */
void Board_Init()
{
	/* Update the clock frequency */
	SystemCoreClockUpdate();

	/* Set up the system oscillator */
	Board_Setup_System_Oscillator();

	/* Set up the system PLL */
	Board_Setup_System_PLL();

	/* Set up the USB PLL */
	Board_Setup_USB_PLL();

	/* Set up the SCT PLL */
	Board_Setup_SCT_PLL();

	/* Configure the system main clock */
	Board_Configure_Main_Clock();

	/* Configure board USART clock */
	Board_Configure_USART_Clock();

	/* Configure board CAN clock */
	Board_Configure_CAN_Clock();

	/* Enable the peripheral clock */
	Board_Enable_PeriphClock();

	/* Configure the pin for the peripheral device */
	Board_Configure_IO();
}


/*Deinitialize the board */
void Board_Deinit()
{
	/* Reset the peripherals */
	LPC_SYSCON->PRESETCTRL[0] = 0xffffffff;
	LPC_SYSCON->PRESETCTRL[1] = 0xffffffff;

	/* Disable clock for all block */
	LPC_SYSCON->SYSAHBCLKCTRL[0] = 0x00000000;
	LPC_SYSCON->SYSAHBCLKCTRL[1] = 0x00000000;
}


/* Lighten the TX led */
void Board_Lighten_TX_LED()
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO, TX_LED_PORT, TX_LED_PIN);
}


/* Lighten the RX led */
void Board_Lighten_RX_LED()
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO, RX_LED_PORT, RX_LED_PIN);
}


/* Off the TX led */
void Board_Off_TX_LED()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO, TX_LED_PORT, TX_LED_PIN);
}


/* Off the RX led */
void Board_Off_RX_LED()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO, RX_LED_PORT, RX_LED_PIN);
}


/* Toggle the TX led */
void Board_Toggle_TX_LED()
{
	Chip_GPIO_SetPinToggle(LPC_GPIO,TX_LED_PORT,TX_LED_PIN);
}


/* Toggle the RX led */
void Board_Toggle_RX_LED()
{
	Chip_GPIO_SetPinToggle(LPC_GPIO,RX_LED_PORT,RX_LED_PIN);
}
