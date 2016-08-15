#pragma once
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <allegro5\allegro.h>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const float FPS = 60;

class EventHandlerBase
{
public:
	virtual void Execute() = 0;
};

template<typename TargetT>
class EventHandler : public EventHandlerBase
{
private:
	typedef void (TargetT::*method_t)();
	TargetT* Object;
	method_t Method;
public:
	EventHandler(TargetT* ObjectT, method_t EventMethod)
		:Object(ObjectT), Method(EventMethod)
	{
	}

	void Execute() override
	{
		(Object->*Method)();
	}
};

class Event
{
private:

	std::map<int, EventHandlerBase*> EventHandlerMap;
	int count;

public:

	template<typename TargetT>
	void AddListener(TargetT* Object, void (TargetT::*Method)())
	{
		EventHandlerMap[count] = new EventHandler<TargetT>(Object, Method);
		count++;
	}
	
	void Execute()
	{
		for (auto& Event : EventHandlerMap)
		{
			Event.second->Execute();
		}
	}

};

class EventManager
{
private:

	struct EventType
	{
		Event* Event;
		char* name;
	};

	ALLEGRO_EVENT_QUEUE		*event_queue;
	ALLEGRO_TIMER			*timer;

	std::vector<EventType> Events;

	static EventManager* Instance;
	EventManager() {}
public:
	
	static EventManager* GetInstance();

	void Init();

	void RegisterEvent(char* Name);

	template<typename TargetT>
	bool Bind(TargetT* Object, void(TargetT::*method_t)(), char* Name)
	{
		for (EventType Event : Events)
		{
			if (strcmp(Event.name, Name) == 0)
			{
				Event.Event->AddListener(Object, method_t);
				return true;
			}
		}
		return false;
	}

	void FireEvent(char* Name);

	void Update(float DeltaTime);

	ALLEGRO_EVENT_QUEUE* GetEventQueue();

	~EventManager();
};

#endif