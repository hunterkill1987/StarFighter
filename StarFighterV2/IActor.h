#include "stdafx.h"
#include <math.h>
#include "SMath.h"
#ifndef IACTOR_H
#define IACTOR_H


class IActor 
{
public:
	virtual void Update(float fTime) = 0;

	virtual char* GetName()= 0;
	virtual char* GetSurface() = 0;
	virtual int GetId() = 0;

	virtual Vector2 GetRotation() = 0;
	virtual Vector2 GetVelocity() = 0;
	virtual Vector2 GetPosition() = 0;
	virtual void Init() = 0;

	virtual bool IsAlive() = false;
	virtual bool IsPlayer() = false;
};

#endif 