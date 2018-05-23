#pragma once
#include "CShape.h"
#include "ISolidShape.h"

class CSolidShape : public ISolidShape, public CShape
{
public:
	CSolidShape(uint32_t & outlineColor, uint32_t & fillColor);

	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

private:
	uint32_t m_fill_color;
};

