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
		int velocidade;
		double mana, hp;
		bool sucesso, item;
		int opcao, level;
};

#endif // MAGO_H
