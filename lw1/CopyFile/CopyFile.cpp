#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{

	if (argc < 2)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}

	string str = "";
	ifstream input(argv[1]);

	while (getline(input, str))
	{
		cout << str;
	}

	return 0;
}
