#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "IGame.H"
#include "IEvent.h"
#include "IEmiter.h"
#include "IActor.h"
#ifndef IENGINE_H
#define IENGINE_H

class IEngine
{
public:
	virtual int Init() = 0;
	virtual void AddDrawActor(IActor* aActor) = 0;
	
	virtual Vector2 GetScreenSize() = 0;

	virtual Vector2 GetActorSize(int OwnerId) = 0;

	virtual IEngine* GetEgnine() = 0;
	virtual float GetCurrentTime() = 0;
	virtual ALLEGRO_PATH* GetPath() = 0;

	virtual long long int Uniq_ID() = 0;

	virtual float RandToFloat(float a,float b) = 0;
	virtual IEvent* GetEvent() =0;
	virtual IGame* GetGame() = 0;
};
#endif