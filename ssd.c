#include "main.h"

extern GPIOReg_t *GPIOC;
extern GPIOReg_t *GPIOD;
extern RCCReg_t  *RCC;

static void init_gpio_pin(void);
static void delay(uint32_t count);

void init_SSD(void)
{
    init_gpio_pin();
}

static void init_gpio_pin(void)
{
    RCC->AHB1ENR |= (1 << 2);
    RCC->AHB1ENR |= (1 << 3);

    for (uint8_t i = 0; i <= 11; i++)
    {
        GPIOC->MODER |= (1 << (2 * i));
        GPIOC->MODER &= ~(1 << ((2 * i) + 1));

        GPIOD->MODER |= (1 << (2 * i));
        GPIOD->MODER &= ~(1 << ((2 * i) + 1));
    }
}

void display_value_on_ssd(uint8_t digit[])
{
    for (uint8_t i = 0; i < 8; i++)
    {
        GPIOC->ODR &= 0xF0FF;
        GPIOC->ODR &= 0xFC00;
        GPIOC->ODR |= (1 << (8 + i));
        GPIOC->ODR |= (digit[i]);

        GPIOD->ODR &= 0xF0FF;
        GPIOD->ODR &= 0xFC00;
        GPIOD->ODR |= (1 << (8 + i));
        GPIOD->ODR |= (digit[i]);

        delay(500);
    }
}

static void delay(uint32_t count)
{
    for (uint32_t i = 0; i < count; i++);
}
