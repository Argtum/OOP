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
			CHECK(IsEqual(vector1.x, 1.2));
			CHECK(IsEqual(vector1.y, 3.4));
			CHECK(IsEqual(vector1.z, 5.6));
		}
	}

	WHEN("Set empty 3D vector, [CVector3D]")
	{
		THEN("Have a zero vector")
		{
			CHECK(IsEqual(vector3.x, 0));
			CHECK(IsEqual(vector3.y, 0));
			CHECK(IsEqual(vector3.z, 0));
		}
	}

	WHEN("Addition of 2 3D vectors, [CVector3D]")
	{
		resultVector = vector1 + vector2;

		THEN("Have the resulting vector")
		{
			CHECK(IsEqual(resultVector.x, 11));
			CHECK(IsEqual(resultVector.y, 11));
			CHECK(IsEqual(resultVector.z, 9.9));
		}
	}

	WHEN("Subtraction of 2 3D vectors, [CVector3D]")
	{
		resultVector = vector2 - vector1;

		THEN("Have the resulting vector")
		{
			CHECK(IsEqual(resultVector.x, 8.6));
			CHECK(IsEqual(resultVector.y, 4.2));
			CHECK(IsEqual(resultVector.z, -1.3));
		}
	}

	WHEN("3D vector multiplication by scalar, [CVector3D]")
	{
		resultVector = vector1 * 3.3;

		THEN("Have the resulting vector")
		{
			CHECK(IsEqual(resultVector.x, 3.96));
			CHECK(IsEqual(resultVector.y, 11.22));
			CHECK(IsEqual(resultVector.z, 18.48));
		}
	}

	WHEN("Scalar multiply by 3D vector, [CVector3D]")
	{
		resultVector = -2.2 * vector1;

		THEN("Have the resulting vector")
		{
			CHECK(IsEqual(resultVector.x, -2.64));
			CHECK(IsEqual(resultVector.y, -7.48));
			CHECK(IsEqual(resultVector.z, -12.32));
		}
	}

	WHEN("3D vector division by scalar, [CVector3D]")
	{
		resultVector = vector1 / 2;

		THEN("Have the resulting vector")
		{
			CHECK(IsEqual(resultVector.x, 0.6));
			CHECK(IsEqual(resultVector.y, 1.7));
			CHECK(IsEqual(resultVector.z, 2.8));
		}
	}

	WHEN("Increasing the length of the 3D vector, [CVector3D]")
	{
		vector1 += vector2;

		THEN("Have a vector")
		{
			CHECK(IsEqual(vector1.x, 11));
			CHECK(IsEqual(vector1.y, 11));
			CHECK(IsEqual(vector1.z, 9.9));
		}
	}

	WHEN("3D vector length reduction, [CVector3D]")
	{
		vector2 -= vector1;

		THEN("Have a vector")
		{
			CHECK(IsEqual(vector2.x, 8.6));
			CHECK(IsEqual(vector2.y, 4.2));
			CHECK(IsEqual(vector2.z, -1.3));
		}
	}

	WHEN("Short form of 3D vector multiplication by scalar, [CVector3D]")
	{
		vector1 *= 3.3;

		THEN("Have a vector")
		{
			CHECK(IsEqual(vector1.x, 3.96));
			CHECK(IsEqual(vector1.y, 11.22));
			CHECK(IsEqual(vector1.z, 18.48));
		}
	}

	WHEN("Short form of 3D vector division by scalar, [CVector3D]")
	{
		vector1 /= 2;

		THEN("Have a vector")
		{
			CHECK(IsEqual(vector1.x, 0.6));
			CHECK(IsEqual(vector1.y, 1.7));
			CHECK(IsEqual(vector1.z, 2.8));
		}
	}

	WHEN("Inversion 3D vector")
	{
		resultVector = -vector1;

		THEN("Have inverted coordinates")
		{
			CHECK(IsEqual(resultVector.x, -1.2));
			CHECK(IsEqual(resultVector.y, -3.4));
			CHECK(IsEqual(resultVector.z, -5.6));
		}
	}

	WHEN("Unary addition 3D vector")
	{
		resultVector = +vector1;

		THEN("Have same coordinates")
		{
			CHECK(IsEqual(resultVector.x, 1.2));
			CHECK(IsEqual(resultVector.y, 3.4));
			CHECK(IsEqual(resultVector.z, 5.6));
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
			CHECK(IsEqual(vector1.x, 0.180171244061461273));
			CHECK(IsEqual(vector1.y, 0.510485191507473608));
			CHECK(IsEqual(vector1.z, 0.840799138953485942));
		}
	}

	WHEN("3D vectors length, [CVector3D]")
	{
		THEN("Have result")
		{
			CHECK(IsEqual(vector1.GetLength(), 6.660330322138685));
		}
	}

	WHEN("Set coordinates 3D vector, [CVector3D]")
	{
		stringstream input;
		input << "9.8 7.6 5.4";
		input >> resultVector;

		THEN("Have a vector")
		{
			CHECK(IsEqual(resultVector.x, 9.8));
			CHECK(IsEqual(resultVector.y, 7.6));
			CHECK(IsEqual(resultVector.z, 5.4));
		}
	}

	WHEN("Set wrong coordinates 3D vector, [CVector3D]")
	{
		stringstream input;
		ios_base::iostate old_state = input.rdstate();
		input << "9.8 7.6";
		input >> resultVector;

		THEN("Have a vector")
		{
			CHECK_FALSE(old_state == input.rdstate());
		}
	}

	WHEN("Scalar product of two 3D vectors, [CVector3D]")
	{
		double result = DotProduct(vector1, vector2);

		THEN("Get the value")
		{
			CHECK(IsEqual(result, 61.68));
		}
	}

	WHEN("Vector product of two 3D vectors, [CVector3D]")
	{
		resultVector = CrossProduct(vector1, vector2);

		THEN("Get the value")
		{
			CHECK(IsEqual(resultVector.x, -27.94));
			CHECK(IsEqual(resultVector.y, 49.72));
			CHECK(IsEqual(resultVector.z, -24.2));
		}
	}

	WHEN("Vector product of two 3D vectors, [CVector3D]")
	{
		resultVector = Normalize(vector1);

		THEN("Get the value")
		{
			CHECK(IsEqual(resultVector.x, 0.180171244061461273));
			CHECK(IsEqual(resultVector.y, 0.510485191507473608));
			CHECK(IsEqual(resultVector.z, 0.840799138953485942));
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
