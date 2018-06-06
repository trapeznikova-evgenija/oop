#include "stdafx.h"
#include "Tools.h"

bool IsEqual(const double& number1, const double& number2)
{
	double distinction;
	distinction = number1 - number2;
	return (distinction <= INNACURACY) && (-distinction <= INNACURACY);
}