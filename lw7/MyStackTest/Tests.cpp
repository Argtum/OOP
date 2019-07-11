#include "pch.h"
#include "lw7/MyStack/CMyStack.h"

TEST_CASE("Stack of integer")
{
	GIVEN("stack")
	{
		CMyStack<int> stack;
		int testValue = 1;

		WHEN("Ñhecking if the stack is empty")
		{
			THEN("The result is positive")
			{
				CHECK(stack.IsEmpty());
			}
		}

		WHEN("Push value to stack")
		{
			stack.Push(testValue);

			THEN("Stack is not empty")
			{
				CHECK(!stack.IsEmpty());
			}
		}

		WHEN("Pushing out from stack with 1 value")
		{
			stack.Push(testValue);
			stack.Pop();

			THEN("Stack is empty")
			{
				CHECK(stack.IsEmpty());
			}
		}

		WHEN("Pushing out from empty stack")
		{
			THEN("Get error message")
			{
				CHECK_THROWS_WITH(stack.Pop(), "ERROR: Stack is empty\n");
			}
		}
	}
}
