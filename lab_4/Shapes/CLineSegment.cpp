#include "stdafx.h"
#include "CLineSegment.h"

CLineSegment::CLineSegment(const CPoint startPoint, const CPoint endPoint, string & outlineColor) 
	: m_startPoint(startPoint),
	  m_endPoint(endPoint),
	  CShape(outlineColor)
{
};

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return GetLengthLine();
}

double CLineSegment::GetLengthLine() const
{
	return sqrt(pow((m_endPoint.m_x - m_startPoint.m_x), 2) + pow((m_endPoint.m_y - m_startPoint.m_y), 2));
}

string CLineSegment::ToString() const
{
	  ostringstream strstream;
	  strstream << "lineSegment " << "startPoint " << m_startPoint.m_x << ", " << m_startPoint.m_y
		<< "endPoint " << m_endPoint.m_x << ", " << m_endPoint.m_y
		<< "area " << GetArea() << "perimeter " << GetPerimeter()
		<< "outlineColor " << GetOutlineColor() << endl;

	  strstream << "sds";
	return strstream.str();
}



