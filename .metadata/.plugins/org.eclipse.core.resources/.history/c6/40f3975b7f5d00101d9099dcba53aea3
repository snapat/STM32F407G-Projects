# **01: Bare-Metal STM32 Blinky**

This project is a fundamental "Hello, World\!" for embedded systems, implemented entirely **bare-metal** on an STM32F407VG microcontroller. I developed this firmware from scratch to blink an external LED without relying on any vendor-provided HAL (Hardware Abstraction Layer) libraries.

## **Motivation**

I built this project to move beyond high-level abstractions and gain a solid, foundational understanding of how microcontrollers work at the hardware level. By writing directly to registers and manually managing peripherals, I was able to directly apply the concepts found in the device's technical documentation.

## **Technical Skills Showcased**

This project demonstrates proficiency in the following core embedded systems concepts:

* **Bare-Metal Development:** Controlling hardware by writing directly to memory-mapped registers.  
* **Reading Technical Documentation:** Parsing a device reference manual (RM0090) to determine memory layouts, register addresses, and bit-level configurations.  
* **Clock Configuration (RCC):** Manually enabling the peripheral clock for GPIOC via the RCC\_AHB1ENR register, a critical step for power management and device operation.  
* **GPIO Driver Development:** Configuring a GPIO pin's mode (Output) and state (High/Low) by manipulating the MODER and ODR registers.  
* **Advanced C for Embedded Systems:**  
  * Using pointers and type-casting to safely access specific memory addresses.  
  * Mapping hardware registers to C structs for clean, readable, and maintainable code.  
  * Applying the volatile keyword correctly to prevent compiler optimizations on hardware-related memory.  
  * Implementing a clean, multi-layer software architecture (BSP, Driver, Application).

## **Software Architecture**

To ensure the code is readable, reusable, and follows professional standards, I organized the project into a three-layer architecture:

1. **Application Layer (main.c)**: Contains the high-level logic (the "what"). It is intentionally kept simple and free of low-level hardware details.  
2. **Driver Layer (gpio.c, gpio.h)**: A reusable module that provides a simple API to control the GPIO peripheral (the "how"). It abstracts the hardware complexity from the application.  
3. **Board Support Package (bsp.h)**: The lowest software layer. This file serves as the "hardware dictionary," defining the memory addresses and register layouts for the target STM32 chip (the "where").

## **Implementation Notes**

The firmware operates on the principle of memory-mapped I/O. A key concept I worked with is that the STM32 memory map is **byte-addressable**. Although the registers are 32-bits (4 bytes) wide, each byte has a unique address, which explains why the address offset between consecutive 32-bit registers is always 4\.

The bsp.h file creates a software map of the physical hardware by defining structs (GPIO\_RegDef\_t, RCC\_RegDef\_t) that mirror the layout of the registers in the reference manual. This allows for clean, structured access to the hardware registers (e.g., GPIOC-\>ODR).

## **Hardware & Software**

* **MCU:** STM32F407VG  
* **Hardware:** External LED, 220Ω Resistor, Breadboard  
* **Toolchain:** STM32CubeIDE, ARM GCC

## **How to Build and Run**

1. Open the project folder in STM32CubeIDE (File \> Open Projects from File System...).  
2. Build the project by pressing Ctrl+B.  
3. Run the project on the target hardware by pressing F11.

The LED connected to pin PC13 will begin to blink once per second.