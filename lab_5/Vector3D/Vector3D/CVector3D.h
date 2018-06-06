#pragma once

class CVector3D
{
public:
	CVector3D();
	CVector3D(double x0, double y0, double z0);

	double GetLength() const;
	void Normalize();

	CVector3D const operator -() const;
	CVector3D const operator +() const;
	
	CVector3D const operator +(CVector3D const& vector2) const;
	CVector3D const operator -(CVector3D const& vector2) const;
	
	CVector3D const operator *(double scalar) const;
	CVector3D const operator /(double scalar) const;

	CVector3D const operator +=(CVector3D const& vector2);
	CVector3D const operator -=(CVector3D const& vector2);
	CVector3D const operator *=(double scalar);
	CVector3D const operator /=(double scalar);

	bool operator ==(CVector3D const& vector2) const;
	bool operator !=(CVector3D const& vector2) const;

	double x, y, z;

private:
	double m_length;
};

ostream& operator <<(ostream& str, CVector3D vector);
istream& operator >>(istream& str, CVector3D vector);
double DotProduct(CVector3D const& vector1, CVector3D const& vector2);
CVector3D CrossProduct(CVector3D const& vector1, CVector3D const& vector2);
CVector3D Normalize(CVector3D const& vector);