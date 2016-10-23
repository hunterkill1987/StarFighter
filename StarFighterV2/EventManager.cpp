#include "stdafx.h"
#include "Engine.h"
#include "EventManager.h"


EventManager* EventManager::Instance = 0;

EventManager* EventManager::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new EventManager();
	}
	return Instance;
}

void EventManager::Init()
{
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	if (!event_queue)
	{
		fprintf(stderr, "failed to create event_queue!\n");
	}

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);
}

void EventManager::Update(float deltaTime)
{
	for (TimerType* CurrTimer : Timers)
	{
		if (CurrTimer->GetTime() > 0.f)
		{
			CurrTimer->SetCurrentTime(CurrTimer->GetCurrentAlfa() - deltaTime);
			if (Math::IsNear(CurrTimer->GetCurrentAlfa(), 0.f, 0.01f))
			{
				fprintf(stderr, "print TestTimer %f %f %f\n", CurrTimer->GetCurrentAlfa(), CurrTimer->GetTime(), deltaTime);
				CurrTimer->Event->Execute();
			}

			if (CurrTimer->GetCurrentAlfa() <= 0.f)
			{
				if (CurrTimer->IsLooped())
				{
					CurrTimer->SetLuncheTime(CurrTimer->GetTime(), CurrTimer->IsLooped());
				}
			} 
		}
	}
}

void EventManager::FireEvent(char* Name)
{
	for (EventType* Event : Events)
	{
		if (Event->name != nullptr)
		{
			if (strcmp(Event->name, Name) == 0)
			{
				Event->Event->Execute();
			}
		}
	}
}

ALLEGRO_EVENT_QUEUE* EventManager::GetEventQueue()
{
	if (event_queue != nullptr)
	{
		return event_queue;
	}
	return nullptr;
}
EventManager::~EventManager()
{
}
