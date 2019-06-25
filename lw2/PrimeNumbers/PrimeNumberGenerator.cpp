#include "pch.h"
#include "PrimeNumberGenerator.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(long const upperBound)
{
	set<int> primeNumbers;
	vector<bool> prime(upperBound + 1, true);
	prime[0] = prime[1] = false;

	if (upperBound > 1)
	{
		for (int i = 2; i * i <= upperBound; ++i)
		{
			if (prime[i])
			{
				primeNumbers.insert(i);

				for (int j = i * i; j <= upperBound; j += i)
				{
					prime[j] = false;
				}
			}
		}
	}

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
