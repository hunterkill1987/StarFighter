#include "stdafx.h"
#include "ActorFactory.h"

ActorFactory* ActorFactory::Instance = 0;

ActorFactory* ActorFactory::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new ActorFactory();
	}	
	return Instance;
}

void ActorFactory::CreateActor(xml_document<> &ActorXML)
{
	Actor* NewActor = nullptr;
	xml_node<> * ActorRoot = ActorXML.first_node("Actor");
	if (ActorRoot != 0)
	{
		char* type = ActorRoot->first_attribute("type")->value();
 		if (type == nullptr)
		{
			NewActor = new Player(0);
		}
		else
		{
			switch (GetType(type))
			{
				case Actor::EActorPlayer:
									{
										NewActor = new Player(0);
										break;
									}
				case Actor::EActorEnemy: break;
				case Actor::EActroEmiter: break;
			}
		}
	}
	if (NewActor != nullptr)
	{
		NewActor->Init(ActorXML);
	}
	ActorPool.push_back(NewActor);
}

Actor::EActorType ActorFactory::GetType(char* type)
{
	Actor::EActorType Type = Actor::EActorBase;

	std::string ActorType = type;
	if (ActorType == "Player" || ActorType == "Player1")
	{
		Type = Actor::EActorPlayer;
	}
	else
	if (ActorType == "Enemy")
	{
		Type = Actor::EActorEnemy;
	}
	else 
	if (ActorType == "Emiter")
	{
		Type = Actor::EActroEmiter;
	}

	return Type;
}
 
Actor* ActorFactory::GetByClass(char* ClassType)
{
	if (ClassType != nullptr)
	{
		std::string ClassTypeString = ClassType;
		for (Actor* ActorClass : ActorPool)
		{
			std::string ActorClassString = ActorClass->GetName();
			if (ClassTypeString == ActorClassString)
			{
				return ActorClass;
			}
		}
	}
	return nullptr;
}

ActorFactory::~ActorFactory()
{
}
