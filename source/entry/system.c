//
// The basic config for SRAM & Clock, they are system IPs.
// But we can also put it in main().
//_____________________________________________________________________________

#include <driver/cortex-m4.h>
#include "system.h"

uint32_t SystemCoreClock = 16000000; /* 16MHz */

void SystemInit(void)
{
  /* Enable FPU & SIMD instructions */
  SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
}
