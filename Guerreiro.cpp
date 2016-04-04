#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Guerreiro.h"

using namespace std;

Inimigo m2;

Guerreiro::Guerreiro(const string &nome, int level):Personagem(nome,level){
    
    this->forca = 157+level*3;
    equiparEspada();
}

void Guerreiro::imprimirData() const{
	
	cout << setw(38) << "Data de Formacao do Guerreiro ";
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
	if(forca != guerreiroDeFora.forca) return false;
	return true;
}

void Guerreiro::verificarStatus(){
}

void Guerreiro::batalhar(){
	
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
                    if(hp>0 && m2.hp_ini>0){
                        defender();
                    }
                    break;
			default: cout << "\n\nOpcao invalida.\n" << endl;
                    break;
		}
		
	}
	while((hp>0 && m2.hp_ini>0) && (opcao==0 || opcao==1));
};

void Guerreiro::atacar(){
	
	cout << nome << " atacou o inimigo\n" << endl;
	sucesso = rand()%2;
	if(sucesso){
		cout << "Ataque bem sucedido!" << endl;
		if(forca<=m2.def_esp_ini){
			dano = (m2.def_esp_ini/(m2.def_esp_ini-forca))/2;
		}
		else if(forca>m2.def_esp_ini){
			dano = (forca-m2.def_esp_ini)*2;
		}
		m2.hp_ini -= dano;
		if(m2.hp_ini <= 0){
			dano += m2.hp_ini;
			cout << "-" << dano << " de dano no inimigo\n" << endl;
			m2.hp_ini = 0;
			cout << "HP do inimigo: " << m2.hp_ini << endl;
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

void Guerreiro::defender(){
	
	system("cls");
	cout << nome << " armou a defesa\n" << endl;
	sucesso = rand()%2;
	if(sucesso){
		cout << "Defesa bem sucedida!\n" << endl;
	}
	else{
		cout << nome << " sofreu dano!" << endl;
		if(m2.forca_ini<=defesa){
			dano = (defesa/(defesa-m2.forca_ini))/2;
		}
		else if(m2.forca_ini>defesa){
			dano = (m2.forca_ini-defesa)*2;
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
	cout << "HP do inimigo: " << m2.hp_ini << endl << endl;
	system("pause");
}
