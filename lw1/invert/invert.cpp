#include "pch.h"
#include "invert.h"

using namespace std;

const unsigned int ARGUMENT_COUNT = 2;
const unsigned int MATRIX_SIZE = 3;

using Matrix = array<array<double, MATRIX_SIZE + 1>, MATRIX_SIZE + 1>;

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
	else if (error == Status::CanNotInvertMatrix)
	{
		cout << "Invalid matrix\n"
			 << "Determinant is 0. This matrix cannot be inverted\n";
	}
}

void readMatrix(string fileName, Matrix& matrix, Status& status)
{
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
		while (getline(inputFile, line) && status == Status::Ok)
		{
			col = 0;

			if (row < MATRIX_SIZE)
			{
				stringstream stringIterator(line);

				while (!stringIterator.eof())
				{
					stringIterator >> matrix[row][col];
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

bool isDeterminantNotNull(Matrix& matrix, double& determinant)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		determinant = determinant + (matrix[0][i] * (matrix[1][(i + 1) % MATRIX_SIZE] * matrix[2][(i + 2) % MATRIX_SIZE] - matrix[1][(i + 2) % MATRIX_SIZE] * matrix[2][(i + 1) % MATRIX_SIZE]));
	}

	return determinant != 0;
}

void invertMatrix(Matrix& inputMatrix, Matrix& resultMatrix, Status& status)
{
	double determinant = 0;

	if (isDeterminantNotNull(inputMatrix, determinant))
	{
		for (int col = 0; col < MATRIX_SIZE; col++)
		{
			for (int row = 0; row < MATRIX_SIZE; row++)
			{
				resultMatrix[row][col] = ((inputMatrix[(row + 1) % MATRIX_SIZE][(col + 1) % MATRIX_SIZE] * inputMatrix[(row + 2) % MATRIX_SIZE][(col + 2) % MATRIX_SIZE]) - (inputMatrix[(row + 1) % MATRIX_SIZE][(col + 2) % MATRIX_SIZE] * inputMatrix[(row + 2) % MATRIX_SIZE][(col + 1) % MATRIX_SIZE])) / determinant;
			}
		}
	}
	else
	{
		status = Status::CanNotInvertMatrix;
	}
}

int main(int argc, char* argv[])
{
	Status status = Status::Ok;
	Matrix inputMatrix, resultMatrix;

	checkArgumentNumber(argc, status);

	if (status == Status::Ok)
	{
		readMatrix(argv[1], inputMatrix, status);
	}

	if (status == Status::Ok)
	{
		invertMatrix(inputMatrix, resultMatrix, status);
	}

	if (status == Status::Ok)
	{
		PrintMatrix(resultMatrix);
	}
	else
	{
		printError(status);
	}

	return 0;
}
