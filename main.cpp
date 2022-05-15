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
void CantidadAsistentes(Asistente Asis[], int n)
{
	system("clear");

	int cont_si, cont_no;
	cont_si = cont_no = 0;

	for(int i = 0; i <= n; i++){
		int resp = Asis[i].getOcupada();
		if(resp == 1)
			cont_si++;
		else
			cont_no++;
	}

	cout << "--------------------------------------" << endl;
	cout << "La cantidad de asistentes al evento fue de: " << cont_si << " personas." << endl;
	cout << "Por el contrario, hubo: " << cont_no << " personas que no ocuparon su entrada." << endl;
}

void AsistentesComuna(Asistente Asis[], int n)
{
	system("clear");

	char comuna[256];

	cout << "--------------------------------------" << endl;
	cout << "Ingrese la comuna que busca (En  mayúsculas, ej: LA CISTERNA): ";
	cin.getline(comuna, 256);

	for(int i = 0; i < n; i++){
		Direccion Aux = Asis[i].getDireccionParticular();
		string comuna_aux = Aux.getComuna();

		if(comuna == comuna_aux)
			Asis[i].verAsistente();
	}
}

void ConvocatoriaArtistas(Artista Art[], int n, Asistente Asis[], int m)
{
	system("clear");

	int dia, cont;
	cont = 0;

	cout << "--------------------------------------" << endl;
	cout << "Ingrese un día del evento (18, 19, 20): ";
	cin >> dia;
	cin.ignore(5, '\n');

	if(dia > 17 && dia < 21){
		for(int i = 0; i < n; i++){
			Fecha Aux = Art[i].getFechaPresentacion();
			
			if(dia == Aux.getDia())
				Art[i].verArtista();
		}
		for(int j = 0; j < m; j++){
			Fecha Aux = Asis[j].getFechaEvento();
			
			if(dia == Aux.getDia()){
				if(Asis[j].getOcupada() == 1)
					cont++;
			}
		}
		cout << "--------------------------------------" << endl;
		cout << "Para el día <<" << dia << ">> hubo un total de: " << cont << " asistentes" << endl;
	}
	else
		cout << "No hubo evento el día que nos indicó." << endl;

	
}

void TipodeEntradas(Asistente Asis[], int n)
{
	system("clear");

	int entrada, cont1_1, cont1_2, cont2_1, cont2_2, cont3_1, cont3_2;
	cont1_1 = cont1_2 = cont2_1 = cont2_2 = cont3_1 = cont3_2 = 0;

	for(int i = 0; i < n; i++){
		entrada = Asis[i].getTipoEntrada();

		switch (entrada){
			case 1:
				if(Asis[i].getOcupada() == 1)
					cont1_1++;
				else
					cont1_2++;
				break;
			case 2:
				if(Asis[i].getOcupada() == 1)
					cont2_1++;
				else
					cont2_2++;
				break;
			case 3:
				if(Asis[i].getOcupada() == 1)
					cont3_1++;
				else
					cont3_2++;
				break;
		}
	}

	cout << "--------------------------------------" << endl;
	cout << "Hubo un total de: " << cont1_1 + cont1_2 << " entradas <<Tipo 1>>" << endl;
	cout << "\t Fue ocupada por: " << cont1_1 << " personas." << endl;
	cout << "\t No fue ocupada por: " << cont1_2 << " personas." << endl;

	cout << "Hubo un total de: " << cont2_1 + cont2_2 << " entradas <<Tipo 2>>" << endl;
	cout << "\t Fue ocupada por: " << cont2_1 << " personas." << endl;
	cout << "\t No fue ocupada por: " << cont2_2 << " personas." << endl;

	cout << "Hubo un total de: " << cont3_1 + cont3_2 << " entradas <<Tipo 3>>" << endl;
	cout << "\t Fue ocupada por: " << cont3_1 << " personas." << endl;
	cout << "\t No fue ocupada por: " << cont3_2 << " personas." << endl;
}

void RangodeEdad(Asistente Asis[], int n)
{
	system("clear");

	int cont1, cont2, cont3;
	cont1 = cont2 = cont3 = 0;

	for(int i = 0; i < n; i++){
		Fecha Aux = Asis[i].getFechaNacimiento();
		int edad = 2022 - Aux.getAnho();

		if(edad > 0 && edad < 19)
			cont1++;
		if(edad > 18 && edad < 29)
			cont2++;
		if(edad > 28 && edad < 100)
			cont3++;
	}
	
	cout << "--------------------------------------" << endl;
	cout << "El total de personas con edad dentro del rango [0-18] es de: " << cont1 << endl;
	cout << "El total de personas con edad dentro del rango [19-28] es de: " << cont2 << endl;
	cout << "El total de personas con edad dentro del rango [28-99] es de: " << cont3 << endl;
}

