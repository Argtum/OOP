#include "pch.h"
#include "../sortMultipliedByMinimumArray/process_vector.h"

TEST_CASE("ReadVector - funcrion must return vector<double>")
{
	istringstream inputStream;
	vector<double> result, expectedResult;

	/*Empty input*/
	inputStream.str("");
	result = ReadVector(inputStream);
	expectedResult = {};
	CHECK(expectedResult == result);

	/*correct input*/
	inputStream.clear();
	inputStream.str("        -2 3.14           0");
	result = ReadVector(inputStream);
	expectedResult = { -2, 3.14, 0 };
	CHECK(expectedResult == result);

	/*incorrect input: have row*/
	inputStream.clear();
	inputStream.str("2 and 4");
	result = ReadVector(inputStream);
	expectedResult = {};
	CHECK(expectedResult == result);
}