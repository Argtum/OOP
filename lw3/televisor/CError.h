#pragma once

class CError
{
public:
	CError(const string& msg)
		: m_message(msg)
	{
	}
	string GetErrorMessage() const;
	virtual void PrintErrorMessage() const;
	virtual ~CError() = default;

private:
	string m_message;
};
