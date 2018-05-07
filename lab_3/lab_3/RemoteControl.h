#pragma once
using namespace std;

class CTVSet;

bool TurnOn(CTVSet & tv);
bool TurnOff(CTVSet & tv);
bool Info(CTVSet & tv);
bool SelectChannel(CTVSet &tv, int channel);

int DetermineChannel(string &userString);