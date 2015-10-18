#include "StdAfx.h"
#include "Game.h"
#include "Camera.h"
#include <algorithm>
#include <functional>
Game::Game(void):
	g_engine(NULL),
	player(NULL)
{
}

int Game::GameInit(IEngine* engine)
{
	if(engine != NULL)
	{
		g_engine = engine; 
		actor = new Actor();
		emiter = new Emiter(g_engine);
		actor->pGame = this;
		actor->pEngine = g_engine;
		actor->pEvent = g_engine->GetEvent();
	}
	else
	{
		return 0;
	}

	if(emiter != NULL)
		emiter->SetupParticle();

	player = new Player();
	actor->SpawnActor(player,Vector2(300,300),Vector2(1,0));

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

void Game::SpawnFX(Vector2 pos,Vector2 rot,int OwnerId)
{
	if(OwnerId >= 0 )
	{
		emiter->SetOwner(OwnerId);
	}
	emiter->Init(); 
	emiter->SetPosition(pos);
	emiter->SetRotaion(rot);
	SpawnActor(emiter);
}

void Game::SpawnActor(IActor* actor)
{
	if(actor != NULL)
	{
		mapActor.insert(std::pair<int,IActor*>(g_engine->Uniq_ID(),actor));
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
		return NULL;
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
