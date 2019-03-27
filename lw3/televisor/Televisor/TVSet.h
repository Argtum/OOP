#pragma once

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
		return 1;
	}

private:
	bool m_isOn = false;
};
