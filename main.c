#include "main.h"

GPIOReg_t *GPIOA = (GPIOReg_t*)GPIOA_BASEADDR;
GPIOReg_t *GPIOB = (GPIOReg_t*)GPIOB_BASEADDR;
GPIOReg_t *GPIOC = (GPIOReg_t*)GPIOC_BASEADDR;
GPIOReg_t *GPIOD = (GPIOReg_t*)GPIOD_BASEADDR;
RCCReg_t  *RCC   = (RCCReg_t*)RCC_BASEADDR;
TIMEReg_t *TIM2  = (TIMEReg_t*)TIM2_BASEADDR;

uint8_t digit[10] = { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };
uint16_t counter = 0, counter1 = 60, counter2 = 30, counter3 = 60, counter4 = 30, temp;
uint8_t get_digit[8];

int main()
{
    init_TIM(252, 63492);
    init_LED();
    init_tim_interrupt();
    init_SSD();

    while (1)
    {
        temp = counter4;
        get_digit[7] = digit[temp % 10];
        get_digit[6] = digit[temp / 10];

        temp = counter3;
        get_digit[5] = digit[temp % 10];
        get_digit[4] = digit[temp / 10];

        temp = counter2;
        get_digit[3] = digit[temp % 10];
        get_digit[2] = digit[temp / 10];

        temp = counter1;
        get_digit[1] = digit[temp % 10];
        get_digit[0] = digit[temp / 10];

        display_value_on_ssd(get_digit);

        if (counter1 == 60 && counter2 == 30)
        {
            GPIOA->ODR &= 0x0000;
            GPIOA->ODR |= 0x0021;
        }
        else if (counter1 == 40 && counter2 == 10)
        {
            GPIOA->ODR &= 0x0000;
            GPIOA->ODR |= 0x0011;
        }
        else if (counter1 == 30 && counter2 == 60)
        {
            GPIOA->ODR &= 0x0000;
            GPIOA->ODR |= 0x000C;
        }
        else if (counter1 == 10 && counter2 == 40)
        {
            GPIOA->ODR &= 0x0000;
            GPIOA->ODR |= 0X000A;
        }

        if (counter3 == 60 && counter4 == 30)
        {
            GPIOB->ODR &= 0x0000;
            GPIOB->ODR |= 0X0021;
        }
        else if (counter3 == 40 && counter4 == 10)
        {
            GPIOB->ODR &= 0x0000;
            GPIOB->ODR |= 0X0011;
        }
        else if (counter3 == 30 && counter4 == 60)
        {
            GPIOB->ODR &= 0x0000;
            GPIOB->ODR |= 0X000C;
        }
        else if (counter3 == 10 && counter4 == 40)
        {
            GPIOB->ODR &= 0x0000;
            GPIOB->ODR |= 0X000A;
        }

        if (counter1 == 0) counter1 = 60;
        if (counter2 == 0) counter2 = 60;
        if (counter3 == 0) counter3 = 60;
        if (counter4 == 0) counter4 = 60;
    }
}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR >> 0 & 0x01)
    {
        counter1--;
        counter2--;
        counter3--;
        counter4--;
        TIM2->SR &= ~(1 << 0);
    }
}
