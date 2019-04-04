#pragma once

class Error : public runtime_error
{
public:
	Error(const string& msg);
	~Error();
};
