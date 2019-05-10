#include "pch.h"
#include "CRectangle.h"
#include "CPoint.h"

using namespace std;

CRectangle::CRectangle(const std::string& type, const CPoint& leftTop, const CPoint& rightBottom, const double width, const double height, const uint32_t lineColor, const uint32_t fillColor)
	: m_type(type)
	, m_leftTopVertex(leftTop)
	, m_rightBottomVertex(rightBottom)
	, m_width(width)
	, m_height(height)
	, m_lineColor(lineColor)
	, m_fillColor(fillColor)
{
}

string CRectangle::ToString() const
{
	ostringstream s;
	s << GetType() << ":" << endl;
	AppendProperties(s);
	s << setprecision(4)
	  << "\tperimeter = " << GetPerimeter() << endl
	  << "\tarea = " << GetArea() << endl
	  << "\tline color = " << GetOutlineColor() << endl
	  << "\tfill color = " << GetFillColor() << endl;

	return s.str();
}

string CRectangle::GetType() const
{
	return m_type;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTopVertex;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottomVertex;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

double CRectangle::GetPerimeter() const
{
	return GetWidth() * 2 + GetHeight() * 2;
}

double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_lineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

void CRectangle::AppendProperties(ostream& s) const
{
	s << "\tleft top vertex = ( " << GetLeftTop().GetX() << " , " << GetLeftTop().GetY()
	  << " ), right bottom vertex = ( " << GetRightBottom().GetX() << " , " << GetRightBottom().GetY()
	  << " ), width = " << GetWidth() << ", height = " << GetHeight() << endl;
}
