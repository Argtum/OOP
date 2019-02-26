#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const unsigned int ARGUMENT_COUNT = 3;

using MatrixCell = double;
using MatrixRow = vector<MatrixCell>;
using Matrix = vector<MatrixRow>;

int main(int argc, char* argv[])
{
	if (argc != ARGUMENT_COUNT)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: multmatrix.exe <matrix file1> <matrix file2>\n";
		return 1;
	}

	ifstream inputOne(argv[1]);

	if (!inputOne.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	ifstream inputTwo(argv[2]);

	if (!inputTwo.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	Matrix matrix1;
	Matrix matrix2;
	Matrix result;

	return 0;
}
