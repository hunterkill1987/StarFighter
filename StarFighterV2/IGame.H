#include "stdafx.h"
#include "Emiter.h"
#include "IEmiter.h"
#ifndef IGAME_H
#define IGAME_H


class IGame 
{
public:
	//virtual void SpawnActor(IActor* actor, Vector2 pos = Vector2(0.0f, 0.0f), Vector2 rot = Vector2(0.0f, 0.0f)) = 0;
	virtual IActor* GetActorById(int id) = 0;
	virtual int GetActorId(IActor* actor) = 0;
	virtual void SpawnFX(IEmiter* emiter,Vector2 pos, int OwnerID = 0) = 0;
};

#endif 