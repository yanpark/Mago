#include <iostream>
#include <string>

using namespace std;
using std::string;

#ifndef MAGO_H
#define MAGO_H

class Mago{
	
	public:
		Mago();
		
		void Status();	
		bool atacar(); 
    		bool defender();
    	
	private:
		string nome;
        	int forca;
	    	int defesa;
	    	int magia;
	    	int defesaEspecial;
	    	int velocidade;
	    	double mana, hp;
	    	bool sucesso;
};

#endif // MAGO_H
