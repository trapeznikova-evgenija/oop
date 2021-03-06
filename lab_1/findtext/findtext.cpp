// findtext.cpp: определяет точку входа для консольного приложения.

// Условия задачи:

// Программа findtext.exe, выполняет поиск указанной строки в файле.
// Если искомая строка найдена возвращается 0 и выводятся номера всех строк (по одному номеру в каждой строке), содержащих искомую строку.
// В противном случае программа возвращает 1 и выводит в стандартный поток вывода «Text not found».
// При осуществлении поиска регистр символов имеет значение.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != 3)
	{
		cout << "Invalid number of arguments. Input Example : findtext.exe <file name> <text to search>" << endl;
		return 1;
	}
	
	ifstream fIn(argv[1]);
	ofstream fOut("output.txt");

	if (!fIn.is_open())
	{
		cout << "Сan not open file" << argv[1] << endl;
		return 1;
	}

	int lineNumber = 1;	
	string searchString = argv[2];
	
	bool foundLineInText = false;
	string currentLine; 
	int positionNumber;
	
	while (!fIn.eof())
	{
		getline(fIn, currentLine);
		
		positionNumber = currentLine.find(searchString);

		if (positionNumber >= 0)
		{
			fOut << lineNumber << endl;
			foundLineInText = true;
		}
		
		lineNumber++;
	}

	if (!foundLineInText)
	{
		fOut << "Text not found";
		return 1;
	}

	system("pause");

    return 0;
}

