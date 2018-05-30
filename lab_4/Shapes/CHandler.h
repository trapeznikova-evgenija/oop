#pragma once

#include "stdafx.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"

class CHandler
{
public:
	CHandler(istream & in, ostream & out, stringstream & strstream);

	bool HandleCommand();

private:
	typedef map<string, function<bool(stringstream & args)>> ActionMap;

	istream & m_input;
	const ActionMap m_actionMap;
};