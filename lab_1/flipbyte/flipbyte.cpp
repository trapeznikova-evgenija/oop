// flipbyte.cpp: определяет точку входа для консольного приложения.
// Программа выполняет изменение порядка следования двоичных битов в одном байте
// На входе - целое число в десятичной системе счисления диапазона 0..255
// Выдавать сообщения об ошибке при передаче не числа и числа не из валидного диапазона

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int StringToDigit(char* arg)
{
	int result = atoi(arg);
	return result;
}

bool IsNumber(string n)
{
	for (int i = 0; i < n.length(); i++)
	{
		if (!(n[i] >= '0' and n[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}

bool IncludeInRange(int number)
{
	if (number >= 0 and number <= 255)
	{
		return true;
	}
	return false;
}

uint8_t Rotate(uint8_t &number)
{
	const uint8_t mask = 128;
	uint8_t result = 0;

	for (int i = 0; i < 8; i++)
	{
		result = result >> 1;
		result |= mask & number;
		number = number << 1;
	}
	return result;	
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != 2)
	{
		cout << "Input Error. You must enter: flipbyte.exe < input byte >" << endl;
		return 1;
	}
	
	ofstream fOut("output.txt");

	if (!fOut.is_open())
	{
		cout << "Сan not open file" << endl;
		return 1;
	}

	string inputString = argv[1];

	//проверка входного параметра на число
	if (!IsNumber(inputString))
	{
		cout << "<input byte> can not contain characters " << endl;
		return 1;
	}
	
	int number = StringToDigit(argv[1]);

	//проверка вхождения числа в диапазон 0..255
	bool isValideNumber = IncludeInRange(number);

	if (!isValideNumber)
	{
		cout << "Your number is not in the range 0..255" << endl;
		return 1;
	}
	
	uint8_t singleByteNumber = number;

	//переворачивание бита числа
    int resultNumber = Rotate(singleByteNumber);
	
	fOut << resultNumber;

    return 0;
}

