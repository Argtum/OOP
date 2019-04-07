#pragma once
#include <boost/noncopyable.hpp>

class CTVSet;

class CRemoteControl : boost::noncopyable
{
public:
	CRemoteControl(CTVSet& tv, istream& input, ostream& output);
	~CRemoteControl();
	bool HandleCommand();

private:
	bool TurnOn(istream& args);
	bool TurnOff(istream& args);
	bool Info(istream& args);
	bool SelectChannel(istream& args);
	typedef map<string, function<bool(istream& args)>> ActionMap;

	CTVSet& m_tv;
	istream& m_input;
	ostream& m_output;
	const ActionMap m_actionMap;
};
