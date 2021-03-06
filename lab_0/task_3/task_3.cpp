// task_3.cpp: определяет точку входа для консольного приложения.

//вывести ряд Фибоначчи от 0 до N
//при условиях, что N - целое число больше 0 и меньше INT_MAX

#include "stdafx.h"
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void CalculateFibonacchi(const int &upperBound)
{
	int counterNum = 1;
	int prevValue = 0; 
	int currValue = 1;
	int nextValue = prevValue + currValue;

	while (nextValue <= upperBound)
	{
		if (counterNum % 5 == 0)
		{
			cout << prevValue << endl;
		} else
		{
			cout << prevValue << ", ";
		}
		nextValue = currValue + prevValue;
		prevValue = currValue;
		currValue = nextValue;

		counterNum++;
	}

	cout << prevValue << endl;
}

int StringToDigit(char* arg, bool &isInteger)
{
	string number = arg;

	for (int i = 0; i < number.length(); i++)
	{
		if ((number[i] == ',') || (number[i] == '.'))
		{
			isInteger = false;
		}
	}

	int result = atoi(arg);
	return result;
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	const int ERROR_AMOUNT_ARG = 1;
	const int ERROR_RANGE = 2;
	const int ERROR_NOT_INT = 3;

	if (argc < 2)
	{
		cout << "Программа выводит числа Фибоначчи от 0 до N. При запуске программы введите N." << endl;
		system("pause");
		return ERROR_AMOUNT_ARG;
	}

	bool isInteger = true;
	auto upperBound = StringToDigit(argv[1], isInteger);

	if (!isInteger)
	{
		cout << "Вы ввели не целое число. Ряд Фибоначчи оперирует только целыми числами." << endl;
		system("pause");
		return ERROR_NOT_INT;
	}

	if (upperBound >= INT_MAX || upperBound < 1)
	{
		cout << "Вы ввели недопустимую верхнюю границу." << endl;
		system("pause");
		return ERROR_RANGE;
	}
	
	cout << "Ряд Фибоначчи: " << endl;
	CalculateFibonacchi(upperBound);

	system("pause");
    return 0;
}

