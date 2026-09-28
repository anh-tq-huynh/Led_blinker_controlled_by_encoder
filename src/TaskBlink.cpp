//
// Created by Anh Huynh on 13.9.2026.
//

#include "../incl/TaskBlink.h"
#include "FreeRTOS.h"
#include "task.h"




void TaskBlink::blink()
{
	while (true)
	{
		if (leds.is_enabled())
		{
			led_half_period = leds.get_period() / 2;
			leds.toggle_leds();
			vTaskDelay(pdMS_TO_TICKS(led_half_period));
		}
		else
		{
			leds.leds_off();
		}
		vTaskDelay(pdMS_TO_TICKS(1));
	}

}




