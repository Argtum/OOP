#include "pch.h"
#include "CError.h"

CError::CError(const string& msg)
	: runtime_error(msg)
{
}

CError::~CError()
{
}
