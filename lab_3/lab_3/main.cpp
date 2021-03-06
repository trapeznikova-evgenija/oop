#include "stdafx.h"
#include "TV.h"
#include "RemoteControl.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	CTVSet tv;
	CRemoteControl remoteControl(tv, cin, cout);

	string userCommand = "";

	while (getline(cin, userCommand))
	{
		if (userCommand == "TurnOn")
		{
			remoteControl.TurnOn();
		} else if (userCommand == "TurnOff")
		{
			remoteControl.TurnOff();

		} else if (userCommand == "Info")
		{
			remoteControl.Info();
		} else if (IsSelectedChannel(userCommand)) //выбор канала
		{
			int channel = DetermineChannel(userCommand);
			remoteControl.SelectChannel(channel);
		} else
		{
			cout << "Unknown command!" << endl;
		}
	}

    return 0;
}

