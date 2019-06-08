#pragma once

enum class Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = Protocol::HTTP);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);
	std::string GetUrl() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol();
	unsigned short GetPort() const;

private:
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};
