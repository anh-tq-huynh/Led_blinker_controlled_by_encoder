//
// Created by Anh Huynh on 13.9.2026.
//

#ifndef LAB3_2_ENCODER_H
#define LAB3_2_ENCODER_H
#include "FreeRTOS.h"
#include "queue.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "GPIOPin.h"


class Encoder
{
	public:
	Encoder(int rot_sw, int rot_a, int rot_b, QueueHandle_t queue)
		: rot_sw(rot_sw, true,true, true),
		rot_a(rot_a, true, false, true),
		rot_b(rot_b, true, false, true),
		queue(queue)
	{
		getInstancePointer() = this;
		gpio_set_irq_enabled_with_callback(rot_a,GPIO_IRQ_EDGE_RISE, true,rotary_callback);
	};
		void irq_handler(uint gpio, uint32_t event_mask) const;
		bool is_pressed();
	private:
		//GPIO and queue
		GPIOPin rot_sw;
		GPIOPin rot_a;
		GPIOPin rot_b;
		QueueHandle_t queue;

		//Variables
		int clockwise = 1;
		int anticlockwise = -1;
		bool last_btn_state = false;
		int last_press_time = 0;

		//Handler for interrupt callback
		static Encoder*& getInstancePointer()
		{
			Encoder* inst = nullptr;
			return inst;
		}
		static void rotary_callback (uint gpio, uint32_t event_mask)
		{
			Encoder* instance = getInstancePointer();
			if (instance)
			{
				instance -> irq_handler(gpio, event_mask);
			}
		}
};


#endif //LAB3_2_ENCODER_H