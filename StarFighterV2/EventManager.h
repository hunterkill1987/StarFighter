#include <allegro5\allegro.h>
#include <utility>
#include <stack>
#include "InputManager.h"
#pragma once

const float FPS = 60;

template<typename Target>
class EventHandler
{
private:
	typedef void (Target::*method_t)(short);
	Target* Owner;
	method_t Method;
public:
	EventHandler(Target* ActorOwner, method_t EventMethod)
		:Owner(ActorOwner), Method(EventMethod)
	{
	}
};

class EventManager
{
private:

	InputManager* Input;

	ALLEGRO_EVENT_QUEUE		*event_queue;
	ALLEGRO_TIMER			*timer;

	static EventManager* Instance;
	EventManager() {}
public:
	
	static EventManager* GetInstance();

	void Init();

	//template<typename Target>
	//void Register(Target* Owner, void (Target::*method_t)(short));


	void Update(float DeltaTime);
	~EventManager();
};

