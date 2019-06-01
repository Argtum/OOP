#include "pch.h"
#include "lw5/Vector3D/CVector3D.h"
#include "lw5/Vector3D/ComparingTwoDouble.h"

TEST_CASE("Set 3D vector, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);

	CHECK(IsEequal(vector.m_x, 1.2));
	CHECK(IsEequal(vector.m_y, 3.4));
	CHECK(IsEequal(vector.m_z, 5.6));
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

	resultVector = vector1 + vector2;

	CHECK(IsEequal(resultVector.m_x, 11));
	CHECK(IsEequal(resultVector.m_y, 11));
	CHECK(IsEequal(resultVector.m_z, 9.9));
}

TEST_CASE("Subtraction of 2 3D vectors, [CVector3D]")
{
	CVector3D vector1(1.2, 3.4, 5.6);
	CVector3D vector2(9.8, 7.6, 4.3);
	CVector3D resultVector;

	resultVector = vector2 - vector1;

	CHECK(IsEequal(resultVector.m_x, 8.6));
	CHECK(IsEequal(resultVector.m_y, 4.2));
	CHECK(IsEequal(resultVector.m_z, -1.3));
}

TEST_CASE("3D vector multiplication by scalar, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);
	CVector3D resultVector;

	resultVector = vector * 3.3;

	CHECK(IsEequal(resultVector.m_x, 3.96));
	CHECK(IsEequal(resultVector.m_y, 11.22));
	CHECK(IsEequal(resultVector.m_z, 18.48));
}

TEST_CASE("Scalar multiply by 3D vector, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);
	CVector3D resultVector;

	resultVector = -2.2 * vector;

	CHECK(IsEequal(resultVector.m_x, -2.64));
	CHECK(IsEequal(resultVector.m_y, -7.48));
	CHECK(IsEequal(resultVector.m_z, -12.32));
}

TEST_CASE("3D vector division by scalar, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);
	CVector3D resultVector;

	resultVector = vector / 2;

	CHECK(IsEequal(resultVector.m_x, 0.6));
	CHECK(IsEequal(resultVector.m_y, 1.7));
	CHECK(IsEequal(resultVector.m_z, 2.8));
}

TEST_CASE("Increasing the length of the 3D vector, [CVector3D]")
{
	CVector3D vector1(1.2, 3.4, 5.6);
	CVector3D vector2(9.8, 7.6, 4.3);

	vector1 += vector2;

	CHECK(IsEequal(vector1.m_x, 11));
	CHECK(IsEequal(vector1.m_y, 11));
	CHECK(IsEequal(vector1.m_z, 9.9));
}

TEST_CASE("3D vector length reduction, [CVector3D]")
{
	CVector3D vector1(1.2, 3.4, 5.6);
	CVector3D vector2(9.8, 7.6, 4.3);

	vector2 -= vector1;

	CHECK(IsEequal(vector2.m_x, 8.6));
	CHECK(IsEequal(vector2.m_y, 4.2));
	CHECK(IsEequal(vector2.m_z, -1.3));
}

TEST_CASE("Short form of 3D vector multiplication by scalar, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);

	vector *= 3.3;

	CHECK(IsEequal(vector.m_x, 3.96));
	CHECK(IsEequal(vector.m_y, 11.22));
	CHECK(IsEequal(vector.m_z, 18.48));
}

TEST_CASE("Short form of 3D vector division by scalar, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);

	vector /= 2;

	CHECK(IsEequal(vector.m_x, 0.6));
	CHECK(IsEequal(vector.m_y, 1.7));
	CHECK(IsEequal(vector.m_z, 2.8));
}

TEST_CASE("Inversion 3D vector, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);
	CVector3D resultVector;

	resultVector = -vector;

	CHECK(IsEequal(resultVector.m_x, -1.2));
	CHECK(IsEequal(resultVector.m_y, -3.4));
	CHECK(IsEequal(resultVector.m_z, -5.6));
}

TEST_CASE("Unary 3D vector addition, [CVector3D]")
{
	CVector3D vector(1.2, 3.4, 5.6);
	CVector3D resultVector;

	resultVector = +vector;

	CHECK(IsEequal(resultVector.m_x, 1.2));
	CHECK(IsEequal(resultVector.m_y, 3.4));
	CHECK(IsEequal(resultVector.m_z, 5.6));
}

TEST_CASE("Comparing two 3D vectors, [CVector3D]")
{
	CVector3D vector1(1.2, 3.4, 5.6);
	CVector3D vector2(1.2, 3.4, 5.6);
	CVector3D vector3(9.8, 7.6, 4.3);

	CHECK(vector1 == vector2);
	CHECK(!(vector1 == vector3));
}

TEST_CASE("Two 3D vectors are not equal to each other, [CVector3D]")
{
	CVector3D vector1(1.2, 3.4, 5.6);
	CVector3D vector2(1.2, 3.4, 5.6);
	CVector3D vector3(9.8, 7.6, 4.3);

	CHECK(vector1 != vector3);
	CHECK(!(vector1 != vector2));
}
