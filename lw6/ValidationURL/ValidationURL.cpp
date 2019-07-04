#include "pch.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char argv[])
{
	string input, output;
	vector<string> urlParameters;

	while (cin >> input)
	{
		try
		{
			boost::split(urlParameters, input, boost::is_any_of(" "));

			if (urlParameters.size() >= 1 && urlParameters.size() <= 5)
			{
				if (urlParameters.size() == 1)
				{
					CHttpUrl url(urlParameters[0]);
					output = PrintUrlParameters(url);
				}
				else if (urlParameters.size() == 2)
				{
					CHttpUrl url(urlParameters[0], urlParameters[1]);
					output = PrintUrlParameters(url);
				}
				else if (urlParameters.size() == 3)
				{
					Protocol protocol = StringToProtocol(urlParameters[2]);
					CHttpUrl url(urlParameters[0], urlParameters[1], protocol);
					output = PrintUrlParameters(url);
				}
				else if (urlParameters.size() == 4)
				{
					Protocol protocol = StringToProtocol(urlParameters[2]);
					unsigned short port = StringToUnsignedShort(urlParameters[3], protocol);
					CHttpUrl url(urlParameters[0], urlParameters[1], protocol, port);
					output = PrintUrlParameters(url);
				}
			}
			else
			{
				cout << "ERROR: Wrong number of arguments!\nPlease enter the URL or its parameters: domain document protocol port" << endl;
			}

			cout << output;
		}
		catch (invalid_argument const& e)
		{
			cout << e.what() << endl;
		}
	}

	return 0;
}
