/*
 * @file      gpio.c
 * @author    PJ
 * @details     This file provides the implementation for the GPIO driver functions declared in gpio.h. It contains the low-level logic for manipulating the hardware registers to control the GPIO peripherals.
 */

#include <stdint.h>
#include "gpio.h"

#include "../Inc/bsp.h"

//---------------------------
// Function Implementations
//---------------------------

/*
 * @brief: Enables or disables the peripheral clock and power for a GPIO port.
 * @param pGPIOx: Pointer to the base address of the GPIO peripheral that is passed.
 * @param EnOrDis: Enable (1) or Disable (0) the clock
 * @retval: None
 */
void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDis)
{
	if (EnOrDis==1)
	{
		if(pGPIOx == GPIOC)
		{
			RCC->AHB1ENR |= (1<<2); //Turn on the clock for the GPIOC peripheral
		}
	} else if (EnOrDis==0)
	{
		if(pGPIOx == GPIOC)
		{
			RCC->AHB1ENR &= ~(1<<2); //Turn off the clock for the GPIOC peripheral
		}
	}
}

/*
 * @brief: Initializes the mode of the GPIO register to output
 * @param pGPIOx: Pointer to the base address of the GPIO peripheral that is passed
 * @param PinNumber: Tells the function which pin within the GPIO port to initialize
 * @retval: None
 */

void GPIO_Init_Output(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t position = PinNumber*2;

	//Clear and set the output register using the corresponding pins to output mode
	pGPIOx->MODER &= ~(0b11 << position);
	pGPIOx->MODER |= (0b01 << position);
}

/*
 * @brief: Toggles the specific GPIO pin's output
 * @param pGPIOx: Pointer to GPIO peripheral
 * @param PinNumber: The pin number's ODR to be toggled
 * @retval: None
 */
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber); //Toggle the output data bit for the specific pin

}





