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

double GetMinValue(vector<double>& vec)
{
	vector<double>::iterator minValue = min_element(vec.begin(), vec.end());

	return *minValue;
}

bool VectorScalarMultiplication(vector<double>& vec, double multiplier)
{
	for (double& item : vec)
	{
		if (multiplier * item > numeric_limits<double>::max() 
			|| multiplier * item < numeric_limits<double>::lowest())
		{
			return false;
		}
		item *= multiplier;
	}

	return true;
}

bool MultipliedByMinimum(vector<double>& vec)
{
	double minValue = GetMinValue(vec);
	return VectorScalarMultiplication(vec, minValue);
}

void PrintVector(const vector<double> vec)
{
	copy(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "));
}

/*For test*/
vector<double> GetVectorScalarMultiplication(const vector<double>& vec, double multiplier)
{
	vector<double> localVector = vec;
	VectorScalarMultiplication(localVector, multiplier);
	return localVector;
}

vector<double> GetMultipliedByMinimum(const vector<double>& vec)
{
	vector<double> localVector = vec;
	MultipliedByMinimum(localVector);
	return localVector;
}
