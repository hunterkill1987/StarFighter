#include "StdAfx.h"
#include "Game.h"
#include "Camera.h"
#include "Player.h"
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
		/*actor->pGame = this;
		actor->pEngine = g_engine;
		actor->pEvent = g_engine->GetEvent();*/
	}
	else
	{
		return 0;
	}

	XmlParser = xmlParser::GetInstance();
	Pool = ActorPool::GetInstance();

	XmlParser->GetFile("../Actor/Actor.xml");
	XmlParser->GetRoot("Actor");

	player = reinterpret_cast<Player*>(Pool->GetResources());
	SpawnActor<Player*>(player,Vector2(0,0),Vector2(1,0));

	return 1;
}

void Game::Update(float fTime)
{
	Pool->UpdatePool(fTime);
}

void Game::SpawnFX(IEmiter* iemiter, Vector2 pos, int OwnerId)
{
	Emiter *emiter = dynamic_cast<Emiter *>(iemiter);
	if (emiter != nullptr)
	{
		if (OwnerId >= 0)
		{
			emiter->SetOwner(OwnerId);
		}
		emiter->SetPosition(pos);
		emiter->SetRotaion(Vector2(0.f, 1.f));
		emiter->Init();
		//SpawnActor(emiter);
	}
}

template<typename T> void Game::SpawnActor(T actor,Vector2 pos,Vector2 rot)
{
	if (actor != nullptr)
	{
		Player* player = dynamic_cast<Player*>(actor);
		if (player != nullptr)
		{
			Pool->CreateActor(player);
		}
			
			/*actor->SetPosition(pos);
			actor->SetRotation(rot);*/
			
		mapActor.insert(std::pair<int, IActor*>(1, actor));

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
/*	tMapActor::iterator it;
	it = find_if(mapActor.begin(),mapActor.end(),std::bind2nd(FindActor(),actor));
	if(it != mapActor.end())
	{
		return it->first;
	}*/
	return 0;
}

Game::~Game(void)
{
	
}
