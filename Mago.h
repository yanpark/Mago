#include <iostream>
#include <string>
#include"Data.h"
using namespace std;

#ifndef MAGO_H
#define MAGO_H

class Mago{
	
	public:
	    Mago(const string &, int);
	    Mago(const Mago &);
		
		void menuPrincipal();
		void verificarStatus(); // Verifica os status de batalha do Mago
		void ganharXP(bool);
		bool batalhar();
		bool atacar(); 
		bool defender();
		bool verificarItem(bool); // Verifica se há um item no chão
		void imprimirData() const;
    	
	private:
		string nome;
		int forca;
<<<<<<< HEAD
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
	    bool xp;
	    static int numerodeMagos;
	    const Data dataFormacaoMagica;
=======
		int defesa; // resistÃªncia a ataques fÃ­sicos
	    int magia;
	    int defesaEspecial; // resistÃªncia a ataques mÃ¡gicos
	    int hp;
	    int mana;
	    int level;
	    int opcao;
	    int dano;
	    bool sucesso;
	    bool item;
	    static int numerodeMagos;
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
};

typedef struct{
	int hp_ini = 125;
	int forca_ini = 98 ;
	int def_esp_ini = 95;	
} Inimigo;
#endif // MAGO_H
