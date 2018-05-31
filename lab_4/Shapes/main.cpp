// Shapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CHandler.h"
#include "CShapesCreator.h"
#include "UserTools.h"

using namespace std;

int main(int argc, char* argv[])
{

	string commandLine = "";
	stringstream strstream;

    //CShapesRecorder shapesRecorder(cin, cout, strstream);
	CShapesCreator shapesCreator;
	CHandler handler(shapesCreator, cin, cout, strstream);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!handler.HandleCommand(shapesCreator))
		{
			cout << "Unknown command!" << endl;
		}
	}

	cout << "Здесь!" << endl;

	vector<unique_ptr<CShape>> shapesArray = handler.GetShapesArray();
	GetShapeWithMinPerimetr(shapesArray);
	GetShapeWithMaxArea(shapesArray);

    return 0;
}

