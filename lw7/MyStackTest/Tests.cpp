#include "pch.h"
#include "lw7/MyStack/CMyStack.h"

TEST_CASE("Stack of integer")
{
	GIVEN("stack")
	{
		CMyStack<int> stack;
		int testValue = 1;
		int value2 = 10;
		int reciever;

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

		WHEN("Get value from not empty stack")
		{
			stack.Push(testValue);
			reciever = stack.GetTop();

			THEN("Stack is empty")
			{
				CHECK(reciever == testValue);
			}
		}

		WHEN("Get value from empty stack")
		{
			THEN("Get error message")
			{
				CHECK_THROWS_WITH(reciever = stack.GetTop(), "ERROR: Stack is empty\n");
			}
		}

		WHEN("Clear not empty stack")
		{
			stack.Push(testValue);
			stack.Push(testValue);
			stack.Clear();

			THEN("Stack is empty")
			{
				CHECK(stack.IsEmpty());
			}
		}

		WHEN("Ñreate a new stack copy of the old")
		{
			stack.Push(testValue);
			stack.Push(value2);
			CMyStack<int> newStack(stack);

			THEN("Their elements coincide")
			{
				CHECK(stack.GetTop() == newStack.GetTop());
				stack.Pop();
				newStack.Pop();
				CHECK(stack.GetTop() == newStack.GetTop());
			}
		}

		WHEN("using operator = new stack ")
		{
			stack.Push(testValue);
			stack.Push(value2);
			CMyStack<int> newStack;
			newStack = stack;

			THEN("the new stacks are equal old stack")
			{
				CHECK(stack.GetTop() == newStack.GetTop());
				stack.Pop();
				newStack.Pop();
				CHECK(stack.GetTop() == newStack.GetTop());
				stack.Pop();
				newStack.Pop();
				CHECK(stack.IsEmpty());
				CHECK(newStack.IsEmpty());
			}
		}
	}
}
