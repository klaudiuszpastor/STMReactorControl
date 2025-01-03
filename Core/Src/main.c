/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE BEGIN Includes */

#include "hagl.h"
#include "font6x9.h"
#include "rgb565.h"
#include <stdio.h>
#include "ds18b20.h"
#include "wchar.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int __io_putchar(int ch)
{
  if (ch == '\n') {
    __io_putchar('\r');
  }

  HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, HAL_MAX_DELAY);

  return 1;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM6_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  if (ds18b20_init() != HAL_OK) {
    Error_Handler();
  }

  const uint8_t ds1[] = { 0x28, 0x29, 0x35, 0x7, 0xD6, 0x1, 0x3C, 0xFF };
  const uint8_t ds2[] = { 0x28, 0xD3, 0xEA, 0x7, 0xD6, 0x1, 0x3C, 0x73 };

  //HAL_TIM_Base_Start(&htim6);
  //HAL_StatusTypeDef rc = wire_reset();

  //wire_write(0x33);

  //int i;
  //uint8_t rom_code[8];
  //for (i = 0; i < 8; i++)
  //rom_code[i] = wire_read();

  //uint8_t crc = wire_crc(rom_code, 7);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  lcd_init();
  hagl_surface_t surface;

  hagl_hal_init(&surface);

  hagl_put_text(&surface, L"T1:", 10, 70, WHITE, font6x9);
  hagl_put_text(&surface, L"T2:", 10, 100, WHITE, font6x9);

  lcd_copy();

  while (1)
  {
      wchar_t wbuffer[16];

      ds18b20_start_measure(ds1);
      ds18b20_start_measure(ds2);

      HAL_Delay(750);

      float temp1 = ds18b20_get_temp(ds1);
      float temp2 = ds18b20_get_temp(ds2);

      printf("Debug Temp1: %.1f, Temp2: %.1f\n", temp1, temp2);

      hagl_fill_rectangle(&surface, 40, 70, 150, 85, rgb565(0, 0, 0));
      hagl_fill_rectangle(&surface, 40, 100, 150, 115, rgb565(0, 0, 0));

      if (temp1 <= -80.0f) {
          swprintf(wbuffer, sizeof(wbuffer) / sizeof(wbuffer[0]), L"Error");
      } else {
          swprintf(wbuffer, sizeof(wbuffer) / sizeof(wbuffer[0]), L"%.1f *C", temp1);
      }
      printf("Buffer T1: %ls\n", wbuffer);
      hagl_put_text(&surface, wbuffer, 40, 70, WHITE, font6x9);

      if (temp2 <= -80.0f) {
          swprintf(wbuffer, sizeof(wbuffer) / sizeof(wbuffer[0]), L"Error");
      } else {
          swprintf(wbuffer, sizeof(wbuffer) / sizeof(wbuffer[0]), L"%.1f *C", temp2);
      }
      printf("Buffer T2: %ls\n", wbuffer);
      hagl_put_text(&surface, wbuffer, 40, 100, WHITE, font6x9);

      lcd_copy();
      //HAL_Delay(1000);

      /* USER CODE END WHILE */
      /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
