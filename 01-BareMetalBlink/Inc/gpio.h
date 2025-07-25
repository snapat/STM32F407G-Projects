/*
 * @file      gpio.h
 * @author    PJ
 * @details     This is the header file for the GPIO driver. It provides the public interface (API)for other modules to interact with the GPIO peripherals.
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "bsp.h" //Include the BSP header to get register definitions

typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET = 1
} GPIO_PinState;

/*	-GPIO_RegDef_t is a struct that has represents the memory structure of the GPIO ports.
 * 	-pGPIOx is a naming convention; "p" denotes the variable is a pointer and "x" denotes the variable's ability to represent any GPIO port.
 * 	-EnOrDis stands for Enable or Disable. The most efficient size is 8 bits due to because memory is byte-addressable.
 */
void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDis);

/* - First argument is identical
 * - Pin number tells the function which pin within the port to initialize.
 *
 * Note: This is a simplified init function.
 */
void GPIO_Init_Output(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * Arguments are identical to previous function.
 */
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

#endif /* INC_GPIO_H_ */
