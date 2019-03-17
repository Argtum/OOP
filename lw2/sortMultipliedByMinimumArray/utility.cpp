#include "pch.h"
#include "utility.h"

void SortVector(vector<double>& vec)
{
	sort(vec.begin(), vec.end());
}

/*For test*/
vector<double> GetSortVector(const vector<double>& vec)
{
	vector<double> localVector = vec;
	SortVector(localVector);
	return localVector;
}
