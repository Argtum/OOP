#include "pch.h"
#include "lw5/Vector3D/CVector3D.h"
#include "lw5/Vector3D/ComparingTwoDouble.h"

TEST_CASE("Set 3D vector, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);

	CHECK(vector.m_x == 1.2);
	CHECK(vector.m_y == 3.4);
	CHECK(vector.m_z == 5.6);
}

TEST_CASE("Set zero 3D vector, [CVector3D]")
{
	CVector3D vector;

	CHECK(IsEequal(vector.m_x, 0));
	CHECK(IsEequal(vector.m_y, 0));
	CHECK(IsEequal(vector.m_z, 0));
}

TEST_CASE("Addition of 2 3D vectors, [CVector3D]")
{
	CVector3D vector1(1.2, 3.4, 5.6);
	CVector3D vector2(9.8, 7.6, 4.3);
	CVector3D resultVector;

	resultVector = vector1.operator+(vector2);

	CHECK(resultVector.m_x == 11);
	CHECK(resultVector.m_y == 11);
	CHECK(resultVector.m_z == 9.9);
}

TEST_CASE("Subtraction of 2 3D vectors, [CVector3D]")
{
	CVector3D vector1(9.8, 7.6, 4.3);
	CVector3D vector2(1.2, 3.4, 5.6);
	CVector3D resultVector;

	resultVector = vector1 + vector2;

	CHECK(resultVector.m_x == 8.6);
	CHECK(resultVector.m_y == 4.2);
	CHECK(resultVector.m_z == -1.3);
}

TEST_CASE("3D vector multiplication by scalar, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);
	CVector3D resultVector;

	resultVector = vector * 3.3;

	CHECK(IsEequal(vector.m_x, 3.96));
	CHECK(IsEequal(vector.m_y, 11.22));
	CHECK(IsEequal(vector.m_z, 18.48));
}

TEST_CASE("Scalar multiply by 3D vector, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);
	CVector3D resultVector;

	resultVector = -2.2 * vector;

	CHECK(IsEequal(vector.m_x, -2.64));
	CHECK(IsEequal(vector.m_y, -7.48));
	CHECK(IsEequal(vector.m_z, -12.32));
}
