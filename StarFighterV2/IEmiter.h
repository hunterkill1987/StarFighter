#include "stdafx.h"
#include <math.h>
#include "IActor.h"
#ifndef IEMITER_H
#define IEMITER_H


class IEmiter : public IActor
{
public:
	virtual void Update(float Time) = 0;
	virtual void Init() = 0;

	virtual Vector2 GetRotation() = 0;
	virtual Vector2 GetVelocity() = 0;
	virtual Vector2 GetPosition() = 0;

	virtual void Activate(bool IsActivate) = 0;
	virtual bool IsActive() = 0;
	virtual void RemoveParticle() = 0;

	virtual const char* GetName()= 0;
	virtual char* GetSurface() = 0;

	virtual void DrawActor() = 0;
	virtual void SetSprite(ALLEGRO_BITMAP* Sprite) = 0;

	virtual bool IsAlive() = false;
	virtual bool IsPlayer() = false;
};

#endif 