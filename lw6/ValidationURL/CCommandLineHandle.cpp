#include "pch.h"
#include "CCommandLineHandle.h"
#include "CHttpUrl.h"
#include <boost/algorithm/string.hpp>

using namespace std;

CCommandLineHandle::CCommandLineHandle(istream& input, ostream& output)
	: m_input(input)
	, m_output(output)
{
}

bool CCommandLineHandle::HandleCommand()
{
	vector<string> urlParameters;
	string commandLine;
	getline(m_input, commandLine);

	if (commandLine.empty())
	{
		throw invalid_argument("ERROR: Empty input!\nPlease enter the URL or its parameters: domain document protocol port\n");
	}

	boost::split(urlParameters, commandLine, boost::is_any_of(" "));

	if (urlParameters.size() == 1)
	{
		CHttpUrl url(urlParameters[0]);
	}
	else if (urlParameters.size() == 2)
	{
		CHttpUrl url(urlParameters[0], urlParameters[1]);
	}
	else if (urlParameters.size() == 3)
	{
		Protocol protocol = StringToProtocol(urlParameters[2]);
		CHttpUrl url(urlParameters[0], urlParameters[1], protocol);
	}
	else if (urlParameters.size() == 4)
	{
		Protocol protocol = StringToProtocol(urlParameters[2]);
		unsigned short port = static_cast<unsigned short>(strtoul(urlParameters[3].c_str(), NULL, 0));
		CHttpUrl url(urlParameters[0], urlParameters[1], protocol, port);
	}

	return true;
}