//Menú
void Menu(int n, int m)
{
	int opcion, cont_art, cont_asis;
	
	if(m != 0)
		cont_art = n;
	else
		cont_art = 0;
	if(n != 0)
		cont_asis = m;
	else
		cont_asis = 0;
	

	//Aquí empieza el menú de selección.
	do{
		//Opciones a elegir.
		cout << "--------------------------------------" << endl;
		cout << "1. Cantidad de asistentes ..." << endl;
		cout << "2. Asistentes por comuna ..." << endl;
		cout << "3. Convocatoria de artistas ..." << endl;
		cout << "4. Asistentes por tipo de entrada ..." << endl;
		cout << "5. Asistentes por rango de edad ..." << endl;
		cout << "Eliga su opción >> ";
		cin >> opcion;
		cin.ignore(5, '\n');
		switch(opcion){
			case 0:
				cout << "Saliendo.\n\t Muchas gracias." << endl;
				break;
			case 1:
				CantidadAsistentes(Asistentes, cont_asis);	
				break;
			case 2:
				AsistentesComuna(Asistentes, cont_asis);
				break;
			case 3:
				ConvocatoriaArtistas(Artistas, cont_art, Asistentes, cont_asis);
				break;
			case 4:
				TipodeEntradas(Asistentes, cont_asis);
				break;
			case 5:
				RangodeEdad(Asistentes, cont_asis);
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
	
	//Abrimos el archivo ARTISTAS.txt
	archivo.open("ARTISTAS.txt", ios::in);
	
	if(archivo.fail()){
		cout << "Error: No se pudo abrir el archivo ARTISTAS.txt" << endl;
		exit(1);
	}

	//Capturamos la primera línea del archivo, pero esta no se ocupará.
	getline(archivo, linea);
	
	while(getline(archivo, linea)){
		stringstream stream(linea);
		
		//Variables para el arreglo artistas.
		string RUN, DV, NAC_DIA, NAC_MES, NAC_ANHO, NOMBRE, PATERNO, MATERNO, CALLE, NRO, COMUNA, EVEN_DIA, EVE_MES, EVE_ANHO, NOMBRE_ARTISTICO, ESTILO;

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
		Fecha FechaAux1(Aux3, Aux4, Aux5);

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

	//Abrimos el archivo ASISTENTES.txt
	archivo.open("ASISTENTES.txt", ios::in);

	if(archivo.fail()){
		cout << "Error: No se pudo abrir el archivo ASISTENTES.txt" << endl;
		exit(1);
	}

	getline(archivo, linea);

	while(getline(archivo, linea)){
		stringstream stream(linea);
		
		//Variables para el arreglo artistas.
		string RUN, DV, NOMBRES, PATERNO, MATERNO, NAC_DIA, NAC_MES, NAC_ANHO, DIRECCION, NRO, COMUNA, TIPO_ENTRADA, EVENTO_DD, EVENTO_MM, EVENTO_AA, OCUPADA;

		getline(stream, RUN, delimitador);
		getline(stream, DV, delimitador);

		getline(stream, NOMBRES, delimitador);
		getline(stream, PATERNO, delimitador);
		getline(stream, MATERNO, delimitador);

		getline(stream, NAC_DIA, delimitador);
		getline(stream, NAC_MES, delimitador);
		getline(stream, NAC_ANHO, delimitador);

		getline(stream, DIRECCION, delimitador);
		getline(stream, NRO, delimitador);
		getline(stream, COMUNA, delimitador);

		getline(stream, TIPO_ENTRADA, delimitador);

		getline(stream, EVENTO_DD, delimitador);
		getline(stream, EVENTO_MM, delimitador);
		getline(stream, EVENTO_AA, delimitador);

		getline(stream, OCUPADA, delimitador);
		
		long Aux1;
		int Aux2, Aux3, Aux4, Aux5, Aux6, Aux7, Aux8, Aux9, Aux10, Aux11;

		Aux1 = stol(RUN);
		if(DV == "K" || DV == "k")
			DV = "0";
		else{
			if(DV == "-")
				DV = "0";
		}
		Aux2 = stoi(DV);
		RUT RunAux(Aux1, Aux2);

		string NombreCompleto = NOMBRES + " " + PATERNO + " " + MATERNO;

		Aux3 = stoi(NAC_DIA);
		Aux4 = stoi(NAC_MES);
		Aux5 = stoi(NAC_ANHO);
		Fecha FechaAux1(Aux3, Aux4, Aux5);

		Aux6 = stoi(NRO);
		Direccion DirAux(DIRECCION, Aux6, COMUNA);

		Aux7 = stoi(EVENTO_DD);
		Aux8 = stoi(EVENTO_MM);
		Aux9 = stoi(EVENTO_AA);
		Fecha FechaAux2(Aux7, Aux8, Aux9);

		Aux10 = stoi(TIPO_ENTRADA);
		Aux11 = stoi(OCUPADA);

		Asistente AsisAux(NombreCompleto, RunAux, DirAux, FechaAux1, Aux10, FechaAux2, Aux11);
		Asistentes[j] = AsisAux;

		j++;
	}
	archivo.close();

	Menu(i, j);
}

int main()
{
	Lectura();
	return 0;
}
