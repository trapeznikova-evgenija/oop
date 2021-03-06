#include "stdafx.h"
#include "../Vector3D/CVector3D.h"
#include "../Vector3D/Tools.h"
#include <Windows.h>

//сравнение double имеет смысл только с оговоркой на некоторую точность вычисления

TEST_CASE("CVector3D Tests")
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Create CVector3D" << endl;
	CVector3D vector3D(5, 8, 10);
	cout << "Check GetLength() method" << endl;
	CHECK(vector3D.GetLength() == 13.74772708486752);
	cout << "Check vector3D.Normalize()" << endl;

	vector3D.Normalize();
	CHECK(IsEqual(vector3D.x, 0.3636964837));
	vector3D.x = 5;
	vector3D.y = 8;
	vector3D.z = 10;
	cout << "Check unary operator -()" << endl;
	CVector3D negativeVector = vector3D.operator-();
	CHECK(negativeVector.x == -vector3D.x);
	CHECK(negativeVector.y == -vector3D.y);
	CHECK(negativeVector.z == -vector3D.z);

	cout << "Check unary operator +()" << endl;
	CVector3D thisVector = vector3D.operator+();
	CHECK(thisVector.x == vector3D.x);
	CHECK(thisVector.y == vector3D.y);
	CHECK(thisVector.z == vector3D.z);

	cout << "Check binary operator +()" << endl;
	CVector3D vector2(4, 6, 10);
	CVector3D sumResultVector;
	sumResultVector = vector3D + vector2;
	CHECK(sumResultVector.x == 9);
	CHECK(sumResultVector.y == 14);
	CHECK(sumResultVector.z == 20);

	cout << "Check binary operatop -()" << endl;
	CVector3D subResultVector;
	subResultVector = vector3D - vector2;
	CHECK(subResultVector.x == 1);
	CHECK(subResultVector.y == 2);
	CHECK(subResultVector.z == 0);

	cout << "Check binary operator *()" << endl;
	CVector3D mulResultVector;
	mulResultVector = vector3D * 2;
	CHECK(mulResultVector.x == 10);
	CHECK(mulResultVector.y == 16);
	CHECK(mulResultVector.z == 20);

	cout << "Check binary operator /()" << endl;
	CVector3D divResultVector1;
	divResultVector1 = vector3D / 2;
	CHECK(divResultVector1.x == 2.5);
	CHECK(divResultVector1.y == 4);
	CHECK(divResultVector1.z == 5);

	CVector3D divResultVector2;
	try
	{
		divResultVector2 = vector3D / 0;
	} catch (const invalid_argument& exception)
	{
		cout << "Exception " << exception.what() << endl;
	}

	cout << "Check operator +=" << endl;
	CVector3D addingResultVector(1, 1, 1);
	addingResultVector += vector3D;
	CHECK(addingResultVector.x == 6);
	CHECK(addingResultVector.y == 9);
	CHECK(addingResultVector.z == 11);

	cout << "Check operatop -=" << endl;
	CVector3D subtractionResultVector(20, 4, 19);
	subtractionResultVector -= vector3D;
	CHECK(subtractionResultVector.x == 15);
	CHECK(subtractionResultVector.y == -4);
	CHECK(subtractionResultVector.z == 9);

	cout << "Check operatop *=" << endl;
	CVector3D vector3(8, 2.4, 3);
	vector3 *= 3.7;
	CHECK(IsEqual(vector3.x, 29.6) == true);
	CHECK(IsEqual(vector3.y, 8.88) == true);
	CHECK(IsEqual(vector3.z, 11.1) == true);

	cout << "Check operatop /=" << endl;
	CVector3D vector4(10, 12, 3);
	try
	{
		vector4 /= 0;
	} catch (const invalid_argument& exception)
	{
		cout << "Exception: " << exception.what() << endl;
	}
	vector4 /= 0.5;
	CHECK(IsEqual(vector4.x, 20));
	CHECK(IsEqual(vector4.y, 24));
	CHECK(IsEqual(vector4.z, 6));

	cout << "Check operatop ==" << endl;
	CVector3D vector5(2.5, 3, 6.3);
	CVector3D vector6(2.5, 3, 6.3);
	bool result = vector5 == vector6;
	CHECK(result == true);

	cout << "Check operator !=" << endl;
	CVector3D vector7(2.6, 3, 6.3);
	result = vector7 != vector6;
	CHECK(result == true);
	CHECK(IsEqual(vector6.x, vector7.x) == false);
	CHECK(IsEqual(vector6.y, vector7.y) == true);
	CHECK(IsEqual(vector6.z, vector7.z) == true);

	cout << "Check operator << and >>" << endl;
	CVector3D vector8(3, 4, 6);

	cin >> vector8;
	cout << vector8;
	cout << vector7;

	cout << "Check DorProduct() function" << endl;
	CVector3D vector9(1, 2, -5);
	CVector3D vector10(4, 8, 1);

	CHECK(DotProduct(vector9, vector10) == 15);

	cout << "Check CrossProduct() function" << endl;
	CVector3D a(1, 2, 3);
	CVector3D b(2, 1, -2);
	CVector3D c(-7, 8, -3);
	CHECK(CrossProduct(a, b) == c);

	cout << "Check Normalize() function" << endl;
	CVector3D vector11(1, 2, 2);
	CVector3D resultUnitVector(0.333333, 0.666667, 0.666667);
	CHECK(Normalize(vector11) == resultUnitVector);


}