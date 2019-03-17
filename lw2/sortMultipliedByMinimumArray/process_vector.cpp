#include "process_vector.h"
#include "pch.h"

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

double GetMinValue(vector<double> vec)
{
	vector<double>::iterator minValue = min_element(vec.begin(), vec.end());

	return *minValue;
}

void VectorScalarMultiplication(vector<double> vec, double multiplier)
{

}

void SortVector(vector<double> vec)
{
	sort(vec.begin(), vec.end());
}

void ProcessVector(vector<double> vec)
{
	double minValue = GetMinValue(vec);
	//transform(vec.begin(), vec.end(), vec.begin(), bind(multiplies<double>(), placeholders::_1, minValue));
	SortVector(vec);
}

void PrintVector(vector<double>& vec)
{
	copy(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "));
}
