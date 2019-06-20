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
	if (v.empty())
	{
		return false;
	}

	max = v[0];

	for (size_t i = 0; i < v.size(); i++)
	{
		if (strcmp(v[i], max) > 0)
		{
			max = v[i];
		}
	}

	return true;
};
