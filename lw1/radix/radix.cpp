#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const unsigned int ARGUMENT_COUNT = 4;
const unsigned int NOTATION_BASE = 10;

bool isCorrectNotation(const char* notation)
{
	char* end;
	return isdigit(strtoll(notation, &end, NOTATION_BASE)) && strtoll(notation, &end, NOTATION_BASE) > 1 && strtoll(notation, &end, 10) <= 36;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != ARGUMENT_COUNT)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: radix.exe <source notation> <destination notation> <value>\n";
		return 1;
	}

	if (!isCorrectNotation(argv[1]) || !isCorrectNotation(argv[2]))
	{
		cout << "Invalid source notation\n"
			 << "The base should be from 2 to 36\n";
		return 1;
	}

	return 0;
}
