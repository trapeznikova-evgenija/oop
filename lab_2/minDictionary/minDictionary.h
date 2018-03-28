#pragma once

#include "stdafx.h"
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

typedef map<string, string> MapStrings;

MapStrings FillOutMapFromFile(string fileName, MapStrings &dictionary);
void DialogWithUser(MapStrings &dictionary);
bool NeedSave(string stringOfUser);
void UpdateDictionaryFile(string fileName, MapStrings &dictionary);