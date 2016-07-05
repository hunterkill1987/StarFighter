#include "StdAfx.h"
#include "Engine.h"
#include "World.h"
#include <functional>

World* World::Instance = 0;

World* World::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new World();
	}
	return Instance;
}

int World::WorldInit()
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
		SpawnActor("Player", Vector2(300, 300), Vector2(0, 0));
		return 1;
	}
	return 0;
}

void World::Update(float deltaTime)
{
	if (Pool != nullptr)
	{
		Pool->UpdatePool(deltaTime);
	}
}

void World::SpawnActor(char* ActorName, Vector2 position, Vector2 rotation)
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

World::~World(void)
{
	delete Pool;
	delete ActorManager;
}
