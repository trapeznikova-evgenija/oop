#pragma once

#include "stdafx.h"
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <Windows.h>
#include <cctype>
#include <locale>
#include <algorithm>

using namespace std;

typedef map<string, string> MapStrings;

MapStrings FillOutMapFromFile(string fileName);
bool DialogWithUser(MapStrings &dictionary);
bool NeedSave(string stringOfUser);
void UpdateDictionaryFile(string fileName, MapStrings &dictionary);
string GetLowerCase(string &stringOfUser);