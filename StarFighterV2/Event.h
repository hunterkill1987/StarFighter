#include <allegro5\allegro.h>
#include "IEvent.h"


#pragma once
#ifndef EVENT_H
#define EVENT_H

const float FPS = 60;

static bool b_act[5] = {false, false, false, false, false};
static bool b_stat[3] = {false, false, false};//only for test

class Event: public IEvent
{
private:
	ALLEGRO_EVENT_QUEUE		*event_queue;
	ALLEGRO_TIMER			*timer;
	ALLEGRO_EVENT			events;
	unsigned int			b_input;

public:
	bool done;

	Event();
	~Event(void);

	int Init();

	virtual bool Tick();
	virtual bool IsQueue();
	
	virtual int UpdateInput();

	virtual int GetInput();
	virtual int GetInputState();
};
#endif

