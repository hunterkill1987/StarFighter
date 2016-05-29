#pragma once
#include "IActor.h"
#include "Actor.h"
#include <list>
class ActorPool
{
private:
	std::vector<Actor*> ActiveActor;
	std::vector<Actor*> DeadActor;
	static const int PoolSize = 100;
	static ActorPool* Instance;
	
	unsigned int Index;

public:

	ActorPool();

	static ActorPool* GetInstance();

	IActor* GetActorById(int ActorId);

	void ResetActor(IActor* Acotr);

	Actor GetResources();

	void CreateActor(Actor* NewActor);
	void UpdatePool(float fTime);

	~ActorPool();
};

