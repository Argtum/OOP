#pragma once
#include <boost/noncopyable.hpp>

class CCommandLineHandle : boost::noncopyable
{
public:
	CCommandLineHandle(std::istream& input, std::ostream& output);
	bool HandleCommand();

private:
	std::istream& m_input;
	std::ostream& m_output;
};
