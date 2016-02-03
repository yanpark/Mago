#include <iostream>
#include <string>

using namespace std;
using std::string;

#ifndef MAGO_H
#define MAGO_H

class Mago{
	
	public:
	    Mago(const string &, int);
		
		void verificarStatus(); // Verifica os status de batalha do Mago
		void batalhar();
		bool atacar(); 
		bool defender();
		bool verificarItem(bool); // Verifica se há um item no chão
    	
	private:
		string nome;
		int forca;
	    	int defesa; // resistência a ataques físicos
	    	int magia;
	    	int defesaEspecial; // resistência a ataques mágicos
	    	int mana, hp, dano, opcao, level;
	    	bool sucesso, item;
};

typedef struct{
	int hp_ini = 125;
	int forca_ini = 98 ;
	int def_esp_ini = 95;	
} Inimigo;
#endif // MAGO_H
