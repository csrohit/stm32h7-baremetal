#include "stm32h7xx.h"
#include <stdint.h>

volatile uint32_t msTicks = 0U;

/**
 * @brief Interrupt handler function
 *
 */
void SysTick_Handler(void)
{
	msTicks++;
}

/**
 * @brief Add blocking delay
 *
 * @param ms delay in milliseconds
 */
void ms_delay(uint32_t ms)
{
	uint32_t expected_ticks = msTicks + ms;
	while (msTicks < expected_ticks)
	{
		__asm("nop");
	}
}

// void ms_delay(int ms) {
//     while (ms-- > 0) {
//         volatile int x = 1000;
//         while (x-- > 0)
//             __asm("nop");
//     }
// }
static inline void gpio_toggle(GPIO_TypeDef *port, uint32_t pin);

// void ms_delay(uint32_t ms);

int main(void) {
    RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN | RCC_AHB4ENR_GPIOEEN;

    GPIOB->MODER &= ~(GPIO_MODER_MODE0 | GPIO_MODER_MODE14);

    GPIOB->MODER |= GPIO_MODER_MODE0_0 | GPIO_MODER_MODE14_0; // Set OUTPUT mode

    GPIOE->MODER &= ~GPIO_MODER_MODE1;

    GPIOE->MODER |= GPIO_MODER_MODE1_0; // Set OUTPUT mode
    
    SysTick_Config(64000);

    while (1) {
        gpio_toggle(GPIOB, GPIO_ODR_OD0);
        ms_delay(100);
        gpio_toggle(GPIOE, GPIO_ODR_OD1);
        ms_delay(100);
        gpio_toggle(GPIOB, GPIO_ODR_OD14);
        ms_delay(100);
    }
}


static inline void gpio_toggle(GPIO_TypeDef *port, uint32_t pin) {
    port->ODR ^= pin;
}
