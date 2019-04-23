#pragma once
#include "IShape.h"
class ISolidShape : public IShape
{
public:
	ISolidShape();
	virtual uint32_t GetFillColor() const = 0;
	virtual ~ISolidShape();
};
