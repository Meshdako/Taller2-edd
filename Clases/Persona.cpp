#include "Persona.h"
#include <iostream>

using namespace std;

Persona::Persona()
{
	nombre = "";
}

Persona::Persona(string a, RUT b, Direccion c, Fecha d)
{
	nombre = a;
	RUN = b;
	direccionParticular = c;
	fechaNacimiento = d;
}

void Persona::verPersona()
{
	cout << "--------------------------------------" << endl;
	cout << "Nombre: " << nombre << endl;
	RUN.verRUT();
	direccionParticular.verDireccion();
	cout << "Fecha de nacimiento: ";
	fechaNacimiento.verFecha();
}

