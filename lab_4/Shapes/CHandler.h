#pragma once

#include "stdafx.h"
//#include "CTriangle.h"
//#include "CRectangle.h"
//#include "CCircle.h"
#include "CShapesCreator.h"

class CHandler
{
public:
	CHandler(CShapesCreator & shapesCreator, istream & in, ostream & out, stringstream & strstream);

	bool HandleCommand(CShapesCreator & shapesCreator);

	bool CheckValidityTriangle(string & params);
	bool CheckValidityRectangle(string & params);
	bool CheckValidityCircle(string & params);
	bool CheckValidityLineSegment(string & params);

	const vector<unique_ptr<CShape>>& GetShapesArray() const;
	const string GetShapeWithMinPerimetr() const;
	const void GetShapeWithMaxArea() const;

private:
	typedef map<string, function<bool(stringstream & args, CShapesCreator & shapesCreator)>> ActionMap;

	vector<unique_ptr<CShape>> m_shapesArray;
	istream & m_input;
	ostream & m_output;
	const ActionMap m_actionMap;
};