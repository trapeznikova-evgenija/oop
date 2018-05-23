#pragma once
#include "IShape.h"

class CShape : public IShape
{
public:
	CShape(uint32_t & outlineColor);
	
	uint32_t GetOutlineColor() const override;


private:
	uint32_t m_outline_color;
};