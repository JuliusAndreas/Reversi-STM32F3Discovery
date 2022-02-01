/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f3xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32f3xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "LiquidCrystal.h"
#include "OthelloLib.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
typedef unsigned char byte;


/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

int raw_rotation = 0;
int scaled_rotation = 0;
uint32_t pwm_channel = TIM_CHANNEL_1;
int time_limit = 0;
int remaining_time = 0;
int stage = 1;
unsigned char move_command[4];
int frequency = 30;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart3;
/* USER CODE BEGIN EV */
extern TIM_HandleTypeDef htim1;
extern byte white_white[];
extern byte white_blank[];
extern byte blank_white[];
extern byte black_white[];
extern byte white_black[];
extern byte black_black[];
extern byte black_blank[];
extern byte blank_black[];
extern int state;
extern int board[8][8];
extern int turn;

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F3xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f3xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line0 interrupt.
  */
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */

  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  /* USER CODE BEGIN EXTI0_IRQn 1 */

  /* USER CODE END EXTI0_IRQn 1 */
}

/**
  * @brief This function handles EXTI line1 interrupt.
  */
void EXTI1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI1_IRQn 0 */

  /* USER CODE END EXTI1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI1_IRQn 1 */

  /* USER CODE END EXTI1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line4 interrupt.
  */
void EXTI4_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI4_IRQn 0 */

  /* USER CODE END EXTI4_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
  /* USER CODE BEGIN EXTI4_IRQn 1 */

  /* USER CODE END EXTI4_IRQn 1 */
}

/**
  * @brief This function handles ADC1 and ADC2 interrupts.
  */
void ADC1_2_IRQHandler(void)
{
  /* USER CODE BEGIN ADC1_2_IRQn 0 */

  /* USER CODE END ADC1_2_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc1);
  /* USER CODE BEGIN ADC1_2_IRQn 1 */

  raw_rotation = HAL_ADC_GetValue(&hadc1);
  scaled_rotation = ((raw_rotation)*50/63) + 10;

  if(state == 0){
	  time_limit = scaled_rotation;
  }

  HAL_ADC_Start_IT(&hadc1);

  /* USER CODE END ADC1_2_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  if(state==0){
	  switch (stage){
	  	  case 1:
			enable_7_seg(1);
			show_number(0);
			stage = 2;
			break;
	  	  case 2:
			enable_7_seg(2);
			show_number(0);
			stage = 3;
			break;
		  case 3:
			enable_7_seg(3);
			show_number((time_limit%100)/10);
			stage = 4;
			break;
		  case 4:
			enable_7_seg(4);
			show_number(time_limit%10);
			stage = 1;
			break;
	 }
  }else if(state==1){
	  switch (stage){
		  case 1:
			enable_7_seg(1);
			show_number((remaining_time%100)/10);
			stage = 2;
			break;
		  case 2:
			enable_7_seg(2);
			show_number(remaining_time%10);
			stage = 3;
			break;
		  case 3:
			enable_7_seg(3);
			show_number((time_limit%100)/10);
			stage = 4;
			break;
		  case 4:
			enable_7_seg(4);
			show_number(time_limit%10);
			stage = 1;
			break;
	  }
  }



  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);
  TIM_HandleTypeDef *timer = &htim3;
  timer->Instance->PSC /= 1.1;


  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */
  if(state==1){
	  remaining_time--;
	  if(remaining_time<10){
		  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
		  HAL_TIM_Base_Start_IT(&htim3);
	  }
	  if(remaining_time==0){
		  state = 3;
		  forced_game_over(turn);
		  HAL_TIM_Base_Stop_IT(&htim2);
		  HAL_TIM_Base_Stop_IT(&htim4);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
	  }
  }
  /* USER CODE END TIM4_IRQn 1 */
}

/**
  * @brief This function handles USART3 global interrupt / USART3 wake-up interrupt through EXTI line 28.
  */
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 0 */

  /* USER CODE END USART3_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 1 */

  if(state==1){
	  if((move_command[3]!='W')&&(move_command[3]!='B')){
		  HAL_UART_Receive_IT(&huart3, move_command, sizeof(unsigned char)*4);
		  return;
	  }
	  if(((move_command[3]=='W') && (turn!=1))||((move_command[3]=='B') && (turn!=2))){
		  HAL_UART_Receive_IT(&huart3, move_command, sizeof(unsigned char)*4);
		  return;
	  }
	  if(move_command[2]!=' '){
		  HAL_UART_Receive_IT(&huart3, move_command, sizeof(unsigned char)*4);
		  return;
	  }
	  if((col_letter_to_num(move_command[0])==-1)||(row_char_to_num(move_command[1])==-1)){
		  HAL_UART_Receive_IT(&huart3, move_command, sizeof(unsigned char)*4);
		  return;
	  }
	  int row = 0;
	  int col = 0;
	  row = row_char_to_num(move_command[1]);
	  col = col_letter_to_num(move_command[0]);
	  if(isValid(row, col, turn)){
		  capture(row, col, turn);
		  print_board();
		  show_scores();
		  if(switch_turns()){
			  state = 3;
		      game_over();
		      HAL_UART_Receive_IT(&huart3, move_command, sizeof(unsigned char)*4);
			  return;
		  }
		  if(board_is_full()){
			  state = 3;
			  game_over();

			  HAL_UART_Receive_IT(&huart3, move_command, sizeof(unsigned char)*4);
			  return;
		  }
	  }else{
		  illegal_move_alert();
	  }
  }

  HAL_UART_Receive_IT(&huart3, move_command, sizeof(unsigned char)*4);
  return;

  /* USER CODE END USART3_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
