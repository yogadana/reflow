/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <lvgl.h>
//#include <examples/lv_examples.h>
#include "ILI9341.h"
#include <ui/ui.h>
#include <math.h>  // Untuk fungsi log()
#include "stdio.h"
#include "string.h"
#include "stdarg.h"

#define constrain(nilaix,bawah,atas) ( (nilaix)<(bawah) ? (bawah) : ( (nilaix)>(atas) ? (atas) : (nilaix) ) )
#define ADC_RESOLUTION 4096  // Resolusi ADC (misalnya, 12-bit untuk STM32)
const float VREF = 3.3;             // Tegangan referensi ADC (dalam volt)
//const float R_SERI = 1230;         // Nilai resistor seri (ohm)
const float R_SERI = 1200;         // Nilai resistor seri (ohm)
uint32_t prev = 0, start_enc_btn_timing = 0;
volatile uint16_t adc_val;
volatile float temperature = 0, integral_sum = 0;
int measured_temperature = 0;
float rNTC, vNTC, time_4_start = 0;
int Temp_target[5] = {0, 150, 150, 221, 221};
int Time_target[5] = {0, 100, 180, 240, 260};
int data_pwm = 0;
bool home = false;
volatile bool enc_btn_flag = false;
volatile bool enc_btn_pressed = false;
//float beta_data[13]={8999.94478, 4597.25931, 4642.77635, 4589.35974, 4922.85215, 4382.09046, 4981.99115, 5088.81046, 5219.67009, 5229.97882, 5231.95880, 8424.73742, 1907.32719
//};
//float R_ref[13]={76800, 37800, 19800, 10900, 6800, 4100, 2860, 1480, 1100, 800, 560, 400, 206
//};
//float T_data[13]={30, 46, 61, 76, 89, 103, 115, 136, 146, 157, 170, 183, 200
//};
//float beta_data[]={3356, 3906, 4282, 4425, 3836, 4491, 4124, 2943, 4671};
float beta_data[]={3358, 3910, 4291, 4444, 3865, 4549, 4211, 3593, 3863};
//float R_ref[]={76260, 38430, 18998, 9555, 5058, 3078, 1818, 1171, 879, 579
float R_ref[]={76230, 38400, 18968, 9525, 5028, 3048, 1788, 1141, 740, 487
};
float T_data[]={30, 50, 70, 90, 110, 130, 150, 170, 195, 220};
//float time_from_start = 0;
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
ADC_HandleTypeDef hadc1;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart2;

SRAM_HandleTypeDef hsram1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_FSMC_Init(void);
static void MX_TIM2_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM4_Init(void);
static void MX_TIM3_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void myprintf(const char *fmt, ...) {
  static char buffer[256];
  va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);

  int len = strlen(buffer);
  HAL_UART_Transmit(&huart2, (uint8_t*)buffer, len, -1);

}

FATFS FatFs;
FRESULT mount_sd(int attemp) {
    FRESULT fres = f_mount(&FatFs, "", 1);
    if (fres != FR_OK) {
    	if(attemp <= 0){
    		return fres;
    	}
    	HAL_Delay(2000);
    	return mount_sd(attemp - 1);
    }
    return fres;
}

void unmount_sd() {
    f_mount(NULL, "", 0);
}

FRESULT write_data(uint16_t d1, uint16_t d2, uint16_t d3, uint16_t d4, uint16_t d5, uint16_t d6, uint16_t d7, uint16_t d8, const char* filename) {
    FIL fil;
    FRESULT fres;
    char path[30];
    sprintf(path, "%s.txt", filename);

    fres = mount_sd(5);
    if(fres != FR_OK) return fres;

    fres = f_open(&fil, path, FA_WRITE | FA_CREATE_ALWAYS);
    if (fres != FR_OK) {
        unmount_sd();
        return fres;
    }

    char buffer[100];
    sprintf(buffer, "%u\n%u\n%u\n%u\n%u\n%u\n%u\n%u\n", d1, d2, d3, d4, d5, d6, d7, d8);

    UINT bytesWritten;
    fres = f_write(&fil, buffer, strlen(buffer), &bytesWritten);
    if (fres != FR_OK) {
        f_close(&fil);
        unmount_sd();
        return fres;
    }

    f_close(&fil);
    unmount_sd();
    return fres;
}

FRESULT read_data(uint16_t* d1, uint16_t* d2, uint16_t* d3, uint16_t* d4, uint16_t* d5, uint16_t* d6, uint16_t* d7, uint16_t* d8, const char* filename) {
    FIL fil;
    FRESULT fres;
    char path[30];
    sprintf(path, "%s.txt", filename);
    fres = mount_sd(5);
	if(fres != FR_OK) return fres;
    fres = f_open(&fil, path, FA_READ);
    if (fres != FR_OK) {
        unmount_sd();
        return fres;
    }
    char buffer[100];
    UINT bytesRead;
    fres = f_read(&fil, buffer, sizeof(buffer) - 1, &bytesRead);
    if (fres != FR_OK) {
        f_close(&fil);
        unmount_sd();
        return fres;
    }
    buffer[bytesRead] = '\0';
    sscanf(buffer, "%hu\n%hu\n%hu\n%hu\n%hu\n\%hu\n%hu\n%hu\n", d1, d2, d3, d4, d5, d6, d7, d8);
    f_close(&fil);
    unmount_sd();
    return fres;
}

