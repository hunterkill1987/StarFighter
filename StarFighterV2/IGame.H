#include "stdafx.h"
#include "Emiter.h"
#ifndef IGAME_H
#define IGAME_H


class IGame 
{
public:
	virtual void SpawnActor(IActor* actor) = 0;
	virtual IActor* GetActorById(int id) = 0;
	virtual int GetActorId(IActor* actor) = 0;
	virtual void SpawnFX(Vector2 pos,Vector2 rot,int OwnerID = 0) = 0;
};

#endif 