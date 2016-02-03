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
		bool verificarItem(bool); // Verifica se h� um item no ch�o
    	
	private:
		string nome;
		int forca;
		int defesa; // resist�ncia a ataques f�sicos
	    int magia;
	    int defesaEspecial; // resist�ncia a ataques m�gicos
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
