#include "pch.h"
#include "process_vector.h"

vector<double> ReadVector(istream& inputStream)
{
	vector<double> vec;

	string line;
	if (getline(inputStream, line))
	{
		istringstream stringIterator(line);
		vec = vector<double>(istream_iterator<double>(stringIterator), istream_iterator<double>());

		if (!stringIterator.eof())
		{
			vec.clear();
		}
	}

	return vec;
}

void ProcessVector(vector<double> vec)
{
	vector<double>::iterator minValue = min_element(vec.begin(), vec.end());
	vector<double>::iterator vectorElement;

	sort(vec.begin(), vec.end());
}

void PrintVector(vector<double>& vec)
{
	copy(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "));
}
