#include <iostream>
#include <string>

using namespace std;
using std::string;

#ifndef MAGO_H
#define MAGO_H

class Mago{
	
	public:
	    Mago(const string &, int);
		
		void verificarStatus(); // Verifica os status do Mago
		void batalhar();
		bool atacar(); 
<<<<<<< HEAD
    	bool defender();
    	bool verificarItem(bool); // Verifica se há um item no chão
=======
<<<<<<< HEAD
    	bool defender();
    	bool verificarItem(bool); // Verifica se há um item no chão
=======
		bool defender();
		bool verificarItem(bool); // Verifica se hÃ¡ um item no chÃ£o
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
    	
	private:
		string nome;
<<<<<<< HEAD
        int forca;
	    int defesa; // resist�ncia a ataques f�sicos
	    int magia;
	    int defesaEspecial; // resist�ncia a ataques m�gicos
	    int mana, hp, dano, opcao, level;
	    bool sucesso, item;
=======
<<<<<<< HEAD
        int forca;
	    int defesa; // resist�ncia a ataques f�sicos
	    int magia;
	    int defesaEspecial; // resist�ncia a ataques m�gicos
	    int velocidade;
	    double mana, hp;
	    bool sucesso, item;
	    int opcao, level;
=======
		int forca;
		int defesa; // resistência a ataques físicos
		int magia;
		int defesaEspecial; // resistência a ataques mágicos
		int velocidade;
		double mana, hp;
		bool sucesso, item;
		int opcao, level;
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
};

typedef struct{
	int hp_ini = 100;
	int forca_ini = 82;
	int defesa_ini = 120;
	int def_esp_ini = 78;	
} Inimigo;
#endif // MAGO_H
