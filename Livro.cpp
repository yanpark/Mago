#include <iostream>
#include <iomanip>
#include "Livro.h"

using namespace std;

Livro::Livro(){
	this->hp = hpDoLivro();
	this->magia = magiaDoLivro();
}

void Livro::print() const{
	
	cout << setw(38) << "Livro " << setw(6) << "HP +" << hp << "\n" << setw(47) << "Magia +" << magia << endl << endl; 
}

int Livro::hpDoLivro(){
	
	hp = 5;
	return hp;
}

int Livro::magiaDoLivro(){
	
	magia = 5;
	return magia;
}
