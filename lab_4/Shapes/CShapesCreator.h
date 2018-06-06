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

	unique_ptr<IShape> GetTriangle(string & paramsStr);
	unique_ptr<IShape> GetRectangle(string & paramsStr);
	unique_ptr<IShape> GetCircle(string & paramsStr);

private:

};