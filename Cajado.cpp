#include <iostream>
#include <iomanip>
#include "Cajado.h"

using namespace std;

Cajado::Cajado(){
	
	this->magia = magiaDoCajado();
	this->defesaEspecial = defEspDoCajado();
}

void Cajado::print() const{
	
	cout << setw(38) << "Cajado Mistico " << setw(9) << "Magia +" << magia << "\n" << setw(57) << "Defesa Especial +" << defesaEspecial << endl << endl; 
}

int Cajado::magiaDoCajado(){
	
	magia = 5;
	return magia;
}

int Cajado::defEspDoCajado(){
	
	defesaEspecial = 3;
	return defesaEspecial;
}
