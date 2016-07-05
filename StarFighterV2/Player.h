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
	
	void Update(float fTime);
	void Init(xml_document<> &ActorXml);
	void HandleInput(IEvent* &Input, IEngine* &Engine);

	Player(unsigned int Index);
	~Player(void);

	Player* Clone(){ return new Player(*this); }
};

