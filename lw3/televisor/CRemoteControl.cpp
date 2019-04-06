#include "pch.h"
#include "CRemoteControl.h"
#include "CTVSet.h"

CRemoteControl::CRemoteControl(CTVSet& tv, istream& input, ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "TurnOn", [this](istream& strm) {
						 return TurnOn(strm);
					 } },
		  { "TurnOff", bind(&CRemoteControl::TurnOff, this, _1) }, { "Info", bind(&CRemoteControl::Info, this, _1) } })
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
	m_output << "TV is turned on" << endl;
	return true;
}

bool CRemoteControl::TurnOff(istream& args)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
	return true;
}

bool CRemoteControl::Info(istream& args)
{
	string info = (m_tv.IsTurnedOn()) ? ("TV is turned on\n") : "TV is turned off\n";

	m_output << info;

	return true;
}
