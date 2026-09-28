//
// Created by Anh Huynh on 13.9.2026.
//

#include "../Encoder.h"

void Encoder::irq_handler(uint gpio, uint32_t event_mask) const
{
	BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
	if (gpio == rot_a.get_pin())
	{
		if (!rot_b.read())
		{
			xQueueSendFromISR(queue, &clockwise , &pxHigherPriorityTaskWoken);
		}
		else
		{
			xQueueSendFromISR(queue, &anticlockwise, &pxHigherPriorityTaskWoken);
		}
	}
}

bool Encoder::is_pressed()
{
	bool current_btn_state = rot_sw.read();
	TickType_t now = xTaskGetTickCount();

	if (current_btn_state != last_btn_state)
	{
		if (now - last_press_time >= pdMS_TO_TICKS(250))
		{
			last_press_time = now;
			last_btn_state = true;
			return true;
		}
	}
	if (!current_btn_state)
	{
		last_btn_state = false;
	}
	return false;
}
