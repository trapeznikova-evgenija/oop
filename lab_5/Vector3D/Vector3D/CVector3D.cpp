#include "stdafx.h"
#include "CVector3D.h"
#include "Tools.h"

CVector3D::CVector3D()
{
	x = 0;
	y = 0;
	z = 0;
	m_length = 0;
}


CVector3D::CVector3D(double x0, double y0, double z0)
	:x(x0), y(y0), z(z0)
{
	m_length = sqrt(x * x + y * y + z * z);
}	

double CVector3D::GetLength() const 
{
	return m_length;
}

void CVector3D::Normalize()
{
	double inversionLength = (1 / m_length);
	x *= inversionLength;
	y *= inversionLength;
	z *= inversionLength;
}

CVector3D const CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}

CVector3D const CVector3D::operator+() const
{
	return *this;
}

CVector3D const CVector3D::operator +(CVector3D const& vector2) const
{
	return CVector3D(x + vector2.x, y + vector2.y, z + vector2.z);
}

CVector3D const CVector3D::operator -(CVector3D const& vector2) const
{
	return CVector3D(x - vector2.x, y - vector2.y, z - vector2.z);
}

CVector3D const CVector3D::operator *(double scalar) const
{
	return CVector3D(scalar * x, scalar * y, scalar * z);
}

CVector3D const CVector3D::operator /(double scalar) const
{
	if (scalar == 0)
	{
		throw invalid_argument("Cannot be divided by 0");
	}
	return CVector3D(x / scalar, y / scalar, z / scalar);
}

CVector3D const CVector3D::operator +=(CVector3D const& vector2) 
{
	x += vector2.x;
	y += vector2.y;
	z += vector2.z;

	return *this;
}

CVector3D const CVector3D::operator -=(CVector3D const& vector2)
{
	x -= vector2.x;
	y -= vector2.y;
	z -= vector2.z;

	return *this;
}

CVector3D const CVector3D::operator *=(double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;

	return *this;
}

CVector3D const CVector3D::operator /=(double scalar)
{
	if (scalar == 0)
	{
		throw invalid_argument("Cannot be divided by 0");
	}

	x /= scalar;
	y /= scalar;
	z /= scalar;

	return *this;
}

bool CVector3D::operator ==(CVector3D const& vector2) const
{
	return IsEqual(x, vector2.x) && IsEqual(y, vector2.y) && IsEqual(z, vector2.z);
}

bool CVector3D::operator !=(CVector3D const& vector2) const
{
	return IsEqual(x, vector2.x) || IsEqual(y, vector2.y) || IsEqual(z, vector2.z);
}

ostream& operator <<(ostream& str, CVector3D vector)
{
	str << vector.x << ", " << vector.y << ", " << vector.z << endl;
	return str;
}

istream& operator >>(istream& str, CVector3D vector)
{
	str >> vector.x >> vector.y >> vector.z;
	return str;
}