#include "stdafx.h"
#include "CShapesCreator.h"

unique_ptr<IShape> CShapesCreator::GetCircle(string & paramsStr)
{
	stringstream strm(paramsStr);

	string shapeName;
	CPoint center;
	double radius;
	string outlineColor;
	string fillColor;

	strm >> shapeName >> center.m_x >> center.m_y >> radius >> outlineColor >> fillColor;

	return make_unique<CCircle>(center, radius, outlineColor, fillColor);
}

unique_ptr<IShape> CShapesCreator::GetRectangle(string &paramsStr)
{
	stringstream strm(paramsStr);

	string action;
	CPoint leftTop;
	double width;
	double height;
	string outlineColor;
	string fillColor;

	strm >> action >> leftTop.m_x >> leftTop.m_y >> width >> height >> outlineColor >> fillColor;

	return make_unique<CRectangle>(leftTop, width, height, outlineColor, fillColor);
}

unique_ptr<IShape> CShapesCreator::GetTriangle(string &paramsStr)
{
	stringstream strm(paramsStr);

	string action;
	CPoint vertex1;
	CPoint vertex2;
	CPoint vertex3;
	string outlineColor;
	string fillColor;

	strm >> action >> vertex1.m_x >> vertex1.m_y >> vertex2.m_x >> vertex2.m_y >> vertex3.m_x >> vertex3.m_y >> outlineColor >> fillColor;
	return make_unique<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
}