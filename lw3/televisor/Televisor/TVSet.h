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
			return m_channel;
		}
		void SelectChannel(int channel)
		{
			m_channel = channel;
		}

	private:
		bool m_isOn = false;
		int m_channel = 1;
};
