#include "pch.h"
#include "lw7/MyStack/CMyStack.h"

TEST_CASE("Stack of integer")
{
	GIVEN("Empty stack")
	{
		CMyStack<int> stack;

		WHEN("Ñhecking if the stack is empty")
		{
			THEN("The result is positive")
			{
				CHECK(stack.IsEmpty());
			}
		}
	}
}
