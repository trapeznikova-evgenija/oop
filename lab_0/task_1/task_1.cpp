// task_1.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h";
#include <iostream>;
#include <cstdlib>;

using namespace std;

int main()
{
	const int maxValue = 100;
	const int minValue = 2;

	for (int i = maxValue; i >= minValue; i -= 2)
	{
		cout << i;

		if (i != minValue)
		{
			cout << ", ";
		}
	}
	cout << endl;
	system("pause");

    return 0;
}

