/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "gpio.h"
#include "oled.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
unsigned char BMP2[] =
        {
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0xDC,0xE4,0xF8,0x79,0x9D,
                0xED,0xF6,0xE7,0xCD,0x3D,0xFB,0xF0,0xCC,0x1C,0xB4,0x80,0x00,0x00,0x80,0x00,0x80,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0xDC,0xEC,0xF0,0x7D,0xBD,
                0xEE,0xF6,0x76,0x2E,0x1D,0x7D,0xF8,0xF4,0xDC,0x28,0x60,0xE0,0xC0,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x80,
                0xA0,0xC0,0xC0,0xE8,0x68,0x68,0x70,0xB7,0x39,0x7E,0x4F,0x07,0x1B,0x1C,0x3F,0x03,
                0x03,0x03,0x07,0x03,0x00,0x03,0x07,0x07,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,
                0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x07,0x07,0x07,0x0D,0x0E,0x00,
                0x00,0x00,0x00,0x00,0x00,0x38,0x33,0x1F,0x3F,0x3E,0x30,0x36,0x7E,0x68,0xE8,0xC8,
                0xD0,0xC0,0xA0,0xA0,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0xD4,0x78,0x9C,0xE0,0xFA,0xFC,0x1C,0xCE,0x07,0x1B,0x1B,
                0x0D,0x01,0x00,0x10,0x62,0x60,0x61,0x61,0xE0,0xE0,0xE0,0xA0,0xF0,0xF0,0xF0,0x00,
                0x00,0x00,0x16,0x0E,0x1C,0x1C,0x1C,0x1C,0x1E,0x02,0x00,0x00,0x58,0x6C,0x98,0x98,
                0xF8,0xF8,0xF8,0x98,0x18,0x78,0xFC,0x7E,0x7E,0x62,0x1C,0x5C,0x5C,0x5C,0x5C,0xFA,
                0xEE,0xBE,0xFA,0xB0,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x61,0x61,0xF3,0xF0,
                0xA4,0x05,0x07,0x53,0x77,0x6E,0x1E,0x3D,0xFA,0xF6,0xCE,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x3B,0x7C,0x33,0x0F,0xBF,0x7F,0x71,0xEF,0xD0,0xB0,0xB0,
                0x37,0x07,0x07,0x03,0x83,0x03,0x83,0x03,0x05,0x01,0x05,0x05,0x05,0x06,0x07,0x00,
                0x00,0x00,0x00,0x00,0x00,0x16,0x1F,0x1F,0x18,0x16,0x06,0x07,0x17,0x03,0x03,0x05,
                0x05,0x05,0x05,0x03,0x03,0x03,0x03,0x16,0x16,0x16,0x0F,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x07,0x06,0x03,0x03,0x03,0x03,0x03,0x06,0x16,0x16,0x16,0x96,0x1F,0x1F,
                0x5D,0x40,0x40,0x98,0xDC,0xEC,0xF0,0x78,0xBF,0xDF,0xE7,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,
                0x0B,0x07,0x06,0x2E,0x2C,0x2D,0x1D,0x5A,0x98,0xBC,0x34,0xB0,0x30,0xB0,0xE0,0xE0,
                0x68,0xB0,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0xF8,0xF0,0x08,0xF0,0xF0,0xF0,0xB0,0x18,0x1A,0x18,0x1C,0x2D,0x2D,0x3E,
                0x36,0x17,0x0B,0x3B,0x05,0x0F,0x0E,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xF8,0xFF,0xFF,0x0F,0xC1,
                0xC6,0x8F,0x06,0x00,0x00,0x20,0x70,0x20,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0xB8,0x87,0xFF,0xFF,0xF8,0x00,0xF8,0xF8,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0xF8,0xF8,0xF8,0x84,0x80,0x80,0x80,0x80,0x80,0x81,0x85,0xF9,
                0xF8,0xF8,0x07,0x07,0x47,0xA7,0xB0,0xD0,0xC0,0x50,0x40,0x40,0xC0,0xC0,0xC0,0x90,
                0x70,0x30,0xF0,0xD0,0xD0,0xD0,0xD0,0xD0,0x40,0xD0,0x30,0x90,0xD0,0xD0,0x50,0x50,
                0x40,0x40,0xC0,0xC0,0x80,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x05,0xFC,0xFC,0x08,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x21,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x1F,
                0x1F,0x1F,0x00,0x0C,0x00,0x2F,0x2F,0x1F,0x1B,0x1B,0x13,0x13,0x13,0x1B,0x1B,0x1B,
                0x22,0x20,0x3F,0x1F,0x1F,0x1F,0x21,0x1E,0x0E,0x00,0x0F,0x0F,0x1F,0x1A,0x1B,0x13,
                0x13,0x13,0x1B,0x1B,0x1B,0x2B,0x00,0x00,0x00,0x0C,0x00,0x04,0x38,0x3F,0x3F,0x00,
                0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//E:\桌面\Snipaste_2022-10-11_02-27-32.bmp0DB 00H 00H 00H 00H 00H 00H 00H 00H 00H 00H 00H 00H 00H 00H 00H 00H;
        };

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
    float num = 13.14;
    char num_temp_buffer[16];
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
    OLED_Init();
    OLED_CLS();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
      OLED_ShowStr(0, 0, "Hello world", 2);//显示字符串
      OLED_ShowStr(0, 2, "Hello world", 1);//显示字符串
      OLED_ShowCN_STR(0, 4 , 0 , 8);
//      sprintf(num_temp_buffer,"show num:%0.2f",num);
      OLED_ShowStr(0, 6, num_temp_buffer, 2);//显示字符串
      HAL_Delay(2000);
//      printf("F401测试\r\n");
      OLED_CLS();
      OLED_DrawBMP(0,0,128,7,BMP2);
      HAL_Delay(2000);
      OLED_CLS();


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

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/