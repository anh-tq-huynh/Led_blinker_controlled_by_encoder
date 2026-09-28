//
// Created by Anh Huynh on 13.9.2026.
//

#ifndef LAB3_2_TASKBLINK_H
#define LAB3_2_TASKBLINK_H
#include "FreeRTOS.h"
#include "LED.h"
#include "task.h"


class TaskBlink
{
	public:
		TaskBlink(LED &leds): leds(leds)
		{
			xTaskCreate(
				blinker,
				"Blinker",
				512,
				(void * )this,
				tskIDLE_PRIORITY + 1,
				&handle);
		};
		void blink();

	private:
		LED &leds;
		int led_half_period = leds.get_period()/ 2;
		int prev_led_half_period = led_half_period;
		int countdown = led_half_period;


		static void blinker (void* param)
		{
			auto *instance = static_cast<TaskBlink*> (param);
			instance -> blink();
		}
		TaskHandle_t handle;

};


#endif //LAB3_2_TASKBLINK_H