#ifndef PERSONA_H
#define PERSONA_H

#include "RUT.h"
#include "Direccion.h"
#include "Fecha.h"
#include <iostream>

using namespace std;

class Persona
{
	private:
		string nombre;
		RUT RUN;
		Direccion direccionParticular;
		Fecha fechaNacimiento;
	public:
		Persona();
		Persona(string, RUT, Direccion, Fecha);

		void setNombre(string x){nombre = x;}
		void setRun(RUT x){RUN = x;}
		void setDireccionParticular(Direccion x){direccionParticular = x;}
		void setFechaNacimiento(Fecha x){fechaNacimiento = x;}

		string getNombre(){return nombre;}
		RUT getRun(){return RUN;}
		Direccion getDireccionParticular(){return direccionParticular;}
		Fecha getFechaNacimiento(){return fechaNacimiento;}

		void verPersona();
};

#endif //PERSONA_H
