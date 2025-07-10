/*
 * @file      main.h
 * @author    PJ
 * @details     This is the main header file for the application. It serves as the central point for including necessary drivers and defining application-specific constants and configurations.
 */

#ifndef MAIN_H_
#define MAIN_H_

//---------------------------
// Includes
//---------------------------
#include "bsp.h"
#include "gpio.h"


//---------------------------
// Application-Specific Defines
//---------------------------

/**
 * @brief The GPIO port where the user LED is connected.
 * By defining this here, we can easily change the port later without
 * searching through the entire application code.
 */
#define LED_PORT    GPIOC

/**
 * @brief The pin number on the GPIO port where the user LED is connected.
 */
#define LED_PIN     13


#endif /* MAIN_H_ */
