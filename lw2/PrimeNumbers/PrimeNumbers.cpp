#include "pch.h"
#include "PrimeNumberGenerator.h"

using namespace std;

const int UPPER_BOUND_LIMIT = 100000000;

int main(int argc, char* argv[])
{
	int upperBound;

	if (argc != 2)
	{
		cout << "ERROR: Invalid arguments count\nUsage: PrimeNumbers.exe <integer>\n";

		return 1;
	}

	try
	{
		upperBound = stoi(argv[1]);
	}
	catch (...)
	{
		cout << "ERROR: Invalid second argument\nUsage: second argument must be integer\n";
		return 1;
	}

	if (upperBound > UPPER_BOUND_LIMIT)
	{
		cout << "ERROR: Invalid second argument\nUsage: second argument is integer less than 100000000 and greater than 0\n";

		return 1;
	}

	PrintPrimeNumbers(GeneratePrimeNumbersSet(upperBound));

	return 0;
}
