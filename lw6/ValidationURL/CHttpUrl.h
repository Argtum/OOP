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
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, int port);
	std::string GetUrl() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

private:
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};

void ToLowercase(std::string& str);
Protocol StringToProtocol(std::string& inpString);
unsigned short StringToUnsignedShort(std::string& port, Protocol protocol);
unsigned short CheckPortRange(const int port);

std::string ProtocolToString(const Protocol& protocol);
std::string PortToString(unsigned short port);
std::string PrintUrlParameters(const CHttpUrl& url);
