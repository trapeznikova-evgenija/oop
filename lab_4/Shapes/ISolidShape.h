#pragma once
#include "CPoint.h"
#include "IShape.h"
using namespace std;

class ISolidShape : public virtual IShape
{
public:

	ISolidShape() = default;

	virtual string GetFillColor() const = 0;
};