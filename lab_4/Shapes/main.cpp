// Shapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "CShapesRecorder.h"
#include "CHandler.h"

using namespace std;

int main(int argc, char* argv[])
{
	CPoint startPoint(3, 2);
	CPoint endPoint(5, 8);
	//CLineSegment lineSegment(startPoint, endPoint, 000000);

	string commandLine = "";
	stringstream strstream;

 
	//uint32_t test;
	//test = 0x9400D3;
	//cout << test << endl;


    //CShapesRecorder shapesRecorder(cin, cout, strstream);
	CHandler handler(cin, cout, strstream);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!handler.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}

	 //shapesRecorder.GetShapesArray();

    return 0;
}

