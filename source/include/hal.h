#ifndef _HAL_H_
#define _HAL_H_

#include "cortex-m4.h"

#include "soc.h"

#include "system.h"

#include "hal_def.h"

#include "hal_conf.h"

#include "hal_cortex.h"

#include "hal_clock.h"

typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;

HAL_StatusTypeDef HAL_Init(void);

#endif
