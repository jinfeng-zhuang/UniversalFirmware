#include <stdint.h>

volatile uint32_t systick_inc = 0;

void SysTick_Handler(void)
{
  systick_inc++;
}
