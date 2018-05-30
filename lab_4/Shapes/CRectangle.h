#include "CSolidShape.h"

class CRectangle: public CSolidShape
{
public:
	CRectangle(const CPoint & leftTop, const double & width, const double & height, string & outlineColor, string & fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	double m_width;
	double m_height;

	CPoint m_leftTop;
	CPoint m_rightBottom;
};