FRESULT list_txt_files(char* file_list, size_t list_size) {
    DIR dir;
    FILINFO fno;
    FRESULT fres;
    size_t list_index = 0;
    fres = mount_sd(5);
	if(fres != FR_OK) return fres;

    fres = f_opendir(&dir, "");
    if (fres != FR_OK) {
        unmount_sd();
        return fres;
    }

    while (1) {
        fres = f_readdir(&dir, &fno);
        if (fres != FR_OK || fno.fname[0] == 0) break;
        if (!(fno.fattrib & AM_DIR)) {
            char *dot = strrchr(fno.fname, '.');
            if (dot && strcasecmp(dot, ".TXT") == 0) {
                size_t name_length = dot - fno.fname;
                if (list_index + name_length + 2 < list_size) {
                    strncpy(&file_list[list_index], fno.fname, name_length);
                    file_list[list_index + name_length] = '\n'; // Add newline
                    file_list[list_index + name_length + 1] = '\0'; // Null terminator
                    list_index += name_length + 1;
                } else {
                    break;
                }
            }
        }
    }
    f_closedir(&dir);
    unmount_sd();
    return FR_OK;
}


FRESULT delete_file(const char *filename) {
    FRESULT fres;
    char path[30];

    snprintf(path, sizeof(path), "%s.txt", filename);
    fres = mount_sd(5);
	if(fres != FR_OK) return fres;
    FILINFO fno;
    fres = f_stat(path, &fno);
    if (fres == FR_NO_FILE) {
        unmount_sd();
        return fres;
    } else if (fres != FR_OK) {
        unmount_sd();
        return fres;
    }

    // Hapus file jika ada
    fres = f_unlink(path);
    unmount_sd();

    return fres;
}

float get_midle_temp(float Ntc_temp){
	return 1.057 * Ntc_temp - 1.6318;
}

float get_temp_pt2(float R2) {
    static float R1 = 0, beta = 0, T1 = 0;
    R1 = R_ref[0];
	beta = beta_data[0];
	T1 = T_data[0];
    for(int a = 0; a <= 9; a++){
        if(R2 < R_ref[a]){
            R1 = R_ref[a];
            beta = beta_data[a];
            T1 = T_data[a];
        }
        else break;
    }
    return 1 / ((-log(R1 / R2) / beta) + (1 / (T1 + 273.15))) - 273.15;
}

uint16_t adc2Celcius() {
    vNTC = (float)adc_val * 3.3f / 4095.0f;
    rNTC = R_SERI * (vNTC / (VREF - vNTC));
    return (uint16_t)get_temp_pt2(rNTC);
}

uint32_t GetElapsedTimems(uint32_t start) {
    uint32_t current = uwTick;  // Membaca nilai counter saat ini
    if (current >= start) {
        return current - start;  // Waktu yang berlalu (tidak ada overflow)
    } else {
        return (4294967295 - start + current + 1);  // +1 karena counter termasuk 0
    }
}

int compute_PI(float pv, float sp, float kp, float ki, float kd) {
    float error = sp - pv;
//    if(error < 0) integral_sum = 0;
    static float prev_err = 0;
    float dt = (float)GetElapsedTimems(prev);
    integral_sum += error * dt;
    prev = uwTick;


    if(error < 20 && error > -20) integral_sum = constrain(integral_sum, 0, 250/ki);
    else integral_sum = 0;
    float derivative = (error - prev_err) / dt;
    prev_err = error;

//    if(error > 0)

    float output = (kp * error) + (ki * integral_sum) + (kd * derivative);
//    output = constrain((int)output, 0, 250) ;
    output = constrain((int)output, 0, 250);
//    if(output == 250.0) integral_sum = 0;
    prev_err = error;

    return output;
}


void my_enc_read (lv_indev_t *indev_drv, lv_indev_data_t * data)
{
    static int prev_data = 0;
    int pulse = (TIM2->CNT) >> 2;
    int selisih = pulse - prev_data;
    prev_data = pulse;
    data->enc_diff = selisih;

    if(enc_btn_flag){
    	data->state = LV_INDEV_STATE_PRESSED;
        enc_btn_flag = false;
    }
    else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}


