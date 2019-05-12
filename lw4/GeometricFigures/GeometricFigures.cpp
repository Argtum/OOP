#include "pch.h"
#include "CCommandHandler.h"
#include "IShape.h"

using namespace std;

int main()
{
	CCommandHandler ch(cin, cout);
	while (!cin.eof() && !cin.fail())
	{
		if (!ch.HandleCommand())
		{
			cout << "Unknown command!\nUsage: LineSegment with parameters" << endl;
		}
	}
	/*shapeInfo.PrintShapeWithMaxArea();
	shapeInfo.PrintShapeWithMinPerimeter();*/

	return 0;
}
