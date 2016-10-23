#include "stdafx.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <math.h>
#include "rapidxml\rapidxml.hpp"
#include "Math.h"
#ifndef IACTOR_H
#define IACTOR_H

using namespace rapidxml;
using namespace std;

class IActor
{
public:
	virtual void Update(float fTime) = 0;

	virtual const char* GetName()= 0;

	virtual Vector2 GetRotation() = 0;
	virtual Vector2 GetVelocity() = 0;
	virtual Vector2 GetPosition() = 0;
	virtual void Init(xml_document<> &ActorXml) = 0;
	
	virtual void DrawActor() = 0;

	virtual bool IsPlayer() = 0;

	virtual void SetSprite(ALLEGRO_BITMAP* Sprite) = 0;
};

#endif 