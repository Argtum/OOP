#include "pch.h"
#include "CHttpUrl.h"

using namespace std;

CHttpUrl::CHttpUrl(string const& url)
{
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol)
	: m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
{
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port)
	: m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
	, m_port(port)
{
}

string CHttpUrl::GetURL() const
{
	string protocol = "http";

	if (m_protocol == Protocol::HTTPS)
	{
		protocol = "https";
	}

	return protocol + "://" + m_domain + "/" + m_document + ":" + to_string(m_port);
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
