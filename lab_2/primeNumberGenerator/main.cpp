// primeNumberGenerator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "primeGenerator.h"

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	if (argc != 2)
	{
		cout << "Неправильный ввод. Пример: <primeNumberGenerator.exe> <upperBound>";
	}

	int upperBound = atoi(argv[1]);
	GeneratePrimeNumberSet(upperBound);
	//PrintSet(GeneratePrimeNumberSet(upperBound));

	return 0;
}

