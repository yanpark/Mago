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
