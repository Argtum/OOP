#include "pch.h"
#include "CCommandHandler.h"
#include "IShape.h"

using namespace std;

int main(int argc, char argv[])
{
	CCommandHandler ch(cin, cout);
	while (!cin.eof() && !cin.fail())
	{
		try
		{
			if (!ch.HandleCommand())
			{
				cout << "Unknown command!\nUsage: Circle, Trinagle, Rectangle or LineSegment with parameters" << endl;
			}
		}
		catch (const exception& e)
		{
			cout << e.what();
		}
	}

	return 0;
}
