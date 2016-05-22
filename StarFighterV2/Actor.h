#include "IActor.h"
#include "IEvent.h"
#include "IEngine.h"
#include "Player.h"
#include "IEmiter.h"
#include "IGame.h"
#include "Camera.h"
#include <map>
#ifndef ACTOR_H
#define ACTOR_H

class Actor : public IActor 
			 
{	
private:

	int Health;
	int MaxHealth;

	int Shield;
	int MaxShield;

	char* Name;
	char* Surface;
	unsigned int id;

	float Time;
	float Acceleration;

	Vector2 Rotation;
	Vector2 Velocity;
	Vector2 Position;

	ALLEGRO_BITMAP*		Bitmap;

public:
	IActor*		pActor;
	IEvent*		pEvent;
	IEngine*	pEngine;
	IGame*		pGame;

	Actor();
	Actor(Actor& actor);
	virtual ~Actor(void);
	virtual void Update(float fTime);
	
	virtual bool IsAlive();
	virtual bool IsPlayer();

	virtual int GetHealth();
	virtual int GetShield();

	virtual char* GetSurface();
	virtual char* GetName();

	virtual Vector2 GetRotation();

	virtual Vector2 GetVelocity();
	virtual Vector2 GetPosition();
	virtual int GetId();
	virtual void DrawActor();

	virtual void Init();

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

	virtual void SetSprite(ALLEGRO_BITMAP* Sprite);
};
#endif
