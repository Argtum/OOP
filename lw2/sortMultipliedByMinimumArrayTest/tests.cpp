#include "pch.h"
#include "lw2/sortMultipliedByMinimumArray/process_vector.h"
#include "lw2/sortMultipliedByMinimumArray/utility.h"

TEST_CASE("ReadVector - funcrion must return vector<double>")
{
	istringstream inputStream;
	vector<double> result, inputVector, expectedResult;
	bool isRead, isGood;

	/* Empty input */
	inputStream.str("");
	inputVector = {};
	expectedResult = {};
	isGood = false;
	if (expectedResult == GetReadVector(inputStream, inputVector) && ReadVector(inputStream, inputVector))
	{
		isGood = true;
	}
	CHECK(isGood);

	/* correct input */
	inputStream.clear();
	inputStream.str("        -2 3.14           0");
	inputVector = {};
	expectedResult = { -2, 3.14, 0 };
	isGood = false;
	if (expectedResult == GetReadVector(inputStream, inputVector) && ReadVector(inputStream, inputVector))
	{
		isGood = true;
	}
	CHECK(isGood);

	/* incorrect input: have row */
	inputStream.clear();
	inputStream.str("2 and 4");
	inputVector = {};
	isRead = ReadVector(inputStream, inputVector);

	CHECK(!isRead);
}

TEST_CASE("GetMinValue - return the value of the minimum element of a vector")
{
	vector<double> incomingVector;
	incomingVector = { -2.5, 3, 0.5 };

	CHECK(-2.5 == GetMinValue(incomingVector));
}

TEST_CASE("VectorScalarMultiplication - return a vector, each element of which is multiplied by a number")
{
	vector<double> incomingVector, outcomingVector;
	double multiplier = -1.5;

	incomingVector = { -2.5, 3, 1.5 };
	outcomingVector = { 3.75, -4.5, -2.25 };

	CHECK(outcomingVector == GetVectorScalarMultiplication(incomingVector, multiplier));
}

TEST_CASE("MultipliedByMinimum - return a vector, each element of which is multiplied by a number")
{
	vector<double> incomingVector, outcomingVector;

	incomingVector = { -2.5, 3, 1.5, 0 };
	outcomingVector = { 6.25, -7.5, -3.75, 0 };

	CHECK(outcomingVector == GetMultipliedByMinimum(incomingVector));


	incomingVector = {};

	CHECK(false == MultipliedByMinimum(incomingVector));
}

TEST_CASE("SortVector - return sorted vector")
{
	vector<double> incomingVector, outcomingVector;

	incomingVector = { -2.5, 3, 1.5, 0 };
	outcomingVector = { -2.5, 0, 1.5, 3 };

	CHECK(outcomingVector == GetSortVector(incomingVector));
}