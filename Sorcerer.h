#include <iostream>
#include <string>
#include"Data.h"
#include"Varinha.h"
#include"Personagem.h"
#include"Mago.h"

#ifndef SORCERER_H
#define SORCERER_H

using namespace std;

class Sorcerer : public Mago{
	
    friend ostream &operator<<(ostream &, const Sorcerer &);
    
	public:
	    Sorcerer(const string &, int);
		~Sorcerer();
        
        virtual void verificarStatus();
        virtual void batalhar();
        virtual void atacar();
        virtual void defender();
        virtual int aumentarMana();
        void equiparVarinha();
		void magiaNegra();
        
		const Sorcerer &operator=(const Sorcerer &);
		bool operator==(const Sorcerer &) const;
		
    private:
        Varinha varinhaDasVarinhas;
};
#endif