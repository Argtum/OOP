#include "pch.h"
#include "exam/ReplaceIf.h"

TEST_CASE("ReplaceIf")
{
	int items[] = { 1, 2, 3, -4, 5, 2, 3 };
	int resultItems[] = { 1, 2, 3, 0, 5, 2, 3 };
	ReplaceIf(
		std::begin(items), std::end(items), [](const int& x) { return x < 0; }, 0);

	CHECK(resultItems == items);
}
