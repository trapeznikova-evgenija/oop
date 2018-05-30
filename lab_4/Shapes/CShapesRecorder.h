#pragma once
#include "stdafx.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"

using namespace std;

class CShapesRecorder
{
public:
	CShapesRecorder(istream & in, ostream & out, stringstream & strstream);

	bool HandleCommand();
	bool CreateTriangle();
	bool CreateRectangle();
	bool CreateCircle();

	//vector<unique_ptr<CShape>> GetShapesArray();

private:
	typedef map<string, function<bool(stringstream & args)>> ActionMap;

	vector<unique_ptr<CShape>> m_shapesArray;

	istream & m_input;
	ostream & m_output;

	const ActionMap m_actionMap;
};
