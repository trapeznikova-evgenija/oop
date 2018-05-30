#include "stdafx.h"
#include "CShapesRecorder.h"

/*bool CShapesRecorder::CreateTriangle()
{
	m_output << "You choose triangle " << endl;
	m_output << "Enter shape parameter" << endl;

	CPoint vertex1;
	CPoint vertex2;
	CPoint vertex3;
	string outlineColor;
	string fillColor;

	string commandLine;
	getline(cin, commandLine);

    stringstream strstream(commandLine);
	strstream >> vertex1.m_x >> vertex1.m_y >> vertex2.m_x >> vertex2.m_y >> vertex3.m_x >> vertex2.m_y >> outlineColor >> fillColor;
			
	auto trianglePtr = make_unique<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
	//m_shapesArray.push_back(move(trianglePtr));
	
	return true;
}

bool CShapesRecorder::CreateRectangle()
{
	m_output << "You choose rectangle " << endl;
	m_output << "Enter shape parameter" << endl;

	CPoint leftTop;
	double width;
	double height;
	string outlineColor;
	string fillColor;

	string commandLine;
	getline(cin, commandLine);

	stringstream strstream(commandLine);
	strstream >> leftTop.m_x >> leftTop.m_y >> width >> height >> outlineColor >> fillColor;

	auto rectanglePtr = make_unique<CRectangle>(leftTop, width, height, outlineColor, fillColor);
	//m_shapesArray.push_back(move(rectanglePtr));

	return true;
}

bool CShapesRecorder::CreateCircle()
{
	m_output << "You choose circle " << endl;
	m_output << "Enter shape parameter" << endl;

	CPoint center;
	double radius;
	string outlineColor;
	string fillColor;

	string commandLine;
	getline(cin, commandLine);

	stringstream strstream(commandLine);
	strstream >> center.m_x >> center.m_y >> radius >> outlineColor >> fillColor;

	auto circlePtr = make_unique<CCircle>(center, radius, outlineColor, fillColor);
	//m_shapesArray.push_back(move(circlePtr));

	return true;
}


CShapesRecorder::CShapesRecorder(istream & in, ostream & out, stringstream & strstream) :
	m_input(in),
	m_output(out)
{
};
*/

//vector<unique_ptr<cshape>> cshapesrecorder::getshapesarray()
//{
//	return m_shapesarray;
//}
