#include <zstack/time.h>

#include <devicetree/armv7m.h>

#define INC_CYCLES  (16/5) //(CORE_FREQ / INC_INSTRUCTIONS) // TODO

void cpu_delay_us(U32 us)
{
    U32 i, j;
    
    for (i = 0; i < us; i++)
	
    {
        for (j = 0; j < INC_CYCLES; j++)
        {
            ;
        }
    }
}

