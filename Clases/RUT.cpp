#include "RUT.h"
#include <iostream>

using namespace std;

RUT::RUT()
{
	run = 0;
	dv = 0;
}

RUT::RUT(int a, int b)
{
	run = a;
	dv = a;
}

void RUT::verRUT()
{
	cout << "RUT: " << run << "-" << dv << endl;
}
