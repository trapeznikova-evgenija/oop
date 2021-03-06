// Нахождение обратной матрицы 
// Коэффициенты результирующей матрицы выводятся в стандартный поток вывода
// Коэффициенты обратной матрицы выводить с точностью до 3 знаков после запятой 


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;
const unsigned int MATRIX_SIZE = 3;

struct Matrix
{
	double values[MATRIX_SIZE][MATRIX_SIZE];
};

void ReadFileIntoArray(ifstream &fIn, Matrix &matrix)
{
	for (int j = 0; j < MATRIX_SIZE; j++)
	{
		for (int i = 0; i < MATRIX_SIZE; i++)
		{
			fIn >> matrix.values[i][j];
			cout << matrix.values[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl; 
}

void PrintMatrixIntoFile(Matrix &const matrix, ofstream &fOut)
{
	fOut << fixed;
	fOut.precision(3);

	for (int j = 0; j < MATRIX_SIZE; j++)
	{
		for (int i = 0; i < MATRIX_SIZE; i++)
		{
			fOut << matrix.values[i][j];

			if (!(i == MATRIX_SIZE - 1 and j == MATRIX_SIZE - 1))
			{
				fOut << " ";
			}
		}
		if (j != MATRIX_SIZE - 1)
		{
			fOut << endl;
		}	
	}
}

double CalculateDeterminant(Matrix &matrix)
{
	double determinant = matrix.values[0][0] * matrix.values[1][1] * matrix.values[2][2] +
		matrix.values[2][0] * matrix.values[0][1] * matrix.values[1][2] +
		matrix.values[1][0] * matrix.values[2][1] * matrix.values[0][2] -
		matrix.values[2][0] * matrix.values[1][1] * matrix.values[0][2] -
		matrix.values[0][0] * matrix.values[2][1] * matrix.values[1][2] -
		matrix.values[1][0] * matrix.values[0][1] * matrix.values[2][2];

	return determinant;
}

double CalculateTwoToTwoMatrixDeterminant(vector<double> matrix)
{
	double determinant = matrix[0] * matrix[3] - matrix[2] * matrix[1];
	return determinant;
}

vector<double> CreateTwoToTwoMatrix(Matrix &matrixArray, int i, int j)
{
	vector <double> twoMatrix;

	for (int col = 0; col < MATRIX_SIZE; col++)
	{
		for (int row = 0; row < MATRIX_SIZE; row++)
		{
			if (col != j and row != i)
			{
				twoMatrix.push_back(matrixArray.values[row][col]);
			}
		}
	}

	return twoMatrix;
}

Matrix FindMinorMatrix(Matrix &matrixArray)
{
	Matrix minorMatrix;
	
	for (int j = 0; j < MATRIX_SIZE; j++)
	{
		for (int i = 0; i < MATRIX_SIZE; i++)
		{
			vector<double> twoMatrix = CreateTwoToTwoMatrix(matrixArray, i, j);
			minorMatrix.values[i][j] = CalculateTwoToTwoMatrixDeterminant(twoMatrix);
		}
	}

	return minorMatrix;
}

void FindAlgebraicComplementsMatrix(Matrix &matrix)
{
	for (int j = 0; j < MATRIX_SIZE; j++)
	{
		for (int i = 0; i < MATRIX_SIZE; i++)
		{
			matrix.values[i][j] = pow(-1, i + j) * matrix.values[i][j];
		}
	}
}

Matrix CreateTransposeMatrix(Matrix &matrix)
{
	Matrix transposeMatrix;

	for (int j = 0; j < MATRIX_SIZE; j++)
	{
		for (int i = 0; i < MATRIX_SIZE; i++)
		{
			transposeMatrix.values[j][i] = matrix.values[i][j];
		}
	}
	
	return transposeMatrix;
}

Matrix CalculateInverseMatrix(Matrix &matrix, double determinant)
{
	Matrix inverseMatrix;

	for (int j = 0; j < MATRIX_SIZE; j++)
	{
		for (int i = 0; i < MATRIX_SIZE; i++)
		{
			inverseMatrix.values[i][j] = matrix.values[i][j] / determinant;
		}
	}

	return inverseMatrix;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != 2)
	{
		cout << "Input Error. You must enter: invert.exe <matrix.txt>" << endl;
		return 1;
	}

	ifstream fIn(argv[1]);
	ofstream fOut("output.txt");

	if (!fIn.is_open())
	{
		cout << "Сan not open file" << argv[1] << endl;
		return 1;
	}

	Matrix matrixArray;

	ReadFileIntoArray(fIn, matrixArray);
	double determinant = CalculateDeterminant(matrixArray);
	
	if (determinant == 0)
	{
		fOut << "The determinant of the matrix is 0. There is no inverse matrix!";
		return 0;
	}

	Matrix minorMatrix = FindMinorMatrix(matrixArray);
	FindAlgebraicComplementsMatrix(minorMatrix);
	Matrix transposeMatrix = CreateTransposeMatrix(minorMatrix);
    Matrix inverseMatrix = CalculateInverseMatrix(transposeMatrix, determinant);
	PrintMatrixIntoFile(inverseMatrix, fOut);

	return 0;
}

