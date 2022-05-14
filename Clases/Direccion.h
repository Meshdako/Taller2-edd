#ifndef DIRECCION_H
#define DIRECCION_H

#include <iostream>

using namespace std;

class Direccion
{
	private:
		string calle;
		int numero;
		string comuna;
	public:
		//Constructores
		Direccion();
		Direccion(string, int, string);

		//Setter
		void setCalle(string x){calle = x;}
		void setNumero(int x){numero = x;}
		void setComuna(string x){comuna = x;}

		//Getters
		string getCalle(){return calle;}
		int getNumero(){return numero;}
		string getComuna(){return comuna;}

		//Métodos.
		void verDireccion();
};

#endif //DIRECCION_H
