#pragma once
#include "CSolidShape.h"

class CCircle : public CSolidShape
{
public:
	CCircle (const CPoint & center, const double & radius, string & outlineColor, string & fillColor);
	
	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center;
	double m_radius;
};
