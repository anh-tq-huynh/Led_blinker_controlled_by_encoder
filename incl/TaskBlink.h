//
// Created by Anh Huynh on 13.9.2026.
//

#ifndef LAB3_2_TASKBLINK_H
#define LAB3_2_TASKBLINK_H
#include "LED.h"



class TaskBlink
{
	public:
	TaskBlink(int led, int frequency): led(led), frequency(frequency){};

	void blink();
	void increase_freq();
	void decrease_freq();
	void turn_on();
	void turn_off();
private:
		LED led;
		bool is_on = false;
		bool period_needs_update = false;
		int frequency;
		int period = 1 * 1000 / frequency;  //convert to ms
		int countdown = period;

};


#endif //LAB3_2_TASKBLINK_H