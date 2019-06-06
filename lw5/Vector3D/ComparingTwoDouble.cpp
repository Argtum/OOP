#include "pch.h"
#include "ComparingTwoDouble.h"
#include <boost/math/special_functions/relative_difference.hpp>

bool IsEqual(double x, double y)
{
	return boost::math::relative_difference(x, y) < std::numeric_limits<double>::epsilon();
}
