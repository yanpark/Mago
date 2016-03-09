#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Personagem.h"

using std::cout;
using std::string;
using std::setw;

int Personagem::numeroDePersonagens = 0;

Personagem::Personagem(const string &nome, int level, const int &nItens){
	
	this->nome = nome;
	this->level = level;
	this->hp = 195+level*5;
	this->defesa = 84+level;
	this->defesaEspecial = 115+level*2;
	this->nItens = nItens;
	this->aux = 0;
	this->itemInventario = 7;
	this->cont = 0;
    numeroDePersonagens++;
	
	if(nItens>0){
		nomeItens = new string[nItens];
		quantItens = nItens;
		cout << "Espaco de itens no inventario de " << nome << ": " << quantItens << "\n\n";
	}
	else{
		nomeItens = 0;
		quantItens = 0;
		cout << "Tamanho invalido\n\n";
	}
}

Personagem::Personagem(const Personagem &persDeFora){
	
	nome = persDeFora.nome;
	level = persDeFora.level;
	hp = persDeFora.hp;
	defesa = persDeFora.defesa;
	defesaEspecial = persDeFora.defesaEspecial;
	nItens = persDeFora.nItens;
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
	
	if((nome != persDeFora.nome) || (level != persDeFora.level)){
		return false;
	}
	return true;
}

const void Personagem::verificarStatus(const Personagem &p){
	
	cout << "\n                          Status do Personagem " << p.nome << "\n\n";
	cout << setw(38) << "Level " << setw(5) << p.level <<'\n';
	cout << setw(38) << "Defesa " << setw(5) << p.defesa <<'\n';
	cout << setw(38) <<"Defesa Especial " << setw(5) << p.defesaEspecial <<'\n' << endl;
	cout << setw(38) <<"HP " << setw(5) << p.hp <<'\n';
	srand(time(NULL));
}

void Personagem::ganharXP(bool xp){
	
	xp = rand()%2;
	if(xp){
		level++;
		cout << "Subida de nivel!\n" << endl;
		hp = 195+level*5;
		defesa += 1;
		defesaEspecial += 2;
	}
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
	
	if(aux >= 0 && aux < quantItens){
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
