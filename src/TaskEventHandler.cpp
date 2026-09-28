//
// Created by Anh Huynh on 13.9.2026.
//

#include "FreeRTOS.h"
#include "queue.h"
#include "../incl/TaskEventHandler.h"

#include <string>

#include "incl/vPrintString.h"


void TaskEventHandler::event_handle()
{
	while (true)
	{
		BaseType_t xStatus = xQueueReceive(queue, &receive_input, portMAX_DELAY);

		if (xStatus == pdPASS)
		{
			//std::string msg = "Recieved from rotary: " + std::to_string(receive_input) + "\n";
			//vPrintString(msg.c_str());
			update();
		}
	}
}

void TaskEventHandler::update() const
{
	if (receive_input == 0) //pressed
	{
		leds.turn_on_off();
	}
	else if (receive_input == 1)
	{
		leds.increase_freq();
	}
	else if (receive_input == -1)
	{
		leds.decrease_freq();
	}
}
