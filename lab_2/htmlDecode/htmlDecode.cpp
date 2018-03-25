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

map <string, string> dictionary = { { "&quot;", "\"" },
{ "&apos;", "`" },
{ "&lt;", "<" },
{ "&gt;", ">" },
{ "&amp;", "&" } };

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
	if (argc != 2)
	{
		cout << "Invalid number of arguments. Input Example : vector.exe <file name>" << endl;
		return 1;
	}

	ifstream fIn(argv[1]);
	ofstream fOut("output.txt");

	if (!fIn.is_open())
	{
		cout << "Сan not open file " << argv[1] << endl;
		return 1;
	}

	string currentLine = "";
	string stringDecode = "";

	while (!fIn.eof())
	{
		getline(fIn, currentLine);
		cout << currentLine << endl;
		stringDecode = HtmlDecode(currentLine);
		cout << stringDecode << endl;
	}

	return 0;
}
