#include "stdafx.h"
#include "ActorPool.h"

ActorPool* ActorPool::Instance = 0;

ActorPool::ActorPool()
{
	for (int i = 0; i < PoolSize; i++)
	{
		AvailableActor.push_back(new Actor);
	}
}

ActorPool* ActorPool::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new ActorPool();
	}
	
	return Instance;
}

void ActorPool::NewActor()
{
	
}

IActor* ActorPool::GetActorById(int ActorId)
{
	return nullptr;
}

ActorPool::~ActorPool()
{
}
