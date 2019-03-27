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
