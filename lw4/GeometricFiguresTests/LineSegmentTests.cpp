#include "pch.h"
#include "lw4/GeometricFigures/CLineSegment.h"
#include "lw4/GeometricFigures/CPoint.h"

TEST_CASE("CLineSegment - create a line segment", "[CLineSegment]")
{
	GIVEN("LineSegment defined two points")
	{
		CPoint point1(1.2, 3.4);
		CPoint point2(5.6, 7.8);

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
