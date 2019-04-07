#include "pch.h"
#include "lw3/Televisor/CError.h"
#include "lw3/Televisor/CRemoteControl.h"
#include "lw3/Televisor/CTVSet.h"

SCENARIO("Remote control can turn on a TV", "[remote]")
{
	GIVEN("A remote control connected to the TV which is turned off")
	{
		CTVSet tv;
		stringstream input, output;
		CRemoteControl rc(tv, input, output);

		REQUIRE(!tv.IsTurnedOn());

		WHEN("user enters TurnOn command")
		{
			input << "TurnOn";
			CHECK(rc.HandleCommand());
			THEN("tv switches on")
			{
				CHECK(tv.IsTurnedOn());
				AND_THEN("user gets notification")
				{
					CHECK(output.str() == "TV is turned on\n");
				}
			}
		}
	}
}

SCENARIO("Remote control provides information about TV", "[remote]")
{
	CTVSet tv;
	stringstream input;
	ostringstream output;
	input << "Info";
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter Info command")
		{
			rc.HandleCommand();
			THEN("it is notified that TV is off")
			{
				CHECK(output.str() == "TV is turned off");
			}
		}
	}

	GIVEN("A turned on TV")
	{
		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());
		WHEN("user enter Info command")
		{
			CHECK(rc.HandleCommand());
			THEN("it is notified that TV is on the current channel")
			{
				CHECK(output.str() == "TV is turned on\nChannel is: 1\n");
			}
		}
	}
}

SCENARIO("Remote control: switched-on TV - can switches channels from 1 to 999, switched-off TV - can't")
{
	GIVEN("A remote control connected to the TV")
	{
		CTVSet tv;
		stringstream input, output;
		CRemoteControl rc(tv, input, output);

		WHEN("TV is turned On")
		{
			tv.TurnOn();
			REQUIRE(tv.IsTurnedOn());
			input << "SelectChannel 42";
			WHEN("user enter SelectChannel command")
			{
				CHECK(rc.HandleCommand());
				THEN("TV switches channel")
				{
					CHECK(tv.GetCurrentChannel() == 42);
					AND_THEN("it is notified that TV switches channel")
					{
						CHECK(output.str() == "Channel changed to 42\n");
					}
				}
			}
		}
		WHEN("TV is turned Off")
		{
			REQUIRE(!tv.IsTurnedOn());
			input << "SelectChannel 42";
			WHEN("user enter SelectChannel command")
			{
				CHECK(rc.HandleCommand());
				CHECK(output.str() == "ERROR: Turned off TV can't switches channel\n");
			}
		}
	}
}

/*
SCENARIO("A turned on TV can select channel from 1 to 999")
{
	GIVEN("A tv")
	{
		WHEN("tv is turned on")
		{
			CTVSet tv;
			tv.TurnOn();
			WHEN("It can select channel from 1 to 999")
			{
				tv.SelectChannel(1);
				CHECK(tv.GetCurrentChannel() == 1);
				tv.SelectChannel(999);
				CHECK(tv.GetCurrentChannel() == 999);
				tv.SelectChannel(666);
				CHECK(tv.GetCurrentChannel() == 666);
			}
		}
	}
}

SCENARIO("A turned off TV can't select channels ")
{
	GIVEN("A tv")
	{
		INFO("A turned off TV can't select channels");
		CTVSet tv;
		WHEN("tv is turned off")
		{
			THEN("It is at channel 0")
			{
				CHECK(tv.GetCurrentChannel() == 0);
			}

			THEN("It can't select channels")
			{
				CHECK_THROWS_AS(tv.SelectChannel(1), Error);
				CHECK_THROWS_WITH(tv.SelectChannel(1), "TV is turned off");
				CHECK(tv.GetCurrentChannel() == 0);
			}
		}
	}
}

SCENARIO("TV can't select a channel beyond the 1..999 range")
{
	SECTION("A turned on TV")
	{
		CTVSet tv;
		tv.TurnOn();
		SECTION("can't select channel less than 1")
		{
			CHECK_THROWS_AS(tv.SelectChannel(0), Error);
			CHECK(tv.GetCurrentChannel() == 1);
		}
		SECTION("can't select channel greater than 999")
		{
			CHECK_THROWS_AS(tv.SelectChannel(1000), Error);
			CHECK(tv.GetCurrentChannel() == 1);
		}
	}
}

SCENARIO("A TV must restore the previously selected channel")
{
	GIVEN("A TV with selected channel")
	{
		CTVSet tv;
		tv.TurnOn();
		tv.SelectChannel(33);
		WHEN("TV is turned off and on")
		{
			tv.TurnOff();
			tv.TurnOn();
			THEN("it restore previously selected channel")
			{
				CHECK(tv.GetCurrentChannel() == 33);
			}
		}
	}
}
*/
