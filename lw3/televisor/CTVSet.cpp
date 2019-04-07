#include "pch.h"

#include "CError.h"
#include "CTVSet.h"

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
	/*if (!m_isOn)
	{
		throw CError("ERROR: Turned off TV can't switches channel\n");
	}
	if (channel < MIN_CHANNEL || channel > MAX_CHANNEL)
	{
		throw CError("Channel is out of range");
	}*/
	m_channel = channel;
}
