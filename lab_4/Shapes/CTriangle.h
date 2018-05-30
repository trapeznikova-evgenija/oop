#pragma once
#include "CSolidShape.h"

class CTriangle : public CSolidShape
{
public:
	CTriangle(const CPoint& a, const CPoint& b, const CPoint& c, string& outlineColor, string& fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	 
	CPoint GetStartPoint() const;
	CPoint GetMiddlePoint() const;
	CPoint GetEndPoint() const;


private:

	double GetLength(CPoint const& vertex1, CPoint  const& vertex2) const;

	CPoint m_vertex_1;
	CPoint m_vertex_2;
	CPoint m_vertex_3;
};
