#include "stdafx.h"
#include "RemoteControl.h"
#include "TV.h"

using namespace std;

CRemoteControl::CRemoteControl(CTVSet & tv, istream & input, ostream & output) :
	m_tv(tv),
	m_input(input),
	m_output(output)
{
}

bool CRemoteControl::TurnOn()
{
	m_tv.TurnOn();
	m_output << "TV is turned on" << endl;
	return true;
}

bool CRemoteControl::TurnOff()
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
	return true;
}

bool CRemoteControl::Info()
{
	string info;

	if (m_tv.isTurnedOn())
	{
		info = "TV is turned on\nChannel is: " + to_string(m_tv.GetChannel()) + "\n";
	} else
	{
		info = "TV is turned off\n";
	}

	m_output << info;
	return true;
}

bool CRemoteControl::SelectChannel(int channel)
{
	m_tv.SelectChannel(channel);
	m_output << "Переключили на " << m_tv.GetChannel() << " канал" << endl;
	return true;
}

int DetermineChannel(string &userString)
{
	int channel = 0;
	auto it = find_if(userString.begin(), userString.end(), isdigit);

	if (it != userString.end()) channel = atoi(userString.c_str() + (it - userString.begin()));
	
	return channel;
}

bool IsSelectedChannel(string userCommand)
{
	if (userCommand.find("SelectChannel") == -1)
	{
		return false;
	}

	return true;
}
