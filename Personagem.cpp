#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Personagem.h"

using namespace std;

int Personagem::numeroDePersonagens = 0;

Personagem::Personagem(const string &nome, int level){
	
	this->nome = nome;
	this->level = level;
	this->hp = 190+level*10;
	this->defesa = 84+level;
	this->defesaEspecial = 115+level*2;
	this->quantItens = 40;
	this->aux = 0;
	this->itemInventario = 7;
	this->cont = 0;
    inventario();
    numeroDePersonagens++;
    srand(time(NULL));
	
	if(quantItens>0){
		nomeItens = new string[quantItens];
		cout << "Espaco de itens no inventario de " << nome << ": " << quantItens << "\n\n";
	}
	else{
		nomeItens = 0;
        quantItens = 0;

	}
}

Personagem::Personagem(const Personagem &persDeFora){
	
	nome = persDeFora.nome;
	level = persDeFora.level;
	hp = persDeFora.hp;
	defesa = persDeFora.defesa;
	defesaEspecial = persDeFora.defesaEspecial;
}

Personagem::~Personagem(){
	delete [] nomeItens;
	delete [] ptr_inventario;
}

ostream &operator<<(ostream &output, const Personagem &persDeFora){
	
	output << persDeFora.nome <<"\nLevel: " << persDeFora.level << endl << endl;
	return output;
}

bool Personagem::operator==(const Personagem &persDeFora) const{
	
	if(nome != persDeFora.nome) return false;
	if(level != persDeFora.level) return false;
	if(hp != persDeFora.hp) return false;
	if(defesa != persDeFora.defesa) return false;
	if(defesaEspecial != persDeFora.defesaEspecial) return false;
	return true;
}

void Personagem::imprimirData() const{
}

void Personagem::menuPrincipal(){
    
    system("cls");
	cout << "Numero de Personagens = " << numeroDePersonagens << endl << endl;
	cout << "Personagem " << nome << endl << endl;
	
    do{
        cout << "1. Entrar em batalha" << endl;
        cout << "0. Recolher item\n" << endl;
        cout << "Escolha uma das opcoes acima: ";
        cin >> opcao;
        switch(opcao){
            case 0: verificarItem();
                    break;
            case 1: batalhar();
                    break;
            default: cout << "\n\nOpcao invalida.\n" << endl;
                    break;
        }
    }
    while(opcao==0);
}
void Personagem::verificarStatus(){
}

void Personagem::ganharXP(bool xp){
}

bool Personagem::verificarItem(){
	
	system("cls");
	sucesso = rand()%2;
	if(sucesso){
		guardarItem();
	}
	else{
		cout << "Nao ha item no chao!" << endl;
	}
	cout << '\n';
	system("pause");
    return sucesso;
}

void Personagem::guardarItem(){
	
	if(cont >= 0 && cont < quantItens){
		aux = rand()%itemInventario;
		nomeItens[cont] = ptr_inventario[aux];
		cout << "Item recolhido!\n" << endl;
		cout << nomeItens[cont] << endl;
		cont++;
	}
	else{
		cout << "Inventario cheio!\n\n";
	}
}

void Personagem::inventario(){
	
	ptr_inventario = new string[itemInventario];
	ptr_inventario[0] = "Potion +20";
	ptr_inventario[1] = "Potion +50";
	ptr_inventario[2] = "Potion +100";
	ptr_inventario[3] = "Elixir +20";
	ptr_inventario[4] = "Elixir +50";
	ptr_inventario[5] = "Elixir +100";
	ptr_inventario[6] = "Elixir +200";
}
