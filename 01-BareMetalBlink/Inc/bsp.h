/*
 * @file      bsp.h
 * @author    PJ
 * @details     This is the Board Support Package file. It's purpose is to define Peripheral Addresses, and Structs are used to define the layout of register memory
 */
#ifndef SRC_BSP_H_
#define SRC_BSP_H_

#include <stdint.h>

// MCU Memory Addresses (RM0090 on STM website)
#define PERIPH_BASE_ADDR 		0x40000000UL
#define AHB1_PERIPH_BASE_ADDR 	(PERIPH_BASE_ADDR + 0x00020000UL)
#define RCC_BASE_ADDR			(AHB1_PERIPH_BASE_ADDR + 0x00003800UL)
#define GPIOC_BASE_ADDR			(AHB1_PERIPH_BASE_ADDR + 0x0800UL)

// Peripheral Register Structure
typedef struct
{
	volatile uint32_t MODER;    // Mode Register, offset: 0x00
	volatile uint32_t OTYPER;   // Output Type Register, offset: 0x04
	volatile uint32_t OSPEEDR;  // Output Speed Register, offset: 0x08
	volatile uint32_t PUPDR;    // Pull-up/Pull-down Register, offset: 0x0C
	volatile uint32_t IDR;      // Input Data Register, offset: 0x10
	volatile uint32_t ODR;      // Output Data Register, offset: 0x14
	volatile uint32_t BSRR;     // Bit Set/Reset Register, offset: 0x18
	volatile uint32_t LCKR;     // Lock Register, offset: 0x1C
	volatile uint32_t AFR[2];   // Alternate Function Registers [0],[1], offset: 0x20-0x24
} GPIO_RegDef_t;

//RCC Register Map Structure
typedef struct
{
	volatile uint32_t CR;            /* RCC clock control register,                                   Address offset: 0x00 */
	volatile uint32_t PLLCFGR;       /* RCC PLL configuration register,                               Address offset: 0x04 */
	volatile uint32_t CFGR;          /* RCC clock configuration register,                             Address offset: 0x08 */
	volatile uint32_t CIR;           /* RCC clock interrupt register,                                 Address offset: 0x0C */
	volatile uint32_t AHB1RSTR;      /* RCC AHB1 peripheral reset register,                           Address offset: 0x10 */
	volatile uint32_t AHB2RSTR;      /* RCC AHB2 peripheral reset register,                           Address offset: 0x14 */
	volatile uint32_t AHB3RSTR;      /* RCC AHB3 peripheral reset register,                           Address offset: 0x18 */
	uint32_t          RESERVED0;     /* Reserved, 0x1C                                                                    */
	volatile uint32_t APB1RSTR;      /* RCC APB1 peripheral reset register,                           Address offset: 0x20 */
	volatile uint32_t APB2RSTR;      /* RCC APB2 peripheral reset register,                           Address offset: 0x24 */
	uint32_t          RESERVED1[2];  /* Reserved, 0x28-0x2C                                                               */
	volatile uint32_t AHB1ENR;       /* RCC AHB1 peripheral clock enable register,                    Address offset: 0x30 */
	volatile uint32_t AHB2ENR;       /* RCC AHB2 peripheral clock enable register,                    Address offset: 0x34 */
	volatile uint32_t AHB3ENR;       /* RCC AHB3 peripheral clock enable register,                    Address offset: 0x38 */
	uint32_t          RESERVED2;     /* Reserved, 0x3C                                                                    */
	volatile uint32_t APB1ENR;       /* RCC APB1 peripheral clock enable register,                    Address offset: 0x40 */
	volatile uint32_t APB2ENR;       /* RCC APB2 peripheral clock enable register,                    Address offset: 0x44 */
	uint32_t          RESERVED3[2];  /* Reserved, 0x48-0x4C                                                               */
	volatile uint32_t AHB1LPENR;     /* RCC AHB1 peripheral clock enable in low power mode register,  Address offset: 0x50 */
	volatile uint32_t AHB2LPENR;     /* RCC AHB2 peripheral clock enable in low power mode register,  Address offset: 0x54 */
	volatile uint32_t AHB3LPENR;     /* RCC AHB3 peripheral clock enable in low power mode register,  Address offset: 0x58 */
	uint32_t          RESERVED4;     /* Reserved, 0x5C                                                                    */
	volatile uint32_t APB1LPENR;     /* RCC APB1 peripheral clock enable in low power mode register,  Address offset: 0x60 */
	volatile uint32_t APB2LPENR;     /* RCC APB2 peripheral clock enabled in low power mode register, Address offset: 0x64 */
	uint32_t          RESERVED5[2];  /* Reserved, 0x68-0x6C                                                               */
	volatile uint32_t BDCR;          /* RCC Backup domain control register,                           Address offset: 0x70 */
	volatile uint32_t CSR;           /* RCC clock control & status register,                          Address offset: 0x74 */
	uint32_t          RESERVED6[2];  /* Reserved, 0x78-0x7C                                                               */
	volatile uint32_t SSCGR;         /* RCC spread spectrum clock generation register,                Address offset: 0x80 */
	volatile uint32_t PLLI2SCFGR;    /* RCC PLLI2S configuration register,                            Address offset: 0x84 */
} RCC_RegDef_t;

// This creates a pointer named "GPIOC" of type "GPIO_RegDef_t*" and points it to the memory address defined by GPIOC_BASE_ADDR.
#define GPIOC   ((GPIO_RegDef_t*) GPIOC_BASE_ADDR)
#define RCC     ((RCC_RegDef_t*)  RCC_BASE_ADDR)

// Bit Position Definition
#define GPIOC_EN_BIT (1 << 2) // Bit 2 in RCC_AHB1ENR enables GPIOC


#endif /* SRC_BSP_H_ */
