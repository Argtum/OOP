#include "pch.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

using namespace std;

CHttpUrl::CHttpUrl(string const& url)
{
	regex ex("([\\w]*)://([^/ :]+)(/?[^ #?]*):([^/ ]*)?");
	cmatch what;
	string protocol, domain, document, port;
	CUrlParsingError error("ERROR: wrong url\nURL must consist of protocol://domain/dodumen:port\n");

	try
	{
		if (regex_match(url.c_str(), what, ex))
		{
			protocol = string(what[1].first, what[1].second);
			domain = string(what[2].first, what[2].second);
			document = string(what[3].first, what[3].second);
			port = string(what[4].first, what[4].second);

			m_protocol = StringToProtocol(protocol);
			m_domain = !domain.empty() ? domain : throw error;
			m_document = !document.empty() ? document : throw error;
			m_port = StringToUnsignedShort(port, m_protocol);
		}
		else
		{
			throw error;
		}
	}
	catch (invalid_argument const& e)
	{
		throw e;
	}
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol)
	: m_protocol(protocol)
{
	CUrlParsingError error("ERROR: wrong url\nURL must consist of protocol://domain/dodumen:port\n");

	m_domain = domain.empty() ? throw error : domain;
	m_document = document.empty() ? throw error : document;

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
	, m_port(port)
{
	CUrlParsingError error("ERROR: wrong url\nURL must consist of protocol://domain/dodumen:port\n");

	m_domain = domain.empty() ? throw error : domain;
	m_document = document.empty() ? throw error : document;
}

string CHttpUrl::GetUrl() const
{
	string protocol = "http";
	string url;

	if (m_protocol == Protocol::HTTPS)
	{
		protocol = "https";
	}

	if (m_port != 0)
	{
		url = protocol + "://" + m_domain + m_document + ":" + to_string(m_port);
	}
	else
	{
		url = protocol + "://" + m_domain + m_document;
	}

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
		CUrlParsingError error("ERROR: wrong protocol value\nProtocol must be http or https\n");
		throw error;
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
			return static_cast<unsigned short>(strtoul(port.c_str(), NULL, 0));
		}
		catch (CUrlParsingError error)
		{
			throw error;
		}
	}
}
