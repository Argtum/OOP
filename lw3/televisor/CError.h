#pragma once

class CError : public runtime_error
{
public:
	CError(const string& msg);
	~CError();
};
