#include <stdint.h>

#include <devicetree/armv7m.h>

#include "itm.h"

#define ITM ((ITM_Type  *)ITM_BASE)

#if 1
uint32_t ITM_SendChar (uint32_t ch)
{
  if (((ITM->TCR & ITM_TCR_ITMENA_Msk) != 0UL) &&      /* ITM enabled */
      ((ITM->TER & 1UL               ) != 0UL)   )     /* ITM Port #0 enabled */
  {
    while (ITM->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ITM->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}
#endif
