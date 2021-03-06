// htmlDecode.cpp: определяет точку входа для консольного приложения.
// Программа выполняет построчное декодирование HTML-сущностей строки html, перечисленных в варианте 3, обратно в их символьное представление.


#include "stdafx.h"
#include "htmlDecode.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map <string, string> dictionary = {
{ "&quot;", "\"" },
{ "&apos;", "`" },
{ "&lt;", "<" },
{ "&gt;", ">" },
{ "&amp;", "&" } };

const string EXIT_STRING = "";

string ReplaceAll(string &str, string &from, string &to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}

string HtmlDecode(string & html)
{
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		string oldValue = it->first;
		string newValue = it->second;
		ReplaceAll(html, oldValue, newValue);

	}
	return html;
}

int main(int argc, char* argv[])
{
	if (argc != 1)
	{
		cout << "Invalid number of arguments. Input Example : htmlDecode.exe" << endl;
		return 1;
	}

	string currentLine = " ";
	string stringDecode = "";

	while (getline(cin, currentLine) and currentLine != EXIT_STRING)
	{
		stringDecode = HtmlDecode(currentLine);
		cout << stringDecode << endl;
	}

	return 0;
}
