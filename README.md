# **STM32F407G Bare-Metal Development Journey**

This repository documents my journey of learning the ARM Cortex-M4 architecture by developing a series of firmware projects for the STM32F407G microcontroller from the ground up.

## **Motivation**

The goal of this collection is to move beyond high-level abstractions and gain a deep, practical understanding of how microcontrollers function at the hardware level. Each project is built entirely **bare-metal**, without the use of vendor-provided HAL (Hardware Abstraction Layer) libraries, to master the fundamentals of embedded systems development.

The projects are structured to be progressive, starting with fundamental concepts and building towards more complex applications.

## **Projects**

This section serves as a table of contents for the projects contained within this repository. Each project includes its own detailed README.md file explaining the specific concepts and implementation.

1. [**01-BareMetalBlink**](https://github.com/snapat/STM32F407G-Projects/tree/main/01-BareMetalBlink)  
   * **Description:** A fundamental "Hello, World\!" project to blink an external LED.  
   * **Peripherals Used:** RCC, GPIO.  
   * **Core Concepts:** Direct register access, clock gating, GPIO configuration, volatile keyword, multi-layer software architecture (BSP, Driver, App).  
2. *(More projects to be added)*

## **Development Philosophy**

* **Bare-Metal First:** All drivers and peripheral interactions are written from scratch by directly manipulating memory-mapped registers.  
* **Documentation-Driven:** Functionality is implemented by reading and interpreting the official STMicroelectronics device reference manual (RM0090) and datasheets.  
* **Clean Architecture:** Each project follows a clean, multi-layer software architecture to promote code readability, reusability, and professional best practices.

## **Core Toolchain**

* **MCU:** STM32F407VG  
* **IDE:** STM32CubeIDE  
* **Compiler:** ARM GCC