#include "stdafx.h"
#include "Emiter.h"
#include "IEmiter.h"
#ifndef IGAME_H
#define IGAME_H


class IGame 
{
public:

	virtual void SpawnActor(char* ActroName, Vector2 pos = Vector2(0.0f, 0.0f), Vector2 rot = Vector2(0.0f, 0.0f)) = 0;
	virtual IActor* GetActorById(int id) = 0;
	virtual int GetActorId(IActor* actor) = 0;
};

#endif 