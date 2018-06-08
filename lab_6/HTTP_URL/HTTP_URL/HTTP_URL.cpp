#include "stdafx.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

int main()
{
	string userString;

	while (getline(cin, userString))
	{
		try
		{
			CHttpUrl url(userString);

			cout << "Url: " << url.GetURL() << endl;
			cout << "Protocol: " << url.GetProtocol() << endl;
			cout << "Domain: " << url.GetDomain() << endl;
			cout << "Port: " << url.GetPort() << endl;
			cout << "Document: " << url.GetDocument() << endl;

		} catch (CUrlParsingError error)
		{
			cout << error.what() << endl;
		}
	}
    return 0;
}

