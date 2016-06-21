#include "stdafx.h"
#include "ActorFactory.h"

ActorFactory* ActorFactory::Instance = 0;

ActorFactory::ActorFactory() : Index(0)
{
	ActiveActor.reserve(PoolSize);
	DeadActor.reserve(PoolSize);
}

ActorFactory* ActorFactory::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new ActorFactory();
	}	
	return Instance;
}

void ActorFactory::UpdatePool(float fTime)
{
	if (!ActiveActor.empty())
	{
		for (Actor* AActor : ActiveActor)
		{
			AActor->Update(fTime);
		}
	}
}
Actor* ActorFactory::CreateActor(xml_document<> &ActorXML)
{
	Actor* NewActor = nullptr;
	xml_node<> * ActorRoot = ActorXML.first_node("Actor");
	if (ActorRoot != 0)
	{
		char* type = ActorRoot->first_attribute("type")->value();
 		if (type == nullptr)
		{
			NewActor = new Player(1);
		}
		else
		{
			switch (GetType(type))
			{
				case Actor::EActorPlayer:
									{
										NewActor = new Player(1);
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
		return NewActor;
	}
	return nullptr;
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

IActor* ActorFactory::GetActorById(int ActorId)
{
	return nullptr;
}

ActorFactory::~ActorFactory()
{
	for (Actor* aa : ActiveActor) delete aa;
	for (Actor* ua : DeadActor) delete ua;
}
