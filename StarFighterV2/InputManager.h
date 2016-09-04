#include <allegro5\allegro.h>
#include <allegro5\keycodes.h>
#include <vector>
#include "rapidxml\rapidxml.hpp"
#include "EventManager.h"

#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

using namespace rapidxml;
using namespace std;

enum EButtonState
{
	EB_Pressed,				
	EB_Released,
	EB_Hold,
};

struct SButtonBind
{
	int		Button;
	char*	EvnetBind;
	EButtonState State;
};

class InputManager
{
private:
	ALLEGRO_EVENT_QUEUE		*Input_queue;
	ALLEGRO_EVENT			events;

	static InputManager* Instance;
	InputManager(){};
	EventManager* InputEvent;

	std::vector<SButtonBind> KeyMap;

public:
	bool done;

	static InputManager* GetInstance();

	~InputManager(void);

	int Init(ALLEGRO_EVENT_QUEUE *event_queue);

	virtual int UpdateInput();
};
#endif

