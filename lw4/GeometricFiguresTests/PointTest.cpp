#include "pch.h"
#include "lw4/GeometricFigures/CPoint.h"

TEST_CASE("CPoint - create a point", "[CPoint]")
{
	CPoint point(1, 2);

	CHECK(point.GetX() == 1);
	CHECK(point.GetY() == 2);
}
