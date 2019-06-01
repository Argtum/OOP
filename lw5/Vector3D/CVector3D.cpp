#include "pch.h"
#include "CVector3D.h"

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

CVector3D const CVector3D::operator+(CVector3D const& vector2) const
{
	return CVector3D(m_x + vector2.m_x, m_y + vector2.m_y, m_z + vector2.m_z);
}

CVector3D const CVector3D::operator-(CVector3D const& vector2) const
{
	return CVector3D(m_x - vector2.m_x, m_y - vector2.m_y, m_z - vector2.m_z);
}
