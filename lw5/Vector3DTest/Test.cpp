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
