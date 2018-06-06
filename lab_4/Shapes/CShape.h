#pragma once
#include "IShape.h"

class CShape : public virtual IShape
{
public:
	CShape(string & outlineColor);
	
	string GetOutlineColor() const override;

private:
	string m_outline_color;
};