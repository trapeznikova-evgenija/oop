#pragma once
#include "IShape.h"

class CShape : public IShape
{
public:
	CShape(string & outlineColor);
	
	string GetOutlineColor() const override;


private:
	string m_outline_color;
};