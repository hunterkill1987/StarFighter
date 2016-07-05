#pragma once
#include "Actor.h"
#include "ActorFactory.h"
#include "ActorPool.h"
#include <map>

using namespace rapidxml;
using namespace std;

class World 
{
private:

	Engine* GEngine;
	ActorFactory* ActorManager;
	ActorPool* Pool;

	static World* Instance;	
	World(){};

public:
	
	static World* GetInstance();

	void Update(float fTime);
	int WorldInit();
	virtual void SpawnActor(char* ActorName, Vector2 pos = Vector2(0.0f, 0.0f), Vector2 rot = Vector2(0.0f, 0.0f));
	
	~World(void);
};

