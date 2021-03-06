// Программа считывает из файла числа с плавающей запятой(разделены пробелами) в <vector>
// Вариант 2: Каждый элемент вектора умножается на минимальный элемент исходного вектора 
// Вектор выводится в output.txt 


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void ReadArrayFromFile(vector<float> &sequence, ifstream &fIn)
{
	while (!fIn.eof())
	{
		float number;
		fIn >> number;
		sequence.push_back(number);
	}
}

void EditSequence(vector<float> &sequence)
{
	sort(sequence.begin(), sequence.end());
	float minElement = sequence[0];
	
	for (auto & floatElem: sequence)
	{
		floatElem = floatElem * minElement;
	}
};

void PrintVector(vector<float> &sequence, ofstream &fOut)
{
	int vectorSize = sequence.size();
	float lastElement = sequence[vectorSize-1];

	auto PrintElement = [&fOut, lastElement](float element)
	{
		fOut << element;
		if (element != lastElement)
		{
			fOut << ' ';
		}
	};

	for_each(sequence.begin(), sequence.end(), PrintElement);
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid number of arguments. Input Example : vector.exe <file name>" << endl;
		return 1;
	}

	ifstream fIn(argv[1]);
	ofstream fOut("output.txt");

	if (!fIn.is_open())
	{
		cout << "Сan not open file" << argv[1] << endl;
		return 1;
	}

	vector<float> sequence;

	ReadArrayFromFile(sequence, fIn);
	EditSequence(sequence);
	PrintVector(sequence, fOut);

	return 0;
}