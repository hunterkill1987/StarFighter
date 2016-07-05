#include <allegro5\allegro.h>
#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

class InputManager
{
private:
	ALLEGRO_EVENT_QUEUE		*Input_queue;
	ALLEGRO_EVENT			events;

	static InputManager* Instance;
	InputManager(){};

public:
	bool done;

	static InputManager* GetInstance();

	~InputManager(void);

	int Init(ALLEGRO_EVENT_QUEUE *event_queue);

	virtual int UpdateInput();

	virtual void KeyPressed(ALLEGRO_EVENT& Event,int& KeyCode);

	virtual void KeyReleased(ALLEGRO_EVENT& Event, int& KeyCode);

	virtual void KeyDown(ALLEGRO_EVENT& Event, int& KeyCode);

};
#endif

