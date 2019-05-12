#include "pch.h"
#include "lw4/GeometricFigures/CCommandHandler.h"
#include "lw4/GeometricFigures/CLineSegment.h"

using namespace std;

SCENARIO("User through the command line creates a line segment with mistake")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters name non-existent figure with parameters")
		{
			input << "Line 1.2 3.4 5.6 7.8 123456";
			CHECK(!ch.HandleCommand());

			THEN("He get error message")
			{
				//CHECK(output.str() == "Line segment is created\n");
			}
		}
	}
}

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

			AND_THEN("Shape is added to the array")
			{
				ch.Info(output);
				CHECK(output.str() == "Line segment is created\nLineSegment:\n\tbegins = ( 1.2 , 3.4 ), ends = ( 5.6 , 7.8 )\n\tlength = 6.22\n\tcolor = 171\n");
			}
		}
	}
}

SCENARIO("User through the command line creates a line segment without params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters only a figure name")
		{
			input << "LineSegment";
			CHECK(!ch.HandleCommand());

			THEN("He get an error message")
			{
				CHECK(output.str() == "No arguments!\nUsage: LineSegment point1.x point1.y point2.x point2.y lineColor\n");
			}
		}
	}
}

SCENARIO("User through the command line creates a line segment with not all params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters line segment parameters without color")
		{
			input << "LineSegment 1.2 3.4 5.6 7.8";
			CHECK(!ch.HandleCommand());

			THEN("He get an error message")
			{
				CHECK(output.str() == "Incorrect count of arguments!\nUsage: LineSegment point1.x point1.y point2.x point2.y lineColor\n");
			}
		}
	}
}

SCENARIO("User through the command line creates a triangle")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters line segment parameters")
		{
			input << "Triamgle 1.2 3.4 5.6 7.8 9.0 1.2 abcdef 123456";
			CHECK(ch.HandleCommand());

			THEN("He get a notification")
			{
				CHECK(output.str() == "Triangle is created\n");
			}
		}
	}
}

SCENARIO("User through the command line creates a triangle without params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters only a figure name")
		{
			input << "Triangle";
			CHECK(!ch.HandleCommand());

			THEN("He get an error message")
			{
				CHECK(output.str() == "No arguments!\nUsage: Triangle point1.x point1.y point2.x point2.y point3.x point3.y lineColor fillColor\n");
			}
		}
	}
}

SCENARIO("User through the command line creates a triangle with not all params")
{
	GIVEN("A command line")
	{
		stringstream input, output;
		CCommandHandler ch(input, output);

		WHEN("User enters triangle parameters without color")
		{
			input << "LineSegment 1.2 3.4 5.6 7.8 9.0 1.2";
			CHECK(!ch.HandleCommand());

			THEN("He get an error message")
			{
				CHECK(output.str() == "Incorrect count of arguments!\nUsage: Triangle point1.x point1.y point2.x point2.y point3.x point3.y lineColor fillColor\n");
			}
		}
	}
}
