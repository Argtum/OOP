#include "pch.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

using Matrix = vector<vector<double>>;

enum class Status
{
	Ok,
	WrongArgumentCount,
	InvalidInputFile,
	WrongInputData
};

const unsigned int ARGUMENT_COUNT = 2;
const unsigned int MATRIX_SIZE = 3;

void printError(Status error)
{
	if (error == Status::WrongArgumentCount)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: invert.exe <matrix file>\n";
	}
	else if (error == Status::InvalidInputFile)
	{
		cout << "Invalid input file\n"
			 << "Can't open input files\n";
	}
	else if (error == Status::WrongInputData)
	{
		cout << "Invalid input data\n"
			 << "Program works with 3x3 matrix\n";
	}
}

ifstream OpenFileForReading(const string& fileName)
{
	ifstream strm(fileName);
	return move(strm);
}

void readMatrix(string inputFile, Matrix& matrix, Status& status)
{
	string line;

	if (auto strm = OpenFileForReading(inputFile))
	{
		while (getline(strm, line))
		{
			istringstream stringIterator(line);
			matrix.push_back(vector<double>(istream_iterator<double>(stringIterator), istream_iterator<double>()));

			if (matrix.back().size() != MATRIX_SIZE)
			{
				status = Status::WrongInputData;
			}
		}
	}
	else
	{
		status = Status::InvalidInputFile;
	}
}

void invertMatrix(Matrix& matrix1, Matrix& resultMatrix, Status& status)
{
}

void checkArgumentNumber(int argc, Status& status)
{
	if (argc != ARGUMENT_COUNT)
	{
		status = Status::WrongArgumentCount;
	}
}

void PrintMatrix(const Matrix& resultMatrix)
{
	for (int row = 0; row < MATRIX_SIZE; row++)
	{
		for (int col = 0; col < MATRIX_SIZE; col++)
		{
			cout.width(10);
			cout.setf(ios::left);
			cout << fixed << setprecision(3) << resultMatrix[row][col];
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	Status status = Status::Ok;
	Matrix matrix1, resultMatrix;

	checkArgumentNumber(argc, status);

	if (status == Status::Ok)
	{
		readMatrix(argv[1], matrix1, status);
	}

	if (status == Status::Ok)
	{
		invertMatrix(matrix1, resultMatrix, status);
	}

	if (status == Status::Ok)
	{
		PrintMatrix(matrix1);
	}
	else
	{
		printError(status);
	}

	return 0;
}
