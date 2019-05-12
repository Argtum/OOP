#include "pch.h"
#include "lw4/GeometricFigures/CLineSegment.h"
#include "lw4/GeometricFigures/CPoint.h"

TEST_CASE("CLineSegment - create a line segment", "[CLineSegment]")
{
	GIVEN("LineSegment defined two points")
	{
		CPoint point1(1.2, 3.4);

		WHEN("Get the coordinates of the starting point")
		{
			THEN("Have the coordinates of the starting point")
			{
				CHECK(point1.GetX() == 1.2);
				CHECK(point1.GetY() == 3.4);
			}
		}

		CPoint point2(5.6, 7.8);

		WHEN("Get the coordinates of the end point")
		{
			THEN("Have the coordinates of the starting point")
			{
				CHECK(point2.GetX() == 5.6);
				CHECK(point2.GetY() == 7.8);
			}
		}

		WHEN("Created line segment of color #123456")
		{
			CLineSegment ls("LineSegment", point1, point2, 123456);

			THEN("Can get all parameters of segment")
			{
				CHECK(ls.ToString() == "LineSegment:\n\tbegins = ( 1.2 , 3.4 ), ends = ( 5.6 , 7.8 )\n\tlength = 6.22\n\tcolor = 123456\n");
			}
		}
	}
}
