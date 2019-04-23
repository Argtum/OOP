#include "pch.h"
#include "CLineSegment.h"
#include "CPoint.h"

CLineSegment::CLineSegment(CPoint& point1, CPoint& point2)
	: m_startPoint(point1)
	, m_endPoint(point2)
{
}

string CLineSegment::ToString() const
{
	ostringstream s;
	s << GetType() << " length: " << GetLength();
	return s.str();
}

string CLineSegment::GetType() const
{
	return "Line segment";
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetLength() const
{
	return round(sqrt(pow(m_endPoint.GetX() - m_startPoint.GetX(), 2) + pow(m_endPoint.GetY() - m_startPoint.GetY(), 2)) * 100) / 100;
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return 0;
}
