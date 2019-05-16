#include "pch.h"
#include "lw4/GeometricFigures/CPoint.h"
#include "lw4/GeometricFigures/CTriangle.h"

TEST_CASE("CTriangle - create a triangle", "[CTriangle]")
{
	GIVEN("Triangle defined by three points")
	{
		CPoint point1(1.2, 3.4);
		CPoint point2(5.6, 7.8);
		CPoint point3(9.0, 1.2);

		WHEN("Created triangle with line color #123456 and fill color #987654")
		{
			CTriangle triangle("Triangle", point1, point2, point3, 123456, 987654);

			THEN("Can get all parameters of segment")
			{
				CHECK(triangle.ToString() == "Triangle:\n\tfirst vertex = ( 1.2 , 3.4 ), second vertex = ( 5.6 , 7.8 ), third vertex = ( 9 , 1.2 )\n\tperimeter = 21.75\n\tarea = 22\n\tline color = 123456\n\tfill color = 987654\n");
			}
		}
	}
}
