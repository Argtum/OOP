#pragma once

class InvalidOperation : public runtime_error
{
public:
	InvalidOperation(const string& msg)
		: runtime_error(msg)
	{
	}
};
