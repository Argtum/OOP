#include "pch.h"
#include "CError.h"

string CError::GetErrorMessage() const
{
	return m_message;
}

void CError::PrintErrorMessage() const
{
	cout << m_message;
}
