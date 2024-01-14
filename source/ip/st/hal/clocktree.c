#include <stm32f4xx_hal.h>

#include <zstack/types.h>

void clocktree_init(U32 source)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	//_________________________________
	// RCU: Clock: from HSI

	if (0 == source)
	{
		RCC_OscInitStruct.OscillatorType 		= RCC_OSCILLATORTYPE_HSI;	// 16MHz, TODO, defined in soc.
		RCC_OscInitStruct.HSIState 				= RCC_HSI_ON;
		RCC_OscInitStruct.HSICalibrationValue 	= RCC_HSICALIBRATION_DEFAULT;
		RCC_OscInitStruct.PLL.PLLState 			= RCC_PLL_NONE; // directly to SYSCLK
	}
	else if (1 == source)
	{
		RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;	// 8MHz // TODO: defined in devicetree
		RCC_OscInitStruct.HSEState = RCC_HSE_ON;
		RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
		RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
		RCC_OscInitStruct.PLL.PLLM = 4; 				// 8MHz / M(=4) = 2MHz // TODO: defined in devicetree ???
		RCC_OscInitStruct.PLL.PLLN = 168; 				// 2MHz * N(=168) = 336MHz
		RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2; 	// 336MHz / P(=2) = 168MHz (SYCLK)
		RCC_OscInitStruct.PLL.PLLQ = 7; 				// 336MHz / 7 = 48MHz (USB)
	}

	HAL_RCC_OscConfig(&RCC_OscInitStruct);

	//_________________________________
	// RCU: Clock: SYSCLK => AHB, APB1, APB2

	RCC_ClkInitStruct.ClockType 	 = 	RCC_CLOCKTYPE_HCLK   |
										RCC_CLOCKTYPE_SYSCLK |
										RCC_CLOCKTYPE_PCLK1  |
										RCC_CLOCKTYPE_PCLK2;
	if (0 == source)
	{
		RCC_ClkInitStruct.SYSCLKSource 	 = 	RCC_SYSCLKSOURCE_HSI;
		RCC_ClkInitStruct.AHBCLKDivider  = 	RCC_SYSCLK_DIV1;	// AHB  = 16M
		RCC_ClkInitStruct.APB1CLKDivider = 	RCC_HCLK_DIV1;		// APB1 = 16M (MUST <= 42MHz)
		RCC_ClkInitStruct.APB2CLKDivider = 	RCC_HCLK_DIV1;		// APB2 = 16M (MUST <= 84MHz)
		HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);
	}
	else if (1 == source)
	{
		RCC_ClkInitStruct.SYSCLKSource 	 = 	RCC_SYSCLKSOURCE_PLLCLK;
		RCC_ClkInitStruct.AHBCLKDivider  = 	RCC_SYSCLK_DIV1;	// AHB  = 168M
		RCC_ClkInitStruct.APB1CLKDivider = 	RCC_HCLK_DIV4;		// APB1 = 42M (MUST <= 42MHz)
		RCC_ClkInitStruct.APB2CLKDivider = 	RCC_HCLK_DIV2;		// APB2 = 84M (MUST <= 84MHz)
		HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
	}
}

