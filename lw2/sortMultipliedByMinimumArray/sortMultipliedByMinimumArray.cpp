#include "pch.h"
#include "process_vector.h"
#include "utility.h"

int main()
{
	vector<double> vec;
	
	if (ReadVector(cin, vec))
	{
		cout << "Invalid input data\n"
			 << "Correct input: <double number> [<double numbers separated by space>]\n";
		return 1;
	}
	if (!MultipliedByMinimum(vec))
	{
		cout << "vector is empty\n";
		return 1;
	}
	SortVector(vec);
	PrintVector(vec);

	return 0;
}
