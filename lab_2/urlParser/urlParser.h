#pragma once
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <regex>
#include <string>

using namespace std;

const string EXIT_STRING = "";

enum class Protocol
{
	HTTP,
	HTTPS,
	FTP
};

struct Port—onstraints
{
	const int LOWER_BOUND = 1;
	const int UPPER_BOUND = 65535;
};

bool ParseURL(string const& url, Protocol & protocol, int & port, string & host, string & document);
void DialogWithUser(string &url);