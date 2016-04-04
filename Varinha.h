#include <iostream>

using namespace std;

#ifndef VARINHA_H
#define VARINHA_H

class Varinha{
	
	public:
		Varinha();
        int defesaDaVarinha();
		int magiaDaVarinha();
		void print() const;
		
    protected:
        int defesa;
		int magia;
};
#endif
