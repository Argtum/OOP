#include "pch.h"
#include "CParentWithoutVirtualDestructor.h"

using namespace std;

CParentWithoutVirtualDestructor::CParentWithoutVirtualDestructor()
{
	cout << "CParentWithoutVirtualDestructor is created" << endl;
}

CParentWithoutVirtualDestructor::~CParentWithoutVirtualDestructor()
{
	cout << "CParentWithoutVirtualDestructor is deleted" << endl;
}
