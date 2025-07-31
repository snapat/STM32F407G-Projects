# 02: Bare-Metal I2C Driver for MPU-6050

This project is the development of a bare-metal I2C driver for the STM32F407VG microcontroller to interface with an MPU-6050 6-axis Inertial Measurement Unit (IMU). The goal is to write the entire driver stack from scratch, without relying on any vendor-provided HAL libraries, to master the process of communicating with a complex external peripheral.

## Demonstration

*(A GIF of the final data output will be added here upon project completion.)*

## Motivation

Building on the foundational concepts from the Blinky project, the goal here is to implement a standard communication protocol (I2C) and interface with a real-world sensor. This project requires reading and interpreting two separate technical documents simultaneously—the microcontroller reference manual and the sensor datasheet—to create a cohesive firmware solution, simulating a common and critical task for a firmware engineer.

## Technical Skills Being Developed

This project is designed to build proficiency in the following core embedded systems concepts:

- **Bare-Metal Driver Development:** Writing firmware that controls hardware by directly reading and writing to memory-mapped peripheral registers.
- **Datasheet & Reference Manual Interpretation:**
  - Parsing the **STM32F407xx Reference Manual (RM0090)** to configure the I2C peripheral, GPIO alternate functions, and system clocks.
  - Parsing the **MPU-6050 Register Map** datasheet to configure the sensor's power management, sampling rates, and data output registers.
- **I2C Protocol Implementation:** Manually implementing the I2C communication sequence in software by polling status flags (`SB`, `ADDR`, `TxE`, `RxNE`) to handle START/STOP conditions, address phases, and data transmission.
- **Layered Software Architecture (MCAL/HAL):** Architecting the firmware using a professional, portable design that separates the Microcontroller Abstraction Layer (the I2C driver) from the Hardware Abstraction Layer (the sensor driver).
- **Advanced C for Embedded Systems:** Utilizing pointers, bit-masking, and `volatile` structs to create a safe and readable hardware interface for both the microcontroller and the external sensor.

## Planned Software Architecture

To ensure the code is portable, reusable, and follows professional standards, this project will use a multi-layer architecture:

1.  **Application Layer (`main.c`)**: Will contain the high-level application logic. It will initialize the sensor and periodically read and print the accelerometer and gyroscope data, remaining completely unaware of the underlying hardware registers.
2.  **Hardware Abstraction Layer (HAL) (`mpu6050.c`)**: A specific driver for the MPU-6050. It will provide a clean API (e.g., `mpu6050_init()`) and contain all the logic for interacting with the sensor, using the MCAL for communication.
3.  **Microcontroller Abstraction Layer (MCAL) (`i2c_driver.c`)**: A generic I2C driver for the STM32F4. It will provide a simple API for I2C communication (e.g., `i2c_read_byte()`) and will directly handle all register-level interactions with the STM32's I2C peripheral.

This architecture will allow the MPU-6050 driver to be easily ported to a different microcontroller by only rewriting the I2C MCAL.

## Development Plan

The project is broken down into four distinct phases:

1.  **Phase 0: Smoke Test:** Write minimal code in `main.c` to read the MPU-6050's `WHO_AM_I` register to validate the hardware setup and basic I2C configuration.
2.  **Phase 1: Build MCAL:** Refactor the working smoke test code into a clean, reusable I2C driver with a well-defined API.
3.  **Phase 2: Build HAL:** Develop the specific driver for the MPU-6050 sensor, which will use the I2C MCAL to communicate.
4.  **Phase 3: Build Application:** Create the final application logic in `main.c` that uses the HAL to read and display sensor data.

## Tools & Environment

- **MCU:** STM32F407VG
- **Hardware:** GY-521 (MPU-6050) Breakout Board, Breadboard
- **IDE:** STM32CubeIDE
- **Compiler:** ARM GCC
- **Version Control:** Git
