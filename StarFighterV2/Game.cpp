#include "StdAfx.h"
#include "Game.h"
#include "Camera.h"
#include <algorithm>
#include <functional>
Game::Game(void):
g_engine(nullptr),
player(nullptr)
{
}

int Game::GameInit(IEngine* engine)
{
	if (engine != nullptr)
	{
		g_engine = engine; 
		actor = new Actor();
		actor->pGame = this;
		actor->pEngine = g_engine;
		actor->pEvent = g_engine->GetEvent();
	}
	else
	{
		return 0;
	}

	player = new Player(*actor);
	SpawnActor(player,Vector2(300,300),Vector2(1,0));

	return 1;
}

void Game::Update(float fTime)
{
	tMapActor::iterator it;
	for(it=mapActor.begin(); it!=mapActor.end(); ++it)
	{	
		IActor* actor = it->second;
		actor->Update(fTime);
	}
}

void Game::SpawnFX(IEmiter* iemiter, Vector2 pos, int OwnerId)
{
	Emiter *emiter = dynamic_cast<Emiter *>(iemiter);
	if (emiter != nullptr)
	{
		emiter->Init();
		if (OwnerId >= 0)
		{
			emiter->SetOwner(OwnerId);
		}
		emiter->SetPosition(pos);
		emiter->SetRotaion(Vector2(0.f, 1.f));
		emiter->Init();
		SpawnActor(emiter);
	}
}

void Game::SpawnActor(IActor* actor,Vector2 pos,Vector2 rot)
{
	if (actor != nullptr)
	{
		Actor *newActor = dynamic_cast<Actor*>(actor);
		if (newActor != nullptr)
		{
			newActor->Init();
			newActor->SetPosition(pos);
			newActor->SetRotation(rot);
		}
		int id = g_engine->Uniq_ID();
		if (id >= 0)
		{
			mapActor.insert(std::pair<int, IActor*>(id, actor));
		}
		g_engine->AddDrawActor(actor);
	}else
	{
		return;
	}
}
IActor* Game::GetActorById(int id)
{
	tMapActor::iterator it;

	it = mapActor.find(id);
	if(it != mapActor.end())
		return it->second;
	else
		return nullptr;
}

int Game::GetActorId(IActor* actor)
{
	tMapActor::iterator it;
	it = find_if(mapActor.begin(),mapActor.end(),std::bind2nd(FindActor(),actor));
	if(it != mapActor.end())
	{
		return it->first;
	}
	return 0;
}

Game::~Game(void)
{
	
}
