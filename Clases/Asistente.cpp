#include "RUT.h"
#include "Direccion.h"
#include "Fecha.h"
#include "Persona.h"
#include "Asistente.h"
#include <iostream>

using namespace std;

Asistente::Asistente()
{
	tipoEntrada = 0;
	ocupada = 0;
}

Asistente::Asistente(string a, RUT b, Direccion c, Fecha d, int e, Fecha f, bool g) : Persona(a, b, c, d)
{
	tipoEntrada = e;
	fechaEvento = f;
	ocupada = g;
}

void Asistente::verAsistente()
{
	verPersona();
	cout << "Tipo de entrada: " << tipoEntrada << endl;
	cout << "Fecha del evento: ";
	fechaEvento.verFecha();
	cout << "Ocupada: ";

	if(ocupada == 0)
		cout << "No" << endl;
	else
		cout << "Si" << endl;
}

