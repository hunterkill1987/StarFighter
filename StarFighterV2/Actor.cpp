#include "StdAfx.h"
#include "Actor.h"
#include "Engine.h"

Actor::Actor(unsigned int Index, EActorType ActorType , Vector2 Pos ) :
	Name(nullptr),
	Bitmap(nullptr),
	Velocity(0,0),
	Acceleration(0.0),
	Rotation(0,0),
	Position(0,0)
{
	UID = Index;
	AType = ActorType;
	Position = Pos;
	pEngine = Engine::GetInstance();
}

void Actor::Init(xml_document<> &ActorParams)
{
	xml_node<> *ActorParamNode = ActorParams.first_node("Actor");
	if (ActorParamNode != nullptr)
	{
		this->SetName(ActorParamNode->first_attribute("name")->value());
		for (xml_node<>* ActorParam = ActorParamNode->first_node("Surface"); ActorParam; ActorParam = ActorParam->next_sibling())
		{
			pEngine->LoadAsset(this, ActorParam->first_attribute("path")->value());
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

long long int Actor::GetUID()
{
	return UID;
}

void Actor::SetUID(long long int NewUID)
{
	UID = NewUID;
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


bool Actor::IsPlayer()
{
	IActor *player = dynamic_cast<Player *>(this);
	if(player != 0)
	{
			return true;
	}
	return false;
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

const char* Actor::GetName()
{
	if (Name != nullptr)
	{
		return this->Name;
	}
	return nullptr;
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

void Actor::SetName(char* ActorName)
{
	Name = strdup(ActorName);
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
