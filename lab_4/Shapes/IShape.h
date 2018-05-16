#pragma once
#include <string>
using namespace std;

class IShape
{
public:
	IShape(const string & outlineColor);
	~IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual string ToString() const = 0;

	string GetOutlineColor() const;

private:
	string m_outlineColor;
};
