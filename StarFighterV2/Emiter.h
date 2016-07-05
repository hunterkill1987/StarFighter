#pragma once
#include "iactor.h"
#include "IEngine.h"
#include <vector>

struct Particle
{
public:
	Vector2				p_pos;
	Vector2				p_rot;
	Vector2				p_vel;

	float				p_Life;
	float				p_duration;
	float				p_SpawnTime;
	float				p_angle;
	float				p_Activate;

	Particle(): 
		p_pos(0,0),
		p_rot(0,0),
		p_vel(0,0) 
	{ } 
};

typedef std::vector<Particle*>::iterator ParticleIterator;

class Emiter : public IEmiter
{
private:
	Vector2		e_pos;
	Vector2		e_rot;
	Vector2		p_scale;

	ALLEGRO_BITMAP*		p_particle;
	int			OwnerId;

	ALLEGRO_PATH*		path;

	int			e_capicity;
	bool		e_IsActive;
	bool		e_Duration;

	ALLEGRO_BITMAP*		p_Color;

	float				p_speed;
	bool				p_dissolve;
	float				p_dissolveRate;
	float				p_spred;
	float				e_EmitTime;

	std::vector<Particle*>			TParticles;
	ParticleIterator				pit;
	Particle*						particle;

	IActor*		Owner;
	IEngine*	eEngine;

public:
	Emiter(IEngine* engine);
	
	void SetupParticle();
	virtual void Update(float fTime);

	virtual Vector2 GetRotation();
	virtual Vector2 GetVelocity();
	virtual Vector2 GetPosition();

	virtual void Activate(bool IsActivate);
	virtual bool IsActive();
	virtual void RemoveParticle();

	virtual const char* GetName();

	virtual bool IsAlive();
	virtual bool IsPlayer();

	virtual void Init();
	virtual void DrawActor();

	virtual void SetSprite(ALLEGRO_BITMAP* Sprite);

	void SpawnParticle();
	void UpdateParticle();
	void Remove();

	void SetOwner(int Owner);

	void SetPosition(Vector2 Pos);
	void SetRotaion(Vector2 Rot);

	~Emiter(void);
};

