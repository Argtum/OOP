#include "pch.h"
#include "lw4/GeometricFigures/CLineSegment.h"
#include "lw4/GeometricFigures/CPoint.h"

TEST_CASE("CLineSegment - create a line segment", "[CLineSegment]")
{
	GIVEN("Two point")
	{
		CPoint point1(1.2, 3.4);
		CPoint point2(5.6, 7.8);

		WHEN("Segment is created")
		{
			CLineSegment ls(point1, point2);

			THEN("Segment must have two dotes")
			{
				CHECK(ls.GetStartPoint().GetX() == 1.2);
				CHECK(ls.GetStartPoint().GetY() == 3.4);
				CHECK(ls.GetEndPoint().GetX() == 5.6);
				CHECK(ls.GetEndPoint().GetY() == 7.8);
			}
			AND_THEN("Segment must have a length")
			{
				CHECK(ls.GetLength() == 6.22);
			}
			AND_THEN("Segment square must be a null")
			{
				CHECK(ls.GetArea() == 0);
			}
			AND_THEN("Segment perimeter must be a null")
			{
				CHECK(ls.GetPerimeter() == 0);
			}
			AND_THEN("CLineSegment print info about new line segment")
			{
				CHECK(ls.ToString() == "Line segment length: 6.22");
			}
		}
	}
}
