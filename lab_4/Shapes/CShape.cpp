#include "stdafx.h"
#include "CShape.h"

CShape::CShape(uint32_t &outlineColor) :
	m_outline_color(outlineColor)
{

}

uint32_t CShape::GetOutlineColor() const
{
	return m_outline_color;
}

	