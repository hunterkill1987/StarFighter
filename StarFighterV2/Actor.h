#include "IActor.h"
#include "IEvent.h"
#include "IEngine.h"
#include "Player.h"
#include "IEmiter.h"
#include "IGame.h"
#include "Engine.h"
#include "Camera.h"
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
	char* Surface;
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

	IActor*		pActor;
	IEvent*		pEvent;
	Engine*	pEngine;
	IGame*		pGame;

	Actor(unsigned int Index, EActorType ActorType = EActorBase, Vector2 pos = Vector2(0, 0));

	virtual ~Actor(void);
	virtual void Update(float fTime);
	
	virtual bool IsPlayer();

	virtual char* GetName();

	virtual Vector2 GetRotation();

	virtual Vector2 GetVelocity();
	virtual Vector2 GetPosition();
	virtual int GetId();
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
	//TODO :: Remove unused code
	//----
	void SetSurface (char* surfaceName);
	//----
	void SetName(char* Name);

	long long int GetUID();
	void SetUID(long long int NewUID);
	virtual void SetSprite(ALLEGRO_BITMAP* Sprite);
};
#endif
