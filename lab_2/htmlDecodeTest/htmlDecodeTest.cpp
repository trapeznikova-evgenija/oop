// htmlDecodeTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../htmlDecode/htmlDecode.h"

using namespace std;

string one = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
string oneResult = "Cat <says> \"Meow\". M&M`s";

string two = "My wonderful day";
string twoResult = "My wonderful day";

string tree = "";
string treeResult = "";

string four = "&quot;&apos;Mother &quot;&apos;&apos;&quot; wash window&apos;&quot;";
string fourResult = "\"`Mother \"``\" wash window`\"";

TEST_CASE("TestFunction test")
{
	HtmlDecode(one);
	CHECK(one == oneResult);

	HtmlDecode(two);
	CHECK(two == twoResult);

	HtmlDecode(tree);
	CHECK(tree == treeResult);

	HtmlDecode(four);
	CHECK(four == fourResult);
}