#include "pch.h"
#include "lw7/MyStack/CMyStack.h"

TEST_CASE("Stack of integer")
{
	GIVEN("Empty stack")
	{
		CMyStack<int> stack;

		WHEN("�hecking if the stack is empty")
		{
			THEN("The result is positive")
			{
				CHECK(stack.IsEmpty());
			}
		}

		WHEN("Push value to stack")
		{
			stack.Push(1);

			THEN("Stack is not empty")
			{
				CHECK(!stack.IsEmpty());
			}
		}
	}
}
