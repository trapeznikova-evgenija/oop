// task_2.cpp: определяет точку входа для консольного приложения.
//Программа, выводящая в порядке возрастания все целые числа диапазона от 1 до N, делящиеся без остатка на сумму своих цифр.

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

const int ERROR_RANGE = 2;
const int ERROR_AMOUNT_ARG = 1;

using namespace std;

int StringToDigit(char* arg)
{
	int result = atoi(arg);
	return result;
};

int SumDigits(int i)
{
	int sum = 0;

	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc < 2)
	{
		cout << "Программа выводит в порядке возрастания числа от 1 до N, делящиеся без остатка на сумму своих цифр." << endl;
		system("pause");
		return ERROR_AMOUNT_ARG;
	};

	int upperBound = StringToDigit(argv[1]);

	if (upperBound < 1 || upperBound >= INT_MAX)
	{
		cout << "Вы ввели недопустимую верхнюю границу." << endl;
		system("pause");
		return ERROR_RANGE;
	}

	for (int num = 1; num <= upperBound; num++)
	{
		if (num % SumDigits(num) == 0)
		{
			cout << num << " ";
		}
	}

	system("pause");
    return 0;
}

