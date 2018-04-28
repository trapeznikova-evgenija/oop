#include "stdafx.h"
#include "TV.h";

void CTVSet::TurnOff()
{
	m_isOn = false;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}

bool CTVSet::isTurnedOn()const
{
	return m_isOn;
}

bool CTVSet::SelectChannel(int channel)
{
	bool isAvailableChannel = (channel >= 1) and (channel <= 99);

	if (isAvailableChannel and m_isOn)
	{
		m_selectedChannel = channel;
		return true;
	}

	return false;
}

int CTVSet::GetChannel()const
{
	return m_isOn ? m_selectedChannel : 0;
}