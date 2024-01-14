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

// ZSTACK
#include <zstack/time.h>

#if 1
int fputc(int ch, FILE *f) 
{
  return(ITM_SendChar(ch));
}
#endif

void cpu_init(void)
{
	// SCB
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	// Systick
	HAL_InitTick(TICK_INT_PRIORITY);
}

void flash_init(void)
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

void power_init(void)
{
	//_________________________________
	// RCU: Clock: Power
	__HAL_RCC_PWR_CLK_ENABLE();

	//_________________________________
	// configure the main internal regulator output voltage
	// Scale1 is the default value after reset
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
}

void clock_enable_init(void)
{
	//_________________________________
	// RCU: Clock: SYSCFG
	// 		RCC APB2 peripheral clock enable register
	//			Bit 14: SYSCFGEN: System configuration controller clock enable
	//			Page 289
	//			structure: SYSCFG_TypeDef
	//				* Memmap
	//				* Ethernet PHY
	//				* EXTI config
	__HAL_RCC_SYSCFG_CLK_ENABLE();
}

void soc_init(void)
{
	// flash clock always enabled, as code start from here
	flash_init();

	clock_enable_init();

	clocktree_init(1);

	power_init();
}

void board_init(void)
{
    hal_gpio_init(LED_USER_ORANGE);
	hal_gpio_init(LED_USER_GREEN);
	hal_gpio_init(LED_USER_RED);
	hal_gpio_init(LED_USER_BLUE);
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
  
  hal_gpio_set(LED_USER_ORANGE, 1);
  hal_gpio_set(LED_USER_GREEN, 1);
  hal_gpio_set(LED_USER_RED, 1);
  hal_gpio_set(LED_USER_BLUE, 1);

  // handle messages
	printf("Hello ITM\n");
  
  while (1)
  {
    //cpu_delay_us(10000);
	  //printf("Hello ITM\n");
  }
}
