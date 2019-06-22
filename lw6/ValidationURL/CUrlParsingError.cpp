#include "pch.h"
#include "CUrlParsingError.h"

using namespace std;

CUrlParsingError::CUrlParsingError(string const& msg = "ERROR: unknown")
	: invalid_argument(msg)
{
}
