#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const unsigned int ARGUMENT_COUNT = 3;

bool CopyFile(ifstream& inputFile, ofstream& outputFile)
{
	string str = "";

	while (getline(inputFile, str))
	{
		outputFile << str;
		if (!inputFile.eof())
			outputFile << endl;
	}

	return inputFile.eof();
}

int main(int argc, char* argv[])
{
	if (argc != ARGUMENT_COUNT)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	ofstream output(argv[2]);

	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	if (!CopyFile(input, output))
	{
		cout << "Failed to copy\n";
		return 1;
	}

	if (!output.flush())
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}

	return 0;
}
