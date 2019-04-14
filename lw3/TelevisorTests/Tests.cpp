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

SCENARIO("Remote control can turn off a TV", "[remote]")
{
	GIVEN("A remote control connected to the TV which is turned on")
	{
		CTVSet tv;
		stringstream input, output;
		CRemoteControl rc(tv, input, output);

		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());

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

SCENARIO("TV turn on channel number 1", "[tv]")
{
	GIVEN("A turned off TV")
	{
		CTVSet tv;
		REQUIRE(!tv.IsTurnedOn());
		tv.TurnOn();

		WHEN("TV is tunned on")
		{
			CHECK(tv.IsTurnedOn());

			THEN("tv switches on channel 1")
			{
				CHECK(tv.GetCurrentChannel() == 1);
			}
		}
	}
}

SCENARIO("Remote control provides information about TV", "[remote]")
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

SCENARIO("Switched-on TV - can switches channels from 1 to 99", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned on TV")
	{
		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());

		WHEN("user select channel to 42 with SelectChannel command")
		{
			input << "SelectChannel 42";
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

		WHEN("user select channel to 1 with SelectChannel command")
		{
			input << "SelectChannel 1";
			CHECK(rc.HandleCommand());

			THEN("TV switches channel")
			{
				CHECK(tv.GetCurrentChannel() == 1);

				AND_THEN("it is notified that TV switches channel")
				{
					CHECK(output.str() == "Channel changed to 1\n");
				}
			}
		}

		WHEN("user select channel to 99 with SelectChannel command")
		{
			input << "SelectChannel 99";
			CHECK(rc.HandleCommand());

			THEN("TV switches channel")
			{
				CHECK(tv.GetCurrentChannel() == 99);

				AND_THEN("it is notified that TV switches channel")
				{
					CHECK(output.str() == "Channel changed to 99\n");
				}
			}
		}
	}
}

SCENARIO("Switched-off TV - can't switches channels", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned off TV")
	{
		WHEN("TV is turned Off")
		{
			tv.TurnOff();
			REQUIRE(!tv.IsTurnedOn());
			input << "SelectChannel 42";

			WHEN("user enter SelectChannel command")
			{
				rc.HandleCommand();

				AND_THEN("it is notified that TV turn off")
				{
					CHECK(output.str() == "ERROR: Turned off TV can't switches channel\n");
				}
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

		WHEN("user enter SelectChannel to 0 TV can't switches channel")
		{
			input << "SelectChannel 0";
			rc.HandleCommand();

			AND_THEN("it is notified that TV turn off")
			{
				CHECK(output.str() == "ERROR: Channel is out of range\n");
			}
		}

		WHEN("user enter SelectChannel to 100")
		{
			input << "SelectChannel 100";
			rc.HandleCommand();

			AND_THEN("it is notified that TV turn off")
			{
				CHECK(output.str() == "ERROR: Channel is out of range\n");
			}
		}

		WHEN("user enter SelectChannel to -10")
		{
			input << "SelectChannel -10";
			rc.HandleCommand();

			AND_THEN("it is notified that TV turn off")
			{
				CHECK(output.str() == "ERROR: Channel is out of range\n");
			}
		}
	}
}

SCENARIO("A TV restore the previously selected channel", "[remote]")
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

SCENARIO("A turned off TV can't selected previous channel", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A double-channel turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		input << "PreviousChannel";

		WHEN("user enter PreviousChannel")
		{
			rc.HandleCommand();

			AND_THEN("it is notified that TV turn off")
			{
				CHECK(output.str() == "ERROR: Turned off TV can't switches channel\n");
			}
		}
	}
}

SCENARIO("RemoveExtraSpaces must remove extra spaces from any input string")
{
	string str = "    A some   string on input      ";

	WHEN("Input: strin with extra spaces")
	{
		RemoveExtraSpaces(str);

		THEN("Output: without extra spaces")
		{
			CHECK(str == "A some string on input");
		}
	}
}

SCENARIO("A user can save channel by name", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned on TV with select channel")
	{
		tv.TurnOn();
		input << "SetChannel 33    Sport  2   ";

		WHEN("user enter set channel name")
		{
			CHECK(rc.HandleCommand());

			THEN("TV store channel name")
			{
				CHECK(tv.GetChannelName(33) == "Sport 2");

				AND_THEN("user gets notification")
				{
					CHECK(output.str() == "Channel saved: 33 - Sport 2\n");
				}
			}
		}
	}
}

SCENARIO("User wants to know which channel is sport", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned on TV with store channel")
	{
		tv.TurnOn();
		tv.SetChannelName(33, "Sport");
		input << "WhatChannelNumber Sport";

		WHEN("user enter request whith channel name")
		{
			CHECK(rc.HandleCommand());

			THEN("User get notification")
			{
				CHECK(output.str() == "33 - Sport\n");
			}
		}
	}
}

SCENARIO("User wants to know that on channel 33", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned on TV with store channel")
	{
		tv.TurnOn();
		tv.SetChannelName(33, "Sport");
		input << "WhatChannelName 33";

		WHEN("user enter request whith channel number")
		{
			CHECK(rc.HandleCommand());

			THEN("User get notification")
			{
				CHECK(output.str() == "33 - Sport\n");
			}
		}
	}
}

SCENARIO("A user can't save channel by name if channel number outside the range", "[remote]")
{
	CTVSet tv;
	stringstream input, output;
	CRemoteControl rc(tv, input, output);

	GIVEN("A turned on TV with select channel")
	{
		tv.TurnOn();
		input << "SetChannel 101    Sport  2   ";

		WHEN("user enter set channel name on channel outside the range")
		{
			CHECK(rc.HandleCommand());

			THEN("user gets notification")
			{
				CHECK(output.str() == "ERROR: Channel is out of range\n");
			}
		}
	}
}
