#include "pch.h"

using namespace std;

const unsigned int ARGUMENT_COUNT = 2;
const unsigned int MATRIX_SIZE = 3;

enum class Status
{
	Ok,
	InvalidInputFile,
	WrongInputData
};

using Matrix = array<array<double, MATRIX_SIZE + 1>, MATRIX_SIZE + 1>;

Status ReadMatrix(const string& fileName, Matrix& matrix)
{
	Status status = Status::Ok;

	ifstream inputFile(fileName);
	string line;
	int row = 0;
	int col;

	if (!inputFile.is_open())
	{
		status = Status::InvalidInputFile;
	}
	else
	{
		while (getline(inputFile, line))
		{
			col = 0;

			if (row < MATRIX_SIZE)
			{
				stringstream stringIterator(line);

				while (!stringIterator.eof()&& status != Status::WrongInputData)
				{
					if (!(stringIterator >> matrix[row][col]))
					{
						status = Status::WrongInputData;
					}
					col++;
				}

				if (col != MATRIX_SIZE)
				{
					status = Status::WrongInputData;
				}
			}

			row++;
		}

		if (row != MATRIX_SIZE)
		{
			status = Status::WrongInputData;
		}
	}

	return status;
}

bool CheckArgumentNumber(int argc)
{
	bool isMatchNumberOfArguments = true;

	if (argc != ARGUMENT_COUNT)
	{
		isMatchNumberOfArguments = false;
	}

	return isMatchNumberOfArguments;
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

double CalcDeterminant(const Matrix& matrix)
{
	double determinant = 0;

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		determinant = determinant
			+ (matrix[0][i] * (matrix[1][(i + 1) % MATRIX_SIZE] * matrix[2][(i + 2) % MATRIX_SIZE]
				- matrix[1][(i + 2) % MATRIX_SIZE] * matrix[2][(i + 1) % MATRIX_SIZE]));
	}

	return determinant;
}

bool InvertMatrix(const Matrix& inputMatrix, Matrix& resultMatrix)
{
	double determinant = CalcDeterminant(inputMatrix);

	if (determinant == 0)
	{
		return false;
	}

	for (int col = 0; col < MATRIX_SIZE; col++)
	{
		for (int row = 0; row < MATRIX_SIZE; row++)
		{
			resultMatrix[col][row] = ((inputMatrix[(row + 1) % MATRIX_SIZE][(col + 1) % MATRIX_SIZE]
											* inputMatrix[(row + 2) % MATRIX_SIZE][(col + 2) % MATRIX_SIZE])
										- (inputMatrix[(row + 1) % MATRIX_SIZE][(col + 2) % MATRIX_SIZE]
											* inputMatrix[(row + 2) % MATRIX_SIZE][(col + 1) % MATRIX_SIZE]))
				/ determinant;
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	Matrix inputMatrix, resultMatrix;

	if (!CheckArgumentNumber(argc))
	{
		cout << "Invalid arguments count\n"
			 << "Usage: invert.exe <matrix file>\n";
		return 1;
	}

	Status readStatus = ReadMatrix(argv[1], inputMatrix);

	if (readStatus == Status::InvalidInputFile)
	{
		cout << "Invalid input file\n"
			 << "Can't open input files\n";
		return 1;
	}
	else if (readStatus == Status::WrongInputData)
	{
		cout << "Invalid input data\n"
			 << "Program works with 3x3 matrix consisting of numbers\n";
		return 1;
	}

	if (!InvertMatrix(inputMatrix, resultMatrix))
	{
		std::cout << "Invalid matrix\n"
				  << "Determinant is 0. This matrix cannot be inverted\n";
		return 1;
	}

	PrintMatrix(resultMatrix);

	return 0;
}
