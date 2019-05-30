#pragma once
#include "CParentWithoutVirtualDestructor.h"
class CDaughter : public CParentWithoutVirtualDestructor
{
public:
	CDaughter();
	~CDaughter();
};
