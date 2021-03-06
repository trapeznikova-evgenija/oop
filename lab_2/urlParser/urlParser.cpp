#include "stdafx.h"
#include "urlParser.h"

bool ParseURL(string const& url, Protocol & protocol, int & port, string & host, string & document)
{
	//проверить всю строку на соответствие регулярному выражению regex_match
	//дальше уже смотреть по вхождениям
	cmatch result;
	regex regular("email");

	cout << "result.size " << result.size() << endl;
	if (regex_match(url.c_str(), result, regular))
	{
		for (size_t i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
		return true;
	}
	return false;
}

void PrintParseURL(string const& url, Protocol & protocol, int & port, string & host, string & document)
{

}

void PrintFailedAnswer()
{
	cout << "Введенный URL не валиден. Попробуйте еще." << endl;
}

void DialogWithUser(string &url)
{
	while (url != EXIT_STRING)
	{
		Protocol protocol;
		int port;
		string host;
		string document;
		if (ParseURL(url, protocol, port, host, document))
		{
			PrintParseURL(url, protocol, port, host, document);
		} else
		{
			PrintFailedAnswer();
		}
		getline(cin, url);
	}
}

