#pragma once
#include "InvalidOperation.h"

class TVSet
{
public:
	bool IsTurnedOn() const
	{
		return m_isOn;
	}
	void TurnOn()
	{
		m_isOn = true;
	}
	void TurnOff()
	{
		m_isOn = false;
	}
	int GetCurrentChannel() const
	{
		return m_isOn ? m_channel : 0;
	}
	void SelectChannel(int channel)
	{
		if (!m_isOn)
		{
			throw InvalidOperation("TV is turned off");
		}
		if (channel < MIN_CHANNEL || channel > MAX_CHANNEL)
		{
			throw InvalidOperation("Channel is out of range");
		}
		m_channel = channel;
	}

private:
	static constexpr int MIN_CHANNEL = 1;
	static constexpr int MAX_CHANNEL = 999;
	bool m_isOn = false;
	int m_channel = 1;
};
