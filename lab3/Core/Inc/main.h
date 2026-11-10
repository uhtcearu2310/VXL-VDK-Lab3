/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN1_Pin GPIO_PIN_3
#define BTN1_GPIO_Port GPIOA
#define BTN2_Pin GPIO_PIN_4
#define BTN2_GPIO_Port GPIOA
#define BTN3_Pin GPIO_PIN_5
#define BTN3_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_6
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_7
#define EN1_GPIO_Port GPIOA
#define P0_Pin GPIO_PIN_0
#define P0_GPIO_Port GPIOB
#define P1_Pin GPIO_PIN_1
#define P1_GPIO_Port GPIOB
#define P2_Pin GPIO_PIN_2
#define P2_GPIO_Port GPIOB
#define T3_Pin GPIO_PIN_10
#define T3_GPIO_Port GPIOB
#define T4_Pin GPIO_PIN_11
#define T4_GPIO_Port GPIOB
#define T5_Pin GPIO_PIN_12
#define T5_GPIO_Port GPIOB
#define T6_Pin GPIO_PIN_13
#define T6_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_8
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_9
#define EN3_GPIO_Port GPIOA
#define R1_Pin GPIO_PIN_10
#define R1_GPIO_Port GPIOA
#define Y1_Pin GPIO_PIN_11
#define Y1_GPIO_Port GPIOA
#define G1_Pin GPIO_PIN_12
#define G1_GPIO_Port GPIOA
#define R2_Pin GPIO_PIN_13
#define R2_GPIO_Port GPIOA
#define Y2_Pin GPIO_PIN_14
#define Y2_GPIO_Port GPIOA
#define G2_Pin GPIO_PIN_15
#define G2_GPIO_Port GPIOA
#define P3_Pin GPIO_PIN_3
#define P3_GPIO_Port GPIOB
#define P4_Pin GPIO_PIN_4
#define P4_GPIO_Port GPIOB
#define P5_Pin GPIO_PIN_5
#define P5_GPIO_Port GPIOB
#define P6_Pin GPIO_PIN_6
#define P6_GPIO_Port GPIOB
#define T0_Pin GPIO_PIN_7
#define T0_GPIO_Port GPIOB
#define T1_Pin GPIO_PIN_8
#define T1_GPIO_Port GPIOB
#define T2_Pin GPIO_PIN_9
#define T2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
