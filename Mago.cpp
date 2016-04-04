#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Mago.h"

using namespace std;

Mago::Mago(const string &nome, int level):Personagem(nome,level){
    
    this->magia = 145+level*3;
    this->mana = 293+level*7;
    this->contEspecial = 0;
    equiparLivro();
}

Mago::~Mago(){
}

void Mago::batalhar(){
}

void Mago::atacar(){
}

void Mago::defender(){
}

void Mago::imprimirData() const{
	
	cout << setw(38) << "Data de Formacao Magica ";
    dataFormacaoMagica.print();
}

void Mago::equiparLivro(){
	
    this->hp += livroDasProfecias.hpDoLivro();
	this->magia += livroDasProfecias.magiaDoLivro();
}

ostream &operator<<(ostream &output, const Mago &magoDeFora){
	
	output << magoDeFora.nome <<"\nLevel: " << magoDeFora.level << endl << endl;
	return output;
}

bool Mago::operator==(const Mago &magoDeFora) const{
	
	if(nome != magoDeFora.nome) return false;
	if(level != magoDeFora.level) return false;
	if(hp != magoDeFora.hp) return false;
	if(defesa != magoDeFora.defesa) return false;
	if(defesaEspecial != magoDeFora.defesaEspecial) return false;
	if(mana != magoDeFora.mana) return false;
	if(magia != magoDeFora.level) return false;
	return true;
}