#pragma once
#include "IEngine.h"
#include "IActor.h"
#include "Player.h"
#include "Actor.h"
#include "Camera.h"
#include "Emiter.h"
#include "IEmiter.h"
#include "IGame.H"
#include <map>

typedef std::pair<int, IActor*>  pair;
typedef std::map< int, IActor*>	 tMapActor;

struct FindActor : public std::binary_function<pair,IActor*,bool>
{
	bool operator()(const pair& p, IActor* value) const
	{
		return p.second == value;
	}
};

class Game : public IGame
{
private:
	
	IEngine* g_engine;
	Player* player;
	Actor* actor;
	Emiter* emiter;
	tMapActor mapActor;

public:
	Game(void);
	
	void Update(float fTime);
	int GameInit(IEngine* g_engine);

	virtual void SpawnActor(IActor* actor, Vector2 pos = Vector2(0.0f, 0.0f), Vector2 rot = Vector2(0.0f, 0.0f));
	virtual void SpawnFX(IEmiter* emiter, Vector2 pos, int OwnerID = 0);
	virtual IActor* GetActorById(int id);
	virtual int GetActorId(IActor* actor);
	
	~Game(void);
};

