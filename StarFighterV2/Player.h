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

	Camera* player_camera;
	Emiter* Player_emiter;
	float fx;
public:
	
	virtual void Update(float fTime);
	virtual void Init();

	Player(void);
	Player(Actor &actor);
	~Player(void);
};

