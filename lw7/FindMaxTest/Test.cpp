#include "pch.h"
#include "lw5/Vector3D/ComparingTwoDouble.h"
#include "lw7/FindMax/FindMax.h"

using namespace std;

TEST_CASE("Empty")
{
	GIVEN("Empty array")
	{
		string maxValue;
		vector<string> inputVector = {};

		WHEN("FindMax function is called")
		{
			THEN("Get false")
			{
				CHECK_FALSE(FindMax(inputVector, maxValue));
			}
		}
	}
}

TEST_CASE("Integer")
{
	GIVEN("Array of ineger")
	{
		int maxValue;
		vector<int> inputVector = { 1, 2, -3, -3, 3, 0, -10 };

		WHEN("FindMax function is called")
		{
			FindMax(inputVector, maxValue);

			THEN("Get max integer")
			{
				CHECK(maxValue == 3);
			}
		}
	}
}

TEST_CASE("Float")
{
	GIVEN("Array of float")
	{
		double maxValue;
		vector<double> inputVector = { 1.2, 2.3, -3, -3, 3, 3.1, 0.1, -10 };

		WHEN("FindMax function is called")
		{
			FindMax(inputVector, maxValue);

			THEN("Get max float")
			{
				CHECK(IsEqual(maxValue, 3.1));
			}
		}
	}
}

TEST_CASE("String")
{
	GIVEN("Array of string")
	{
		string maxValue;
		vector<string> inputVector = { "Hello", "World", "Olleh", "Worldd" };

		WHEN("FindMax function is called")
		{
			FindMax(inputVector, maxValue);

			THEN("Get the maximum string in lexicographical order")
			{
				CHECK(maxValue == "Worldd");
			}
		}
	}
}

TEST_CASE("Empty character pointer")
{
	GIVEN("Empty array of ñharacter pointer")
	{
		const char* maxValue;
		vector<const char*> inputVector = {};

		WHEN("FindMax function is called")
		{
			THEN("Get false")
			{
				CHECK_FALSE(FindMax(inputVector, maxValue));
			}
		}
	}
}

TEST_CASE("Ñharacter pointer")
{
	GIVEN("Array of ñharacter pointer")
	{
		const char* maxValue;
		vector<const char*> inputVector = { "Hello", "World", "Olleh" };

		WHEN("FindMax function is called")
		{
			FindMax(inputVector, maxValue);

			THEN("Get the maximum string in lexicographical order")
			{
				CHECK(string(maxValue) == "World");
			}
		}
	}
}
