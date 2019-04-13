#include "pch.h"
#include "CRemoteControl.h"
#include "CError.h"
#include "CTVSet.h"

CRemoteControl::CRemoteControl(CTVSet& tv, istream& input, ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "TurnOn", [this](istream& strm) { return TurnOn(strm); } },
		  { "TurnOff", bind(&CRemoteControl::TurnOff, this, placeholders::_1) },
		  { "Info", bind(&CRemoteControl::Info, this, placeholders::_1) },
		  { "SelectChannel", bind(&CRemoteControl::SelectChannel, this, placeholders::_1) },
		  { "PreviousChannel", bind(&CRemoteControl::PreviousChannel, this, placeholders::_1) },
		  { "SetChannel", bind(&CRemoteControl::SaveChannel, this, placeholders::_1) },
		  { "WhatChannelNumber", bind(&CRemoteControl::WhatChannelNumber, this, placeholders::_1) },
		  { "WhatChannelName", bind(&CRemoteControl::WhatChannelName, this, placeholders::_1) },

	  })
{
}

CRemoteControl::~CRemoteControl()
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto instruction = m_actionMap.find(action);
	if (instruction != m_actionMap.end())
	{
		return instruction->second(strm);
	}

	return false;
}

bool CRemoteControl::TurnOn(istream& args)
{
	m_tv.TurnOn();
	m_output << "TV is turned on\n";
	return true;
}

bool CRemoteControl::TurnOff(istream& args)
{
	m_tv.TurnOff();
	m_output << "TV is turned off\n";
	return true;
}

bool CRemoteControl::Info(istream& args)
{
	string info = (m_tv.IsTurnedOn()) ? ("TV is turned on\nChannel is: " + to_string(m_tv.GetCurrentChannel()) + "\n") : "TV is turned off\n";

	m_output << info;

	return true;
}

bool CRemoteControl::SelectChannel(istream& args)
{
	int channelNumber = *istream_iterator<int>(args);

	m_tv.SelectChannel(channelNumber);

	m_output << "Channel changed to " + to_string(m_tv.GetCurrentChannel()) + "\n";

	return true;
}

bool CRemoteControl::PreviousChannel(istream& args)
{
	m_tv.SelectPreviousChannel();

	m_output << "Channel changed to " + to_string(m_tv.GetCurrentChannel()) + "\n";

	return true;
}

bool CRemoteControl::SaveChannel(istream& args)
{
	int channelNumber = *istream_iterator<int>(args);
	string channelName = *istream_iterator<string>(args);

	m_tv.SetChannelName(channelNumber, channelName);

	m_output << "Channel saved: " + to_string(channelNumber) + " - " + channelName + "\n";

	return true;
}

bool CRemoteControl::WhatChannelNumber(istream& args)
{
	string channelName = *istream_iterator<string>(args);

	m_tv.GetChannelByName(channelName);

	m_output << to_string(m_tv.GetChannelByName(channelName)) + " - " + channelName << endl;

	return true;
}

bool CRemoteControl::WhatChannelName(istream& args)
{
	int channelNumber = *istream_iterator<int>(args);

	m_tv.GetChannelName(channelNumber);

	m_output << to_string(channelNumber) + " - " + m_tv.GetChannelName(channelNumber) << endl;

	return true;
}
