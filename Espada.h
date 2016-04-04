#include <iostream>

using namespace std;

#ifndef ESPADA_H
#define ESPADA_H

class Espada{
	
	public:
		Espada();
		int forcaDaEspada();
		void print() const;
		
	protected:
		int forca;
};
#endif
