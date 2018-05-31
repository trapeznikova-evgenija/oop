#pragma once
#include "stdafx.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"

using namespace std;

class CShapesCreator
{
public:
	CShapesCreator() = default;

	unique_ptr<CShape> GetTriangle(string & paramsStr);
	unique_ptr<CShape> GetRectangle(string & paramsStr);
	unique_ptr<CShape> GetCircle(string & paramsStr);

private:

};