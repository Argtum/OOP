#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
/*
bool isDecimalNumber(const unsigned long int dec)
{

}
*/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: copyfile.exe <число в десятичной системе>\n";
		return 1;
	}
	
	try
	{
		unsigned long int dec = stoul(argv[1], nullptr, 10);
	}
	catch (const exception& e)
	{
		cout << e.what();
		return 1;
	}

	cout << dec;

	return 0;
}
