#include "pch.h"
#include "RemoveExtraSpaces.h"

void RemoveExtraSpaces(string& stringToTrim)
{
	boost::trim(stringToTrim);
	for (string::iterator it = stringToTrim.begin(); it != stringToTrim.end(); it++)
	{
		string::iterator begin = it;
		while (it != stringToTrim.end() && isspace(*it))
			it++;
		if (it - begin > 1)
			it = stringToTrim.erase(begin + 1, it) - 1;
	}
}
