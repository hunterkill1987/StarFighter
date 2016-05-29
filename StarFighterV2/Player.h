#pragma once
#include "actor.h"
#include "IEvent.h"
#include "Camera.h"
class Player :
	public Actor
{
private:
	float maxacc;
	float acc;
	float Angle;
	float accTime;
	float a;

	int Health;
	int MaxHealth;

	int Shield;
	int MaxShield;

	Camera* player_camera;
	Emiter* Player_emiter;
	float fx;
public:
	
	virtual void Update(float fTime);
	virtual void Init();
	virtual void HandleInput(IEvent* &Input, IEngine* &Engine);

	Player(unsigned int Index);
	//Player(Actor &actor);
	~Player(void);

	Player& operator= (const Actor& actor ) { return *this; }
};

