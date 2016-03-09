#include <iostream>

using namespace std;

#ifndef DATA_H
#define DATA_H

class Data{
	
	public:
		Data(int = 30, int = 1, int = 1990);
		void print() const;
		
	private:
		int dia;
		int mes;
		int ano;
		
		int checarDia(int) const;
};
#endif
