//
// Created by Anh Huynh on 6.9.2026.
//

#ifndef LAB3_1_LED_H
#define LAB3_1_LED_H

#include "GPIOPin.h"


class LED
{
	public:
		explicit LED(int led_pin) : led(led_pin,false, false, false){};
		void toggle_led();

		void led_off() const;

		void led_on() const;

	private:
		GPIOPin led;
		bool last_state = false;
};



#endif //LAB3_1_LED_H