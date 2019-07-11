#pragma once
// Выполняет замену элементов в диапазоне, заданном итераторами [first, last),
// для которых унарная функция predicate возвращает true на newValue

template <typename it, typename T, typename Predicate>
void ReplaceIf(it first, it last, Predicate predicate, const T& newValue)
{
	for (auto i = first; i != last; ++i)
	{
		if (predicate(*i))
		{
			*i = newValue;
		}
	}
}
