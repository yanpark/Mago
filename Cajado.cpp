#include <iostream>
#include <iomanip>
#include "Cajado.h"

using namespace std;

Cajado::Cajado(){
	
	this->magia = Magia();
	this->defesaEspecial = DefEsp();
}

void Cajado::print() const{
	
	cout << setw(38) << "Cajado Mistico " << setw(9) << "Magia +" << magia << "\n" << setw(57) << "Defesa Especial +" << defesaEspecial << endl << endl; 
}

int Cajado::Magia(){
	
	magia = 5;
	return magia;
}

int Cajado::DefEsp(){
	
	defesaEspecial = 3;
	return defesaEspecial;
}
