#include "pch.h"
#include "lw5/Vector3D/CVector3D.h"
#include "lw5/Vector3D/ComparingTwoDouble.h"

using namespace std;

TEST_CASE("Vector operations")
{
	CVector3D vector1(1.2, 3.4, 5.6);
	CVector3D vector2(9.8, 7.6, 4.3);
	CVector3D vector3;
	CVector3D resultVector;

	WHEN("Set 3D vector, [CVector3D]")
	{
		THEN("Have a vector")
		{
			CHECK(IsEequal(vector1.m_x, 1.2));
			CHECK(IsEequal(vector1.m_y, 3.4));
			CHECK(IsEequal(vector1.m_z, 5.6));
		}
	}

	WHEN("Set empty 3D vector, [CVector3D]")
	{
		THEN("Have a zero vector")
		{
			CHECK(IsEequal(vector3.m_x, 0));
			CHECK(IsEequal(vector3.m_y, 0));
			CHECK(IsEequal(vector3.m_z, 0));
		}
	}

	WHEN("Addition of 2 3D vectors, [CVector3D]")
	{
		resultVector = vector1 + vector2;

		THEN("Have the resulting vector")
		{
			CHECK(IsEequal(resultVector.m_x, 11));
			CHECK(IsEequal(resultVector.m_y, 11));
			CHECK(IsEequal(resultVector.m_z, 9.9));
		}
	}

	WHEN("Subtraction of 2 3D vectors, [CVector3D]")
	{
		resultVector = vector2 - vector1;

		THEN("Have the resulting vector")
		{
			CHECK(IsEequal(resultVector.m_x, 8.6));
			CHECK(IsEequal(resultVector.m_y, 4.2));
			CHECK(IsEequal(resultVector.m_z, -1.3));
		}
	}

	WHEN("3D vector multiplication by scalar, [CVector3D]")
	{
		resultVector = vector1 * 3.3;

		THEN("Have the resulting vector")
		{
			CHECK(IsEequal(resultVector.m_x, 3.96));
			CHECK(IsEequal(resultVector.m_y, 11.22));
			CHECK(IsEequal(resultVector.m_z, 18.48));
		}
	}

	WHEN("Scalar multiply by 3D vector, [CVector3D]")
	{
		resultVector = -2.2 * vector1;

		THEN("Have the resulting vector")
		{
			CHECK(IsEequal(resultVector.m_x, -2.64));
			CHECK(IsEequal(resultVector.m_y, -7.48));
			CHECK(IsEequal(resultVector.m_z, -12.32));
		}
	}

	WHEN("3D vector division by scalar, [CVector3D]")
	{
		resultVector = vector1 / 2;

		THEN("Have the resulting vector")
		{
			CHECK(IsEequal(resultVector.m_x, 0.6));
			CHECK(IsEequal(resultVector.m_y, 1.7));
			CHECK(IsEequal(resultVector.m_z, 2.8));
		}
	}

	WHEN("Increasing the length of the 3D vector, [CVector3D]")
	{
		vector1 += vector2;

		THEN("Have a vector")
		{
			CHECK(IsEequal(vector1.m_x, 11));
			CHECK(IsEequal(vector1.m_y, 11));
			CHECK(IsEequal(vector1.m_z, 9.9));
		}
	}

	WHEN("3D vector length reduction, [CVector3D]")
	{
		vector2 -= vector1;

		THEN("Have a vector")
		{
			CHECK(IsEequal(vector2.m_x, 8.6));
			CHECK(IsEequal(vector2.m_y, 4.2));
			CHECK(IsEequal(vector2.m_z, -1.3));
		}
	}

	WHEN("Short form of 3D vector multiplication by scalar, [CVector3D]")
	{
		vector1 *= 3.3;

		THEN("Have a vector")
		{
			CHECK(IsEequal(vector1.m_x, 3.96));
			CHECK(IsEequal(vector1.m_y, 11.22));
			CHECK(IsEequal(vector1.m_z, 18.48));
		}
	}

	WHEN("Short form of 3D vector division by scalar, [CVector3D]")
	{
		vector1 /= 2;

		THEN("Have a vector")
		{
			CHECK(IsEequal(vector1.m_x, 0.6));
			CHECK(IsEequal(vector1.m_y, 1.7));
			CHECK(IsEequal(vector1.m_z, 2.8));
		}
	}

	WHEN("Inversion 3D vector")
	{
		resultVector = -vector1;

		THEN("Have inverted coordinates")
		{
			CHECK(IsEequal(resultVector.m_x, -1.2));
			CHECK(IsEequal(resultVector.m_y, -3.4));
			CHECK(IsEequal(resultVector.m_z, -5.6));
		}
	}

	WHEN("Unary addition 3D vector")
	{
		resultVector = +vector1;

		THEN("Have same coordinates")
		{
			CHECK(IsEequal(resultVector.m_x, 1.2));
			CHECK(IsEequal(resultVector.m_y, 3.4));
			CHECK(IsEequal(resultVector.m_z, 5.6));
		}
	}

	WHEN("Comparing two 3D vectors, [CVector3D]")
	{
		THEN("Have result")
		{
			CHECK(vector1 == vector1);
			CHECK(!(vector1 == vector2));
			CHECK(vector1 != vector2);
			CHECK(!(vector1 != vector1));
		}
	}

	WHEN("3D vectors normalization, [CVector3D]")
	{
		vector1.Normalize();

		THEN("We have the resulting vector")
		{
			CHECK(IsEequal(vector1.m_x, 1));
			CHECK(IsEequal(vector1.m_y, 1));
			CHECK(IsEequal(vector1.m_z, 1));
		}
	}

	WHEN("3D vectors length, [CVector3D]")
	{
		THEN("Have result")
		{
			CHECK(IsEequal(vector1.GetLength(), 6.660330322138685));
		}
	}
}

