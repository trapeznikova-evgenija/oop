#include "stdafx.h"
#include "UserTools.h"
#include "CHandler.h"

using namespace std;



void GetShapeWithMinPerimetr(const vector<unique_ptr<CShape>>& shapesArray)
{
	auto FindMinElement = [](const unique_ptr<CShape>& shapeOne, const unique_ptr<CShape>& shapeTwo)
	{
		return shapeOne->GetPerimeter() < shapeTwo->GetPerimeter();
	};

	auto result = min_element(shapesArray.begin(), shapesArray.end(), FindMinElement);

	if (result != shapesArray.end())
	{
		cout << "Shape with min perimetr " << endl;
		cout << (*result)->ToString() << endl;
	}
}

void GetShapeWithMaxArea(const vector<unique_ptr<CShape>>& shapesArray)
{
	auto FinMaxElement = [](const unique_ptr<CShape>& shapeOne, const unique_ptr<CShape>& shapeTwo)
	{
		return shapeOne->GetArea() > shapeTwo->GetArea();
	};

	auto result = max_element(shapesArray.begin(), shapesArray.end(), FinMaxElement);
   
	if (result != shapesArray.end())
	{
		cout << "Shape with max area " << endl;
		cout << (*result)->ToString() << endl;
	}
}
