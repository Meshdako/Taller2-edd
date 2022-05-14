#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha
{
	private:
		int dd;
		int mm;
		int aa;
	public:
		Fecha();
		Fecha(int, int, int);

		void setDia(int x){dd = x;}
		void setMes(int x){mm = x;}
		void setAnho(int x){aa = x;}

		int getDia(){return dd;}
		int getMes(){return mm;}
		int getAnho(){return aa;}

		void verFecha();
};

#endif //FECHA_H
