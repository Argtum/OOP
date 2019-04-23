#pragma once
#include "pch.h"
#include "CPoint.h"
#include "IShape.h"

class CLineSegment final : public IShape
{
public:
	CLineSegment(const CPoint& point1, const CPoint& point2);
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	std::string GetType() const;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	//uint32_t GetOutlineColor() const override;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};
