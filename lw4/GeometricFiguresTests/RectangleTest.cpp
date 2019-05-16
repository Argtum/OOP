#include "pch.h"
#include "lw4/GeometricFigures/CPoint.h"
#include "lw4/GeometricFigures/CRectangle.h"

TEST_CASE("CRectangle - create a rectangle", "[CRectangle]")
{
	GIVEN("Rectangle left top b right bottom points")
	{
		CPoint leftTopPoint(1.2, 3.4);

		WHEN("Created triangle with width = 9.2, height = 4.1, line color #123456 and fill color #987654")
		{
			CRectangle rectangle("Rectangle", leftTopPoint, 9.2, 4.1, 123456, 987654);

			AND_THEN("Can get all parameters of segment")
			{
				CHECK(rectangle.ToString() == "Rectangle:\n\tleft top vertex = ( 1.2 , 3.4 ), width = 9.2, height = 4.1\n\tperimeter = 26.6\n\tarea = 37.72\n\tline color = 123456\n\tfill color = 987654\n");
			}
		}
	}
}
