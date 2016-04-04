#include <iostream>
#include <iomanip>
#include "Varinha.h"

using namespace std;

Varinha::Varinha(){
	
    this->defesa = defesaDaVarinha();
	this->magia = magiaDaVarinha();
}

void Varinha::print() const{
	
	cout << setw(38) << "Varinha " << setw(10) << "Defesa +" << defesa << "\n" << setw(47) << "Magia +" << magia << endl << endl; 
}

int Varinha::defesaDaVarinha(){
	
	defesa = 3;
	return defesa;
}

int Varinha::magiaDaVarinha(){
	
	magia = 5;
	return magia;
}
