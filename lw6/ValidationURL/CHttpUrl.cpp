#include "pch.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

using namespace std;

CHttpUrl::CHttpUrl(string const& url)
{
	regex ex("([\\w]*)://([^/ :]+)(:([0-9]{1,5}))?(/[^:#?\\s]*)?");
	cmatch what;
	string protocol, domain, port;

	if (regex_match(url.c_str(), what, ex))
	{
		protocol = string(what[1].first, what[1].second);
		domain = string(what[2].first, what[2].second);
		m_document = string(what[5].first, what[5].second);
		port = string(what[4].first, what[4].second);

		m_protocol = StringToProtocol(protocol);
		m_domain = !domain.empty() ? domain : throw CUrlParsingError("ERROR: wrong url\nURL must consist of protocol://domain:port/documen\n");
		m_port = StringToUnsignedShort(port, m_protocol);
	}
	else
	{
		throw CUrlParsingError("ERROR: wrong url\nURL must consist of protocol://domain/documen:port\n");
	}
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol)
	: m_protocol(protocol)
{
	string errorMessage = "ERROR: wrong url\nURL must consist of protocol://domain:port/documen\n";

	m_domain = !domain.empty() ? domain : throw CUrlParsingError(errorMessage);
	m_document = !document.empty() ? document : throw CUrlParsingError(errorMessage);

	if (protocol == Protocol::HTTPS)
	{
		m_port = 443;
	}
	else
	{
		m_port = 80;
	}
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, int port)
	: m_protocol(protocol)
{
	string errorMessage = "ERROR: wrong url\nURL must consist of protocol://domain:port/documen\n";

	m_domain = !domain.empty() ? domain : throw CUrlParsingError(errorMessage);
	m_document = !document.empty() ? document : throw CUrlParsingError(errorMessage);

	m_port = CheckPortRange(port);
}

string CHttpUrl::GetUrl() const
{
	string protocol = "http";
	string url;
	string port = "";

	if (m_protocol == Protocol::HTTPS)
	{
		protocol = "https";
	}

	if (!(m_protocol == Protocol::HTTP && m_port == 80) && !(m_protocol == Protocol::HTTPS && m_port == 443))
	{
		port = ":" + PortToString(m_port);
	}

	url = protocol + "://" + m_domain + port + m_document + "\n";

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

Protocol CHttpUrl::GetProtocol() const
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
			int p = static_cast<int>(strtoul(port.c_str(), NULL, 10));

			return CheckPortRange(p);
		}
		catch (CUrlParsingError error)
		{
			throw error;
		}
	}
}

unsigned short CheckPortRange(const int port)
{
	if (port < 1 || port > USHRT_MAX)
	{
		throw CUrlParsingError("ERROR: wrong port\nPort must be in the range of 1 to 65535\n");
	}

	return (unsigned short)port;
}

string ProtocolToString(const Protocol& protocol)
{
	return protocol == Protocol::HTTP ? "http" : "https";
}

string PortToString(unsigned short port)
{
	return to_string(port);
}

string PrintUrlParameters(const CHttpUrl& url)
{
	return "\nProtocol: " + ProtocolToString(url.GetProtocol()) + "\n"
		+ "Domain: " + url.GetDomain() + "\n"
		+ "Port: " + PortToString(url.GetPort()) + "\n"
		+ "Document: " + url.GetDocument() + "\n"
		+ url.GetUrl() + "\n";
}
