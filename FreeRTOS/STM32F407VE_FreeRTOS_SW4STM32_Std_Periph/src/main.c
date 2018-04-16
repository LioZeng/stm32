/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */


#include "includes.h"
#include "task.h"

static void vTaskTaskUserIF(void *pvParameters);
static void vTaskLED(void *pvParameters);
static void vTaskMsgPro(void *pvParameters);
static void vTaskStart(void *pvParameters);
static void AppTaskCreate(void);


static TaskHandle_t xHandleTaskUserIF = NULL;
static TaskHandle_t xHandleTaskLED = NULL;
static TaskHandle_t xHandleTaskMsgPro = NULL;
static TaskHandle_t xHandleTaskStart = NULL;

int main(void)
{
	__set_PRIMASK(1);

	BSP_Config();

	AppTaskCreate();

	vTaskStartScheduler();

	for(;;);
}



/*******************************************************************************
* 函数名  :      vTaskTaskUserIF
* 描述:          接口消息处理,这里用作LED闪烁
* 输入参数:      pvParameters是在创建该任务时传递的形参
*
* Output         : 无
* Return         :
*******************************************************************************/
static void vTaskTaskUserIF(void *pvParameters)
{
  while(1)
  {
    GPIO_ToggleBits(GPIOB, GPIO_Pin_0);
    vTaskDelay(100);
  }
}


static void vTaskLED(void *pvParameters)
{
  while(1)
  {
    GPIO_ToggleBits(GPIOB, GPIO_Pin_1);
    vTaskDelay(1000);
  }
}


static void vTaskMsgPro(void *pvParameters)
{
  while(1)
  {
    GPIO_ToggleBits(GPIOA, GPIO_Pin_3);
    vTaskDelay(300);
  }
}


static void vTaskStart(void *pvParameters)
{
  while(1)
  {
    GPIO_ToggleBits(GPIOA, GPIO_Pin_4);
    vTaskDelay(400);
  }
}

static void AppTaskCreate(void)
{
  xTaskCreate(vTaskTaskUserIF,
              "vTaskUserIF",
              512,
              NULL,
              1,
              &xHandleTaskUserIF);

  xTaskCreate(vTaskLED,
              "vTaskLED",
			  512,
              NULL,
              2,
              &xHandleTaskLED);

  xTaskCreate(vTaskMsgPro,
              "vTaskMsgPro",
			  512,
              NULL,
              3,
              &xHandleTaskMsgPro);

  xTaskCreate(vTaskStart,
              "vTaskStart",
			  512,
              NULL,
              4,
              &xHandleTaskStart);
}

/********************************* End of file *********************************/
