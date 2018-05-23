// Shapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "CShapesRecorder.h"

int main(int argc, char* argv[])
{
	CPoint startPoint(3, 2);
	CPoint endPoint(5, 8);
	//CLineSegment lineSegment(startPoint, endPoint, 000000);

	string commandLine = "";

	CShapesRecorder shapesRecorder(cin);


    return 0;
}

