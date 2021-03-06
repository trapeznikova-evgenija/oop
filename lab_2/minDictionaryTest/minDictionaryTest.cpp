// minDictionaryTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../minDictionary/minDictionary.h"

TEST_CASE("NeedSave Function Test")
{
	CHECK(NeedSave("l") == false);
	CHECK(NeedSave("y") == true);
	CHECK(NeedSave("Y") == true);
	CHECK(NeedSave("Mald") == false);
};

string strOne = "CaT";
string strOneResult = "cat";

string strTwo = "MaMiNO";
string strTwoResult = "mamino";

TEST_CASE("GetLowerCase Function Test")
{
	CHECK(GetLowerCase(strOne) == strOneResult);
	CHECK(GetLowerCase(strTwo) == strTwoResult);
}
