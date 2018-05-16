#pragma once
#include "CPoint.h"
#include "IShape.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(const CPoint startPoint, const CPoint endPoint, const string & outlineColor);

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;


private:

	double GetLengthLine() const;

	CPoint m_startPoint;
	CPoint m_endPoint;
};