void create_group(){
	lv_indev_t *my_indev = lv_indev_create();

	ui_create_groups();
	lv_indev_set_type(my_indev, LV_INDEV_TYPE_ENCODER);
	lv_indev_set_read_cb(my_indev, my_enc_read);
	lv_indev_set_group(my_indev, groups.Enc);
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
  MX_FSMC_Init();
  MX_TIM2_Init();
  MX_ADC1_Init();
  MX_TIM4_Init();
  MX_TIM3_Init();
  MX_SPI1_Init();
  MX_FATFS_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  lv_init();
  lv_port_disp_init();
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  start_enc_btn_timing = uwTick;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  create_group();
  ui_init();
  if ((htim3.Instance->CR1 & TIM_CR1_CEN) == 1) {
		  HAL_TIM_Base_Stop_IT(&htim3);
  }
  while (1)
  {
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1, 1);
	  adc_val = HAL_ADC_GetValue(&hadc1);
//	  HAL_Delay(50);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  lv_task_handler();
	  ui_tick();
	  if(home){
//		  lv_scr_load(objects.main);
		  back_to_home();
		  home = !home;
	  }
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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_14;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 5;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 5;
  if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 8399;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 4999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 10000;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 839;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : ENC_BTN_Pin */
  GPIO_InitStruct.Pin = ENC_BTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(ENC_BTN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SD_CS_Pin */
  GPIO_InitStruct.Pin = SD_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SD_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Button_Pin */
  GPIO_InitStruct.Pin = Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Button_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : RST_Pin */
  GPIO_InitStruct.Pin = RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RST_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* FSMC initialization function */
static void MX_FSMC_Init(void)
{

  /* USER CODE BEGIN FSMC_Init 0 */

  /* USER CODE END FSMC_Init 0 */

  FSMC_NORSRAM_TimingTypeDef Timing = {0};

  /* USER CODE BEGIN FSMC_Init 1 */

  /* USER CODE END FSMC_Init 1 */

  /** Perform the SRAM1 memory initialization sequence
  */
  hsram1.Instance = FSMC_NORSRAM_DEVICE;
  hsram1.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
  /* hsram1.Init */
  hsram1.Init.NSBank = FSMC_NORSRAM_BANK1;
  hsram1.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
  hsram1.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
  hsram1.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_8;
  hsram1.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
  hsram1.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram1.Init.WrapMode = FSMC_WRAP_MODE_DISABLE;
  hsram1.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
  hsram1.Init.WriteOperation = FSMC_WRITE_OPERATION_ENABLE;
  hsram1.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
  hsram1.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
  hsram1.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram1.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
  hsram1.Init.PageSize = FSMC_PAGE_SIZE_NONE;
  /* Timing */
  Timing.AddressSetupTime = 0;
  Timing.AddressHoldTime = 15;
  Timing.DataSetupTime = 3;
  Timing.BusTurnAroundDuration = 0;
  Timing.CLKDivision = 16;
  Timing.DataLatency = 17;
  Timing.AccessMode = FSMC_ACCESS_MODE_A;
  /* ExtTiming */

  if (HAL_SRAM_Init(&hsram1, &Timing, NULL) != HAL_OK)
  {
    Error_Handler( );
  }

  /* USER CODE BEGIN FSMC_Init 2 */

  /* USER CODE END FSMC_Init 2 */
}

/* USER CODE BEGIN 4 */
float kpp = 2;
//float kp = 3.5;
//float kp = 6.25;
//float ki = 0;
//float kip = 0.0005;
float kip = 0.00004;
//float kdp = 8500;
float kdp = 3500;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM3) {
//    	adc2Celcius();
    	data_pwm =compute_PI(adc2Celcius(), (float) SP_data, kpp, kip, kdp);
//    	data_pwm = abs(SP_data) % 251;
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, data_pwm * (TIM4->ARR / 250));
//		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, compute_PI(adc2Celcius(), (float) SP_data, kp, ki) * (TIM4->ARR / 250));
//    	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, (int)SP_data * (TIM4->ARR / 250));
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == Button_Pin){
//		lv_scr_load(objects.main);
		home = true;
	}
	else if(GPIO_Pin == ENC_BTN_Pin){
//		HAL_Delay(2);
//		if(HAL_GPIO_ReadPin(ENC_BTN_GPIO_Port, ENC_BTN_Pin) == 1) return;

//		if(GetElapsedTimems(start_enc_btn_timing) <= 200) return;
//		start_enc_btn_timing = uwTick;
//		enc_btn_flag = true;

		if(HAL_GPIO_ReadPin(ENC_BTN_GPIO_Port, ENC_BTN_Pin) == 0){
			start_enc_btn_timing = uwTick;
		}
		else if(HAL_GPIO_ReadPin(ENC_BTN_GPIO_Port, ENC_BTN_Pin) == 1 && GetElapsedTimems(start_enc_btn_timing) >= 100){
//			start_enc_btn_timing = uwTick;
			enc_btn_flag = true;
		}

	}
}
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
