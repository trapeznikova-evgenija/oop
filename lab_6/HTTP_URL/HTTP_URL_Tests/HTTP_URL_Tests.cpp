#include "stdafx.h"
#include "../HTTP_URL/CHttpUrl.h"
#include "../HTTP_URL/CUrlParsingError.h"

TEST_CASE("CHttpUrl(string const& url) Tests")
{
	cout << "Create CHttpUrl.h" << endl;
	CHttpUrl url("http://www.mysite.com/docs/document.html");

	cout << "Check GetUrl()" << endl;
	CHECK(url.GetURL() == "http://www.mysite.com/docs/document.html");

	cout << "Check AddProtocolValue()" << endl;
	CHECK(url.AddProtocolValue("http") == HTTP);
	CHECK(url.AddProtocolValue("https") == HTTPS);
	
	cout << "url.CheckUrl() with Invalid URL" << endl;
	//url.CheckUrl("ftp://www.mysite.com/docs/document.html");
	
	cout << "Check AddPortValue()" << endl;
	CHECK(url.AddPortValue("80") == 80);
	CHECK(url.AddPortValue("3200") == 3200);


	CHECK(url.AddPortValue("32000000"));

	cout << "Check AddDocumentValue()" << endl;
	CHECK(url.AddDocumentValue("docs/document.html") == "/docs/document.html");
	CHECK(url.AddDocumentValue("/docs/document.html") == "/docs/document.html");


	cout << "Check AddDomainValue()" << endl;
	CHECK(url.AddDomainValue("www.mysite.com") == "www.mysite.com");
}

TEST_CASE("CHttpUrl(string const& domain, string const& document, Protocol protocol) Tests")
{
	CHttpUrl url("www.mysite.com", "docs", HTTP);
	
	cout << url.GetURL() << endl;
}