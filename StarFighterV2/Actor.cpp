#include "StdAfx.h"
#include "Actor.h"

Actor::Actor():
	Health(0),
	MaxHealth(0),
	Shield(0),
	MaxShield(0),
	Name(nullptr),
	Surface(nullptr),
	Bitmap(nullptr),
	Velocity(0,0),
	Acceleration(0.0),
	Rotation(0,0),
	Position(0,0)
{
	
}

//Just for test;

Actor::Actor(Actor& actor):
	Health(0),
	MaxHealth(0),
	Shield(0),
	MaxShield(0),
	Name(nullptr),
	Surface(nullptr),
	Bitmap(nullptr),
	Velocity(0, 0),
	Acceleration(0.0),
	Rotation(0, 0),
	Position(0, 0)
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
			player->MaxHealth = 100;

			if (player->Health <= 0)
			{
				player->Health = MaxHealth;
			}

			player->MaxShield = 100;

			if (player->Shield <= 0)
			{
				player->Shield = MaxShield;
			}
		}
	}

}

void Actor::DrawActor()
{
	Vector2 pos = this->GetPosition();
	Vector2 rot = this->GetRotation();

	if (Bitmap != nullptr)
	{
		float width = al_get_bitmap_width(Bitmap);
		float height = al_get_bitmap_height(Bitmap);

		double angle = atan2(rot.GetY(), rot.GetX());
		al_draw_rotated_bitmap(Bitmap, width / 2, height / 2, pos.GetX(), pos.GetY(), angle, 0);
	}
}

void Actor::Update(float fTime)
{
	Time = fTime;

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
	if(Health <= 0)
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
	return Health;
}

int Actor::GetShield()
{
	return Shield;
}

char* Actor::GetSurface()
{
	return Surface;
}

Vector2 Actor::GetVelocity()
{
	return Velocity;
}

void Actor::SetVelocity(Vector2 vel)
{
	//printf("%f  %f \n",vel.GetX(),vel.GetY());
	Velocity = vel;
}

Vector2 Actor::GetRotation()
{
	return Rotation;
}

Vector2 Actor::GetPosition() 
{
	//printf("%f  %f \n",m_position.x,m_position.y);
	return Position;
}

char* Actor::GetName()
{
	return Name;
}

void Actor::SetRotation(Vector2 rot)
{
		Rotation = rot;
}

void Actor::SetRotation(float Angle)
{	
	Rotation = Vector2(sinf(Angle),cos(Angle));
}

void Actor::SetPosition(Vector2 pos)
{
		//printf("%f  %f \n",pos.x,pos.y);
		Position = pos;
}

void Actor::SetSurface (char* SurfaceName)
{
	Surface  = SurfaceName;
}

void Actor::SetName(char* ActorName)
{
	Name = ActorName;
}

void Actor::SetAcceleration(float acc)
{
	if(acc >=0 )
	{
		Acceleration = acc;
	}
	else
	{
		Acceleration = 0.0f;
	}
}

int Actor::GetId()
{
	return this->pGame->GetActorId(this);
}


void Actor::SetSprite(ALLEGRO_BITMAP* Sprite)
{
	if (Sprite != nullptr)
	{
		Bitmap = Sprite;
	}
}
Actor::~Actor(void)
{
}
