//
// Created by Anh Huynh on 13.9.2026.
//

#ifndef LAB3_2_TASKEVENTHANDLER_H
#define LAB3_2_TASKEVENTHANDLER_H
#include "queue.h"
#include "Encoder.h"
#include "LED.h"


class TaskEventHandler
{
	public:
	TaskEventHandler(LED &leds, QueueHandle_t queue)
		:
		queue(queue),
		leds(leds)
	{
		xTaskCreate(
			event_handler,
			"Event handler",
			512,
			(void *) this,
			tskIDLE_PRIORITY +1,
			&handle);
	};

		void event_handle();
		void update() const;

	private:
		QueueHandle_t queue;
		LED &leds;
		int receive_input;
		BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
		static void event_handler (void *param)
		{
			auto *instance = static_cast<TaskEventHandler*>(param);
			instance ->event_handle();
		}
		TaskHandle_t handle;
};


#endif //LAB3_2_TASKEVENTHANDLER_H