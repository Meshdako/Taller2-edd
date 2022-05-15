#ifndef RUT_H
#define RUT_H

class RUT
{
	private:
		long run;
		int dv;
	public:
		//Constructores.
		RUT();
		RUT(long, int);

		//Setters.
		void setRun(int x){run = x;}
		void setDv(int x){dv = x;}

		//Getters.
		long getRun(){return run;}
		int getDv(){return dv;}

		//Métodos
		void verRUT();
};

#endif //RUT_H
