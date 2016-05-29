#include "stdafx.h"
#include "ActorPool.h"

ActorPool* ActorPool::Instance = 0;

ActorPool::ActorPool() : Index(0)
{
	ActiveActor.reserve(PoolSize);
	DeadActor.reserve(PoolSize);
}

ActorPool* ActorPool::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new ActorPool();
	}
	
	return Instance;
}

void ActorPool::UpdatePool(float fTime)
{
	if (!ActiveActor.empty())
	{
		for (Actor* AActor : ActiveActor)
		{
			AActor->Update(fTime);
		}
	}
}
Actor ActorPool::GetResources()
{
	Actor* NewActor = nullptr;

	if (!DeadActor.empty())
	{
		NewActor = DeadActor.back();
		DeadActor.pop_back();
		if (NewActor != nullptr)
		{
			NewActor->SetUID(NewActor->GetId() + 1);
			return (*NewActor);
		}
	}

	NewActor = new Actor(Index++);
	ActiveActor.push_back(NewActor);
	return (*NewActor);
}

void ActorPool::CreateActor(Actor* NewActor)
{
	if (NewActor != nullptr)
	{
		NewActor->Init();
		ActiveActor[NewActor->GetUID()] = NewActor;
	}
}

IActor* ActorPool::GetActorById(int ActorId)
{
	return nullptr;
}

ActorPool::~ActorPool()
{
	for (Actor* aa : ActiveActor) delete aa;
	for (Actor* ua : DeadActor) delete ua;
}
