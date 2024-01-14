#include <hal/gpio.h>

#include <stm32f4xx_hal.h>

void hal_gpio_init(U16 pin)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	__HAL_RCC_GPIOD_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN(pin);
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Alternate = 0;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void hal_gpio_set(U16 pin, U8 value)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN(pin), value ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

