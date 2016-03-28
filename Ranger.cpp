#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Personagem.h"
#include"Guerreiro.h"
#include"Ranger.h"

using std::cout;
using std::string;
using std::setw;

Ranger::Ranger(const string &nome, int level, const int &nItens):Guerreiro(nome,level,nItens){
    
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
	if(nItens != rangDeFora.nItens) return false;
	if(upForca != rangDeFora.upForca) return false;
	return true;
}