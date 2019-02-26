#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const unsigned int ARGUMENT_COUNT = 4;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != ARGUMENT_COUNT)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: radix.exe <source notation> <destination notation> <value>\n";
		return 1;
	}

	return 0;
}
