#pragma once
#include "iactor.h"
#include "IEngine.h"
class Particle :
	public IActor
{
private:
	Vector2				p_pos;
	Vector2				p_rot;
	Vector2				p_scale;
	ALLEGRO_BITMAP*		p_Tex;

	ALLEGRO_BITMAP*		p_Color;
	
	float				p_Life;

public:
	Particle(void);
	~Particle(void);

	void SpawnParticle();
	void UpdateParticle(float deltaTime);
};

