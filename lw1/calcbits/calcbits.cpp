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

	cout << argv[1];

	return 0;
}
