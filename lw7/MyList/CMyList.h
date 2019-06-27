#pragma once

template <typename T>
class CMyList
{
	struct Item
	{
		Item(T data, Item* next, Item* prev)
			: data(data)
			, next(next)
			, prev(prev)
		{
		}

		T data;
		Item* next;
		Item* prev;
	};

public:
	CMyList() = default;

	CMyList(CMyList const& list)
		: CMyList()
	{
		try
		{
			list.m_rbegin = list.m_begin;

			m_begin = new Item(list.m_rbegin->data, nullptr, nullptr);
			m_rbegin = m_begin;
			m_rend = m_end;
			list.m_rbegin = list.m_rbegin->next;

			while (list.m_rbegin)
			{
				m_rend = new Item(list.m_rbegin->data, m_rbegin, nullptr);
				m_rbegin->next = m_rend;
				m_rbegin = m_rend;
				list.m_rbegin = list.m_rbegin->next;
			}

			m_end = m_rend;
		}
		catch (...)
		{
			DeleteItems();
			throw;
		}
	}

	void InsertAtTheBegining(T const& value)
	{
		Item* insertValue = new Item(value, nullptr, m_begin);
		m_begin->prev = insertValue;
		m_begin = insertValue;
	}

	void InsertToTheEnd(T const& value)
	{
		Item* insertValue = new Item(value, m_end, nullptr);
		m_end->next = insertValue;
		m_end = insertValue;
	}

	void Insert(T const& value)
	{
		Item* insertValue = new Item(value, m_rend, m_rbegin);
		m_rend->prev = insertValue;
		m_rbegin->next = insertValue;
	}

	void Delete()
	{
		m_rbegin->next = m_rend->next;
		delete (m_rend);
		m_rend = m_rbegin->next;
		m_rend->prev = m_rbegin;
	}

	size_t GetSize()
	{
		size_t numberOfItems = 0;

		m_rbegin = m_begin;

		while (m_rbegin)
		{
			numberOfItems++;
			m_rbegin = m_rbegin->next;
		}

		return numberOfItems;
	}

	Item* Begin()
	{
		return m_begin;
	}

	Item* End()
	{
		return m_end;
	}

	Item* RBegin()
	{
		return m_rbegin;
	}

	Item* REnd()
	{
		return m_rend;
	}

	void DeleteItems(Item* begin, Item* end, Item* rbegin, Item* rend)
	{
		m_rbegin = m_begin;
		m_rend = m_rbegin;

		while (m_rend)
		{
			m_rend = m_rend->next;
			delete (m_rbegin);
			m_rbegin = m_rend;
		}

		RawDealloc(begin);
		RawDealloc(end);
		RawDealloc(rbegin);
		RawDealloc(rend);
	}

	void RawDealloc(Item* p)
	{
		free(p);
	}

	~CMyList()
	{
		DeleteItems(m_begin, m_end, m_rbegin, m_rend);
	}

private:
	Item* m_begin = nullptr;
	Item* m_end = nullptr;
	Item* m_rbegin = nullptr;
	Item* m_rend = nullptr;
};
