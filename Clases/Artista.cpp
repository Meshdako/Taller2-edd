#include "Artista.h"
#include <iostream>

using namespace std;

Artista::Artista()
{
	nombreArtistico = "";
	generoMusical = "";
}

Artista::Artista(string a, RUT b, Direccion c, Fecha d, string e, string f, Fecha g) : Persona(a, b, c, d)
{
	nombreArtistico = e;
	generoMusical = f;
	fechaPresentacion = g;
}

void Artista::verArtista()
{
	verPersona();
	cout << "Nombre artístico: " << nombreArtistico << endl;
	cout << "Género musical: " << generoMusical << endl;
	cout << "Fecha de presentación: ";
	fechaPresentacion.verFecha();
}

