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
		if (is_on)
		{
			if (countdown > 0)
			{
				countdown -= 10;
			}
			else
			{
				led.toggle_led();
				countdown = led.get_period();
			}
		}
		else
		{
			led.led_off();
		}
		vTaskDelay(pdMS_TO_TICKS(10));
	}

}

void TaskBlink::increase_freq()
{
	int increment = 20;
	if (frequency + increment <= MAX_FREQ)
	{
		frequency += increment;
		period = 1 * 1000 / frequency;  //convert to ms
	}
}

void TaskBlink::decrease_freq()
{
	int decrement = 20;
	if (frequency - decrement >= MIN_FREQ)
	{
		frequency -= decrement;
		period = 1 * 1000 / frequency;  //convert to ms
	}
}

void TaskBlink::turn_on()
{
	is_on = true;
}

void TaskBlink::turn_off()
{
	is_on = false;
}



