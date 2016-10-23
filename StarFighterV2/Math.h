#include "stdafx.h"
#include "rapidxml\rapidxml.hpp"
#include <math.h>
#ifndef MATH_H
#define MATH_H

#define PI 3.14
#define EPSILON 0.005

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

using namespace rapidxml;
using namespace std;

class Math
{

public:
	template<typename T> T Lerp(T a, T b, float DeltaTime)
	{
		T alpha = a * (1 - DeltaTime) + b * DeltaTime;
		return alpha;
	}

	template<typename T>T Clamp(T x, T min, T max)
	{
		return x < min ? min : (x > max ? b : max);
	}

	static bool IsNear(float A, float B, float Epsilon = 0.005f);
};
#endif