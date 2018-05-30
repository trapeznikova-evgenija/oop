// Shapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "CShapesRecorder.h"

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


    CShapesRecorder shapesRecorder(cin, cout, strstream);


	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!shapesRecorder.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}

	/*vector<unique_ptr<CShape>> shapesArray = shapesRecorder.GetShapesArray();
	cout << "shapesArray size " << shapesArray.size();*/


    return 0;
}

