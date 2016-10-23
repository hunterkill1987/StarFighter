#include "stdafx.h"
#include "Math.h"
#include <math.h>

bool Math::IsNear(float A, float B, float Epsilon)
{
	float NewEpsilon = EPSILON;
	if (Epsilon != 0.f)
	{
		NewEpsilon = Epsilon;
	}
	if ((fabs(A - B) < NewEpsilon))
	{
		return true;
	}
	return false;
}
