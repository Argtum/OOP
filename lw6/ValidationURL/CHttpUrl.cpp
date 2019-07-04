#include "pch.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

using namespace std;

CHttpUrl::CHttpUrl(string const& url)
{
	regex ex("([\\w]*)://([^/ :]+)(/[^:#?\\s]*)?(:([0-9]{1,5}))?");
	cmatch what;
	string protocol, domain, document, port;

	if (regex_match(url.c_str(), what, ex))
	{
		protocol = string(what[1].first, what[1].second);
		domain = string(what[2].first, what[2].second);
		m_document = string(what[3].first, what[3].second);
		port = string(what[5].first, what[5].second);

		m_protocol = StringToProtocol(protocol);
		m_domain = !domain.empty() ? domain : throw CUrlParsingError("ERROR: wrong url\nURL must consist of protocol://domain/dodumen:port\n");
		m_port = StringToUnsignedShort(port, m_protocol);
	}
	else
	{
		throw CUrlParsingError("ERROR: wrong url\nURL must consist of protocol://domain/dodumen:port\n");
	}
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol)
	: m_protocol(protocol)
{
	m_domain = !domain.empty() ? domain : throw CUrlParsingError("ERROR: wrong url\nURL must consist of protocol://domain/dodumen:port\n");
	m_document = !document.empty() ? document : throw CUrlParsingError("ERROR: wrong url\nURL must consist of protocol://domain/dodumen:port\n");

	if (protocol == Protocol::HTTPS)
	{
		m_port = 443;
	}
	else
	{
		m_port = 80;
	}
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port)
	: m_protocol(protocol)
{
	m_domain = !domain.empty() ? domain : throw CUrlParsingError("ERROR: wrong url\nURL must consist of protocol://domain/dodumen:port\n");
	m_document = !document.empty() ? document : throw CUrlParsingError("ERROR: wrong url\nURL must consist of protocol://domain/dodumen:port\n");

	if (port != 0)
	{
		m_port = port;
	}
	else
	{
		throw CUrlParsingError("ERROR: wrong port\nPort can not be zero\n");
	}
}

string CHttpUrl::GetUrl() const
{
	string protocol = "http";
	string url;

	if (m_protocol == Protocol::HTTPS)
	{
		protocol = "https";
	}

	url = protocol + "://" + m_domain + m_document + ":" + to_string(m_port);

	return url;
}

string CHttpUrl::GetDomain() const
{
	return m_domain;
}

string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol()
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

void ToLowercase(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

Protocol StringToProtocol(string& inpString)
{
	ToLowercase(inpString);
	Protocol protocol;

	if (inpString == "https")
	{
		protocol = Protocol::HTTPS;
	}
	else if (inpString == "http")
	{
		protocol = Protocol::HTTP;
	}
	else
	{
		throw CUrlParsingError("ERROR: wrong protocol value\nProtocol must be http or https\n");
	}

	return protocol;
}

unsigned short StringToUnsignedShort(string& port, Protocol protocol)
{
	if (port.empty())
	{
		return protocol == Protocol::HTTP ? 80 : 443;
	}
	else
	{
		try
		{
			unsigned short p = static_cast<unsigned short>(strtoul(port.c_str(), NULL, 10));

			if (p == 0)
			{
				throw CUrlParsingError("ERROR: wrong port\nPort can not be zero\n");
			}

			return p;
		}
		catch (CUrlParsingError error)
		{
			throw error;
		}
	}
}
