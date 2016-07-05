#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "IGame.H"
#include "IEmiter.h"
#include "IActor.h"
#ifndef IENGINE_H
#define IENGINE_H

class IEngine
{
public:
	virtual int Init() = 0;

	virtual void LoadAsset(IActor* Actor, char* asset) = 0;
	
	virtual Vector2 GetScreenSize() = 0;

	virtual Vector2 GetActorSize(int OwnerId) = 0;

	virtual IEngine* GetEgnine() = 0;
	virtual float GetCurrentTime() = 0;
	virtual ALLEGRO_PATH* GetPath() = 0;

	virtual float RandToFloat(float a,float b) = 0;
	virtual IGame* GetGame() = 0;
	virtual float GetDeltaTime() = 0;
};
#endif