#pragma once
#include "Engine.h"
#include "Player.h"
#include "Actor.h"
#include "Camera.h"
#include "Emiter.h"
#include "ActorFactory.h"
#include <map>

using namespace rapidxml;
using namespace std;



class Game 
{
private:
	
	Player* player;
	Actor* actor;
	Emiter* emiter;
	Engine* GEngine;
	ActorFactory* Pool;

public:

	Game(void);
	
	void Update(float fTime);
	int GameInit();
	Engine* GetEngine();
	template<typename T> void SpawnActor(T actor, Vector2 pos = Vector2(0.0f, 0.0f), Vector2 rot = Vector2(0.0f, 0.0f));
	
	~Game(void);
};

