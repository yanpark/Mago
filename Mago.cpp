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

Mago::Mago(const string &nome, int level, const int nItens):dataFormacaoMagica(){
	
	this->nome = nome;
	this->level = level;
	this->hp = 198+level*2;
	this->mana = 297+level*3;
	this->forca = 0;
	this->defesa = 84+level;
	this->magia = 145+level*3;
	this->defesaEspecial = 115+level*2;
	this->nItens = nItens;
	this->aux = 0;
	equiparCajado();
	inventarioDoMago();
	numerodeMagos++;
	
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

Mago::Mago(const Mago &magodeFora):dataFormacaoMagica(){
	
	nome = magodeFora.nome;
	level = magodeFora.level;
	hp = magodeFora.hp;
	mana = magodeFora.mana;
	forca = magodeFora.forca;
	defesa = magodeFora.defesa;
	magia = magodeFora.magia;
	defesaEspecial = magodeFora.defesaEspecial;
	nItens = magodeFora.nItens;
}

Mago::~Mago(){
	delete [] nomeItens;
	delete [] inventario;
}

ostream &operator<<(ostream &output, const Mago &magoDeFora){
	
	output << magoDeFora.nome <<"\nLevel: " << magoDeFora.level << endl << endl;
	return output;
}

bool Mago::operator==(const Mago &magoDeFora) const{
	
	if((nome != magoDeFora.nome) || (level != magoDeFora.level)){
		return false;
	}
	return true;
}

void Mago::imprimirData() const{
	
	dataFormacaoMagica.print();
}

void Mago::equiparCajado(){
	
	this->magia += cajadoMistico.Magia();
	this->defesaEspecial += cajadoMistico.DefEsp();
}

void Mago::verificarStatus(){
	
	cout << "\n                          Status do Mago " << nome << "\n\n";
	cajadoMistico.print();
	cout << setw(38) << "Level " << setw(5) << level <<'\n';
	cout << setw(38) << "Forca " << setw(5) << forca <<'\n';
	cout << setw(38) << "Defesa " << setw(5) << defesa <<'\n';
	cout << setw(38) << "Magia " << setw(5) << magia <<'\n';
	cout << setw(38) <<"Defesa Especial " << setw(5) << defesaEspecial <<'\n' << endl;
	cout << setw(38) <<"HP " << setw(5) << hp <<'\n';
	cout << setw(38) <<"Mana " << setw(5) << mana <<"\n\n";
	imprimirData();
	srand(time(NULL));
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
		case 0: verificarItem();
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
				monstro.hp_ini = 0;
				cout << "HP do inimigo: " << monstro.hp_ini << endl;
				cout << "Inimigo derrotado!" << endl << endl;
				ganharXP(xp);
				Mago(nome,level,nItens);
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
		hp += 2;
		mana += 3;
		forca += 0;
		defesa += 1;
		magia += 3;
		defesaEspecial += 2;
	}
}

void Mago::guardarItem(){
	
	if(aux >= 0 && aux < quantItens){
		aux = rand()%itemInventario;
		nomeItens[cont] = inventario[aux];
		cout << "Item recolhido!\n" << endl;
		cout << nomeItens[cont] << endl;
		cont++;
	}
	else{
		cout << "Inventario cheio!\n\n";
	}
}

bool Mago::verificarItem(){
	
	system("cls");
	sucesso = rand()%2;
	if(sucesso){
		guardarItem();
	}
	else{
		cout << "Nao ha item no chao!" << endl;
	}
}

void Mago::inventarioDoMago(){
	
	inventario = new string[itemInventario];
	inventario[0] = "Potion +20";
	inventario[1] = "Potion +50";
	inventario[2] = "Potion +100";
	inventario[3] = "Elixir +20";
	inventario[4] = "Elixir +50";
	inventario[5] = "Elixir +100";
	inventario[6] = "Elixir +200";
}
