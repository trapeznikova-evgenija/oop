#pragma once
#include "stdafx.h"

class CUrlParsingError : public invalid_argument
{
public:
	CUrlParsingError(string const& message);
};