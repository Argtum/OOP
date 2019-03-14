#include "pch.h"
#include "errors.h"

void printError(Status error)
{
	if (error == Status::WrongArgumentCount)
	{
		std::cout << "Invalid arguments count\n"
			 << "Usage: invert.exe <matrix file>\n";
	}
	else if (error == Status::InvalidInputFile)
	{
		std::cout << "Invalid input file\n"
			 << "Can't open input files\n";
	}
	else if (error == Status::WrongInputData)
	{
		std::cout << "Invalid input data\n"
			 << "Program works with 3x3 matrix\n";
	}
	else if (error == Status::CanNotInvertMatrix)
	{
		std::cout << "Invalid matrix\n"
			 << "Determinant is 0. This matrix cannot be inverted\n";
	}
}
