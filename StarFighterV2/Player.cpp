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
	this->AType = EActorPlayer;
}

void Player::Update(float deltaTime)
{
	Actor::Update(deltaTime);
}

void Player::HandleInput(IEvent* &Input, IEngine* &Engine)
{
	/*
	Vector2 rotation = this->GetRotation();
	Vector2 velocity = this->GetVelocity();

	if (Input != nullptr && pEngine != nullptr)
	{
		int input = 0;

		if (input )
		{
			Angle += pEngine->GetDeltaTime() * 3.14f;
			if (Angle > 3.14f) Angle -= 3.14 * 2.f;
			rotation = Vector2(cosf(Angle), sinf(Angle));
			SetRotation(rotation);
		}

		if (input )
		{
			Angle -= pEngine->GetDeltaTime() * 3.14f;
			if (Angle < -3.14f) Angle += 3.14 * 2.f;
			rotation = Vector2(cosf(Angle), sinf(Angle));
			SetRotation(rotation);
		}

		if (input )
		{
			rotation = Vector2(GetRotation().GetX(), GetRotation().GetY());
			velocity = velocity + rotation * 4 * pEngine->GetDeltaTime();
		}

		if (input )
		{
			rotation = Vector2(-1 * GetRotation().GetX(), -1 * GetRotation().GetY());
			velocity = velocity + rotation * 4 * pEngine->GetDeltaTime();
		}

		if (input )
		{

		}


		Vector2 pos = GetPosition();
		Vector2 newpos = GetPosition();

		newpos = newpos + velocity;
		SetVelocity(velocity);
		SetPosition(newpos);
	}
	*/
}
void Player::Init(xml_document<> &ActorXml)
{
	Actor::Init(ActorXml);
	if (pEngine != nullptr)
	{
		pEngine->GetEventManager()->Bind(this, &Player::MoveLeft, "OnMoveLeft");
		pEngine->GetEventManager()->Bind(this, &Player::MoveRight, "OnMoveRigth");
		pEngine->GetEventManager()->Bind(this, &Player::Move, "OnMove");
		pEngine->GetEventManager()->Bind(this, &Player::Back, "OnBack");
		pEngine->GetEventManager()->SetTimer(this, &Player::TestTimer, 1.6, false);
	}

	Actor::Init(ActorXml);
}

void Player::TestTimer()
{
	fprintf(stderr, "print TestTimer %f\n",pEngine->GetDeltaTime());
}

void Player::MoveLeft()
{
	//fprintf(stderr, "Move Left\n");
	Vector2 rotation = this->GetRotation();
	Vector2 velocity = this->GetVelocity();
	Angle += pEngine->GetDeltaTime() * 3.14f;
	if (Angle > 3.14f) Angle -= 3.14 * 2.f;
	rotation = Vector2(cosf(Angle), sinf(Angle));
	SetRotation(rotation);
}

void Player::MoveRight()
{
	//fprintf(stderr, "Move Right\n");
	Vector2 rotation = this->GetRotation();
	Vector2 velocity = this->GetVelocity();
	Angle -= pEngine->GetDeltaTime() * 3.14f;
	if (Angle < -3.14f) Angle += 3.14 * 2.f;
	rotation = Vector2(cosf(Angle), sinf(Angle));
	SetRotation(rotation);
}


void Player::Move()
{
	//fprintf(stderr, "Move Forward\n");
	Vector2 rotation = this->GetRotation();
	Vector2 velocity = this->GetVelocity();
	rotation = Vector2(GetRotation().GetX(), GetRotation().GetY());
	velocity = velocity + rotation * 4 * pEngine->GetDeltaTime();
	SetVelocity(velocity);
}

void Player::Back()
{
	//fprintf(stderr, "Move Back\n");
	Vector2 rotation = this->GetRotation();
	Vector2 velocity = this->GetVelocity();

	rotation = Vector2(-1 * GetRotation().GetX(), -1 * GetRotation().GetY());
	velocity = velocity + rotation * 4 * pEngine->GetDeltaTime();

	SetVelocity(velocity);
	
}


Player::~Player(void)
{
}
