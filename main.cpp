#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "Clases/RUT.h"
#include "Clases/RUT.cpp"

#include "Clases/Direccion.h"
#include "Clases/Direccion.cpp"

#include "Clases/Fecha.h"
#include "Clases/Fecha.cpp"

#include "Clases/Persona.h"
#include "Clases/Persona.cpp"

#include "Clases/Artista.h"
#include "Clases/Artista.cpp"

#include "Clases/Asistente.h"
#include "Clases/Asistente.cpp"

using namespace std;

//Arreglos de clases.
Asistente Asistentes[1000];
Artista Artistas[105];

//Funciones
/* void CantidadAsistentes();
void AsistentesComuna();
void ConvocatoriaArtistas();
void TipodeEntradas();
void RangodeEdad(); */

//Menú
void Menu(int n, int m)
{
	int opcion, cont_asis, cont_art;
	
	if(n != 0)
		cont_asis = n;
	else
		cont_asis = 0;
	if(m != 0)
		cont_art = m;
	else
		cont_art = 0;

	//Aquí empieza el menú de selección.
	do{
		//Limpiamos la consola.
		system("clear");

		//Opciones a elegir.
		cout << "1. Cantidad de asistentes ..." << endl;
		cout << "2. Asistentes por comuna ..." << endl;
		cout << "3. Convocatoria de artistas ..." << endl;
		cout << "4. Asistentes por tipo de entrada ..." << endl;
		cout << "5. Asistentes por rango de edad ..." << endl;
		cout << "Eliga su opción >> ";
		cin >> opcion;

		switch(opcion){
			case 0:
				cout << "Saliendo.\n\t Muchas gracias." << endl;
				break;
			case 1:
				//CantidadAsistentes();	
				break;
			case 2:
				//AsistentesComuna();
				break;
			case 3:
				//ConvocatoriaArtistas();
				break;
			case 4:
				//TipodeEntradas();
				break;
			case 5:
				//RangodeEdad();
				break;
			deafult:
				break;
		}
	}while(opcion != 0);
}

//Lectura del archivo
void Lectura()
{	
	//Variables
	ifstream archivo;
	string linea;
	char delimitador = ';';

	int i, j;
	i = j = 0;
	
	//Abrimos el archivo
	archivo.open("ARTISTAS.txt", ios::in);
	
	if(archivo.fail()){
		cout << "Error: No se pudo abrir el archivo ARTISTAS.txt" << endl;
		exit(1);
	}

	//Capturamos la primera línea del archivo, pero esta no se ocupará.
	getline(archivo, linea);

	//Variables para el arreglo artistas.
	string RUN, DV, NAC_DIA, NAC_MES, NAC_ANHO, NOMBRE, PATERNO, MATERNO, CALLE, NRO, COMUNA, EVEN_DIA, EVE_MES, EVE_ANHO, NOMBRE_ARTISTICO, ESTILO;
	while(getline(archivo, linea)){
		stringstream stream(linea);

		getline(stream, RUN, delimitador);
		getline(stream, DV, delimitador);

		getline(stream, NAC_DIA, delimitador);
		getline(stream, NAC_MES, delimitador);
		getline(stream, NAC_ANHO, delimitador);

		getline(stream, NOMBRE, delimitador);
		getline(stream, PATERNO, delimitador);
		getline(stream, MATERNO, delimitador);

		getline(stream, CALLE, delimitador);
		getline(stream, NRO, delimitador);
		getline(stream, COMUNA, delimitador);

		getline(stream, EVEN_DIA, delimitador);
		getline(stream, EVE_MES, delimitador);
		getline(stream, EVE_ANHO, delimitador);

		getline(stream, NOMBRE_ARTISTICO, delimitador);
		getline(stream, ESTILO, delimitador);

		//Transformamos las variables correspondientes a valores enteros.
		long Aux1;
		int Aux2, Aux3, Aux4, Aux5, Aux6, Aux7, Aux8, Aux9;

		Aux1 = stol(RUN);
		Aux2 = stoi(DV);
		RUT RunAux(Aux1, Aux2);

		Aux3 = stoi(NAC_DIA);
		Aux4 = stoi(NAC_MES);
		Aux5 = stoi(NAC_ANHO);
		Fecha FechaAux1(Aux1, Aux2, Aux3);

		string NombreCompleto = NOMBRE + PATERNO + MATERNO;

		Aux6 = stoi(NRO);
		Direccion DirAux(CALLE, Aux6, COMUNA);

		Aux7 = stoi(EVEN_DIA);
		Aux8 = stoi(EVE_MES);
		Aux9 = stoi(EVE_ANHO);
		Fecha FechaAux2(Aux7, Aux8, Aux9);

		Artista ArtAux(NombreCompleto, RunAux, DirAux, FechaAux1, NOMBRE_ARTISTICO, ESTILO, FechaAux2);
		Artistas[i] = ArtAux;

		i++;
	}
	//Cerramos el archivo ARTISTAS.txt
	archivo.close();

	Menu(i, j);
}

int main()
{
	Lectura();
	return 0;
}
