#include "stdafx.h"
#include "ActorPool.h"


ActorPool* ActorPool::Instance = 0;

ActorPool* ActorPool::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new ActorPool();
	}
	return Instance;
}

ActorPool::ActorPool()
{
	ActiveActor.reserve(PoolSize);
	DeadActor.reserve(PoolSize);  
	for (int i = 0; i < PoolSize; i++)
	{
		DeadActor.push_back(new Actor());
	}
}

void ActorPool::AddNewActor(Actor* AddActor)
{
	Actor* NewActor = nullptr;
	if (!DeadActor.empty())
	{
		NewActor = DeadActor.back();
		DeadActor.pop_back();
		if (NewActor != nullptr)
		{  
			Actor* tmpActor(AddActor);
			NewActor = tmpActor;
			NewActor->SetUID(NewActor->GetUID() + 1 );
			ActiveActor.push_back(NewActor);
		}
	}
}

void ActorPool::DrwaActorPool()
{
	for (Actor* AActor : ActiveActor)
	{
		AActor->DrawActor();
	}
}

void ActorPool::UpdatePool(float deltaTime)
{
	for (Actor* AActor : ActiveActor)
	{
		AActor->Update(deltaTime);
	}
}

void ActorPool::RemoveActor(Actor* Actor)
{
}

ActorPool::~ActorPool()
{
}
 