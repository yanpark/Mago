#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Mago.h"

using std::cout;
using std::string;
using std::setw;

Inimigo monstro;

int Mago::numerodeMagos = 0;

<<<<<<< HEAD
Mago::Mago(const string &nome, int level)
:dataFormacaoMagica()
{
=======
Mago::Mago(const string &nome, int level){
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
	
	this->nome = nome;
	this->level = level;
	this->hp = 198+level*2;
	this->mana = 297+level*3;
	this->forca = 0;
	this->defesa = 84+level;
	this->magia = 145+level*3;
	this->defesaEspecial = 115+level*2;
	numerodeMagos++;
}

<<<<<<< HEAD
Mago::Mago(const Mago &magodeFora)
:dataFormacaoMagica()
{
	nome = magodeFora.nome;
	level = magodeFora.level;
	hp = magodeFora.hp;
	mana = magodeFora.mana;
	forca = magodeFora.forca;
	defesa = magodeFora.defesa;
	magia = magodeFora.magia;
	defesaEspecial = magodeFora.defesaEspecial;
}

void Mago::imprimirData() const{
	
	dataFormacaoMagica.print();
=======
Mago::Mago(const Mago &magodeFora){
	nome = magodeFora.nome;
	level = magodeFora.level;
	hp = magodeFora.hp;
	mana = magodeFora.mana;
	forca = magodeFora.forca;
	defesa = magodeFora.defesa;
	magia = magodeFora.magia;
	defesaEspecial = magodeFora.defesaEspecial;
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
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
<<<<<<< HEAD
	imprimirData();
	srand(time(NULL));
=======
	cout << "Numero de Magos = " << numerodeMagos << endl << endl;
	srand(time(NULL));
	system("pause");
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
}

void Mago::menuPrincipal(){
	
	system("cls");
	cout << "Numero de Magos = " << numerodeMagos << endl << endl;
	cout << "Mago " << nome << endl << endl;
	
	cout << "1. Entrar em batalha" << endl;
	cout << "0. Recolher item\n" << endl;
	cout << "Escolha uma das opcoes acima: ";
	cin >> opcao;
	switch(opcao){
		case 0: verificarItem(item);
				break;
		case 1: batalhar();
				break;
		default: cout << "\n\nOpcao invalida.\n" << endl;
				break;
	}
}

bool Mago::batalhar(){
	
	do{
		system("cls");
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
	while((hp>0 && monstro.hp_ini>0) && (opcao==0 || opcao==1));
};

bool Mago::atacar(){
	
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
				cout << "Inimigo derrotado!" << endl;
				monstro.hp_ini = 0;
				cout << "HP do inimigo: " << monstro.hp_ini << endl << endl;
				ganharXP(xp);
				Mago(nome,level);
				verificarStatus();
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

bool Mago::defender(){
	
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

void Mago::ganharXP(bool xp){
	
	xp = rand()%2;
	if(xp){
		level++;
		cout << "Subida de nivel!\n" << endl;
	}
}

bool Mago::verificarItem(bool item){
	
<<<<<<< HEAD
	system("cls");
=======
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
	item = rand()%2;
	if(item){
		cout << "Item recolhido!\n" << endl;
	}
	else{
		cout << "Nao ha item no chao!\n" << endl;
	}
	system("pause");
}
