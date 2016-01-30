#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include"Mago.h"

using std::cout;
using std::string;
using std::setw;

Mago::Mago(){
	this->nome="Gandalf";
<<<<<<< HEAD
    this->hp = 400;
    this->mana = 600;
=======
    	this->hp = 1200;
    	this->mana = 2500;
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
	this->forca = 0;
	this->defesa = 162;
	this->magia = 300;
	this->defesaEspecial = 255;
	this->velocidade = 191;
	this->sucesso = true;
}

void Mago::verificarStatus(){
	
	cout << "\n                          Status do Mago " << nome << "\n\n";
	cout << setw(38) << "Forca " << setw(5) << forca <<'\n';
	cout << setw(38) << "Defesa " << setw(5) << defesa <<'\n';
	cout << setw(38) << "Magia " << setw(5) << magia <<'\n';
	cout << setw(38) <<"Defesa Especial " << setw(5) << defesaEspecial <<'\n';
	cout << setw(38) <<"Velocidade " << setw(5) << velocidade <<"\n\n";
	cout << setw(38) <<"HP " << setw(5) << hp <<'\n';
	cout << setw(38) <<"Mana " << setw(5) << mana <<"\n\n";
}

void Mago::batalhar(bool opcao){
	
	cout << nome << " entrou em batalha\n" << endl;
	cout << "1. Atacar" << endl;
	cout << "2. Defender\n" << endl;
	atacar();
	defender();
};

bool Mago::atacar(){
	
	cout << nome << " atacou o inimigo\n" << endl;
	mana -= 20;
	if(sucesso){
		cout << "Ataque bem sucedido!\n" << endl;
	}
	else{
		cout << "O inimigo se esquivou do ataque!\n" << endl;
	}
	cout << "Mana de Gandalf: " << mana << endl << endl;
}

bool Mago::defender(){
	
	cout << nome << " armou a defesa\n" << endl;
	mana -= 20;
	if(sucesso){
		cout << "Defesa bem sucedida!\n" << endl;
		mana += 20;
	}
	else{
		cout << nome << " sofreu dano!\n" << endl;
		hp -= 0.1*hp;
	}
	cout << "HP de Gandalf: " << hp << endl;
	cout << "Mana de Gandalf: " << mana << endl << endl;
}

bool Mago::verificarItem(bool item){
	
	if(item){
		cout << "Item recolhido!" << endl;
	}
	else{
		cout << "Nao ha nenhum item!" << endl;
	}
}
