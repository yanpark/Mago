#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Personagem.h"
#include"Mago.h"
#include"Sorcerer.h"

using namespace std;

Inimigo m3;

Sorcerer::Sorcerer(const string &nome, int level):Mago(nome,level){
    
    this->hp += 10;
    this->mana += 30;
    equiparVarinha();
    this->auxHP = hp;
}

int Sorcerer::aumentarMana(){
    
    this->mana += 30;
    return mana;
}

void Sorcerer::equiparVarinha(){
    
    this->defesa += varinhaDasVarinhas.defesaDaVarinha();
    this->magia += varinhaDasVarinhas.magiaDaVarinha();
}

Sorcerer::~Sorcerer(){
}

ostream &operator<<(ostream &output, const Sorcerer &sorcDeFora){
	
	output << sorcDeFora.nome <<"\nLevel: " << sorcDeFora.level << endl << endl;
	return output;
}

bool Sorcerer::operator==(const Sorcerer &sorcDeFora) const{
	
	if(nome != sorcDeFora.nome) return false;
	if(level != sorcDeFora.level) return false;
	if(hp != sorcDeFora.hp) return false;
	if(defesa != sorcDeFora.defesa) return false;
	if(defesaEspecial != sorcDeFora.defesaEspecial) return false;
    if(magia != sorcDeFora.magia) return false;
	if(mana != sorcDeFora.mana) return false;
	return true;
}

void Sorcerer::verificarStatus(){
	
	cout << "\n                          Status do Sorcerer " << nome << "\n\n";
    livroDasProfecias.print();
    varinhaDasVarinhas.print();
	cout << setw(38) << "Level " << setw(5) << level <<'\n';
    cout << setw(38) << "Magia " << setw(5) << magia <<'\n';
	cout << setw(38) << "Defesa " << setw(5) << defesa <<'\n';
	cout << setw(38) << "Defesa Especial " << setw(5) << defesaEspecial <<'\n' << endl;
	cout << setw(38) << "HP " << setw(5) << hp <<'\n';
    cout << setw(38) << "Mana " << setw(5) << mana <<'\n' << endl;
    imprimirData();
}

void Sorcerer::magiaNegra(){
    
    if(hp <= auxHP*1/3 && contEspecial < 1){
        cout << "Ativar Magia Negra\n\nMagia +60" << endl << endl;
        contEspecial++;
        this->magia = 60;
        system("pause");
        system("cls");
    }
}

void Sorcerer::batalhar(){
	
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
                    if(hp>0 && m3.hp_ini>0){
                        defender();
                    }
                    break;
			default: cout << "\n\nOpcao invalida.\n" << endl;
                    break;
		}
		
	}
	while((hp>0 && m3.hp_ini>0) && (opcao==0 || opcao==1));
}

void Sorcerer::atacar(){
	
    magiaNegra();
	cout << nome << " atacou o inimigo\n-20 Mana\n" << endl;
	mana -= 20;
	sucesso = rand()%2;
	if(mana>0){
		if(sucesso){
			cout << "Ataque bem sucedido!" << endl;
			if(magia<=m3.hp_ini){
				dano = (m3.def_esp_ini/(m3.def_esp_ini-magia))/2;
			}
			else if(magia>m3.def_esp_ini){
				dano = (magia-m3.def_esp_ini)*2;
			}
			m3.hp_ini -= dano;
			if(m3.hp_ini <= 0){
				dano += m3.hp_ini;
				cout << "-" << dano << " de dano no inimigo\n" << endl;
				m3.hp_ini = 0;
				cout << "HP do inimigo: " << m3.hp_ini << endl;
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

void Sorcerer::defender(){
	
	system("cls");
	cout << nome << " armou a defesa\n" << endl;
	sucesso = rand()%2;
	if(sucesso){
		cout << "Defesa bem sucedida!" << endl;
        aumentarMana();
		cout << "+10 Mana\n" << endl;
	}
	else{
		cout << nome << " sofreu dano!" << endl;
		if(m3.forca_ini<=defesa){
			dano = (defesa/(defesa-m3.forca_ini))/2;
		}
		else if(m3.forca_ini>defesa){
			dano = (m3.forca_ini-defesa)*2;
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
	cout << "HP do inimigo: " << m3.hp_ini << endl << endl;
	system("pause");
}
