#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Personagem.h"
#include"Guerreiro.h"
#include"Ranger.h"

using namespace std;

Ranger::Ranger(const string &nome, int level):Guerreiro(nome,level){
    
    this->upForca = forca + 30;
    this->upHP = hp + 20;
}

Ranger::~Ranger(){
}

ostream &operator<<(ostream &output, const Ranger &rangDeFora){
	
	output << rangDeFora.nome <<"\nLevel: " << rangDeFora.level << endl << endl;
	return output;
}

bool Ranger::operator==(const Ranger &rangDeFora) const{
	
	if(nome != rangDeFora.nome) return false;
	if(level != rangDeFora.level) return false;
	if(upHP != rangDeFora.upHP) return false;
	if(defesa != rangDeFora.defesa) return false;
	if(defesaEspecial != rangDeFora.defesaEspecial) return false;
	if(upForca != rangDeFora.upForca) return false;
	return true;
}

void Ranger::verificarStatus(){
	
	cout << "\n                        Status do Ranger " << nome << "\n\n";
    espadaExcalibur.print();
	cout << setw(38) << "Level " << setw(5) << level <<'\n';
    cout << setw(38) << "Forca " << setw(5) << forca <<'\n';
	cout << setw(38) << "Defesa " << setw(5) << defesa <<'\n';
	cout << setw(38) <<"Defesa Especial " << setw(5) << defesaEspecial <<'\n' << endl;
	cout << setw(38) <<"HP " << setw(5) << hp <<'\n' << endl;
    imprimirData();
}