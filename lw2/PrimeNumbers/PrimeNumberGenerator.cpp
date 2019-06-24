#include "pch.h"
#include "PrimeNumberGenerator.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(int const upperBound)
{
	set<int> primeNumbers;

	return primeNumbers;
}

void PrintPrimeNumbers(const set<int> PrimeNumbers)
{
	for (set<int>::iterator it = PrimeNumbers.begin(); it != PrimeNumbers.end(); ++it)
	{
		cout << *it << ' ';
	}

	cout << endl;
}
