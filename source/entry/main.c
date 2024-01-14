//
// Based on HAL
//
// Jinfeng Zhuang, 2024.Week2
//_____________________________________________________________________________

// C Standard
#include <stdio.h>

// LL
#include <stm32f4xx_hal.h>

// HAL
#include <hal/gpio.h>
#include <hal/clocktree.h>

// Board
#include <devicetree/stm32f4_discovery.h>

int fputc(int ch, FILE *f) 
{
  return(ITM_SendChar(ch));
}

void cpu_init(void)
{
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	
	HAL_InitTick(TICK_INT_PRIORITY);
	
	__HAL_RCC_SYSCFG_CLK_ENABLE();
  	__HAL_RCC_PWR_CLK_ENABLE();
	
	clocktree_init(0);
}

void soc_init(void)
{
#if (INSTRUCTION_CACHE_ENABLE != 0U)
	  __HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
#endif
		
#if (DATA_CACHE_ENABLE != 0U)
	  __HAL_FLASH_DATA_CACHE_ENABLE();
#endif
		
#if (PREFETCH_ENABLE != 0U)
	  __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
#endif

}

void board_init(void)
{
    
}

void task_init(void)
{
    
}

int main(void)
{
  // It can be A9, A53, M3, M4, x86, ...
  // It contains the CPU IPs initialize
  cpu_init();
  
  // It can be STM32, ZYNQ, iMX6, ...
  soc_init();
  
  // The devices connected to SoC
  board_init();
  
  task_init();
  
  hal_gpio_init(LED_USER_ORANGE);
  hal_gpio_set(LED_USER_ORANGE, 1);

  hal_gpio_init(LED_USER_GREEN);
  hal_gpio_set(LED_USER_GREEN, 1);

  hal_gpio_init(LED_USER_RED);
  hal_gpio_set(LED_USER_RED, 1);

  hal_gpio_init(LED_USER_BLUE);
  hal_gpio_set(LED_USER_BLUE, 1);

  printf("Hello ITM\n");
  
  // handle messages
  
  while (1)
  {
    
  }
}
