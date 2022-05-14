#include "Fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha()
{
	dd = 0;
	mm = 0;
	aa = 0;
}

Fecha::Fecha(int a, int b, int c)
{
	dd = a;
	mm = b;
	aa = c;
}

void Fecha::verFecha()
{
	cout << dd << "/" << mm << "/" << aa << endl;
}

