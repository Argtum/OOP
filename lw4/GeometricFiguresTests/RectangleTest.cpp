#include "pch.h"
#include "lw4/GeometricFigures/CPoint.h"
#include "lw4/GeometricFigures/CRectangle.h"

TEST_CASE("CRectangle - create a rectangle", "[CRectangle]")
{
	GIVEN("Rectangle defined by two points, width and height")
	{
		CPoint leftTopPoint(1.2, 3.4);

		WHEN("Get the coordinates of the first point")
		{
			THEN("Have their coordinates")
			{
				CHECK(leftTopPoint.GetX() == 1.2);
				CHECK(leftTopPoint.GetY() == 3.4);
			}
		}

		CPoint rightBottomPoint(10.4, -1.5);

		WHEN("Get the coordinates of the second point")
		{
			THEN("Have their coordinates")
			{
				CHECK(rightBottomPoint.GetX() == 10.4);
				CHECK(rightBottomPoint.GetY() == -1.5);
			}
		}

		WHEN("Created triangle with line color #123456 and fill color #987654")
		{
			CRectangle rectangle("rectangle", leftTopPoint, rightBottomPoint, 9.2, 4.1, 123456, 987654);

			THEN("Can get all parameters of segment")
			{
				CHECK(rectangle.ToString() == "rectangle:\n\tleft top vertex = ( 1.2 , 3.4 ), right bottom vertex = ( 10.4 , -1.5 ), width = 9.2, height = 4.1\n\tperimeter = 26.6\n\tarea = 37.72\n\tline color = 123456\n\tfill color = 987654\n");
			}
		}
	}
}
