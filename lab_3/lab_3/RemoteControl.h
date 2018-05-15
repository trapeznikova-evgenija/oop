#pragma once
#include <boost/noncopyable.hpp>
using namespace std;

class CTVSet;

class CRemoteControl : boost::noncopyable
{
public:
	CRemoteControl(CTVSet & tv, istream & input, ostream & output);

	bool TurnOn();
	bool TurnOff();
	bool Info();
	bool SelectChannel(int channel);

private:

	CTVSet & m_tv;
	istream & m_input;
	ostream & m_output;
};

int DetermineChannel(string &userString);
bool IsSelectedChannel(string userCommand);