#ifndef _HAL_GPIO_H_
#define _HAL_GPIO_H_

#include "types.h"

#define PD12 (('D' << 8) | 12)
#define PD13 (('D' << 8) | 13)
#define PD14 (('D' << 8) | 14)
#define PD15 (('D' << 8) | 15)

#define GPIO_PORT(x) 	(((x) >> 8) & 0xFF)
#define GPIO_PIN(x)		((x) & 0xFF)

void hal_gpio_init 			(U16 pin);
void hal_gpio_set       (U16 pin, U8 value);
U8   hal_gpio_get    		(U16 pin);
void hal_gpio_toggle		(U16 pin);

#endif
