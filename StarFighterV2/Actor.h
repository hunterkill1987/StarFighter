#include "Engine.h"
#include "IActor.h"
#include "rapidxml\rapidxml.hpp"
#include <map>
#ifndef ACTOR_H
#define ACTOR_H

using namespace rapidxml;
using namespace std;

class Actor : public IActor 	 
{	
private:

	char* Name;
	unsigned int UID;

	float Time;
	float Acceleration;

	Vector2 Rotation;
	Vector2 Velocity;
	Vector2 Position;

	ALLEGRO_BITMAP*		Bitmap;

public:
	enum EActorType
	{
		EActorBase,
		EActorPlayer,
		EActorEnemy,
		EActroEmiter
	};

	EActorType AType;

	Engine*		pEngine;

	Actor(EActorType ActorType = EActorBase);
	Actor(Actor& CopyActor);

	virtual ~Actor(void);
	virtual void Update(float fTime);
	
	virtual bool IsPlayer();

	virtual const char* GetName();

	virtual Vector2 GetRotation();

	virtual Vector2 GetVelocity();
	virtual Vector2 GetPosition();
	virtual void DrawActor();

	virtual void Init(xml_document<> &ActorParams);

	void Reset();

	void StartFire();
	void StopFire();
	void MoveActor();

	void SetRotation(Vector2 rot);
	void SetRotation(float angle);
	void SetVelocity(Vector2 vel);
	void SetPosition(Vector2 pos);
	void SetAcceleration(float acc);

	void SetName(char* ClassName);

	Actor* Clone(){ return new Actor(*this);  }

	long long int GetUID();
	void SetUID(long long int NewUID);
	virtual void SetSprite(ALLEGRO_BITMAP* Sprite);
};
#endif
