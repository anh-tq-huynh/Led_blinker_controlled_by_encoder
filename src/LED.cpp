//
// Created by Anh Huynh on 6.9.2026.
//


#include "../incl/LED.h"
void LED::toggle_led()
{
	last_state = !last_state;
	led.write(last_state);
}

void LED::led_off() const
{
	led.write(false);
}

void LED::led_on() const
{
	led.write(true);
}