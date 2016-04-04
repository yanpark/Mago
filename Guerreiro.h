#ifndef GUERREIRO_H
#define GUERREIRO_H

#include <iostream>
#include <string>
#include"Data.h"
#include"Personagem.h"
#include"Espada.h"

using namespace std;

class Guerreiro : public Personagem{
	
    friend ostream &operator<<(ostream &, const Guerreiro &);
    
	public:
	    Guerreiro(const string &, int);
		
        virtual void verificarStatus();
        virtual void batalhar();
		virtual void atacar();
		virtual void defender();
		virtual void imprimirData() const;
		void equiparEspada();
		
		const Guerreiro &operator=(const Guerreiro &);
		bool operator==(const Guerreiro &) const;
		
	protected:
	    int forca;
	    const Data dataFormacaoDoGuerreiro;
	    Espada espadaExcalibur;
};
#endif
