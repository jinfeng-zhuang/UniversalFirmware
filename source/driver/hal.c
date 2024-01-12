//
// The HAL wrapper of Common
//_____________________________________________________________________________
//

#include <hal.h>

HAL_TickFreqTypeDef uwTickFreq = HAL_TICK_FREQ_DEFAULT;  /* 1KHz */

HAL_StatusTypeDef HAL_Init(void)
{
  /* 4bit for priority */
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
  
  /* Use systick as time base source and configure 1ms tick (default clock after Reset is HSI) */
  if (HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq)) > 0U)
  {
    return HAL_ERROR;
  }
  
  HAL_NVIC_SetPriority(SysTick_IRQn, TICK_INT_PRIORITY, 0U);
  
  HAL_NVIC_EnableIRQ(SysTick_IRQn);
  
  /* Clock Tree init */
  
  return HAL_OK;
}
