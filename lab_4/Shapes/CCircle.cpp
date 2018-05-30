#include "stdafx.h"
#include "CSolidShape.h"
#include "CCircle.h"

CCircle::CCircle(const CPoint & center, const double & radius, string & outlineColor, string & fillColor) :
	m_center(center),
	m_radius(radius),
	CSolidShape(outlineColor, fillColor)
{
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

string CCircle::ToString() const
{
	ostringstream str;

	str << "circle " << "perimetr " << GetPerimeter() << " area " << GetArea()
		<< " outlineColor " << GetOutlineColor() << " fillColor " << GetFillColor()
		<< " radius " << m_radius << " center vertex " << m_center.m_x << " " << m_center.m_y;

	return str.str();
}