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

		WHEN("user enters TurnOff command")
		{
			input << "TurnOff";
			CHECK(rc.HandleCommand());

			THEN("tv switches off")
			{
				CHECK(!tv.IsTurnedOn());

				AND_THEN("user gets notification")
				{
					CHECK(output.str() == "TV is turned off\n");
				}
			}
		}
	}
}

SCENARIO("Remote control provides information about TV. TV turn on channel number 1", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		input << "Info";

		WHEN("user enter Info command")
		{
			CHECK(rc.HandleCommand());

			THEN("it is notified that TV is off")
			{
				CHECK(output.str() == "TV is turned off\n");
			}
		}
	}

	GIVEN("A turned on TV")
	{
		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());
		input << "Info";

		WHEN("user turned on TV and enter Info command")
		{
			CHECK(rc.HandleCommand());

			THEN("it is notified that TV is on the current channel")
			{
				CHECK(output.str() == "TV is turned on\nChannel is: 1\n");
			}
		}
	}
}

SCENARIO("Switched-on TV - can switches channels from 1 to 999, switched-off TV - can't", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned on TV")
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

	GIVEN("A turned off TV")
	{
		WHEN("TV is turned Off")
		{
			tv.TurnOff();
			REQUIRE(!tv.IsTurnedOn());
			input << "SelectChannel 42";

			WHEN("user enter SelectChannel command")
			{
				CHECK_THROWS_WITH(rc.HandleCommand(), "ERROR: Turned off TV can't switches channel\n");
			}
		}
	}
}

SCENARIO("TV can't select a channel beyond the 1..99 range", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned on TV")
	{
		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());
		input << "SelectChannel 0";

		WHEN("user enter SelectChannel to 0 TV can't switches channel")
		{
			CHECK_THROWS_WITH(rc.HandleCommand(), "ERROR: Channel is out of range\n");
		}

		input << "SelectChannel 100";
		WHEN("user enter SelectChannel to 100")
		{
			CHECK_THROWS_WITH(rc.HandleCommand(), "ERROR: Channel is out of range\n");
		}
	}
}

SCENARIO("A TV must restore the previously selected channel", "[tv]")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(33);

	GIVEN("A TV with selected channel")
	{

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

SCENARIO("A TV selected previous channel", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A double-channel TV")
	{
		tv.TurnOn();
		tv.SelectChannel(33);
		tv.SelectChannel(50);
		input << "PreviousChannel";

		WHEN("user enter PreviousChannel")
		{
			CHECK(rc.HandleCommand());

			THEN("TV switches to previous channel")
			{
				CHECK(tv.GetCurrentChannel() == 33);

				AND_THEN("user gets notification")
				{
					CHECK(output.str() == "Channel changed to 33\n");
				}
			}
		}
	}
}
