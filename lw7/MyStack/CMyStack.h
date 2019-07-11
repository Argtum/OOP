#pragma once

template <typename T>
class CMyStack
{
	struct Item
	{
		Item(T data, Item* next)
			: data(std::move(data))
			, next(next)
		{
		}

		T data;
		Item* next;
	};

public:
	CMyStack() = default;

	CMyStack(CMyStack const& stack)
		: CMyStack()
	{
		try
		{
			Item* stackPtr = stack.m_top;

			while (stackPtr)
			{
				Item* newItem = new Item(stack->data, nullptr);

				if (this->m_top)
				{
					newItem->next = this->m_top;
				}

				this->m_top = newItem;
				stackPtr = stackPtr->next;
			}
		}
		catch (...)
		{
			Clear();
			throw;
		}
	}

	bool IsEmpty() const
	{
		return !m_top;
	}

	void Push(const T& data)
	{
		Item* newItem = new Item(data, m_top);
		m_top = newItem;
	}

	void Pop()
	{
		if (IsEmpty())
		{
			throw std::logic_error("ERROR: Stack is empty\n");
		}

		Item* itemPtr = m_top;
		m_top = m_top->next;
		delete itemPtr;
	}

	void Clear()
	{
		while (m_top)
		{
			Item* itemPtr = m_top;
			m_top = m_top->next;
			delete itemPtr;
		}
	}

	~CMyStack()
	{
		Clear();
		free(m_top);
	}

private:
	Item* m_top = nullptr;
};
