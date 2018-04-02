#pragma once
#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include <Windows.h>
#include <algorithm>

using namespace std;

set<int> GeneratePrimeNumberSet(int upperBound);
void PrintSet(set<int> primeNumbers);
int GetAmountPrimeNumbers(set<int> PrimeNumbers);