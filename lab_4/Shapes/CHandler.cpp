#include "stdafx.h"
#include "CShapesCreator.h"
#include "CHandler.h"

CHandler::CHandler(CShapesCreator & shapesCreator, istream & in, ostream & out, stringstream & strstream)
	:m_input(in),
	 m_output(out),
	m_actionMap({
		{ "triangle", [this](stringstream & strstream, CShapesCreator & shapesCreator)
					  {
						string paramsStr = strstream.str();
						if (CHandler::CheckValidityTriangle(paramsStr))
						{
							m_shapesArray.push_back(move(shapesCreator.GetTriangle(paramsStr)));
							return true;
						} else
						{
							return false;
						}
					  }
		},
		{ "rectangle", [this](stringstream & strstream,  CShapesCreator & shapesCreator)
					   {
						  string paramsStr = strstream.str();
						  if (CHandler::CheckValidityRectangle(paramsStr))
						  {
							  m_shapesArray.push_back(move(shapesCreator.GetRectangle(paramsStr)));
							  return true;
						  } else
						  {
							  return false;
						  }
					   }
		},
		{ "circle", [this](stringstream & strstream,  CShapesCreator & shapesCreator)
					{
				      string paramsStr = strstream.str();
					  if (CHandler::CheckValidityCircle(paramsStr))
					  {
						m_shapesArray.push_back(move(shapesCreator.GetCircle(paramsStr)));
					    return true;
					  } else
					  {
					    return false;
					  }
					}
		},
		})
{
}

bool CHandler::HandleCommand(CShapesCreator & shapesCreator)
{
	string commandLine;
	getline(m_input, commandLine);
	stringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm, shapesCreator);
	}

	return false;
}

bool CHandler::CheckValidityTriangle(string & params)
{

	return true;
}

bool CHandler::CheckValidityCircle(string & params)
{
	return true;
}

bool CHandler::CheckValidityRectangle(string & params)
{
	return true;
}

bool CHandler::CheckValidityLineSegment(string & params)
{
	return true;
}

const vector<unique_ptr<CShape>>& CHandler::GetShapesArray() const
{
	return m_shapesArray;
}