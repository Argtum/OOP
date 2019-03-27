#include "pch.h"
#include "lw3/televisor/Televisor/TVSet.h"

SCENARIO("TVSet can be turned on and off", "[tv]")
{
	GIVEN("A turned off TV")
	{
		TVSet tv;
		INFO("The TV must be initially turned off");
		REQUIRE(!tv.IsTurnedOn());

		WHEN("tv is turned on")
		{
			tv.TurnOn();
			THEN("it becomes turned on")
			{
				CHECK(tv.IsTurnedOn());
			}
		}

		AND_WHEN("tv is turned off")
		{
			tv.TurnOff();
			THEN("it becomes turned off")
			{
				tv.TurnOff();
				THEN("it becomes turned off")
				{
					CHECK(!tv.IsTurnedOn());
				}
			}
		}
	}
}

SCENARIO("A TV after first turning-on is at channel 1")
{
	TVSet tv;
	tv.TurnOn();
	CHECK(tv.GetCurrentChannel() == 1);
}

SCENARIO("A turned on TV can select channel from 1 to 999")
{
	GIVEN("A tv")
	{
		WHEN("tv is turned on")
		{
			TVSet tv;
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
