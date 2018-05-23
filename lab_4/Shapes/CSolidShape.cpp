#include "stdafx.h"
#include "CSolidShape.h"

CSolidShape::CSolidShape(uint32_t & outlineColor, uint32_t &fillColor) :
	m_fill_color(fillColor),
	CShape(outlineColor)
{

}

uint32_t CSolidShape::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

uint32_t CSolidShape::GetFillColor() const
{
	return m_fill_color;
}

