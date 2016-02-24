#include <iostream>

using namespace std;

#ifndef CAJADO_H
#define CAJADO_H

class Cajado{
	
	public:
		Cajado();
		int Magia();
		int DefEsp();
		void print() const;
		
	private:
		int magia;
		int defesaEspecial;
};
#endif
