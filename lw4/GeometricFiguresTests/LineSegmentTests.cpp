#include "pch.h"
#include "lw4/GeometricFigures/CLineSegment.h"
#include "lw4/GeometricFigures/CPoint.h"

TEST_CASE("The line segment when created should have a length, and its ends should be the coordinates", "[CLineSegment]")
{
	GIVEN("Line segment defined two points")
	{
		CPoint point1(1.2, 3.4);
		CPoint point2(5.6, 7.8);

		WHEN("Created line segment of color #123456")
		{
			CLineSegment ls(point1, point2, 123456);

			THEN("Can get type")
			{
				CHECK(ls.GetType() == "Line segment");
			}
			AND_THEN("Can get start point")
			{
				CHECK(ls.GetStartPoint().GetX() == 1.2);
				CHECK(ls.GetStartPoint().GetY() == 3.4);
			}
			AND_THEN("Can get end point")
			{
				CHECK(ls.GetEndPoint().GetX() == 5.6);
				CHECK(ls.GetEndPoint().GetY() == 7.8);
			}
			AND_THEN("Can get perimeter")
			{
				CHECK(round(ls.GetPerimeter() * 100) / 100 == 6.22);
			}
			AND_THEN("Can get area")
			{
				CHECK(ls.GetArea() == 0);
			}
			AND_THEN("Can get line color")
			{
				CHECK(ls.GetOutlineColor() == 123456);
			}
		}
	}
}

TEST_CASE("CLineSegment - create a line segment", "[CLineSegment]")
{
	GIVEN("LineSegment defined two points")
	{
		CPoint point1(1.2, 3.4);
		CPoint point2(5.6, 7.8);

		WHEN("Created line segment of color #123456")
		{
			CLineSegment ls(point1, point2, 123456);

			THEN("Can get all parameters of segment")
			{
				CHECK(ls.ToString() == "Line segment:\n\tbegins = ( 1.2 , 3.4 ), ends = ( 5.6 , 7.8 )\n\tlength = 6.22\n\tcolor = 123456\n");
			}
		}
	}
}
