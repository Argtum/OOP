#include "pch.h"
#include "ParseUrl.h"

using namespace std;

void ParseUrl(string const& url)
{
	boost::regex ex("(http|https)://([^/ :]+)(/?[^ #?]*):([^/ ]*)");
	boost::cmatch what;
	string protocol, domain, path, port;

	if (regex_match(url.c_str(), what, ex))
	{
		protocol = string(what[1].first, what[1].second);
		domain = string(what[2].first, what[2].second);
		path = string(what[3].first, what[3].second);
		port = string(what[4].first, what[4].second);
	}
}
