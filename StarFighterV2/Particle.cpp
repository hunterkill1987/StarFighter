#include "StdAfx.h"
#include "Particle.h"


Particle::Particle(void):
		p_pos(0,0),
		p_rot(0,0),
		p_scale(0,0),
		p_Tex(NULL),
		p_Life(0.0)
{
}

void Particle::SpawnParticle()
{
}

void Particle::UpdateParticle(float deltaTime)
{
}


Particle::~Particle(void)
{
}
