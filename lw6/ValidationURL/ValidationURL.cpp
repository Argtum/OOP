#include "pch.h"
#include "CHttpUrl.h"
#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char argv[])
{
	string input, output;
	vector<string> urlParameters;

	try
	{
		while (cin >> input)
		{
			boost::split(urlParameters, input, boost::is_any_of(" "));

			if (urlParameters.size() == 1)
			{
				CHttpUrl url(urlParameters[0]);
				output = url.GetUrl();
			}
			else if (urlParameters.size() == 2)
			{
				CHttpUrl url(urlParameters[0], urlParameters[1]);
				output = url.GetUrl();
			}
			else if (urlParameters.size() == 3)
			{
				Protocol protocol = StringToProtocol(urlParameters[2]);
				CHttpUrl url(urlParameters[0], urlParameters[1], protocol);
				output = url.GetUrl();
			}
			else if (urlParameters.size() == 4)
			{
				Protocol protocol = StringToProtocol(urlParameters[2]);
				unsigned short port = static_cast<unsigned short>(strtoul(urlParameters[3].c_str(), NULL, 0));
				CHttpUrl url(urlParameters[0], urlParameters[1], protocol, port);
				output = url.GetUrl();
			}
			else
			{
				output = "ERROR: Wrong number of arguments!\nPlease enter the URL or its parameters: domain document protocol port\n";
			}

			cout << output;
		}

		return 0;
	}
	catch (exception const& e)
	{
		cout << e.what() << endl;
		return 1;
	}
}
