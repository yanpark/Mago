#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Mago.h"

using namespace std;

Inimigo monstro;

int Mago::numeroDeMagos = 0;

Mago::Mago(const string &nome, int level, const int &nItens):Personagem(nome,level,nItens){
    
    this->magia = 145+level*3;
    this->mana = 293+level*7;
    numeroDeMagos++;
}

Mago::~Mago(){
}

void Mago::imprimirData() const{
	
	dataFormacaoMagica.print();
}

void Mago::equiparCajado(){
	
	this->magia += cajadoMistico.magiaDoCajado();
	this->defesaEspecial += cajadoMistico.defEspDoCajado();
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
	if(nItens != magoDeFora.nItens) return false;
	if(mana != magoDeFora.mana) return false;
	if(magia != magoDeFora.level) return false;
	return true;
}

void Mago::menuPrincipal(){
	
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
		case 1: batalharMago();
				break;
		default: cout << "\n\nOpcao invalida.\n" << endl;
				break;
	}
}

bool Mago::batalharMago(){
	
	do{
		system("cls");
		cout << nome << " entrou em batalha\n" << endl;
		cout << "1. Atacar" << endl;
		cout << "0. Defender\n" << endl;
		cout << "Escolha uma das opcoes acima: ";
		cin >> opcao;
		system("cls");
		switch(opcao){
			case 0: defenderComMago();
				break;
			case 1: atacarComMago();
				if(hp>0 && monstro.hp_ini>0){
					defenderComMago();
				}
				break;
			default: cout << "\n\nOpcao invalida.\n" << endl;
				break;
		}
		
	}
	while((hp>0 && monstro.hp_ini>0) && (opcao==0 || opcao==1));
};

bool Mago::atacarComMago(){
	
	cout << nome << " atacou o inimigo\n-20 Mana\n" << endl;
	mana -= 20;
	sucesso = rand()%2;
	if(mana>0){
		if(sucesso){
			cout << "Ataque bem sucedido!" << endl;
			if(magia<=monstro.def_esp_ini){
				dano = (monstro.def_esp_ini/(monstro.def_esp_ini-magia))/2;
			}
			else if(magia>monstro.def_esp_ini){
				dano = (magia-monstro.def_esp_ini)*2;
			}
			monstro.hp_ini -= dano;
			if(monstro.hp_ini <= 0){
				dano += monstro.hp_ini;
				cout << "-" << dano << " de dano no inimigo\n" << endl;
				monstro.hp_ini = 0;
				cout << "HP do inimigo: " << monstro.hp_ini << endl;
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
	}
	else{
		cout << "Mana esgotada! " << nome << " nao pode atacar!\n" << endl;
	}
	system("pause");
}

bool Mago::defenderComMago(){
	
	system("cls");
	cout << nome << " armou a defesa\n" << endl;
	sucesso = rand()%2;
	if(sucesso){
		cout << "Defesa bem sucedida!" << endl;
		mana += 10;
		cout << "+10 Mana\n" << endl;
	}
	else{
		cout << nome << " sofreu dano!" << endl;
		if(monstro.forca_ini<=defesa){
			dano = (defesa/(defesa-monstro.forca_ini))/2;
		}
		else if(monstro.forca_ini>defesa){
			dano = (monstro.forca_ini-defesa)*2;
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
	cout << "Mana de " << nome << ": " << mana << endl << endl;
	cout << "HP do inimigo: " << monstro.hp_ini << endl << endl;
	system("pause");
}
