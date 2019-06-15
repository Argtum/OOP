#include "pch.h"
#include "CUrlParsingError.h"

using namespace std;

CUrlParsingError::CUrlParsingError(string const& msg)
	: invalid_argument(msg)
{
}
