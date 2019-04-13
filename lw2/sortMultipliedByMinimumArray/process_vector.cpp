#include "pch.h"
#include "process_vector.h"

bool ReadVector(istream& inputStream, vector<double>& vec)
{
	string line;
	if (getline(inputStream, line))
	{
		istringstream stringIterator(line);
		vec = vector<double>(istream_iterator<double>(stringIterator), istream_iterator<double>());

		if (!stringIterator.eof())
		{
			return false;
		}
	}

	return true;
}

double GetMinValue(vector<double>& vec)
{
	vector<double>::iterator minValue = min_element(vec.begin(), vec.end());

	return *minValue;
}

void VectorScalarMultiplication(vector<double>& vec, double multiplier)
{
	transform(vec.begin(), vec.end(), vec.begin(), [multiplier](double current) {
		return current * multiplier;
	});
}

bool MultipliedByMinimum(vector<double>& vec)
{
	if (vec.empty())
	{
		return false;
	}
	double minValue = GetMinValue(vec);
	VectorScalarMultiplication(vec, minValue);

	return true;
}

void PrintVector(const vector<double> vec)
{
	copy(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "));
}

/*For test*/
vector<double> GetReadVector(istream& inputStream, vector<double>& vec)
{
	vector<double> localVector = vec;
	ReadVector(inputStream, localVector);
	return localVector;
}

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
