#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Guerreiro.h"

using namespace std;

Inimigo m;

int Guerreiro::numeroDeGuerreiros = 0;

Guerreiro::Guerreiro(const string &nome, int level, const int &nItens):Personagem(nome,level,nItens){
    
    this->forca = 157+level*3;
    numeroDeGuerreiros++;
}

void Guerreiro::imprimirData() const{
	
	dataFormacaoDoGuerreiro.print();
}

void Guerreiro::equiparEspada(){
	
	this->forca += espadaExcalibur.forcaDaEspada();
}

ostream &operator<<(ostream &output, const Guerreiro &guerreiroDeFora){
	
	output << guerreiroDeFora.nome <<"\nLevel: " << guerreiroDeFora.level << endl << endl;
	return output;
}

bool Guerreiro::operator==(const Guerreiro &guerreiroDeFora) const{
	
	if(nome != guerreiroDeFora.nome) return false;
	if(level != guerreiroDeFora.level) return false;
	if(hp != guerreiroDeFora.hp) return false;
	if(defesa != guerreiroDeFora.defesa) return false;
	if(defesaEspecial != guerreiroDeFora.defesaEspecial) return false;
	if(nItens != guerreiroDeFora.nItens) return false;
	if(forca != guerreiroDeFora.forca) return false;
	return true;
}

void Guerreiro::menuPrincipal(){
	
	system("cls");
	cout << "Numero de Personagens = " << numeroDePersonagens << endl << endl;
	cout << "Personagem " << nome << endl << endl;
	
	cout << "1. Entrar em batalha" << endl;
	cout << "0. Recolher item\n" << endl;
	cout << "Escolha uma das opcoes acima: ";
	cin >> opcao;
	switch(opcao){
		case 0: verificarItem();
				break;
		case 1: batalharGuerreiro();
				break;
		default: cout << "\n\nOpcao invalida.\n" << endl;
				break;
	}
}

bool Guerreiro::batalharGuerreiro(){
	
	do{
		system("cls");
		cout << nome << " entrou em batalha\n" << endl;
		cout << "1. Atacar" << endl;
		cout << "0. Defender\n" << endl;
		cout << "Escolha uma das opcoes acima: ";
		cin >> opcao;
		system("cls");
		switch(opcao){
			case 0: defenderComGuerreiro();
					break;
			case 1: atacarComGuerreiro();
					if(hp>0 && m.hp_ini>0){
						defenderComGuerreiro();
					}
					break;
			default: cout << "\n\nOpcao invalida.\n" << endl;
					break;
		}
		
	}
	while((hp>0 && m.hp_ini>0) && (opcao==0 || opcao==1));
};

bool Guerreiro::atacarComGuerreiro(){
	
	cout << nome << " atacou o inimigo\n" << endl;
	sucesso = rand()%2;
	if(sucesso){
		cout << "Ataque bem sucedido!" << endl;
		if(forca<=m.def_esp_ini){
			dano = (m.def_esp_ini/(m.def_esp_ini-forca))/2;
		}
		else if(forca>m.def_esp_ini){
			dano = (forca-m.def_esp_ini)*2;
		}
		m.hp_ini -= dano;
		if(m.hp_ini <= 0){
			dano += m.hp_ini;
			cout << "-" << dano << " de dano no inimigo\n" << endl;
			m.hp_ini = 0;
			cout << "HP do inimigo: " << m.hp_ini << endl;
			cout << "Inimigo derrotado!" << endl << endl;
			ganharXP(xp);
		}
		else{
			cout << "-" << dano << " de dano no inimigo\n" << endl;
		}
	}
	else{
		cout << "O inimigo se esquivou do ataque!\n" << endl;
	}
	system("pause");
}

bool Guerreiro::defenderComGuerreiro(){
	
	system("cls");
	cout << nome << " armou a defesa\n" << endl;
	sucesso = rand()%2;
	if(sucesso){
		cout << "Defesa bem sucedida!\n" << endl;
	}
	else{
		cout << nome << " sofreu dano!" << endl;
		if(m.forca_ini<=defesa){
			dano = (defesa/(defesa-m.forca_ini))/2;
		}
		else if(m.forca_ini>defesa){
			dano = (m.forca_ini-defesa)*2;
		}
		hp -= dano;
		if(hp > 0){
			cout << "-" << dano << " HP\n" << endl;
		}
		else{
			dano += hp;
			cout << "-" << dano << " HP\n" << endl; 
			cout << nome << " foi derrotado!\nFim de jogo!\n" << endl;
			hp = 0;
		}
	}
	cout << "HP de " << nome << ": " << hp << endl;
	cout << "HP do inimigo: " << m.hp_ini << endl << endl;
	system("pause");
}
