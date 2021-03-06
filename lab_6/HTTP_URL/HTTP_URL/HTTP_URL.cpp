#include "stdafx.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

string DefineProtocol(CHttpUrl& url);
void ShowUrlInformation(CHttpUrl& url);

int main()
{
	string userString;

	while (getline(cin, userString))
	{
		try
		{
			CHttpUrl url(userString);
			ShowUrlInformation(url);

		} catch (CUrlParsingError error)
		{
			cout << error.what() << endl;
		}
	}
    return 0;
}

void ShowUrlInformation(CHttpUrl& url)
{
	cout << "Url: " << url.GetURL() << endl;
	cout << "Protocol: " << DefineProtocol(url) << endl;
	cout << "Domain: " << url.GetDomain() << endl;
	cout << "Port: " << url.GetPort() << endl;
	cout << "Document: " << url.GetDocument() << endl;
}

string DefineProtocol(CHttpUrl& url)
{
	Protocol protocol =  url.GetProtocol();
	if (protocol == HTTP)
	{
		return "http";
	} else if (protocol == HTTPS)
	{
		return "https";
	}

	return "";
}