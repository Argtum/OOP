#include "pch.h"
#include "lw2/PrimeNumbers/PrimeNumberGenerator.h"

using namespace std;
const int UPPER_BOUND_LIMIT = 100000000;

TEST_CASE("GeneratePrimeNumbersSet must generate a set of prime numbers not greater than the root of the entered value")
{
	long inputValue = 100;
	long firstInputValue = 1;
	set<int> outputSet = { 2, 3, 5, 7 };
	set<int> emptyOutputSet = {};

	CHECK(GeneratePrimeNumbersSet(inputValue) == outputSet);
	CHECK(GeneratePrimeNumbersSet(firstInputValue) == emptyOutputSet);
}
