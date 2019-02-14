#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: copyfile.exe <byte>\n";
		return 1;
	}

	long number;

	try
	{
		number = stoi(argv[1]);
	}
	catch (const exception &e)
	{
		cout << e.what() << '\n';
		return 1;
	}

	cout << number;

	return 0;
}