TEST_CASE("Get coordinates 3D vector, [CVector3D]")
{
	stringstream output;
	string outString;

	WHEN("3D vector has coordinates")
	{
		CVector3D vector(1.2, 3.4, 5.6);

		output << vector;
		getline(output, outString);

		THEN("Output is 3D vector coordinates")
		{
			CHECK(outString == "1.2 3.4 5.6");
		}
	}

	WHEN("3D vector is empty")
	{
		CVector3D vector;

		output << vector;
		getline(output, outString);

		THEN("Output is 0")
		{
			CHECK(outString == "0 0 0");
		}
	}
}

TEST_CASE("Set coordinates 3D vector, [CVector3D]")
{
	stringstream input;
	input << "9.8 7.6 5.4";

	WHEN("When the 3D vector is empty")
	{
		CVector3D vector;
		vector >> input;

		THEN("Have a vector")
		{
			CHECK(IsEequal(vector.m_x, 9.8));
			CHECK(IsEequal(vector.m_y, 7.6));
			CHECK(IsEequal(vector.m_z, 5.4));
		}
	}

	WHEN("When the 3D vector is already with coordinates")
	{
		CVector3D vector(1.2, 3.4, 5.6);
		vector >> input;

		THEN("Have a vector")
		{
			CHECK(IsEequal(vector.m_x, 9.8));
			CHECK(IsEequal(vector.m_y, 7.6));
			CHECK(IsEequal(vector.m_z, 5.4));
		}
	}
}

/*
TEST_CASE("Wrong input data, [CVector3D]")
{
	stringstream input;
	input << "9.8 7.6";
	CVector3D vector(1.2, 3.4, 5.6);

	vector << input;

	CHECK(IsEequal(vector.m_x, 9.8));
	CHECK(IsEequal(vector.m_y, 7.6));
	CHECK(IsEequal(vector.m_z, 5.4));
}*/
