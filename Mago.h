#include <iostream>
#include <string>

using namespace std;

#ifndef MAGO_H
#define MAGO_H

class Mago{
	
	public:
	    Mago(const string &, int);
	    Mago(const Mago &);
		
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
	    int hp;
	    int mana;
	    int level;
	    int opcao;
	    int dano;
	    bool sucesso;
	    bool item;
	    static int numerodeMagos;
};

typedef struct{
	int hp_ini = 125;
	int forca_ini = 98 ;
	int def_esp_ini = 95;	
} Inimigo;
#endif // MAGO_H
