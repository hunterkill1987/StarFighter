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

	virtual void SpawnActor(IActor* actor);
	virtual void SpawnFX(Vector2 pos,Vector2 rot,int OwnerID = 0);
	virtual IActor* GetActorById(int id);
	virtual int GetActorId(IActor* actor);
	
	~Game(void);
};

