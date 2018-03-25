// htmlDecodeTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../htmlDecode/htmlDecode.h"

using namespace std;

string one = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
string oneResult = "Cat <says> \"Meow\". M&M`s";

TEST_CASE("TestFunction test")
{
	HtmlDecode(one);
	CHECK(one == oneResult);
}