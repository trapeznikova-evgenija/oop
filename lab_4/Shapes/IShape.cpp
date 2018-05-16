#include "stdafx.h"
#include "IShape.h"

IShape::IShape(const string & outlineColor)
	: m_outlineColor(outlineColor)
{

}

string IShape::GetOutlineColor() const
{
	return m_outlineColor;
}