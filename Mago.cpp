#include <iostream>
#include"Mago.h"

using std::cout;
using std::string;
#include <iomanip>
using std::setw;

Mago::Mago(){
	this->nome="Gandalf";
    	this->hp = 1200;
    	this->mana = 2500;
	this->forca = 0;
	this->defesa = 162;
	this->magia = 300;
	this->defesaEspecial = 255;
	this->velocidade = 191;
}

void Mago::Status(){
	
	cout << "\n                          Status do Mago " << nome << "\n\n";
	cout << setw(38) << "Forca " << setw(5) << forca <<'\n';
	cout << setw(38) << "Defesa " << setw(5) << defesa <<'\n';
	cout << setw(38) << "Magia " << setw(5) << magia <<'\n';
	cout << setw(38) <<"Defesa Especial " << setw(5) << defesaEspecial <<'\n';
	cout << setw(38) <<"Velocidade " << setw(5) << velocidade <<"\n\n";
	cout << setw(38) <<"Hp " << setw(5) << hp <<'\n';
	cout << setw(38) <<"Mana " << setw(5) << mana <<"\n\n";
}
