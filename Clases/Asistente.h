#ifndef ASISTENTE_H
#define ASISTENTE_H

#include <iostream>

using namespace std;

class Asistente : public Persona
{
	private:
		int tipoEntrada;
		Fecha fechaEvento;
		bool ocupada;
	public:
		Asistente();
		Asistente(string, RUT, Direccion, Fecha, int, Fecha, bool);

		void setTipoEntrada(int x){tipoEntrada = x;}
		void setFechaEvento(Fecha x){fechaEvento = x;}
		void setOcupada(int x){ocupada = x;}

		int getTipoEntrada(){return tipoEntrada;}
		Fecha getFechaEvento(){return fechaEvento;}
		bool getOcupada(){return ocupada;}

		void verAsistente();
		int EntradaOcupada();
};

#endif //ASISTENTE_H
