#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Personagem.h"
#include"Mago.h"
#include"Wizard.h"

using std::cout;
using std::string;
using std::setw;

Wizard::Wizard(const string &nome, int level, const int &nItens):Mago(nome,level,nItens){
    
    this->upHP = hp + 20;
    this->upMana = mana + 50;
    this->upMagia = magia + 30;
}

Wizard::~Wizard(){
}

ostream &operator<<(ostream &output, const Wizard &wizDeFora){
	
	output << wizDeFora.nome <<"\nLevel: " << wizDeFora.level << endl << endl;
	return output;
}

bool Wizard::operator==(const Wizard &wizDeFora) const{
	
	if(nome != wizDeFora.nome) return false;
	if(level != wizDeFora.level) return false;
	if(upHP != wizDeFora.upHP) return false;
	if(defesa != wizDeFora.defesa) return false;
	if(defesaEspecial != wizDeFora.defesaEspecial) return false;
	if(nItens != wizDeFora.nItens) return false;
	if(upMana != wizDeFora.upMana) return false;
	if(upMagia != wizDeFora.upMagia) return false;
	return true;
}