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
    	bool defender();
    	bool verificarItem(bool); // Verifica se hÃ¡ um item no chÃ£o
    	
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
	int hp_ini = 100;
	int forca_ini = 82;
	int defesa_ini = 120;
	int def_esp_ini = 78;	
} Inimigo;
#endif // MAGO_H
