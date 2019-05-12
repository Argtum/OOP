#include "pch.h"
#include "CCommandHandler.h"
#include "CCircle.h"
#include "CError.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include <boost/algorithm/string.hpp>

using namespace std;

CCommandHandler::CCommandHandler(istream& input, ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "LineSegment", bind(&CCommandHandler::CreateLineSegment, this, placeholders::_1) },
		  { "Triangle", bind(&CCommandHandler::CreateTriangle, this, placeholders::_1) },

	  })
{
}

bool CCommandHandler::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

void CCommandHandler::Info(std::ostream& output)
{
	for (const auto& shape : m_shapeList)
	{
		output << shape->ToString();
	}
}

bool CCommandHandler::CreateLineSegment(istream& args)
{
	vector<string> shapeDescription;
	string description;
	getline(args, description);

	if (description.empty())
	{
		m_output << "No arguments!\nUsage: LineSegment point1.x point1.y point2.x point2.y lineColor\n";
		return false;
	}

	boost::split(shapeDescription, description, boost::is_any_of(" "));

	if (shapeDescription.size() != 6)
	{
		m_output << "Incorrect count of arguments!\nUsage: LineSegment point1.x point1.y point2.x point2.y lineColor\n";
		return false;
	}

	CPoint point1 = { stod(shapeDescription[1]), stod(shapeDescription[2]) };
	CPoint point2 = { stod(shapeDescription[3]), stod(shapeDescription[4]) };
	uint32_t lineColor;

	try
	{
		lineColor = strtoul(shapeDescription[5].substr(0, 2).c_str(), NULL, 16);
	}
	catch (CError e)
	{
		m_output << e.GetErrorMessage();
		return false;
	}

	auto lineSegment = make_unique<CLineSegment>("LineSegment", point1, point2, lineColor);
	m_shapeList.push_back(move(lineSegment));
	m_output << "Line segment is created\n";

	return true;
}

bool CCommandHandler::CreateTriangle(istream& args)
{
	vector<string> shapeDescription;
	string description;
	getline(args, description);

	if (description.empty())
	{
		m_output << "No arguments!\nUsage: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex3.y lineColor fillColor\n";
		return false;
	}

	boost::split(shapeDescription, description, boost::is_any_of(" "));

	if (shapeDescription.size() != 9)
	{
		m_output << "Incorrect count of arguments!\nUsage: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex3.y lineColor fillColor\n";
		return false;
	}

	CPoint vertex1 = { stod(shapeDescription[1]), stod(shapeDescription[2]) };
	CPoint vertex2 = { stod(shapeDescription[3]), stod(shapeDescription[4]) };
	CPoint vertex3 = { stod(shapeDescription[5]), stod(shapeDescription[6]) };
	uint32_t lineColor;
	uint32_t fillColor;

	try
	{
		lineColor = strtoul(shapeDescription[7].substr(0, 2).c_str(), NULL, 16);
		fillColor = strtoul(shapeDescription[8].substr(0, 2).c_str(), NULL, 16);
	}
	catch (CError e)
	{
		m_output << e.GetErrorMessage();
		return false;
	}

	auto triangle = make_unique<CTriangle>("Triangle", vertex1, vertex2, vertex3, lineColor, fillColor);
	m_shapeList.push_back(move(triangle));
	m_output << "Triangle is created\n";

	return true;
}
