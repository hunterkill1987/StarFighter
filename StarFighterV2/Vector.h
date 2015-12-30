#include "stdafx.h"
#include <math.h>
#ifndef VECTOR_H
#define VECTOR_H

#define PI 3.14
typedef struct Vector2
{
private:
	float x;
	float y;

public: 

	Vector2(float ix, float iy) : 
	x(0),y(0)
	{
			x = ix;
			y = iy;
	}

	Vector2 operator + (const Vector2 v1)
	{
		float dx = x + v1.x;
		float dy = y + v1.y;
		return Vector2(dx,dy);
	}

	Vector2 operator + (const float v)
	{
		float dx = GetX() + v;
		float dy = GetY() + v;
		return Vector2(dx,dy);
	}

	Vector2 operator * (const Vector2 v1)
	{
		float dx = x  * v1.x;
		float dy = y * v1.y;
		return Vector2(dx,dy);
	}
	
	Vector2 operator / (const float v1)
	{
		float dx = x  / v1;
		float dy = y / v1;
		return Vector2(dx,dy);
	}
	
	Vector2 operator * (const float v)
	{
		float dx = x * v;
		float dy = y * v;
		return Vector2(dx,dy);
	}


	Vector2 operator - (const float v1)
	{
		float dx = x - v1;
		float dy = y - v1;
		return Vector2(dx,dy);
	}

	
	Vector2 operator - (const Vector2& v1)
	{
		float dx = x  - v1.x;
		float dy = y - v1.y;
		return Vector2(dx,dy);
	}

	float GetX(){return x;}
	float GetY(){return y;}

	Vector2 normalize()
	{
		float len = this->length();

		float dx = 0.0, dy = 0.0;

		if(len != 0 )
		{
				dx = x/len;
				dy = y/len;
		}
		return Vector2(dx,dy);
	}
	
	float length()
	{
		return sqrt((x*x) + (y*y));
	}

	float dot(Vector2& v1)
	{
		return (x*v1.x) + (y*v1.y);
	}

	float angelToRot(float angle)
	{
		
	}
}Vector2;



#endif