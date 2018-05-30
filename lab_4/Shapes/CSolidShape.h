#pragma once
#include "CShape.h"
#include "ISolidShape.h"

class CSolidShape : public ISolidShape, public CShape
{
public:
	CSolidShape(string & outlineColor, string & fillColor);

	string GetOutlineColor() const override;
	string GetFillColor() const override;

private:
	string m_fill_color;
};

