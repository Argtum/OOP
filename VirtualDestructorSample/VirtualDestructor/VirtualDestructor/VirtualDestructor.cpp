#include "pch.h"
#include "CDaughter.h"
#include "CParentWithVirtualDestructor.h"
#include "CParentWithoutVirtualDestructor.h"
#include "CSon.h"
#include <iostream>

using namespace std;

int main()
{
	CParentWithVirtualDestructor* pSon = new CSon();
	delete pSon;
	cout << "------------------------------------------------------------" << endl;
	CParentWithoutVirtualDestructor* pDaughter = new CDaughter();
	delete pDaughter;
}
