#include "RUT.h"
#include <iostream>

using namespace std;

RUT::RUT()
{
	run = 0;
	dv = 0;
}

RUT::RUT(long a, int b)
{
	run = a;
	dv = b;
}

void RUT::verRUT()
{
	cout << "RUT: " << run << "-" << dv << endl;
}
