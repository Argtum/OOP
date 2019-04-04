#include "pch.h"

#include "CTVSet.h"
#include "Error.h"

CTVSet::CTVSet()
{
}

CTVSet::~CTVSet()
{
}

bool CTVSet::IsTurnedOn() const
{
	return m_isOn;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}
void CTVSet::TurnOff()
{
	m_isOn = false;
}

int CTVSet::GetCurrentChannel() const
{
	return m_isOn ? m_channel : 0;
}

void CTVSet::SelectChannel(int channel)
{
	if (!m_isOn)
	{
		throw Error("TV is turned off");
	}
	if (channel < MIN_CHANNEL || channel > MAX_CHANNEL)
	{
		throw Error("Channel is out of range");
	}
	m_channel = channel;
}
