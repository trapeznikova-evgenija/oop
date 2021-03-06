#include "stdafx.h"
#include "primeGenerator.h"

set<int> FillSetWithPrimeNumbers(vector<bool> &isPrime)
{
	set<int> primeNumbersSet;
	for (int i = 2; i < isPrime.size(); ++i)
	{
		if (isPrime[i])
		{
			primeNumbersSet.insert(i);
		}
	}
	return primeNumbersSet;
}

void PrintSet(set<int> primeNumbers)
{
	auto PrintNumber = [](int number)
	{
		cout << number << " ";
	};
	for_each(primeNumbers.begin(), primeNumbers.end(), PrintNumber);
}

int GetAmountPrimeNumbers(set<int> PrimeNumbers)
{
	return static_cast<int>(PrimeNumbers.size());
}

set<int> GeneratePrimeNumberSet(int upperBound)
{
	vector<bool> isPrime(upperBound, true);
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i < upperBound; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < upperBound; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	set<int> primeNumbersSet = FillSetWithPrimeNumbers(isPrime);

	return primeNumbersSet;
}
