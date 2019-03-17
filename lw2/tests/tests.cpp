#include "pch.h"
#include "../sortMultipliedByMinimumArray/process_vector.h"

TEST_CASE("ReadVector - funcrion must return vector<double>")
{
	istringstream inputStream;
	vector<double> result, expectedResult;

	/*Empty input*/
	inputStream.str("");
	expectedResult = {};

	CHECK(expectedResult == ReadVector(inputStream));

	/*correct input*/
	inputStream.clear();
	inputStream.str("        -2 3.14           0");
	expectedResult = { -2, 3.14, 0 };
	
	CHECK(expectedResult == ReadVector(inputStream));

	/*incorrect input: have row*/
	inputStream.clear();
	inputStream.str("2 and 4");
	expectedResult = {};
	
	CHECK(expectedResult == ReadVector(inputStream));
}

TEST_CASE("GetMinValue - returns the value of the minimum element of a vector")
{
	vector<double> incomingVector;
	incomingVector = { -2.5, 3, 0.5 };

	CHECK(-2.5 == GetMinValue(incomingVector));
}

TEST_CASE("VectorScalarMultiplication - returns a vector, each element of which is multiplied by a number")
{
	vector<double> incomingVector, outcomingVector;
	double multiplier = -1.5;

	incomingVector = {-2.5, 3, 1.5};
	outcomingVector = {3.75, -4.5, -2.25};

	CHECK(outcomingVector == GetVectorScalarMultiplication(incomingVector, multiplier));
}

TEST_CASE("ProcessVector - returns a vector, each element of which is multiplied by a number")
{
	vector<double> incomingVector, outcomingVector;

	incomingVector = { -2.5, 3, 1.5, 0};
	outcomingVector = { 6.25, -7.5, -3.75, 0 };

	CHECK(outcomingVector == GetProcessVector(incomingVector));

	incomingVector = { 2.5, 3, 1.5, 0 };
	outcomingVector = { 0, 0, 0, 0 };

	CHECK(outcomingVector == GetProcessVector(incomingVector));
}

/*
TEST_CASE("ProcessVector - funcrion must multiply each vector element by min vector element and sort result")
{
	vector<double> incomingVector, outcomingVector, expectedResult;

	/*correct incoming vector when min value less null */
/*	incomingVector = {-2.5, 3, 0.5};
	outcomingVector = {-7.5, -1.25, 6.25};
	expectedResult = ProcessVector(incomingVector);
	CHECK(outcomingVector == expectedResult);

	/*correct incoming vector when min value equal 0*/
/*	incomingVector = {5.233, 1, 89, 0, 5};
	outcomingVector = {0, 0, 0, 0, 0};
	expectedResult = ProcessVector(incomingVector);
	CHECK(outcomingVector == expectedResult);
}
*/