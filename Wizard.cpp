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
