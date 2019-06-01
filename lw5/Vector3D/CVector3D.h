#pragma once

class CVector3D
{
public:
	CVector3D();
	CVector3D(const double x, const double y, const double z);
	double GetLength() const;
	void Normalize();

	CVector3D const operator+(CVector3D const& vector2) const;
	CVector3D const operator-(CVector3D const& vector2) const;
	CVector3D const operator*(double scalar) const;
	CVector3D const operator/(double scalar) const;
	CVector3D& operator+=(CVector3D const& vector2);
	CVector3D& operator-=(CVector3D const& vector2);
	CVector3D& operator*=(double scalar);
	CVector3D& operator/=(double scalar);
	CVector3D const operator+() const;
	CVector3D const operator-() const;
	bool operator==(CVector3D const& vector2) const;
	bool operator!=(CVector3D const& vector2) const;

	double m_x, m_y, m_z;
};

CVector3D const operator*(double scalar, CVector3D const& vector);
std::ostream& operator<<(std::ostream& output, CVector3D const& vector);
std::istream& operator>>(std::istream& input, CVector3D& vector);
