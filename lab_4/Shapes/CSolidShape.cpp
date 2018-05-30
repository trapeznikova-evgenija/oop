#include "stdafx.h"
#include "CSolidShape.h"

CSolidShape::CSolidShape(string & outlineColor, string &fillColor) :
	m_fill_color(fillColor),
	CShape(outlineColor)
{

}

string CSolidShape::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

string CSolidShape::GetFillColor() const
{
	return m_fill_color;
}

