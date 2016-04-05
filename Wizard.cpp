#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include"Personagem.h"
#include"Mago.h"
#include"Wizard.h"

using namespace std;

Inimigo m1;

Wizard::Wizard(const string &nome, int level):Mago(nome,level){
    
    this->hp += 10;
    this->magia += 30;
    equiparCajado();
    this->auxHP = hp;
}

Wizard::~Wizard(){
}

int Wizard::aumentarMana(){
    
    this->mana += 20;
    return mana;
}

void Wizard::equiparCajado(){
	
    this->defesaEspecial += cajadoMistico.defEspDoCajado();
	this->magia += cajadoMistico.magiaDoCajado();
}

ostream &operator<<(ostream &output, const Wizard &wizDeFora){
	
	output << wizDeFora.nome <<"\nLevel: " << wizDeFora.level << endl << endl;
	return output;
}

bool Wizard::operator==(const Wizard &wizDeFora) const{
	
	if(nome != wizDeFora.nome) return false;
	if(level != wizDeFora.level) return false;
	if(hp != wizDeFora.hp) return false;
	if(defesa != wizDeFora.defesa) return false;
	if(defesaEspecial != wizDeFora.defesaEspecial) return false;
	if(magia != wizDeFora.magia) return false;
    if(mana != wizDeFora.mana) return false;
	return true;
}

void Wizard::verificarStatus(){
	
	cout << "\n                        Status do Wizard " << nome << "\n\n";
    livroDasProfecias.print();
    cajadoMistico.print();
	cout << setw(38) << "Level " << setw(5) << level <<'\n';
    cout << setw(38) << "Magia " << setw(5) << magia <<'\n';
	cout << setw(38) << "Defesa " << setw(5) << defesa <<'\n';
	cout << setw(38) <<"Defesa Especial " << setw(5) << defesaEspecial <<'\n' << endl;
	cout << setw(38) <<"HP " << setw(5) << hp <<'\n';
    cout << setw(38) << "Mana " << setw(5) << mana <<'\n' << endl;
    imprimirData();
}

void Wizard::magiaElementar(){
    
    if(hp <= auxHP*1/3 && contEspecial < 1){
        cout << "Ativar Magia Elementar" << endl << endl;
        this->magia += 30;
        contEspecial++;
        cout << "Escolha o tipo de magia: " << endl << endl;
        cout << "1 - Fogo   - Magia +30/ Defesa Especial + 20" << endl;
        cout << "2 - Trovao - Magia +30/ HP + 20" << endl;
        cout << "3 - Gelo   - Magia +30/ Defesa + 20" << endl << endl;
        
        cout << "Opcao: ";
        cin >> opcao;
        
        switch(opcao){
            case 1: this->defesaEspecial += 20;
                    break;
            case 2: this->hp += 20;
                    break;
            case 3: this->defesa += 20;
                    break;
            default: cout << "\n\nOpcao invalida.\n" << endl;
                    break;
        }
        system("cls");
    }
}

void Wizard::batalhar(){
	
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
                    if(hp>0 && m1.hp_ini>0){
                        defender();
                    }
                    break;
			default: cout << "\n\nOpcao invalida.\n" << endl;
                    break;
		}
		
	}
	while((hp>0 && m1.hp_ini>0) && (opcao==0 || opcao==1));
};

void Wizard::atacar(){
	
    magiaElementar();
	cout << nome << " atacou o inimigo\n-20 Mana\n" << endl;
	mana -= 20;
	sucesso = rand()%2;
	if(mana>0){
		if(sucesso){
			cout << "Ataque bem sucedido!" << endl;
			if(magia<=m1.hp_ini){
				dano = (m1.def_esp_ini/(m1.def_esp_ini-magia))/2;
			}
			else if(magia>m1.def_esp_ini){
				dano = (magia-m1.def_esp_ini)*2;
			}
			m1.hp_ini -= dano;
			if(m1.hp_ini <= 0){
				dano += m1.hp_ini;
				cout << "-" << dano << " de dano no inimigo\n" << endl;
				m1.hp_ini = 0;
				cout << "HP do inimigo: " << m1.hp_ini << endl;
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

void Wizard::defender(){
	
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
		if(m1.forca_ini<=defesa){
			dano = (defesa/(defesa-m1.forca_ini))/2;
		}
		else if(m1.forca_ini>defesa){
			dano = (m1.forca_ini-defesa)*2;
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
	cout << "HP do inimigo: " << m1.hp_ini << endl << endl;
	system("pause");
}
