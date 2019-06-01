#include "pch.h"
#include "ComparingTwoDouble.h"

using namespace std;

bool IsEequal(double x, double y)
{
	return fabs(x - y) < numeric_limits<double>::epsilon();
}
