#include <iostream>

using namespace std;

#ifndef CAJADO_H
#define CAJADO_H

class Cajado{
	
	public:
		Cajado();
		int magiaDoCajado();
		int defEspDoCajado();
		void print() const;
		
	protected:
		int magia;
		int defesaEspecial;
};
#endif
