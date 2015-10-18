#include "StdAfx.h"
#include "Emiter.h"
#include <time.h>

Emiter::Emiter(IEngine* engine):
	e_pos(0,0),
	e_rot(0,0),
	e_IsActive(false),
	p_scale(0,0),
	eEngine(NULL),
	e_Duration(1.0f),
	particle(NULL)
{
	particle = new Particle();
	eEngine = engine;

}

void Emiter::SpawnParticle()
{
	if(TParticles.size() > 0 )
	{
		for( pit = TParticles.begin() ; pit != TParticles.end() ; pit++)
		{
			(*pit)->p_pos = e_pos;
			(*pit)->p_Life = eEngine->RandToFloat(0.f,3.0f);
			(*pit)->p_duration = 0.1f;
			float dir =  atan2(e_rot.GetX(),e_rot.GetY()) * 180/PI;
			(*pit)->p_angle= eEngine->RandToFloat(-180+dir,180+dir) * PI/180;

			(*pit)->p_rot = Vector2(sinf((*pit)->p_angle),cosf((*pit)->p_angle));
		
		}
	}
}

void Emiter::SetupParticle()
{		

	p_particle = "particle.bmp";

	e_capicity			= 200;
	p_speed				= 20.0f;
	p_dissolve			= true;
	p_dissolveRate		= 4;
	e_IsActive			= true;
	
	for(int i = 0; i != e_capicity; ++i)
	{
		particle = new Particle();
		TParticles.push_back(particle);
	}
}

void Emiter::Init()
{
	if(OwnerId >= 0)
	{
		Owner = eEngine->GetGame()->GetActorById(OwnerId);
		if(Owner != NULL)
		{
			e_pos = Owner->GetPosition();
			e_rot = Owner->GetRotation();
		}
	}

	SpawnParticle();
}

void Emiter::Update(float deltaTime)
{
	if(e_IsActive)
	{
		for( pit = TParticles.begin() ; pit != TParticles.end() ; pit++)
		{
			(*pit)->p_vel = (*pit)->p_vel + (*pit)->p_rot * p_speed * deltaTime;
			(*pit)->p_pos = (*pit)->p_pos + (*pit)->p_vel;
		
			(*pit)->p_Life -= (*pit)->p_duration;
			
			if( (*pit)->p_Life <= 0 )
			{
 				delete (*pit);
				pit = TParticles.erase( pit );
				if( pit == TParticles.end() ) return;
			}		
		}
	}

}


void Emiter::DrawParticle(ALLEGRO_BITMAP* particle)
{
	if(particle != NULL)
	{
		for( pit = TParticles.begin() ; pit != TParticles.end() ; pit++)
		{
			if(particle != NULL)
			{
				al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE,ALLEGRO_INVERSE_ALPHA);

				float width = al_get_bitmap_width(particle);
				float height = al_get_bitmap_height(particle);

				double angle = atan2((*pit)->p_rot.GetY(),(*pit)->p_rot.GetX());
				al_draw_rotated_bitmap(particle,width/2,height/2,(*pit)->p_pos.GetX(),(*pit)->p_pos.GetY(),angle,0);
			}
		}
	}
}

void Emiter::RemoveParticle()
{
	for(pit = TParticles.begin(); pit != TParticles.end(); pit++)
	{
		delete (*pit);
		pit = TParticles.erase( pit );
		if( pit == TParticles.end() ) return;
	}
}

Vector2 Emiter::GetRotation()
{
	return e_rot;
}

Vector2 Emiter::GetVelocity()
{
	return e_rot; // TODO
}

Vector2 Emiter::GetPosition()
{
	return e_pos;
}

void Emiter::Activate(bool IsActivate)
{
	e_IsActive = IsActivate;
}

bool Emiter::IsActive()
{
	return e_IsActive;
}

char* Emiter::GetName(){return NULL; }
char* Emiter::GetSurface(){return p_particle; }
int Emiter::GetId() {return 0;}
bool Emiter::IsAlive() {return false;}
bool Emiter::IsPlayer() {return false;}

void Emiter::SetOwner(int Owner){OwnerId = Owner;}

void Emiter::SetPosition(Vector2 Pos){ e_pos = Pos;}
void Emiter::SetRotaion(Vector2 Rot){ e_rot = Rot;}

Emiter::~Emiter(void)
{

}
