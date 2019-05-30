#include "pch.h"
#include "lw4/GeometricFigures/AdditionFunction.h"
#include "lw4/GeometricFigures/CCircle.h"
#include "lw4/GeometricFigures/CCommandHandler.h"
#include "lw4/GeometricFigures/CLineSegment.h"
#include "lw4/GeometricFigures/CRectangle.h"

using namespace std;

TEST_CASE("GetSegmentLength - mast return a distance between two points")
{
	CPoint point1(1.2, 3.4);
	CPoint point2(5.6, 7.8);
	double length = GetSegmentLength(point1, point2);
	CHECK(round(length * 100) / 100 == 6.22);
}

//----------LINE SEGMENT----------
SCENARIO("User through the command line creates a line segment")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters line segment parameters")
		{
			input << "LineSegment 1.2 3.4 5.6 7.8 abcdef";
			CHECK(ch.HandleCommand());

			THEN("He get a notification")
			{
				CHECK(output.str() == "Line segment is created\n");
			}

			/*AND_THEN("Shape is added to the array")
			{
				ch.Info(output);
				CHECK(output.str() == "Line segment is created\nLineSegment:\n\tbegins = ( 1.2 , 3.4 ), ends = ( 5.6 , 7.8 )\n\tlength = 6.22\n\tcolor = 171\n");
			}*/
		}
	}
}

SCENARIO("User through the command line can't creates a line segment without params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters only a figure name")
		{
			input << "LineSegment";

			THEN("He get an error message")
			{
				CHECK_THROWS_WITH(ch.HandleCommand(), "No arguments!\nUsage: LineSegment point1.x point1.y point2.x point2.y lineColor\n");
			}
		}
	}
}

SCENARIO("User through the command line can't creates a line segment with not all params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters line segment parameters without color")
		{
			input << "LineSegment 1.2 3.4 5.6 7.8";

			THEN("He get an error message")
			{
				CHECK_THROWS_WITH(ch.HandleCommand(), "Incorrect count of arguments!\nUsage: LineSegment point1.x point1.y point2.x point2.y lineColor\n");
			}
		}
	}
}

//---------TRIANGLE----------
SCENARIO("User through the command line creates a triangle")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters triangle parameters")
		{
			input << "Triangle 1.2 3.4 5.6 7.8 9.0 1.2 abcdef 123456";
			CHECK(ch.HandleCommand());

			THEN("He get a notification")
			{
				CHECK(output.str() == "Triangle is created\n");
			}
		}
	}
}

SCENARIO("User through the command line can't creates a triangle without params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters only a figure name")
		{
			input << "Triangle";

			THEN("He get an error message")
			{
				CHECK_THROWS_WITH(ch.HandleCommand(), "No arguments!\nUsage: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex3.y lineColor fillColor\n");
			}
		}
	}
}

SCENARIO("User through the command line can't creates a triangle with not all params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters triangle parameters without color")
		{
			input << "Triangle 1.2 3.4 5.6 7.8 9.0 1.2";

			THEN("He get an error message")
			{
				CHECK_THROWS_WITH(ch.HandleCommand(), "Incorrect count of arguments!\nUsage: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex3.y lineColor fillColor\n");
			}
		}
	}
}

//----------RECTANGLE----------
SCENARIO("User through the command line creates a rectangle")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters rectangle parameters")
		{
			input << "Rectangle 1.2 3.4 9.2 4.1 abcdef 123456";
			CHECK(ch.HandleCommand());

			THEN("He get a notification")
			{
				CHECK(output.str() == "Rectangle is created\n");
			}
		}
	}
}

SCENARIO("User through the command line can't creates a rectangle without params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters only a figure name")
		{
			input << "Rectangle";

			THEN("He get an error message")
			{
				CHECK_THROWS_WITH(ch.HandleCommand(), "No arguments!\nUsage: Rectangle leftTopVertex.x leftTopVertex.y width height lineColor fillColor\n");
			}
		}
	}
}

SCENARIO("User through the command line can't creates a rectangle with not all params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters triangle parameters without color")
		{
			input << "Rectangle 1.2 3.4 9.2 4.1";

			THEN("He get an error message")
			{
				CHECK_THROWS_WITH(ch.HandleCommand(), "Incorrect count of arguments!\nUsage: Rectangle leftTopVertex.x leftTopVertex.y width height lineColor fillColor\n");
			}
		}
	}
}

//----------CIRCLE----------
SCENARIO("User through the command line creates a circle")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters circle parameters")
		{
			input << "Circle 1.2 3.4 3 abcdef 123456";
			CHECK(ch.HandleCommand());

			THEN("He get a notification")
			{
				CHECK(output.str() == "Circle is created\n");
			}
		}
	}
}

SCENARIO("User through the command line can't creates a circle without params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters only a figure name")
		{
			input << "Circle";

			THEN("He get an error message")
			{
				CHECK_THROWS_WITH(ch.HandleCommand(), "No arguments!\nUsage: Circle center.x center.y radius lineColor fillColor\n");
			}
		}
	}
}

SCENARIO("User through the command line can't creates a circle with not all params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters circle parameters without color")
		{
			input << "Circle 1.2 3.4 3";

			THEN("He get an error message")
			{
				CHECK_THROWS_WITH(ch.HandleCommand(), "Incorrect count of arguments!\nUsage: Circle center.x center.y radius lineColor fillColor\n");
			}
		}
	}
}
/*
SCENARIO("When the user finishes entering shapes, information is displayed about the shape with the smallest perimeter and largest area")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters circle parameters")
		{
			input << "Circle 1.2 3.4 3 abcdef 123456";
			CHECK(ch.HandleCommand());

			THEN("He get a notification")
			{
				CHECK(output.str() == "Circle is created\n");
			}
		}

		WHEN("User enters rectangle parameters")
		{
			input << "Rectangle 1.2 3.4 9.2 4.1 abcdef 123456";
			CHECK(ch.HandleCommand());

			THEN("He get a notification")
			{
				CHECK(output.str() == "Rectangle is created\n");
			}
		}

		WHEN("User enters rectangle parameters")
		{
			input << "\0";

			THEN("He get a notification")
			{
				CHECK(output.str() == "Min perimeter shape: Circle:\n\tcenter = ( 1.2 , 3.4 ), radius = 3\n\tperimeter = 18.85\n\tarea = 28.27\n\tline color = 123456\n\tfill color = 987654\nMax square shape: Rectangle:\n\tleft top vertex = ( 1.2 , 3.4 ), width = 9.2, height = 4.1\n\tperimeter = 26.6\n\tarea = 37.72\n\tline color = 123456\n\tfill color = 987654\n");
			}
		}
	}
}
*/
