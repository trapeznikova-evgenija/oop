#pragma once
#include "CPoint.h"
#include "IShape.h"
using namespace std;

class ISolidShape : public virtual IShape
{
public:

	ISolidShape() = default;

	virtual uint32_t GetFillColor() const = 0;
};