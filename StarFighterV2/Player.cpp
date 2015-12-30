#include "StdAfx.h"
#include "Player.h"
#include "Emiter.h"

Player::Player(Actor &actor):
	Angle(0.0),
	acc(0.0),
	accTime(0.0)
{
	pGame = actor.pGame;
	pEngine = actor.pEngine;
	pEvent = actor.pEvent;
}

void Player::Update(float deltaTime)
{
	Vector2 rotation = this->GetRotation();
	Vector2 velocity = this->GetVelocity();

	Actor::Update(deltaTime);
	
	if(this->pEvent != NULL)
	{ 
		int input=this->pEvent->GetInput();
			
		if(input & ( 1 << LEFT))
		{
			Angle += deltaTime * 3.14f;
			if(Angle > 3.14f) Angle -= 3.14 * 2.f;
			//fprintf(stderr,"player angle %f %f \n", Angle ,Angle * 180/ PI);
			rotation = Vector2(cosf(Angle),sinf(Angle));
			SetRotation(rotation);
		}

		if(input & ( 1 << RIGHT))
		{
			Angle -= deltaTime * 3.14f;
			if(Angle < -3.14f) Angle += 3.14 * 2.f;
			//fprintf(stderr,"player angle %f %f \n", Angle ,Angle * 180/ PI);
			rotation = Vector2(cosf(Angle),sinf(Angle));
			SetRotation(rotation);
		}

		if( input & ( 1 << UP))
		{
			rotation = Vector2(GetRotation().GetX(), GetRotation().GetY());
			velocity = velocity + rotation * 4 * deltaTime;
		}

		if( input & ( 1 << DOWN))
		{
			rotation = Vector2(-1 * GetRotation().GetX(), -1 * GetRotation().GetY());
			velocity = velocity + rotation * 4 * deltaTime;
		}

		if( input & ( 1 << FIRE))
		{
			
		}
		

		Vector2 pos = GetPosition();
		Vector2 newpos = GetPosition();

		newpos = newpos + velocity;
		SetVelocity(velocity);
		SetPosition(newpos);
	}

	//Test fx !!! works
	if(this->pEngine->GetTickCount() > fx && fx > 0.0)
	{
		fx = 0.f;
		this->pGame->SpawnFX(Player_emiter, this->GetPosition(), -1);
	}
	if(player_camera != NULL)
		player_camera->UpdateCamera();
}

void Player::Init()
{
	this->SetSurface("herok.bmp");
	this->SetName("Player");
	
	fx = this->pEngine->GetTickCount() + 0.7;
	player_camera = new Camera();
	Player_emiter = new Emiter(this->pEngine);
	fprintf(stderr,"player id: %i  \n", this->GetId());

	player_camera->InitCamera(this,this->pEngine);
}

Player::~Player(void)
{
}
