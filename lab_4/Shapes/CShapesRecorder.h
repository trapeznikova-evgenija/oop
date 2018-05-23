#pragma once
#include "stdafx.h"
#include "CTriangle.h"

using namespace std;

class CShapesRecorder
{
public:
	CShapesRecorder(istream & in, ostream & out);

	bool HandleCommand();
	bool CreateTriangle();

private:
	typedef std::map<std::string, function<bool(istream & args)>> ActionMap;

	istream & m_input;
	ostream & m_output;

	const ActionMap m_actionMap;
};
