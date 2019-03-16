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

TEST_CASE("ProcessVector - funcrion must multiply each vector element by min vector element and sort result")
{
	vector<double> incomingVector, outcomingVector;

	/*Empty input*/
	incomingVector = {};
	outcomingVector = {};
	ProcessVector(incomingVector);
	CHECK(outcomingVector == incomingVector);

	/*correct incoming vector when min value less null */
	incomingVector = {-2.5, 3, 0.5};
	outcomingVector = {-7.5, -1.25, 6.25};
	ProcessVector(incomingVector);
	CHECK(outcomingVector == incomingVector);

	/*correct incoming vector when min value equal 0*/
	incomingVector = {5.233, 1, 89, 0, 5};
	outcomingVector = {0, 0, 0, 0, 0};
	ProcessVector(incomingVector);
	CHECK(outcomingVector == incomingVector);
}
