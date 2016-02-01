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
    	bool verificarItem(bool); // Verifica se há um item no chão
    	
	private:
		string nome;
        int forca;
	    int defesa; // resist�ncia a ataques f�sicos
	    int magia;
	    int defesaEspecial; // resist�ncia a ataques m�gicos
	    int velocidade;
	    double mana, hp;
	    bool sucesso, item;
	    int opcao, level;
};

#endif // MAGO_H
