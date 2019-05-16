#include "pch.h"
#include "lw4/GeometricFigures/CCircle.h"
#include "lw4/GeometricFigures/CPoint.h"

TEST_CASE("CCircle - create a circle", "[CCircle]")
{
	GIVEN("Circle center point")
	{
		CPoint center(1.2, 3.4);

		WHEN("Created circle with radius 3, line color #123456 and fill color #987654")
		{
			CCircle circle("Circle", center, 3, 123456, 987654);

			THEN("Can get all parameters of segment")
			{
				CHECK(circle.ToString() == "Circle:\n\tcenter = ( 1.2 , 3.4 ), radius = 3\n\tperimeter = 18.85\n\tarea = 28.27\n\tline color = 123456\n\tfill color = 987654\n");
			}
		}
	}
}
