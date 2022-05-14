#include "Direccion.h"
#include <iostream>

using namespace std;

Direccion::Direccion()
{
	calle = "";
	numero = 0;
	comuna = "";
}

Direccion::Direccion(string a, int b, string c)
{
	calle = a;
	numero = b;
	comuna = c;
}

void verDireccion()
{
	cout << "Direccion: " << calle << ", " << numero << ", " << comuna << endl;
}
