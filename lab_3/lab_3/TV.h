#pragma once
using namespace std;

class CTVSet
{
public:
	bool isTurnedOn()const;
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int channel);
	int GetChannel()const;

private:
	bool m_isOn = false;
	int m_selectedChannel = 1;

};