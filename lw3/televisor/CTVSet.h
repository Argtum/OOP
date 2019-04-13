#pragma once

#include <boost/bimap.hpp>

typedef boost::bimap<int, string> BMType;
typedef BMType::value_type ChannelAndName;

class CTVSet
{
public:
	CTVSet();
	bool IsTurnedOn() const;
	void TurnOn();
	void TurnOff();
	int GetCurrentChannel() const;
	void SelectChannel(const int channel);
	void SelectPreviousChannel();
	void SetChannelName(const int channelNumber, const string& channelName);
	string GetChannelName(const int channel) const;
	int GetChannelByName(const string& channel) const;

private:
	static constexpr int MIN_CHANNEL = 1;
	static constexpr int MAX_CHANNEL = 99;
	bool m_isOn = false;
	int m_channel = 1;
	int m_previousChannel = 1;
	BMType m_channelList;
};
