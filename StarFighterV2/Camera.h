#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "IActor.h"
#include "IEngine.h"

class Camera
{
private:
	ALLEGRO_TRANSFORM	camera;

	IActor*				owner;
	IEngine*			cEngine;

	Vector2				campos;
	Vector2				winsize;

public:
	Camera();
	~Camera(void);
	
	int	 InitCamera(IActor* actor,IEngine* pEngine);
	void UpdateCamera();
	void ReSize(Vector2 newSize);
	Vector2 GetCameraPos();
};

