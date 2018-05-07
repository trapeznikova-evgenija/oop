#include "stdafx.h"
#include "RemoteControl.h"
#include "TV.h"

using namespace std;

bool TurnOn(CTVSet & tv)
{
	tv.TurnOn();
	cout << "TV is turned on" << endl;
	return true;
}

bool TurnOff(CTVSet & tv)
{
	tv.TurnOff();
	cout << "TV is turned off" << endl;
	return true;
}

bool Info(CTVSet & tv)
{
	string info;

	if (tv.isTurnedOn())
	{
		info = "TV is turned on\nChannel is: " + to_string(tv.GetChannel()) + "\n";
	} else
	{
		info = "TV is turned off\n";
	}

	cout << info;
	return true;
}

bool SelectChannel(CTVSet &tv, int channel)
{
	tv.SelectChannel(channel);
	cout << "Переключили на " << tv.GetChannel() << "канал" << endl;
	return true;
}

int DetermineChannel(string &userString)
{
	int channel = 0;
	auto it = find_if(userString.begin(), userString.end(), isdigit);

	if (it != userString.end()) channel = atoi(userString.c_str() + (it - userString.begin()));
	
	return channel;
}
