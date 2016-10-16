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
		bool bLooped;

		void SetLuncheTime(float Alfa)
		{
			AlfaTime = Alfa;
			LuncheTime = al_get_time() + Alfa;
		}

		float GetTime()
		{
			return AlfaTime;
		}

	private: 
		
		float AlfaTime;
		float LuncheTime = 0.f;
	
	};

	ALLEGRO_EVENT_QUEUE		*event_queue;
	ALLEGRO_TIMER			*timer;

	std::vector<EventType> Events;

	std::vector<EventType> Timers;

	static EventManager* Instance;
	EventManager() {}
public:
	
	static EventManager* GetInstance();

	void Init();
	 
	template<typename TargetT>
	bool SetTimer(TargetT* Object, void(TargetT::*method_t)(), float Alfa, bool bIsLooped)
	{
		if (Alfa != 0.f)
		{
			EventType e;
			e.Event = new Event();
			e.bLooped = bIsLooped;
			e.Event->AddListener(Object, method_t);
			e.name = nullptr;
			e.SetLuncheTime(Alfa);
			Timers.push_back(e);
			return true;
		}
		return false;
	}

	template<typename TargetT>
	bool Bind(TargetT* Object, void(TargetT::*method_t)(), char* Name)
	{
		for (EventType CurrEvent : Events)
		{
			if (strcmp(CurrEvent.name, Name) == 0)
			{
				return false;
			}
		}

		EventType e;
		e.Event = new Event();
		e.name = Name;
		e.Event->AddListener(Object, method_t);
		Events.push_back(e);

		return true;
	}

	void FireEvent(char* Name);

	void Update(float DeltaTime);

	ALLEGRO_EVENT_QUEUE* GetEventQueue();

	~EventManager();
};

#endif