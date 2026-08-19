#ifndef MAIN_H_
#define MAIN_H_

#include<stdio.h>
#include<string.h>
#include<stdint.h>

typedef struct
{
    uint32_t MODER;
    uint32_t OTYPER;
    uint32_t OSPEEDR;
    uint32_t PUPDR;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t LCKR;
    uint32_t AFRL;
    uint32_t AFRH;
} GPIOReg_t;

typedef struct
{
    uint32_t CR;
    uint32_t PLLCFGR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t AHB1RSTR;
    uint32_t AHB2RSTR;
    uint32_t RESERVED1[2];
    uint32_t APB1RSTR;
    uint32_t APB2RSTR;
    uint32_t RESERVED2[2];
    uint32_t AHB1ENR;
    uint32_t AHB2ENR;
    uint32_t RESERVED3[2];
    uint32_t APB1ENR;
    uint32_t APB2ENR;
    uint32_t RESERVED4[2];
    uint32_t AHB1LPENR;
    uint32_t AHB2LPENR;
    uint32_t RESERVED5[2];
    uint32_t APB1LPENR;
    uint32_t APB2LPENR;
    uint32_t RESERVED6[2];
    uint32_t BDCR;
    uint32_t CSR;
    uint32_t RESERVED7[2];
    uint32_t SSCGR;
    uint32_t PLLI2SCFGR;
    uint32_t RESERVED8;
    uint32_t DCKCFGR;
} RCCReg_t;

typedef struct
{
    uint32_t CR1;
    uint32_t CR2;
    uint32_t SMCR;
    uint32_t DIER;
    uint32_t SR;
    uint32_t EGR;
    uint32_t CCMR1;
    uint32_t CCMR2;
    uint32_t CCER;
    uint32_t CNT;
    uint32_t PSC;
    uint32_t ARR;
    uint32_t RESERVED;
    uint32_t CCR1;
    uint32_t CCR2;
    uint32_t CCR3;
    uint32_t CCR4;
    uint32_t RESERVED1;
    uint32_t DCR;
    uint32_t DMAR;
    uint32_t OR;
} TIMEReg_t;

#define RCC_BASEADDR    0x40023800U
#define GPIOD_BASEADDR  0x40020C00U
#define TIM2_BASEADDR   0x40000000U
#define GPIOA_BASEADDR  0x40020000U
#define GPIOC_BASEADDR  0x40020800U
#define GPIOB_BASEADDR  0x40020400U

#define NVIC_ISER0 (uint32_t*)0xE000E100
#define NVIC_ISER1 (uint32_t*)(NVIC_ISER0+4)
#define NVIC_ISER2 (uint32_t*)(NVIC_ISER1+4)
#define NVIC_ISER3 (uint32_t*)(NVIC_ISER2+4)
#define NVIC_ISER4 (uint32_t*)(NVIC_ISER3+4)
#define NVIC_ISER5 (uint32_t*)(NVIC_ISER4+4)
#define NVIC_ISER6 (uint32_t*)(NVIC_ISER5+4)
#define NVIC_ISER7 (uint32_t*)(NVIC_ISER6+4)

#define NVIC_IPR0  (uint32_t*)0xE000E400
#define NVIC_IPR1  (uint32_t*)(NVIC_IPR0+4)
#define NVIC_IPR2  (uint32_t*)(NVIC_IPR1+4)
#define NVIC_IPR3  (uint32_t*)(NVIC_IPR2+4)
#define NVIC_IPR4  (uint32_t*)(NVIC_IPR3+4)
#define NVIC_IPR5  (uint32_t*)(NVIC_IPR4+4)
#define NVIC_IPR6  (uint32_t*)(NVIC_IPR5+4)
#define NVIC_IPR7  (uint32_t*)(NVIC_IPR6+4)
#define NVIC_IPR8  (uint32_t*)(NVIC_IPR7+4)
#define NVIC_IPR9  (uint32_t*)(NVIC_IPR8+4)
#define NVIC_IPR10 (uint32_t*)(NVIC_IPR9+4)
#define NVIC_IPR11 (uint32_t*)(NVIC_IPR10+4)
#define NVIC_IPR12 (uint32_t*)(NVIC_IPR11+4)
#define NVIC_IPR13 (uint32_t*)(NVIC_IPR12+4)
#define NVIC_IPR14 (uint32_t*)(NVIC_IPR13+4)
#define NVIC_IPR15 (uint32_t*)(NVIC_IPR14+4)

#define MAX_SSD 8

void init_TIM(uint32_t psc, uint32_t arr);
void init_tim_interrupt(void);
void init_LED(void);
void led_ON(void);
void led_OFF(void);
void led_Toggle(void);

#define ZERO  0X3F
#define ONE   0X06
#define TWO   0X5B
#define THREE 0X4F
#define FOUR  0X66
#define FIVE  0X6D
#define SIX   0X7D
#define SEVEN 0X07
#define EIGHT 0X7F
#define NINE  0X6F

#define ZERO1  0XBF
#define ONE1   0X86
#define TWO1   0XDB
#define THREE1 0XCF
#define FOUR1  0XE6
#define FIVE1  0XED
#define SIX1   0XFD
#define SEVEN1 0X87
#define EIGHT1 0XFF
#define NINE1  0XEF

void init_SSD(void);
void display_value_on_ssd(uint8_t digit[]);

#endif /* MAIN_H_ */
