#include "StdAfx.h"
#include "Camera.h"


Camera::Camera():
owner(nullptr),
	campos(0,0),
	winsize(0,0)
{

}

int Camera::InitCamera(IActor* actor,IEngine* pEngine)
{
	if (actor != nullptr && actor->IsPlayer())
	{
		owner = actor;
		winsize = pEngine->GetScreenSize(); 
		return 1;
	}
	return 0;
}

void Camera::UpdateCamera()
{
	float x,y;
	if (owner != nullptr && owner->IsPlayer())
	{
		Vector2 ownerpos = owner->GetPosition();

		x = -(winsize.GetX() / 2) + ownerpos.GetX();
		y = -(winsize.GetY() / 2) + ownerpos.GetY();

		if( x < 0)
		{
			x = 0;
		}

		if(y < 0 )
		{
			y = 0;
		}
		
		campos = Vector2(x,y);	

		al_identity_transform(&camera);
		al_translate_transform(&camera,-campos.GetY(),-campos.GetX());
		al_use_transform(&camera);
	}
}

void Camera::ReSize(Vector2 newsize)
{
	winsize = newsize;
}


Vector2 Camera::GetCameraPos()
{
	return campos;
}

Camera::~Camera(void)
{
}
