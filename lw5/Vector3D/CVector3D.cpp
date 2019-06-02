#include "pch.h"
#include "CVector3D.h"
#include "ComparingTwoDouble.h"
#include <boost/algorithm/string.hpp>

using namespace std;

CVector3D::CVector3D()
	: m_x(0)
	, m_y(0)
	, m_z(0)
{
}

CVector3D::CVector3D(const double x, const double y, const double z)
	: m_x(x)
	, m_y(y)
	, m_z(z)
{
}

double CVector3D::GetLength() const
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
}

void CVector3D::Normalize()
{
	m_x = 1;
	m_y = 1;
	m_z = 1;
}

CVector3D const CVector3D::operator+(CVector3D const& vector2) const
{
	return CVector3D(m_x + vector2.m_x, m_y + vector2.m_y, m_z + vector2.m_z);
}

CVector3D const CVector3D::operator-(CVector3D const& vector2) const
{
	return CVector3D(m_x - vector2.m_x, m_y - vector2.m_y, m_z - vector2.m_z);
}

CVector3D const CVector3D::operator*(double scalar) const
{
	return CVector3D(m_x * scalar, m_y * scalar, m_z * scalar);
}

CVector3D const operator*(double scalar, CVector3D const& vector)
{
	return CVector3D(scalar * vector.m_x, scalar * vector.m_y, scalar * vector.m_z);
}

CVector3D const CVector3D::operator/(double scalar) const
{
	return CVector3D(m_x / scalar, m_y / scalar, m_z / scalar);
}

CVector3D& CVector3D::operator+=(CVector3D const& vector2)
{
	m_x += vector2.m_x;
	m_y += vector2.m_y;
	m_z += vector2.m_z;

	return *this;
}

CVector3D& CVector3D::operator-=(CVector3D const& vector2)
{
	m_x -= vector2.m_x;
	m_y -= vector2.m_y;
	m_z -= vector2.m_z;

	return *this;
}

CVector3D& CVector3D::operator*=(double scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	m_z *= scalar;

	return *this;
}

CVector3D& CVector3D::operator/=(double scalar)
{
	m_x /= scalar;
	m_y /= scalar;
	m_z /= scalar;

	return *this;
}

CVector3D const CVector3D::operator+() const
{
	return CVector3D(m_x, m_y, m_z);
}

CVector3D const CVector3D::operator-() const
{
	return CVector3D(-m_x, -m_y, -m_z);
}

bool CVector3D::operator==(CVector3D const& vector2) const
{
	return IsEequal(m_x, vector2.m_x) && IsEequal(m_y, vector2.m_y) && IsEequal(m_z, vector2.m_z);
}

bool CVector3D::operator!=(CVector3D const& vector2) const
{
	return !(IsEequal(m_x, vector2.m_x) && IsEequal(m_y, vector2.m_y) && IsEequal(m_z, vector2.m_z));
}

ostream& operator<<(ostream& output, CVector3D const& vector)
{
	output << vector.m_x << " " << vector.m_y << " " << vector.m_z << endl;

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
	return vector1.m_x * vector2.m_x + vector1.m_y * vector2.m_y + vector1.m_z * vector2.m_z;
}
