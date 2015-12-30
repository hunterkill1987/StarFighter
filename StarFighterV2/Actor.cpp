#include "StdAfx.h"
#include "Actor.h"

Actor::Actor():
	mHealth(0),
	maxHealth(0),
	mShield(0),
	maxShield(0),
	name(nullptr),
	surface(nullptr),
	m_velocity(0,0),
	m_acceleration(0.0),
	m_rotation(0,0),
	m_position(0,0)
{
	
}

//Just for test;

Actor::Actor(Actor& actor):
	mHealth(0),
	maxHealth(0),
	mShield(0),
	maxShield(0),
	name(nullptr),
	surface(nullptr),
	m_velocity(0, 0),
	m_acceleration(0.0),
	m_rotation(0, 0),
	m_position(0, 0)
{
	pGame = actor.pGame;
	pEngine = actor.pEngine;
	pEvent = actor.pEvent;
}

void Actor::Init()
{
	IActor* actor = pGame->GetActorById(GetId());
	if (actor != nullptr)
	{
		Player *player = dynamic_cast<Player *>(actor);
		if (player != nullptr)
		{
			player->maxHealth = 100;

			if (player->mHealth <= 0)
			{
				player->mHealth = maxHealth;
			}

			player->maxShield = 100;

			if (player->mShield <= 0)
			{
				player->mShield = maxShield;
			}
		}
	}

}
void Actor::Update(float fTime)
{
	time = fTime;

}

void Actor::MoveActor()
{

}
void Actor::Reset()
{
}

void Actor::StartFire()
{
}

void Actor::StopFire()
{
}

bool Actor::IsAlive()
{
	if(mHealth <= 0)
	{
			return false;
	}
	return true;
}

bool Actor::IsPlayer()
{
	IActor *player = dynamic_cast<Player *>(this);
	if(player != 0)
	{
			return true;
	}
	return false;
}

int Actor::GetHealth()
{
	return mHealth;
}

int Actor::GetShield()
{
	return mShield;
}

char* Actor::GetSurface()
{
	return surface;
}

Vector2 Actor::GetVelocity()
{
	return m_velocity;
}

void Actor::SetVelocity(Vector2 vel)
{
	//printf("%f  %f \n",vel.GetX(),vel.GetY());
	m_velocity = vel;
}

Vector2 Actor::GetRotation()
{
	return m_rotation;
}

Vector2 Actor::GetPosition() 
{
	//printf("%f  %f \n",m_position.x,m_position.y);
	return m_position;
}

char* Actor::GetName()
{
	return name;
}

void Actor::SetRotation(Vector2 rot)
{
		m_rotation = rot;
}

void Actor::SetRotation(float angle)
{	
	m_rotation = Vector2(sinf(angle),cos(angle));
}

void Actor::SetPosition(Vector2 pos)
{
		//printf("%f  %f \n",pos.x,pos.y);
		m_position = pos;
}

void Actor::SetSurface (char* surfaceName)
{
	surface  = surfaceName;
}

void Actor::SetName(char* Name)
{
	name = Name;
}

void Actor::SetAcceleration(float acc)
{
	if(acc >=0 )
	{
		m_acceleration = acc;
	}
	else
	{
		m_acceleration = 0.0f;
	}
}

int Actor::GetId()
{
	return this->pGame->GetActorId(this);
}

Actor::~Actor(void)
{
}
