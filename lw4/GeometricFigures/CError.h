#pragma once

class CError
{
public:
	CError(const std::string& msg);
	std::string GetErrorMessage() const;

private:
	std::string m_message;
};
