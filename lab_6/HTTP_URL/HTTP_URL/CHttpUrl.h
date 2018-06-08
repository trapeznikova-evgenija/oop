#pragma once

enum Protocol
{
	HTTP = 80,
	HTTPS = 443
};

const int MIN_BOUND_PORT = 1;
const int MAX_BOUND_PORT = 65535;

class CHttpUrl
{
public:
	CHttpUrl(string const& url);
	CHttpUrl(string const& domain, string const& document, Protocol protocol = HTTP);
	CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port);

	string GetURL() const;
	string GetDomain() const;
	string GetDocument() const;
	Protocol GetProtocol() const; 
	unsigned short GetPort() const;

	void CheckUrl(string const& url);
	Protocol AddProtocolValue(string const& protocol);
	unsigned short AddPortValue(string const& port);
	string AddDomainValue(string const& domain);
	string AddDocumentValue(string const& document);

private:

	string m_url;
	string m_domain;
	string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};
