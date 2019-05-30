#pragma once
#include "CParentWithVirtualDestructor.h"

class CSon : public CParentWithVirtualDestructor
{
public:
	CSon();
	~CSon();
};
