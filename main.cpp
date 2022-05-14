#include <iostream>
#include <ffstream>

#include "RUT.h"
#include "Direccion.h"
#include "Fecha.h"
#include "Persona.h"
#include "Artista.h"
#include "Asistente.h"

using namespace std;

//Funciones
void CantidadAsistentes();
void AsistentesComuna();
void ConvocatoriaArtistas();
void TipodeEntradas();
void RangodeEdad();

//Menú
void Menu()
{
	int opcion;

	do{
	cout << "Eliga su opción >> ";
	cin >> opcion;

	switch(opcion)
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		deafult:
			break;
	}while(opcion != 0);
}

//Lectura del archivo
void Lectura()
{

	Menu();
}

int main()
{
	Lectura();
	return 0;
}
