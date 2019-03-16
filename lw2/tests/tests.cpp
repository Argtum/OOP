#include "pch.h"
#include "../sortMultipliedByMinimumArray/process_vector.h"

TEST_CASE("ReadVector - funcrion must return vector<double>")
{
	istringstream inputStream;
	vector<double> result, expectedResult;

	/*Empty string*/
	inputStream.str("");
	result = ReadVector(inputStream);
	expectedResult = {};
	CHECK(expectedResult == result);

	/*normal input*/
	inputStream.clear();
	inputStream.str("2 3 4");
	result = ReadVector(inputStream);
	expectedResult = { 2, 3, 4 };
	CHECK(expectedResult == result);
}