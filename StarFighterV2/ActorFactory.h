#pragma once
#include "IActor.h"
#include "Actor.h"
#include "rapidxml\rapidxml.hpp"
#include <list>

using namespace rapidxml;
using namespace std;

class ActorFactory
{
private:
	std::vector<Actor*> ActiveActor;
	std::vector<Actor*> DeadActor;
	static const int PoolSize = 100;
	static ActorFactory* Instance;
	
	unsigned int Index;

	Actor::EActorType GetType(char* type);

public:

	ActorFactory();

	static ActorFactory* GetInstance();

	IActor* GetActorById(int ActorId);

	void ResetActor(IActor* Acotr);
	
	Actor* CreateActor(xml_document<> &ActorXML);
	void UpdatePool(float fTime);

	~ActorFactory();
};

