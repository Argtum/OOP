#include "pch.h"
#include "lw4/GeometricFigures/CPoint.h"
#include "lw4/GeometricFigures/CTriangle.h"

TEST_CASE("CTriangle - create a triangle", "[CTriangle]")
{
	GIVEN("Triangle defined by three points")
	{
		CPoint point1(1.2, 3.4);

		WHEN("Get the coordinates of the first point")
		{
			THEN("Have their coordinates")
			{
				CHECK(point1.GetX() == 1.2);
				CHECK(point1.GetY() == 3.4);
			}
		}

		CPoint point2(5.6, 7.8);

		WHEN("Get the coordinates of the second point")
		{
			THEN("Have their coordinates")
			{
				CHECK(point2.GetX() == 5.6);
				CHECK(point2.GetY() == 7.8);
			}
		}

		CPoint point3(9.0, 1.2);

		WHEN("Get the coordinates of the third point")
		{
			THEN("Have their coordinates")
			{
				CHECK(point3.GetX() == 9.0);
				CHECK(point3.GetY() == 1.2);
			}
		}

		WHEN("Created triangle with line color #123456 and fill color #987654")
		{
			CTriangle triangle("triangle", point1, point2, point3, 123456, 987654);

			THEN("Can get all parameters of segment")
			{
				CHECK(triangle.ToString() == "triangle:\n\tfirst vertex = ( 1.2 , 3.4 ), second vertex = ( 5.6 , 7.8 ), third vertex = ( 9 , 1.2 )\n\tperimeter = 21.75\n\tarea = 22\n\tline color = 123456\n\tfill color = 987654\n");
			}
		}
	}
}
