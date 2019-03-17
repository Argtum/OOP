#include "pch.h"
#include "process_vector.h"
#include "utility.h"

int main()
{
	vector<double> vec = ReadVector(cin);
	if (vec.size() == 0)
	{
		cout << "Invalid input data\n"
			 << "Correct input: <double number> [<double numbers separated by space>]\n";
		return 1;
	}
	if (!MultipliedByMinimum(vec))
	{
		cout << "multiplication overflow\n";
		return 1;
	}
	SortVector(vec);
	PrintVector(vec);

	return 0;
}
