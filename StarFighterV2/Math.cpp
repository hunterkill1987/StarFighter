#include "stdafx.h"
#include "SMath.h"
#include <math.h>

/*
template<typename T1,typename T2> T1 lerp(T1 a, T2 b, float DeltaTime)
{
	T1 alpha = a + DeltaTime*(b - a);
	return alpha;
}
*/

float lerp(float a, float b, float DeltaTime)
{
	float alpha = a + DeltaTime*(b - a);
	return alpha;
}
