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

	int mHealth;
	int maxHealth;

	int mShield;
	int maxShield;

	char* name;
	char* surface;
	unsigned int id;

	float time;
	float m_acceleration;

	Vector2 m_rotation;
	Vector2 m_velocity;
	Vector2 m_position;

public:
	IActor*		pActor;
	IEvent*		pEvent;
	IEngine*	pEngine;
	IGame*		pGame;

	Actor();
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

	virtual void Init();

	void SpawnActor(IActor* actor,Vector2 pos, Vector2 rot);
	void Reset();

	void StartFire();
	void StopFire();
	void MoveActor();

	void SetRotation(Vector2 rot);
	void SetRotation(float angle);
	void SetVelocity(Vector2 vel);
	void SetPosition(Vector2 pos);
	void SetAcceleration(float acc);
	void SetSurface (char* surfaceName);
	void SetName(char* Name);
};
#endif
