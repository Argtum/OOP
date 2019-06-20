#pragma once

template <typename T>
bool FindMax(std::vector<T> const& v, T& max)
{
	if (v.empty())
	{
		return false;
	}

	const T* maxElement = &v[0];

	for (auto& currentElement : v)
	{
		if (*maxElement < currentElement)
		{
			maxElement = &currentElement;
		}
	}

	max = *maxElement;

	return true;
}

template <>
bool FindMax<const char*>(std::vector<const char*> const& v, const char*& max)
{
	return true;
};
