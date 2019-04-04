#include "pch.h"
#include "lw3/Televisor/CTVSet.h"
#include "lw3/Televisor/Error.h"

SCENARIO("TVSet can be turned on and off", "[tv]")
{
	GIVEN("A turned off TV")
	{
		CTVSet tv;
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
	CTVSet tv;
	INFO("Àirst turning-on TV must at channel 1");
	tv.TurnOn();
	CHECK(tv.GetCurrentChannel() == 1);
}

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
