//
// jinfengz, 2024.w2
//
// Attention: as HAL_GPIO_Xxx use bitmask, they can set lots of GPIO one time.
//_____________________________________________________________________________

#include <hal/gpio.h>

#include <stm32f4xx_hal.h>

void hal_gpio_init(U16 pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	uint16_t pin_mask;
	
	pin_mask = 1 << GPIO_PIN(pin);
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	HAL_GPIO_WritePin(GPIOD, pin_mask, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin = pin_mask;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void hal_gpio_set(U16 pin, U8 value)
{
	uint16_t pin_mask;
	
	pin_mask = 1 << GPIO_PIN(pin);
	
	HAL_GPIO_WritePin(GPIOD, pin_mask, value ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

