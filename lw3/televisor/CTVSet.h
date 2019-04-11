#pragma once

#include <boost/bimap.hpp>

typedef boost::bimap<int, string> bm_type;
typedef bm_type::value_type ñhannelHasName;

class CTVSet
{
public:
	CTVSet();
	~CTVSet();
	bool IsTurnedOn() const;
	void TurnOn();
	void TurnOff();
	int GetCurrentChannel() const;
	void SelectChannel(const int& channel);
	void SelectPreviousChannel();
	void SetChannelName(const int& channelNumber, const string& channelName);
	string GetChannelName(const int& channel) const;

private:
	static constexpr int MIN_CHANNEL = 1;
	static constexpr int MAX_CHANNEL = 99;
	bool m_isOn = false;
	int m_channel = 1;
	int m_previousChannel = 1;
	bm_type m_channelList;
};
