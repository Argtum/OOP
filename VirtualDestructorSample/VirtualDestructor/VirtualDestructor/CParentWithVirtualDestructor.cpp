#include "pch.h"
#include "CParentWithVirtualDestructor.h"

using namespace std;

CParentWithVirtualDestructor::CParentWithVirtualDestructor()
{
	cout << "CParentWithVirtualDestructor is created" << endl;
}

CParentWithVirtualDestructor::~CParentWithVirtualDestructor()
{
	cout << "CParentWithVirtualDestructor is deleted" << endl;
}
