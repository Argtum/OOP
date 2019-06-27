#include "pch.h"
#include "lw7/MyList/CMyList.h"

using namespace std;

SCENARIO("New custom list")
{
	GIVEN("New List of int")
	{
		CMyList<int> list;
		int item1 = 1, item2 = 2;

		REQUIRE(list.GetSize() == 0);

		WHEN("Insert one item at the begining of the list")
		{
			list.InsertAtTheBegining(item1);

			THEN("The number of items in the list increases by 1")
			{
				CHECK(list.GetSize() == 1);
			}
		}

		WHEN("Insert one item at the begining of the list")
		{
			list.InsertToTheEnd(item2);

			THEN("The number of items in the list increases by 1")
			{
				CHECK(list.GetSize() == 2);
			}
		}
	}
}
