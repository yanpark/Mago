#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Mago.h"

using std::cout;
using std::string;
using std::setw;

Inimigo monstro;

Mago::Mago(const string &nome, int level){
	
	this->nome=nome;
	this->level = level;
	this->hp = 198+level*2;
<<<<<<< HEAD
    this->mana = 297+level*3;
=======
<<<<<<< HEAD
    this->mana = 297+level*3;
=======
	this->mana = 297+level*3;
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
	this->forca = 0;
	this->defesa = 84+level;
	this->magia = 145+level*3;
	this->defesaEspecial = 115+level*2;
}

void Mago::verificarStatus(){
	
	cout << "\n                          Status do Mago " << nome << "\n\n";
	cout << setw(38) << "Level " << setw(5) << level <<'\n';
	cout << setw(38) << "Forca " << setw(5) << forca <<'\n';
	cout << setw(38) << "Defesa " << setw(5) << defesa <<'\n';
	cout << setw(38) << "Magia " << setw(5) << magia <<'\n';
	cout << setw(38) <<"Defesa Especial " << setw(5) << defesaEspecial <<'\n' << endl;
	cout << setw(38) <<"HP " << setw(5) << hp <<'\n';
	cout << setw(38) <<"Mana " << setw(5) << mana <<"\n\n";
	system("pause");
}

void Mago::batalhar(){
	
	while(hp>0 && monstro.hp_ini>0){
		cout << nome << " entrou em batalha\n" << endl;
		cout << "1. Atacar" << endl;
		cout << "0. Defender\n" << endl;
		cout << "Escolha uma das opcoes acima: ";
		cin >> opcao;
		system("cls");
		switch(opcao){
			case 0: defender();
					break;
			case 1: atacar();
					if(hp>0 && monstro.hp_ini>0){
						defender();
					}
					break;
			default: cout << "\n\nOpcao invalida.\n" << endl;
					break;
		}
	}
};

bool Mago::atacar(){
	
	cout << nome << " atacou o inimigo\n-20 Mana\n" << endl;
	mana -= 20;
	srand(time(NULL));
	sucesso = rand()%2;
	if(mana>0){
		if(sucesso){
			cout << "Ataque bem sucedido!" << endl;
			dano = (magia-monstro.def_esp_ini);
			monstro.hp_ini -= dano;
			if(monstro.hp_ini <= 0){
				cout << "\nInimigo derrotado!\n" << endl;
				monstro.hp_ini = 0;
			}
			else if(monstro.hp_ini > 0){
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
	cout << "HP de Gandalf: " << hp << endl;
	cout << "Mana de Gandalf: " << mana << endl << endl;
	cout << "HP do inimigo: " << monstro.hp_ini << endl << endl;
	system("pause");
	system("cls");
}

bool Mago::defender(){
	
	cout << nome << " armou a defesa\n" << endl;
	srand(time(NULL));
	sucesso = rand()%2;
	if(sucesso){
		cout << "Defesa bem sucedida!" << endl;
		mana += 10;
		cout << "+10 Mana\n" << endl;
	}
	else{
		cout << nome << " sofreu dano!" << endl;
		dano = defesa-(monstro.forca_ini/2);
		hp -= dano;
		if(hp > 0){
			cout << "-" << dano << " HP\n" << endl;
		}
		if(hp <= 0){
			cout << '\n';
			cout << nome << " foi derrotado!\nFim de jogo!\n" << endl;
			hp = 0;
		}
	}
	cout << "HP de Gandalf: " << hp << endl;
	cout << "Mana de Gandalf: " << mana << endl << endl;
	cout << "HP do inimigo: " << monstro.hp_ini << endl << endl;
	system("pause");
	system("cls");
}

bool Mago::verificarItem(bool item){
	
	srand(time(NULL));
	item = rand()%2;
	if(item){
		cout << "Item recolhido!" << endl;
	}
	else{
		cout << "Nao ha item no chao!" << endl;
	}
}
