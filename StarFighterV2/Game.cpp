#include "StdAfx.h"
#include "Engine.h"
#include "Game.h"
#include "Camera.h"
#include "Player.h"
#include <algorithm>
#include <functional>
Game::Game(void):
player(nullptr)
{
}

int Game::GameInit()
{
	GEngine = Engine::GetInstance();
	Pool = ActorFactory::GetInstance();
	if (GEngine != nullptr && Pool != nullptr)
	{

		xml_document<> ActorList;
		vector<char> ActorXml = GEngine->GetFile("Actor.xml");
		ActorList.parse<0>(&ActorXml[0]);
		xml_node<> * ActroListRootNode = ActorList.first_node("ActorPool");
		for (xml_node<> * ActorListNode = ActroListRootNode->first_node("Actor"); ActorListNode; ActorListNode = ActorListNode->next_sibling())
		{
			fprintf(stderr, "ActorXML %s \n", ActorListNode->first_attribute("ActorXml")->value());

			xml_document<> Actor;
			vector<char> ActorXml = GEngine->GetFile(ActorListNode->first_attribute("ActorXml")->value());
			Actor.parse<0>(&ActorXml[0]);
			xml_node<>* ActroRootNode = Actor.first_node("Actor");

			Pool->CreateActor(Actor);

			fprintf(stderr, "ActorName %s \n", ActroRootNode->first_attribute("name")->value());

			for (xml_node<> * ActorNode = ActroRootNode->first_node("Surface"); ActorNode; ActorNode = ActorNode->next_sibling())
			{
				fprintf(stderr, "ActorSprite %s \n", ActorNode->first_attribute("path")->value());
			}
		}
		return 1;
	}
	return 0;
}

void Game::Update(float fTime)
{
	Pool->UpdatePool(fTime);
}

Engine* Game::GetEngine()
{
	if (GEngine != nullptr)
	{
		return GEngine;
	}
}
Game::~Game(void)
{
	
}
