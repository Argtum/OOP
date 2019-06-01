#pragma once
class CVector3D
{
public:
	CVector3D();
	CVector3D(const double x, const double y, const double z);
	//double GetLength() const;
	//void Normalize();

	CVector3D const operator+(CVector3D const& vector2) const;
	CVector3D const operator-(CVector3D const& vector2) const;
	CVector3D const operator*(double scalar) const;

	double m_x, m_y, m_z;
};

CVector3D const operator*(double scalar, CVector3D const& vector);
