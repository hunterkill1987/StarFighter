#include "StdAfx.h"
#include "Player.h"
#include "Emiter.h"

Player::Player(unsigned int Index) : Actor(EActorPlayer),
	Angle(0.0),
	acc(0.0),
	accTime(0.0),
	Health(0),
	MaxHealth(0),
	Shield(0),
	MaxShield(0)
{
}

void Player::Update(float deltaTime)
{
	//Test fx !!! works
	if (this->pEngine->GetTickCount() > fx && fx > 0.0)
	{
		fx = 0.f;
		//this->pGame->SpawnFX(Player_emiter, this->GetPosition(), this->GetId());
	}
	if (player_camera != NULL)
		player_camera->UpdateCamera();

	/*a = lerp<float>(a, 1.f, deltaTime);
	fprintf(stderr, "player lerp %f  \n",a);

	lerp(0.f,1.f, deltaTime);*/
}

void Player::HandleInput(IEvent* &Input, IEngine* &Engine)
{
	Vector2 rotation = this->GetRotation();
	Vector2 velocity = this->GetVelocity();

	if (Input != nullptr && Engine != nullptr)
	{
		int input = Input->GetInput();

		if (input & (1 << LEFT))
		{
			Angle += Engine->GetDeltaTime() * 3.14f;
			if (Angle > 3.14f) Angle -= 3.14 * 2.f;
			//fprintf(stderr,"player angle %f %f \n", Angle ,Angle * 180/ PI);
			rotation = Vector2(cosf(Angle), sinf(Angle));
			SetRotation(rotation);
		}

		if (input & (1 << RIGHT))
		{
			Angle -= Engine->GetDeltaTime() * 3.14f;
			if (Angle < -3.14f) Angle += 3.14 * 2.f;
			//fprintf(stderr,"player angle %f %f \n", Angle ,Angle * 180/ PI);
			rotation = Vector2(cosf(Angle), sinf(Angle));
			SetRotation(rotation);
		}

		if (input & (1 << UP))
		{
			rotation = Vector2(GetRotation().GetX(), GetRotation().GetY());
			velocity = velocity + rotation * 4 * Engine->GetDeltaTime();
		}

		if (input & (1 << DOWN))
		{
			rotation = Vector2(-1 * GetRotation().GetX(), -1 * GetRotation().GetY());
			velocity = velocity + rotation * 4 * Engine->GetDeltaTime();
		}

		if (input & (1 << FIRE))
		{

		}


		Vector2 pos = GetPosition();
		Vector2 newpos = GetPosition();

		newpos = newpos + velocity;
		SetVelocity(velocity);
		SetPosition(newpos);
	}
}
void Player::Init(xml_document<> &ActorXml)
{
	Actor::Init(ActorXml);
}

Player::~Player(void)
{
}
