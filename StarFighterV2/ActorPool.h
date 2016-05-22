#pragma once
#include "IActor.h"
#include "Actor.h"
#include <list>
class ActorPool
{
private:
	std::list<Actor*> AvailableActor;
	std::list<Actor*> InUseActor;
	static const int PoolSize = 100;
	static ActorPool* Instance;

public:

	ActorPool();

	static ActorPool* GetInstance();

	IActor* GetActorById(int ActorId);

	void ResetActor(IActor* Acotr);

	void NewActor();

	~ActorPool();
};

