#include "pch.h"
#include "process_vector.h"

vector<double> ReadInputVector(istream& inputStream)
{
	vector<double> vec;
	double value;

	while (inputStream >> value)
	{
		vec.push_back(value);
	}

	return vec;
}