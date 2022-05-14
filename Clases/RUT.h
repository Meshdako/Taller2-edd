#ifndef RUT_H
#define RUT_H

class RUT
{
	private:
		int run;
		int dv;
	public:
		//Constructores.
		RUT();
		RUT(int, int);

		//Setters.
		void setRun(int x){run = x;}
		void setDv(int x){dv = x;}

		//Getters.
		int getRun(){return run;}
		int getDv(){return dv;}

		//Métodos
		void verRUT();
};

#endif //RUT_H
