#pragma once
#include "Actor.h"
#include "IEvent.h"
#include "Camera.h"
#include "EventManager.h"
#ifndef PLAYER_H
#define PLAYER_H

using namespace rapidxml;
using namespace std;

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
	
	virtual void Update(float fTime) override;
	virtual void Init(xml_document<> &ActorXml) override;
	void HandleInput(IEvent* &Input, IEngine* &Engine);

	Player(unsigned int Index);
	~Player(void);

	void MoveLeft();
	void MoveRight();
	void Move();
	void Back();
};

#endif
