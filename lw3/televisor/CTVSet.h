#pragma once

class CTVSet
{
public:
	CTVSet();
	~CTVSet();
	bool IsTurnedOn() const;
	void TurnOn();
	void TurnOff();
	/*int GetCurrentChannel() const;
	void SelectChannel(int channel);
	*/
private:
	/*	static constexpr int MIN_CHANNEL = 1;
	static constexpr int MAX_CHANNEL = 999;*/
	bool m_isOn = false;
	int m_channel = 1;
};
