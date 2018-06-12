#pragma once
#include <string>
using namespace std;

class IShape
{
public:
	virtual ~IShape() = default;

	IShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual string ToString() const = 0;
	virtual string GetOutlineColor() const = 0;

private:
	string m_outlineColor;
};
