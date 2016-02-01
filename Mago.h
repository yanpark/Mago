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
    		bool verificarItem(bool item); // Verifica se há um item no chão
    	
	private:
		string nome;
        	int forca;
	    	int defesa; // resistencia para ataques físicos
	    	int magia;
	    	int defesaEspecial; // resistência a ataques mágicos
	    	int velocidade;
	    	double mana, hp;
	    	bool sucesso, item;
	    	int opcao;
};

#endif // MAGO_H
