#include "pch.h"
#include "Error.h"

Error::Error(const string& msg)
	: runtime_error(msg)
{
}

Error::~Error()
{
}
