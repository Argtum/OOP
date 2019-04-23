#pragma once
#include "pch.h"
#include "CPoint.h"
#include "IShape.h"

using namespace std;

class CLineSegment final : public IShape
{
public:
	CLineSegment(CPoint& point1, CPoint& point2);
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	double GetLength() const;

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	//uint32_t GetOutlineColor() const override;

protected:
	string GetType() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};
