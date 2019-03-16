#include "pch.h"
#include "process_vector.h"

int main()
{
	vector<double> vec = ReadVector(cin);
	if (vec.size() == 0)
	{
		cout << "Invalid input data\n"
			 << "Correct input: <double number> [<double numbers separated by space>]";
		return 1;
	}
	ProcessVector(vec);
	PrintVector(vec);

	return 0;
}
