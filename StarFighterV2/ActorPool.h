#pragma once
#include "Actor.h"
#include "rapidxml\rapidxml.hpp"
#include <list>

using namespace std;

class ActorPool
{
private:
	static ActorPool* Instance;

	std::vector<Actor*> ActiveActor;
	std::vector<Actor*> DeadActor;

	static const int PoolSize = 1000;

public:
	static ActorPool* GetInstance();

	ActorPool();

	void AddNewActor(Actor* Actor);  

	void RemoveActor(Actor* Actor);

	void UpdatePool(float DeltaTime);
	void DrwaActorPool();
	~ActorPool();
};

