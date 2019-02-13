﻿#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{ /*
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}*/

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

	string str = "";

	while (getline(input, str))
	{
		output << str;
		if (!input.eof())
			output << endl;
	}
	
	if (!output.flush())
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}
	
	input.close();
	output.close();

	return 0;
}
