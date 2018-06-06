#include "stdafx.h"
#include "../Shapes/CHandler.h"

TEST_CASE("CTriangle Class Tests")
{
	CPoint a(0, 0);
	CPoint b(0, 8);
	CPoint c(15, 0);
	string outlineColor = "red";
	string fillColor = "blue";

	stringstream strstream;
	strstream << "triangle 0 0 0 8 15 0 red blue";

	CTriangle triangle(a, b, c, outlineColor, fillColor);
	CShapesCreator shapesCreator;
	CHandler handler(shapesCreator, cin, cout, strstream);

	CPoint startVertex1 = triangle.GetStartPoint();
	CHECK(startVertex1.m_x == a.m_x);
	CHECK(startVertex1.m_y == a.m_y);

	CPoint middleVertex2 = triangle.GetMiddlePoint();
	CHECK(middleVertex2.m_x == b.m_x);
	CHECK(middleVertex2.m_y == b.m_y);

	CPoint endVertex3 = triangle.GetEndPoint();
	CHECK(endVertex3.m_x == c.m_x);
	CHECK(endVertex3.m_y == c.m_y);

	CHECK(triangle.GetArea() == 60);
	CHECK(triangle.GetPerimeter() == 40);

	CHECK(triangle.GetLength(a, b) == 8);
	CHECK(triangle.GetLength(b, c) == 17);

	cout << "Check ToString() function" << endl;

	string resultString = "triangle perimetr 40 area 60 outlineColor red fillColor blue";
	CHECK(triangle.ToString() == resultString);
	//string paramStr = "triangle 0 0 0 8 15 0 red blue";
	//unique_ptr<CShape> ptrShape =  shapesCreator.GetTriangle(paramStr);
	//vector<unique_ptr<CShape>> m_shapesArray =  handler.GetShapesArray();
	//m_shapesArray.push_back(move(shapesCreator.GetTriangle(paramStr)));
	//CHECK(handler.GetShapeWithMinPerimetr() == resultString);
}

TEST_CASE("CRectangle Class Tests")
{
	cout << "CRectangle tests" << endl;
	CPoint leftTop(0, 0);
	double width = 10;
	double height = 20;
	string outlineColor = "blue";
	string fillColor = "black";

	CRectangle rectangle(leftTop, width, height, outlineColor, fillColor);

	CPoint leftTopPosition = rectangle.GetLeftTop();
	CHECK(leftTopPosition.m_x == leftTop.m_x);
	CHECK(leftTopPosition.m_y == leftTop.m_y);

	CHECK(rectangle.GetArea() == 200);
	CHECK(rectangle.GetPerimeter() == 60);

	CHECK(rectangle.GetWidth() == width);
	CHECK(rectangle.GetHeight() == height);

	string resultRectangleString = "rectangle perimetr 60 area 200 outlineColor blue fillColor black width 10 height 20 left top 0 0";
	CHECK(rectangle.ToString() == resultRectangleString);

	CHECK(rectangle.GetFillColor() == "black");
	CHECK(rectangle.GetOutlineColor() == "blue");

}

TEST_CASE("CCircle Class Tests")
{
	CPoint center(0, 0);
	double circleRadius = 25;
	string outlineColor = "orange";
	string fillColor = "white";

	CCircle circle(center, circleRadius, outlineColor, fillColor);

	CHECK(circle.GetRadius() == circleRadius);

	CPoint circleCenterResult = circle.GetCenter();
	CHECK(circleCenterResult.m_x == center.m_x);
	CHECK(circleCenterResult.m_y == center.m_y);

	CHECK(circle.GetArea() == 1963.4954084936207740391521145497);
	CHECK(circle.GetPerimeter() == 157.07963267948966192313216916398);

}
