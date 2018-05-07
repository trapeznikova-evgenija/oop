#include "stdafx.h"
#include "TV.h"
#include "RemoteControl.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	CTVSet tv;

	string userCommand = "";

	while (getline(cin, userCommand))
	{

	  if (userCommand == "TurnOn")
	  {
		  TurnOn(tv);
	  } else if (userCommand == "TurnOff")
	  {
		  TurnOff(tv);

	  } else if (userCommand == "Info")
	  {
		  Info(tv);
	  } else //выбор канала
	  {
		  int channel = DetermineChannel(userCommand);
		  SelectChannel(tv, channel);
	  };
	}

    return 0;
}

