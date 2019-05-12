#include "pch.h"
#include "CError.h"

using namespace std;

CError::CError(const string& msg)
	: m_message(msg)
{
}

string CError::GetErrorMessage() const
{
	return m_message;
}
