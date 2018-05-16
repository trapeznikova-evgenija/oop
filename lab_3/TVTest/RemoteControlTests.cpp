#include "stdafx.h"
#include "../lab_3/RemoteControl.h"
#include "../lab_3/TV.h"

CTVSet tv;
CRemoteControl remoteControl(tv, cin, cout);

TEST_CASE("RemoteControl Tests")
{
	cout << "RemoteControl Tests" << endl;

	string command = "SelectChannel 5";
	CHECK(DetermineChannel(command) == 5);

	remoteControl.TurnOff();
	remoteControl.TurnOn();
	CHECK(tv.GetChannel() == 1);

	remoteControl.SelectChannel(25);
	CHECK(tv.GetChannel() == 25);
	remoteControl.TurnOff();
	remoteControl.TurnOn();
	cout << "Checking what really switched" << endl;
	CHECK(tv.GetChannel() == 25);

}

TEST_CASE("SelectedChannel Function Tests")
{
	CHECK(IsSelectedChannel("SelectChannel 232") == true);
	CHECK(IsSelectedChannel("Beautiful Life M") == false);
}