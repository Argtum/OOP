#include "pch.h"
#include "ReplaceIf.h"

int main()
{
	int items[] = { 1, 2, 3, -4, 5, 2, 3 };
	// �������� ��� ��������, ������� 0 �� 0
	ReplaceIf(
		std::begin(items), std::end(items), [](const int& x) { return x < 0; }, 0);
	/* ������� items � stdout */

	for (int item : items)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl
			  << std::endl;

	std::vector<std::string> strings = { "One", "Two", "Three", "Four", "Five", "", "Seven" };
	// �������� ��� ������ ������ �� "Empty"
	ReplaceIf(
		strings.begin(), strings.end(), [](const std::string& str) { return str.empty(); }, "Empty");
	/* ������� items � stdout */

	copy(strings.begin(), strings.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl
			  << std::endl;

	return 0;
}
