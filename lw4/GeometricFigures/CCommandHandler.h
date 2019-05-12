#pragma once
#include "IShape.h"
#include <boost/noncopyable.hpp>

class CCommandHandler : boost::noncopyable
{
public:
	CCommandHandler(std::istream& input, std::ostream& output);
	bool HandleCommand();
	void Info(std::ostream& output);
	/*void PrintShapeWithMinPerimeter();
	void PrintShapeWithMaxArea();*/

private:
	bool CreateLineSegment(std::istream& args);
	/*bool CreateTriangle(istream& args);
	bool CreateRectangle(istream& args);
	bool CreateCircle(istream& args);*/
	typedef std::map<std::string, std::function<bool(std::istream& args)>> ActionMap;

	std::istream& m_input;
	std::ostream& m_output;
	const ActionMap m_actionMap;
	std::vector<std::unique_ptr<IShape>> m_shapeList;
};
