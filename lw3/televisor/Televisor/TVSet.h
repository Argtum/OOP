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

private:
	bool m_isOn = false;
};
