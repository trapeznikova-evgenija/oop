// Shapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CHandler.h"
#include "CShapesCreator.h"

using namespace std;

int main(int argc, char* argv[])
{
	string commandLine = "";
	stringstream strstream;

	CShapesCreator shapesCreator;
	CHandler handler(shapesCreator, cin, cout, strstream);

	while (!cin.eof() && !cin.fail())
	{
	  cout << "> ";
	  if (!handler.HandleCommand(shapesCreator) && !cin.eof())
	  {
		cout << "Unknown command!" << endl;
	  }
	}

	cout << handler.GetShapeWithMinPerimetr() << endl;
	cout << handler.GetShapeWithMaxArea() << endl;

    return 0;
}

