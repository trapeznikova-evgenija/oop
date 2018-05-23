#pragma once
#include "CPoint.h"
#include "CShape.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(const CPoint startPoint, const CPoint endPoint, uint32_t & outlineColor);

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

	double GetArea() const override;
	double GetPerimeter() const override;
	double GetLengthLine() const;
	string ToString() const override;


private:

	CPoint m_startPoint;
	CPoint m_endPoint;
};
