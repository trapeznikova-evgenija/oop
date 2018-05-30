#include "stdafx.h"
#include "CHandler.h"

CHandler::CHandler(istream & in, ostream & out, stringstream & strstream)
	:m_input(in),
	m_actionMap({
		{ "triangle", [this](stringstream & strstream)
					  {
						return true; //CreateTriangle();
					  }
		},
		{ "rectangle", [this](stringstream & strstream)
					   {
						 return true; // CreateRectangle();
					   }
		},
		{ "circle", [this](stringstream & strstream)
					{
					  return true; //CreateCircle();
					}
		}
		})
{
}

bool CHandler::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	stringstream strm(commandLine);
	cout << "commandLine " << commandLine;

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}