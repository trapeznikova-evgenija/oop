#include "stdafx.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

CHttpUrl::CHttpUrl(string const& url) :
	m_url(url)
{
	CheckUrl(url);
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol) :
	m_domain(domain),
	m_document(document),
	m_protocol(protocol)
{
	if (domain.empty())
	{
		throw CUrlParsingError("You enter empty domain");
	}

	string protocolStr = "";

	if (protocol == HTTP)
	{
		protocolStr = "http://";
	} else if (protocol == HTTPS)
	{
		protocolStr = "https://";
	}

	m_document = AddDocumentValue(document);

	m_url = protocolStr + m_domain + m_document;
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port) :
	m_domain(domain),
	m_document(document),
	m_protocol(protocol),
	m_port(port)
{

}

Protocol CHttpUrl::AddProtocolValue(string const& protocolName)
{
	Protocol protocol;

	if (protocolName == "http")
	{
		protocol = HTTP;
		return protocol;
	} else if (protocolName == "https")
	{
		protocol = HTTPS;
		return protocol;
	} else
	{
		throw CUrlParsingError("Unknown Protocol type");
	}

}

string CHttpUrl::AddDomainValue(string const& domain)
{
	return domain;
}

bool IsValidRange(unsigned short port)
{
	return (port >= MIN_BOUND_PORT) && (port <= MAX_BOUND_PORT);
}

unsigned short CHttpUrl::AddPortValue(string const& portNumber)
{
	if (portNumber.empty())
	{
		cout << "static_cast<unsigned short>(m_protocol) " << endl;
		return static_cast<unsigned short>(m_protocol);
	}

	auto port = stoi(portNumber);

	if (IsValidRange(port))
	{
		return port;
	} else
	{
		throw CUrlParsingError("Port out of range");
	}
}

string CHttpUrl::AddDocumentValue(string const& documentName)
{

	if (documentName.empty() || (documentName[0] != '/'))
	{
		return "/" + documentName;
	}
	return documentName;
}

void CHttpUrl::CheckUrl(string const& url) 
{
	if (url == "")
	{
		throw CUrlParsingError("URL cannot be saved, because it empty");
	}

	regex regularExpression(R"(^(\w+):\/\/([^\s:\/]+)(?::(\d+))?(?:\/(\S*))?$)", regex::icase);
	smatch partsUrl;
	bool isSearch = regex_search(url, partsUrl, regularExpression);

	if (!isSearch)
	{
		throw CUrlParsingError("URL was not validated");
	}

	m_protocol = AddProtocolValue(partsUrl[1]);
	m_domain = AddDomainValue(partsUrl[2]);
	m_port = AddPortValue(partsUrl[3]);
	m_document = AddDocumentValue(partsUrl[4]);	
}

string CHttpUrl::GetURL() const
{
	return m_url;
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

