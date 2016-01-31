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
		void batalhar();
		bool atacar(); 
<<<<<<< HEAD
    	bool defender();
    	bool verificarItem(bool item); // Verifica se há um item no chão
=======
    		bool defender();
    		bool verificarItem(bool item); // Verifica se hÃ¡ um item no chÃ£o
    		bool defender();
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
    	
	private:
		string nome;
<<<<<<< HEAD
        int forca;
	    int defesa;
	    int magia;
	    int defesaEspecial;
	    int velocidade;
	    double mana, hp;
	    bool sucesso, item;
	    int opcao;
=======
        	int forca;
	    	int defesa;
	    	int magia;
	    	int defesaEspecial;
	    	int velocidade;
	    	double mana, hp;
	    	bool sucesso, item;
	    	int opcao;
>>>>>>> branch 'master' of https://github.com/yanpark/Mago.git
};

#endif // MAGO_H
