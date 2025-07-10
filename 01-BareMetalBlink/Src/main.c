 /*
  * @file           : main.c
  * @author         : PJ
  * @brief          : Main program body for the Bare-Metal Blinky project.
  *
  * @details        This application initializes the necessary peripherals using
  * custom-built, low-level drivers and enters an infinite loop
  * to toggle the user LED.
  */

#include "main.h"

//---------------------------
// Private Function Prototypes
//---------------------------
void delay(volatile uint32_t count);


//---------------------------
// Main Program
//---------------------------

/**
 * @brief  The main function for the application.
 * @retval int: This function never returns.
 */
int main(void)
{
    // 1. Enable the clock for the GPIOC peripheral using our driver function.
    //    We pass the port we want to enable (LED_PORT, which is GPIOC)
    //    and the enable flag (1).
    GPIO_ClockControl(LED_PORT, GPIO_PIN_SET);

    // 2. Initialize the LED pin as an output using our driver function.
    GPIO_Init_Output(LED_PORT, LED_PIN);

    // 3. Main application loop (superloop)
    while(1)
    {
        // Toggle the LED pin using our driver function and then wait.
        GPIO_TogglePin(LED_PORT, LED_PIN);
        delay(2000000); // Adjust this value to change the blink speed
    }
}


//---------------------------
// Private Functions
//---------------------------

/**
 * @brief  A simple software delay loop.
 * @param  count: The number of loop iterations to wait.
 * @retval None
 */
void delay(volatile uint32_t count)
{
    // This is a "blocking" delay. The CPU does nothing but loop
    // until the count reaches zero.
    while(count--);
}
