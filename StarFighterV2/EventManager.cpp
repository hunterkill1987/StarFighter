#include "stdafx.h"
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

	Input = InputManager::GetInstance();
	Input->Init(event_queue);
}

void EventManager::Update(float deltaTime)
{
	if (Input != nullptr)
	{
		Input->UpdateInput();
	}
}

EventManager::~EventManager()
{
}
