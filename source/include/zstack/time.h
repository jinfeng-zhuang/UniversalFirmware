#ifndef _HAL_TIME_H_
#define _HAL_TIME_H_

#include <zstack/types.h>

U64 timestamp(void);

void cpu_delay_us(U32 us);
void cpu_delay_ms(U32 ms);

#endif
