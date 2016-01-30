#include <iostream>
#include <string>

using namespace std;
using std::string;

#ifndef MAGO_H
#define MAGO_H

class Mago{
	
	public:
		Mago();
		
		void verificarStatus(); // Verifica os status do Mago
		void batalhar(bool opcao);
		bool atacar(); 
    		bool defender();
    		bool verificarItem(bool item); // Verifica se há um item no chão
    		bool defender();
    	
	private:
		string nome;
        	int forca;
	    	int defesa;
	    	int magia;
	    	int defesaEspecial;
	    	int velocidade;
	    	double mana, hp;
	    	bool sucesso, item;
	    	int opcao;
};

#endif // MAGO_H
