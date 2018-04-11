#include "stdafx.h"
#include "urlParser.h"

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	if (argc != 1)
	{
		cout << "Неправильный ввод. Пример: <urlParser.exe> <URL-string>";
	}

	string userString = "";
	getline(cin, userString);
	if (userString != EXIT_STRING)
	{
		DialogWithUser(userString);
	}
	return 0;
}

