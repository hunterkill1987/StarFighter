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

	static ActorFactory* Instance;
	vector<Actor*> ActorPool;
	Actor::EActorType GetType(char* type);
	ActorFactory(){};
public:
	
	static ActorFactory* GetInstance();
	
	void CreateActor(xml_document<> &ActorXML);

	Actor* GetByClass(char* ActorClassType);


	~ActorFactory();
};

