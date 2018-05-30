#include "stdafx.h"
#include "CShape.h"

CShape::CShape(string &outlineColor) :
	m_outline_color(outlineColor)
{

}

string CShape::GetOutlineColor() const
{
	return m_outline_color;
}

	