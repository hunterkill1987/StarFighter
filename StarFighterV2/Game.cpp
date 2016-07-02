#include "StdAfx.h"
#include "Engine.h"
#include "Game.h"
#include "Camera.h"
#include "Player.h"
#include <algorithm>
#include <functional>
Game::Game(void)
{
}

int Game::GameInit()
{
	GEngine = Engine::GetInstance();
	ActorManager = ActorFactory::GetInstance();
	Pool = ActorPool::GetInstance();
	if (GEngine != nullptr && ActorManager != nullptr)
	{

		xml_document<> ActorList;
		vector<char> ActorXml = GEngine->GetFile("Actor.xml");
		ActorList.parse<0>(&ActorXml[0]);
		xml_node<> * ActroListRootNode = ActorList.first_node("ActorPool");
		for (xml_node<> * ActorListNode = ActroListRootNode->first_node("Actor"); ActorListNode; ActorListNode = ActorListNode->next_sibling())
		{
			xml_document<> Actor;
			vector<char> ActorXml = GEngine->GetFile(ActorListNode->first_attribute("ActorXml")->value());
			Actor.parse<0>(&ActorXml[0]);
			xml_node<>* ActroRootNode = Actor.first_node("Actor");

			ActorManager->CreateActor(Actor);
		}
		SpawnActor("Player", Vector2(0, 0), Vector2(0, 0));
		return 1;
	}
	return 0;
}

void Game::Update(float fTime)
{
}

void Game::SpawnActor(char* ActorName,Vector2 rotation,Vector2 position)
{
	if (ActorName != nullptr)
	{
		Actor* SpawnActor = ActorManager->GetByClass(ActorName);
		if (SpawnActor != nullptr) 
		{
			SpawnActor->SetPosition(position);
			SpawnActor->SetRotation(rotation);
			Pool->AddNewActor(SpawnActor);
		}
	}
}

Game::~Game(void)
{
	
}
