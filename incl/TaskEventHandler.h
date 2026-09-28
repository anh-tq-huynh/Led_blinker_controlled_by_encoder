//
// Created by Anh Huynh on 13.9.2026.
//

#ifndef LAB3_2_TASKEVENTHANDLER_H
#define LAB3_2_TASKEVENTHANDLER_H
#include "queue.h"
#include "Encoder.h"


class TaskEventHandler
{
	public:
	TaskEventHandler(int rot_w, int rot_a, int rot_b, QueueHandle_t queue)
		:
		queue(queue),
		encoder(rot_w, rot_a, rot_b, queue){};
	private:
		QueueHandle_t queue;
		Encoder encoder;

};


#endif //LAB3_2_TASKEVENTHANDLER_H