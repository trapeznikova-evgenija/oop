#include "stdafx.h"
#include "minDictionary.h"

using namespace std;

const string EXIT_STRING = "...";

void FillOutMapFromFile(string fileName, MapStrings &dictionary)
{
	ifstream dictionaryFile(fileName);

	string wordForTranslation = "";
	string translation = "";

	while (getline(dictionaryFile, wordForTranslation))
	{
		getline(dictionaryFile, translation);
		dictionary.insert(pair<string, string>(wordForTranslation, translation));
	}

	/*for (auto it = dictionary.begin(); it != dictionary.end(); ++ it)
	{
		cout << (*it).first << " " <<  (*it).second << endl;
	}*/
}

void AddWordInDictionary(string word, string translationOfUser, MapStrings &dictionary)
{
	dictionary.insert(pair<string, string>(word, translationOfUser));
}

bool NeedSave(string stringOfUser)
{

	if (stringOfUser == "Y" or stringOfUser == "y")
	{
		return true;
	}

	return false;
}

void UpdateDictionaryFile(string fileName, MapStrings &dictionary)
{
	fstream file(fileName, ios::out);
	ofstream fOut(fileName);
	
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		fOut << (*it).first << endl;
		fOut <<  (*it).second << endl;
	}

}

void DialogWithUser(MapStrings &dictionary)
{
	string stringOfUser = "";
	string translationOfUser = "";
	bool changeDictionary = false;

	cout << "> ";
	getline(cin, stringOfUser);
	
	if (stringOfUser != EXIT_STRING)
	{
		while (stringOfUser != EXIT_STRING)
		{
			MapStrings::iterator it = dictionary.find(stringOfUser);
			if (it != dictionary.end()) // если введенное пользователем слово есть в словаре
			{
				cout << it->second << endl;
			} else
			{
				cout << "Неизвестное слово " << "\"" << stringOfUser << "\". " << "Введите перевод или пустую строку для отказа." << endl;
				cout << "> ";
				getline(cin, translationOfUser);
				if (translationOfUser != "")
				{
					AddWordInDictionary(stringOfUser, translationOfUser, dictionary);
					cout << "Слово " << "\"" << stringOfUser << "\" " << "сохранено в словаре как " << "\"" << translationOfUser << "\"." << endl;
					changeDictionary = true;
				} else
				{
					cout << "Слово " << "\"" << stringOfUser << "\" проигнорировано." << endl;
				}
			}
			cout << "> ";
			getline(cin, stringOfUser);
		}
	}

	if (changeDictionary)
	{
		cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;

	}
	
	
}

