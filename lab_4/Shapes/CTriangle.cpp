#include "stdafx.h"
#include "CTriangle.h"
#include "CSolidShape.h"

CTriangle::CTriangle(const CPoint& a, const CPoint& b, const CPoint& c, string& outlineColor, string& fillColor) :
	m_vertex_1(a),
	m_vertex_2(b),
	m_vertex_3(c),
    CSolidShape(outlineColor, fillColor)
{
}

CPoint CTriangle::GetStartPoint() const
{
	return m_vertex_1;
}

CPoint CTriangle::GetMiddlePoint() const
{
	return m_vertex_2;
}

CPoint CTriangle::GetEndPoint() const
{
	return m_vertex_3;
}

double CTriangle::GetPerimeter() const
{
	return GetLength(m_vertex_1, m_vertex_2) + GetLength(m_vertex_2, m_vertex_3) + GetLength(m_vertex_3, m_vertex_1);
}

double CTriangle::GetArea() const
{
	double p = GetPerimeter() / 2; // считаем полупериметр для формулы Герона

	double a = GetLength(m_vertex_1, m_vertex_2);
	double b = GetLength(m_vertex_2, m_vertex_3);
	double c = GetLength(m_vertex_3, m_vertex_1);
	
	return	sqrt(p*(p - a)*(p - b)*(p - c));
}

double CTriangle::GetLength(CPoint const & vertex1, CPoint const & vertex2) const 
{
	return sqrt(pow((vertex2.m_x - vertex1.m_x), 2) + pow((vertex2.m_y - vertex2.m_y), 2));
}

string CTriangle::ToString() const
{
	ostringstream str;

	str << "triangle " << "perimetr " << GetPerimeter() << " area " << GetArea()
		<< "outlineColor " << GetOutlineColor() << " fillColor " << GetFillColor() << endl;

	return str.str();
}
