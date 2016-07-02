#pragma once
#include "Engine.h"
#include "Player.h"
#include "Actor.h"
#include "Camera.h"
#include "Emiter.h"
#include "ActorFactory.h"
#include "ActorPool.h"
#include <map>

using namespace rapidxml;
using namespace std;



class Game 
{
private:

	Engine* GEngine;
	ActorFactory* ActorManager;
	ActorPool* Pool;
public:

	Game(void);
	
	void Update(float fTime);
	int GameInit();
	virtual void SpawnActor(char* ActorName, Vector2 pos = Vector2(0.0f, 0.0f), Vector2 rot = Vector2(0.0f, 0.0f));
	
	~Game(void);
};

