#include "main.h"

extern GPIOReg_t *GPIOA;
extern GPIOReg_t *GPIOB;
extern RCCReg_t  *RCC;

static void init_gpio_led(void);

void init_LED(void)
{
    init_gpio_led();
}

static void init_gpio_led(void)
{
    RCC->AHB1ENR |= (1 << 0);
    RCC->AHB1ENR |= (1 << 1);

    for (int i = 0; i <= 11; i++)
    {
        GPIOB->MODER |= (1 << (2 * i));
        GPIOB->MODER &= ~(1 << ((2 * i) + 1));

        GPIOA->MODER |= (1 << (2 * i));
        GPIOA->MODER &= ~(1 << ((2 * i) + 1));
    }
}
