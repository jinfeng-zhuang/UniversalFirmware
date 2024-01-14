//
// The HAL wrapper of Cortex-M4
//_____________________________________________________________________________
//

#include <hal.h>

void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  /* Set the PRIGROUP[10:8] bits according to the PriorityGroup parameter value */
  NVIC_SetPriorityGrouping(PriorityGroup);
}

void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority)
{ 
  uint32_t prioritygroup = 0x00U;
  
  prioritygroup = NVIC_GetPriorityGrouping();
  
  NVIC_SetPriority(IRQn, NVIC_EncodePriority(prioritygroup, PreemptPriority, SubPriority));
}

void HAL_NVIC_EnableIRQ(IRQn_Type IRQn)
{
  /* Enable interrupt */
  NVIC_EnableIRQ(IRQn);
}

void HAL_NVIC_DisableIRQ(IRQn_Type IRQn)
{
  /* Disable interrupt */
  NVIC_DisableIRQ(IRQn);
}

uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb)
{
   return SysTick_Config(TicksNumb);
}


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
