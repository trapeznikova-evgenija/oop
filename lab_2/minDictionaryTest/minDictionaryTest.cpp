// minDictionaryTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../minDictionary/minDictionary.h"


MapStrings mapTest;
string fileName = "dictionary.txt";

string stringOne = "CaT";

TEST_CASE("FillOutMapFromFile Function Test")
{
	/*size_t mapStartSize = mapTest.size();
	mapTest = FillOutMapFromFile(fileName, mapTest);
	size_t mapAfterSize = mapTest.size();
	CHECK(mapStartSize < mapAfterSize); */
};


TEST_CASE("GetLowerCase Function Test")
{
}
