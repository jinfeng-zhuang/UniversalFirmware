//
// Based on HAL
//
// Jinfeng Zhuang, 2024.Week2
//_____________________________________________________________________________


#include <stdio.h>

int fputc(int ch, FILE *f) 
{
  return(ITM_SendChar(ch));
}

void cpu_init(void)
{
	// HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	// HAL_InitTick(TICK_INT_PRIORITY);

	// __HAL_RCC_SYSCFG_CLK_ENABLE();

	// __HAL_RCC_PWR_CLK_ENABLE();

	// SystemClock_Config
		// __HAL_RCC_PWR_CLK_ENABLE();
		// __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
		// HAL_RCC_OscConfig(HSI)
		// HAL_RCC_ClockConfig
}

void soc_init(void)
{

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

  printf("Hello ITM\n");
  
  // handle messages
  
  while (1)
  {
    
  }
  
  return 0;
}
