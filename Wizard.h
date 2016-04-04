#include <iostream>
#include <string>
#include"Data.h"
#include"Cajado.h"
#include"Personagem.h"
#include"Mago.h"

#ifndef WIZARD_H
#define WIZARD_H

using namespace std;

class Wizard : public Mago{
	
    friend ostream &operator<<(ostream &, const Wizard &);
    
	public:
	    Wizard(const string &, int);
        ~Wizard();
		
        virtual void verificarStatus();
        virtual void batalhar();
        virtual void atacar();
        virtual void defender();
        virtual int aumentarMana();
        void equiparCajado();
        void magiaElementar();
        
		const Wizard &operator=(const Wizard &);
		bool operator==(const Wizard &) const;
		
    private:
        Cajado cajadoMistico;
};
#endif