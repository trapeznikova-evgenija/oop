// primeNumberGeneratorTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../primeNumberGenerator/primeGenerator.h"

int oneUpperBound = 10;
int twoUpperBount = 100;
int treeUpperBound = 100000000;

TEST_CASE("GetAmountPrimeNumbers Function")
{
	set<int> oneSet = GeneratePrimeNumberSet(oneUpperBound);
	CHECK(GetAmountPrimeNumbers(oneSet) == 4);

	set<int> twoSet = GeneratePrimeNumberSet(twoUpperBount);
	CHECK(GetAmountPrimeNumbers(twoSet) == 25);

	set<int> treeSet = GeneratePrimeNumberSet(treeUpperBound);
	CHECK(GetAmountPrimeNumbers(treeSet) == 5761455);
}