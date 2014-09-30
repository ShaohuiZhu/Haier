/* Includes ------------------------------------------------------------------*/
#include "includes.h"
RTC_DateTypeDef RTC_DateStruct_get;
RTC_TimeTypeDef RTC_TimeStruct_get;
int main(void)
{
	Init();
 /* Start tasks */
	xTaskCreate(Main_task, (int8_t *) "Main_task", STACK_MAIN_TASK,    NULL, MAIN_TASK,  NULL);
	xTaskCreate(Wifi_task, (int8_t *) "Wifi_task", STACK_WIFI_TASK,    NULL, WIFI_TASK,  NULL);
	xTaskCreate(Touch_task, (int8_t *) "Touch_task", STACK_TOUCH_TASK, NULL, TOUCH_TASK, NULL);
	xTaskCreate(DC_task, (int8_t *) "DC_task",     STACK_DC_TASK,      NULL, DC_TASK,    NULL);
	xTaskCreate(AC_task, (int8_t *) "AC_task",     STACK_AC_TASK,      NULL, AC_TASK,    NULL);
 /* Start scheduler */
  vTaskStartScheduler();
}
/**
	* @brief Init function 
	* @param None
	* @retval None
	*/
void Init(void)
{
	Blu_Led_Pwm();
	uart_init();
	rtc_init();
}
/**
  * @brief  Main task run in the background all the time
  * @param  None
  * @retval None
  */
void Main_task(void * pvParameters)
{
	while(1)
	{
		vTaskDelay(2000);
		uart_putstr("Main_task start.");
		
	}
}
/**
	* @brief Wifi task to communicate to the app
	* @param None
	* @retval None
	*/
void Wifi_task(void * pvParameters)
{
	while(1)
	{
		vTaskDelay(2000);
		uart_putstr("Wifi_task start.");
	}
}
/**
	* @brief Touch task to display the UI and communicate with the users
	* @param None
	* @retval None
	*/
void Touch_task(void * pvParameters)
{
	while(1)
	{
		vTaskDelay(2000);
		uart_putstr("Touch_task start.");
		RTC_GetTime(RTC_Format_BCD, &RTC_TimeStruct_get);
		RTC_GetDate(RTC_Format_BCD, &RTC_DateStruct_get);
		uart_putchar(RTC_TimeStruct_get.RTC_Minutes);
	}
}
/**
	* @brief DC task to communicate to air-condition by direct current
	* @param None
	* @retval None
	*/
void DC_task(void * pvParameters)
{
	while(1)
	{
		vTaskDelay(2000);
		uart_putstr("DC_task start.");
	}
}
/**
	* @brief AC task to communicate to air-condition by alternating current
	* @param None
	* @retval None
	*/
void AC_task(void * pvParameters)
{
	while(1)
	{
		vTaskDelay(2000);
		uart_putstr("AC_task start.");
	}
}
