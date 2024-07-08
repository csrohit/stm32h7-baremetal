/**
 * @file        startup_stm32h7.c
 * @description Startup routine for STM32H7 micro-controller
 * @author      Rohit Nimkar
 * @version     1.0
 * @date        2023-07-01
 * @copyright   Copyright 2024 Rohit Nimkar
 *
 * @attention
 *  Use of this source code is governed by a BSD-style
 *  license that can be found in the LICENSE file or at
 *  opensource.org/licenses/BSD-3-Clause
 */

#include "startup_stm32h7.h"

/* Function declarations */
extern int main();

// Define the veector table
uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
    (uint32_t)&_stack_top,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)SVC_Handler,
    (uint32_t)DebugMon_Handler,
    0,
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,
    (uint32_t)WWDG_IRQHandler,
    (uint32_t)PVD_IRQHandler,
    (uint32_t)TAMP_STAMP_IRQHandler,
    (uint32_t)RTC_WKUP_IRQHandler,
    0,
    (uint32_t)RCC_IRQHandler,
    (uint32_t)EXTI0_IRQHandler,
    (uint32_t)EXTI1_IRQHandler,
    (uint32_t)EXTI2_IRQHandler,
    (uint32_t)EXTI3_IRQHandler,
    (uint32_t)EXTI4_IRQHandler,
    (uint32_t)DMA1_Channel1_IRQHandler,
    (uint32_t)DMA1_Channel2_IRQHandler,
    (uint32_t)DMA1_Channel3_IRQHandler,
    (uint32_t)DMA1_Channel4_IRQHandler,
    (uint32_t)DMA1_Channel5_IRQHandler,
    (uint32_t)DMA1_Channel6_IRQHandler,
    (uint32_t)ADC_IRQHandler,
    0,
    0,
    0,
    0,
    (uint32_t)EXTI9_5_IRQHandler,
    (uint32_t)TIM1_BRK_IRQHandler,
    (uint32_t)TIM1_UP_IRQHandler,
    (uint32_t)TIM1_TRG_COM_IRQHandler,
    (uint32_t)TIM1_CC_IRQHandler,
    (uint32_t)TIM2_IRQHandler,
    (uint32_t)TIM3_IRQHandler,
    (uint32_t)TIM4_IRQHandler,
    (uint32_t)I2C1_EV_IRQHandler,
    (uint32_t)I2C1_ER_IRQHandler,
    (uint32_t)I2C2_EV_IRQHandler,
    (uint32_t)I2C2_ER_IRQHandler,
    (uint32_t)SPI1_IRQHandler,
    (uint32_t)SPI2_IRQHandler,
    (uint32_t)USART1_IRQHandler,
    (uint32_t)USART2_IRQHandler,
    (uint32_t)USART3_IRQHandler,
    (uint32_t)EXTI15_10_IRQHandler,
    (uint32_t)RTC_Alarm_IRQHandler,
    0    
};

/**
 * @brief
 *   Default handler for unregister interrupts * 
 */
void Default_Handler(void)
{
  while (1)
    ;
}


/**
 * @brief 
 *   Entry point of application
 * 
 * Copy Data and BSS sections
 */
__attribute__((noreturn)) void Reset_Handler(void) {
  extern uint32_t _sdata, _edata, _la_data, _sbss, _ebss;

  memcpy(&_sdata, &_la_data, &_edata - &_sdata);
  memset(&_sbss, 0, &_ebss - &_sbss);

  main();

  while (1)
    ;
}

/**
 * @brief
 *   Definition for the memcpy function
 */
__attribute__((weak)) void *memcpy(void *dest, const void *src, uint32_t n) {
  for (uint32_t i = 0; i < n; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

/**
 * @brief
 *   Definition for the memset function
 */ 
__attribute__((weak)) void *memset(void *dst0, int c, uint32_t length) {
  char *dst = (char *)dst0;
  while (length--) {
    *dst = (char)c;
    dst++;
  }
  return dst0;
}

