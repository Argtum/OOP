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

		WHEN("�hecking if the stack is empty")
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

		WHEN("�reate a new stack copy of the old")
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

		WHEN("Using copy operator = ")
		{
			stack.Push(testValue);
			stack.Push(value2);
			CMyStack<int> newStack = stack;

			THEN("New stack are equal old stack")
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

		WHEN("�reate a new stack using move constructor")
		{
			stack.Push(testValue);
			stack.Push(value2);
			CMyStack<int> dublicate = stack;
			CMyStack<int> newStack(std::move(stack));

			THEN("Their elements coincide")
			{
				CHECK(dublicate.GetTop() == newStack.GetTop());
				dublicate.Pop();
				newStack.Pop();
				CHECK(dublicate.GetTop() == newStack.GetTop());
				dublicate.Pop();
				newStack.Pop();
				CHECK(dublicate.IsEmpty());
				CHECK(newStack.IsEmpty());
			}
		}

		WHEN("Using moving operator = ")
		{
			stack.Push(testValue);
			stack.Push(value2);
			CMyStack<int> dublicate = stack;
			CMyStack<int> newStack = std::move(stack);

			THEN("New stack are equal old stack")
			{
				CHECK(dublicate.GetTop() == newStack.GetTop());
				dublicate.Pop();
				newStack.Pop();
				CHECK(dublicate.GetTop() == newStack.GetTop());
				dublicate.Pop();
				newStack.Pop();
				CHECK(dublicate.IsEmpty());
				CHECK(newStack.IsEmpty());
			}
		}
	}
}

TEST_CASE("Stack of string")
{
	GIVEN("stack")
	{
		CMyStack<std::string> stack;
		std::string testValue = "Hello";
		std::string value2 = "world!";
		std::string reciever;

		WHEN("�hecking if the stack is empty")
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

		WHEN("�reate a new stack copy of the old")
		{
			stack.Push(testValue);
			stack.Push(value2);
			CMyStack<std::string> newStack(stack);

			THEN("Their elements coincide")
			{
				CHECK(stack.GetTop() == newStack.GetTop());
				stack.Pop();
				newStack.Pop();
				CHECK(stack.GetTop() == newStack.GetTop());
			}
		}

		WHEN("Using copy operator = ")
		{
			stack.Push(testValue);
			stack.Push(value2);
			CMyStack<std::string> newStack = stack;

			THEN("New stack are equal old stack")
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

		WHEN("�reate a new stack using move constructor")
		{
			stack.Push(testValue);
			stack.Push(value2);
			CMyStack<std::string> dublicate = stack;
			CMyStack<std::string> newStack(std::move(stack));

			THEN("Their elements coincide")
			{
				CHECK(dublicate.GetTop() == newStack.GetTop());
				dublicate.Pop();
				newStack.Pop();
				CHECK(dublicate.GetTop() == newStack.GetTop());
				dublicate.Pop();
				newStack.Pop();
				CHECK(dublicate.IsEmpty());
				CHECK(newStack.IsEmpty());
			}
		}

		WHEN("Using moving operator = ")
		{
			stack.Push(testValue);
			stack.Push(value2);
			CMyStack<std::string> dublicate = stack;
			CMyStack<std::string> newStack = std::move(stack);

			THEN("New stack are equal old stack")
			{
				CHECK(dublicate.GetTop() == newStack.GetTop());
				dublicate.Pop();
				newStack.Pop();
				CHECK(dublicate.GetTop() == newStack.GetTop());
				dublicate.Pop();
				newStack.Pop();
				CHECK(dublicate.IsEmpty());
				CHECK(newStack.IsEmpty());
			}
		}
	}
}
