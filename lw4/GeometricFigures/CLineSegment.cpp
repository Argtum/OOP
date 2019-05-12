#include "pch.h"
#include "CLineSegment.h"
#include "CPoint.h"

using namespace std;

CLineSegment::CLineSegment(const string& type, const CPoint& point1, const CPoint& point2, const uint32_t color)
	: m_type(type)
	, m_startPoint(point1)
	, m_endPoint(point2)
	, m_color(color)
{
}

string CLineSegment::ToString() const
{
	ostringstream s;
	s << m_type << ":" << endl;
	AppendProperties(s);
	s << setprecision(3)
	  << "\tlength = " << GetPerimeter() << endl
	  << "\tcolor = " << m_color << endl;

	return s.str();
}

string CLineSegment::GetType() const
{
	return m_type;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetPerimeter() const
{
	return sqrt(pow(m_endPoint.GetX() - m_startPoint.GetX(), 2) + pow(m_endPoint.GetY() - m_startPoint.GetY(), 2));
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_color;
}

void CLineSegment::AppendProperties(ostream& s) const
{
	s << "\tbegins = ( " << m_startPoint.GetX() << " , " << m_startPoint.GetY()
	  << " ), ends = ( " << m_endPoint.GetX() << " , " << m_endPoint.GetY() << " )" << endl;
}
