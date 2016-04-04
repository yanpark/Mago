#include <iostream>
#include <iomanip>
#include "Espada.h"

using namespace std;

Espada::Espada(){
	
	this->forca = forcaDaEspada();
}

void Espada::print() const{
	
	cout << setw(38) << "Espada Excalibur " << setw(9) << "Forca +" << forca << "\n" << setw(57) << endl; 
}

int Espada::forcaDaEspada(){
	
	forca = 5;
	return forca;
}
