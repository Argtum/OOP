#include "pch.h"
#include "CVector3D.h"
#include "ComparingTwoDouble.h"
#include <boost/algorithm/string.hpp>

using namespace std;

CVector3D::CVector3D()
	: x(0)
	, y(0)
	, z(0)
{
}

CVector3D::CVector3D(const double x, const double y, const double z)
	: x(x)
	, y(y)
	, z(z)
{
}

double CVector3D::GetLength() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void CVector3D::Normalize()
{
	double length = GetLength();

	x = x / length;
	y = y / length;
	z = z / length;
}

CVector3D const CVector3D::operator+(CVector3D const& vector2) const
{
	return CVector3D(x + vector2.x, y + vector2.y, z + vector2.z);
}

CVector3D const CVector3D::operator-(CVector3D const& vector2) const
{
	return CVector3D(x - vector2.x, y - vector2.y, z - vector2.z);
}

CVector3D const CVector3D::operator*(double scalar) const
{
	return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D const operator*(double scalar, CVector3D const& vector)
{
	return CVector3D(scalar * vector.x, scalar * vector.y, scalar * vector.z);
}

CVector3D const CVector3D::operator/(double scalar) const
{
	return CVector3D(x / scalar, y / scalar, z / scalar);
}

CVector3D& CVector3D::operator+=(CVector3D const& vector2)
{
	x += vector2.x;
	y += vector2.y;
	z += vector2.z;

	return *this;
}

CVector3D& CVector3D::operator-=(CVector3D const& vector2)
{
	x -= vector2.x;
	y -= vector2.y;
	z -= vector2.z;

	return *this;
}

CVector3D& CVector3D::operator*=(double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;

	return *this;
}

CVector3D& CVector3D::operator/=(double scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;

	return *this;
}

CVector3D const CVector3D::operator+() const
{
	return CVector3D(x, y, z);
}

CVector3D const CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}

bool CVector3D::operator==(CVector3D const& vector2) const
{
	return IsEqual(x, vector2.x) && IsEqual(y, vector2.y) && IsEqual(z, vector2.z);
}

bool CVector3D::operator!=(CVector3D const& vector2) const
{
	return !(IsEqual(x, vector2.x) && IsEqual(y, vector2.y) && IsEqual(z, vector2.z));
}

ostream& operator<<(ostream& output, CVector3D const& vector)
{
	output << vector.x << " " << vector.y << " " << vector.z << endl;

	return output;
}

istream& operator>>(istream& input, CVector3D& vector)
{
	double x, y, z;
	if ((input >> x) && (input >> y) && (input >> z))
	{
		vector = CVector3D(x, y, z);
	}
	else
	{
		input.setstate(ios_base::failbit | input.rdstate());
	}
	return input;
}

double const DotProduct(CVector3D const& vector1, CVector3D const& vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

CVector3D const CrossProduct(CVector3D const& vector1, CVector3D const& vector2)
{
	return CVector3D(vector1.y * vector2.z - vector1.z * vector2.y,
		(vector1.x * vector2.z - vector1.z * vector2.x) * -1,
		vector1.x * vector2.y - vector1.y * vector2.x);
}

CVector3D const Normalize(CVector3D const& vector)
{
	double length = vector.GetLength();

	return CVector3D(vector.x / length, vector.y / length, vector.z / length);
}
