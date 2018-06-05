#include "stdafx.h"
#include "CSolidShape.h"
#include "CRectangle.h"

CRectangle::CRectangle(const CPoint & leftTop, const double & width, const double & height, string & outlineColor, string & fillColor) :
	m_height(height),
	m_width(width),
	m_leftTop(leftTop),
	CSolidShape(outlineColor, fillColor)
{
}


CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const 
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

double CRectangle::GetArea() const
{
	return (m_width * m_height);
}

string CRectangle::ToString() const
{
	ostringstream str;

	str << "rectangle " << "perimetr " << GetPerimeter() << " area " << GetArea()
		<< " outlineColor " << GetOutlineColor() << " fillColor " << GetFillColor()
		<< " width " << m_width << " height " << m_height
		<< " left top " << m_leftTop.m_x << " " << m_leftTop.m_y;

	return str.str();
} 