#ifndef ARTISTA_H
#define ARTISTA_H

#include <iostream>

using namespace std;

class Artista : public Persona
{
	private:
		string nombreArtistico;
		string generoMusical;
		Fecha fechaPresentacion;
	public:
		Artista();
		Artista(string, RUT, Direccion, Fecha, string, string, Fecha);

		void setNombreArtistico(string x){nombreArtistico = x;}
		void setGeneroMusical(string x){generoMusical = x;}
		void setFechaPresentacion(Fecha x){fechaPresentacion = x;}

		string getNombreArtistico(){return nombreArtistico;}
		string getGeneroMusical(){return generoMusical;}
		Fecha getFechaPresentacion(){return fechaPresentacion;}

		void verArtista();
};

#endif //ARTISTA_H
