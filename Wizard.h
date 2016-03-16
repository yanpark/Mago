#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include <string>
#include"Data.h"
#include"Cajado.h"
#include"Personagem.h"
#include"Mago.h"

using namespace std;

class Wizard : public Mago{
	
    friend ostream &operator<<(ostream &, const Wizard &);
    
	public:
	    Wizard(const string &, int, const int &);
		~Wizard();
		
		const Wizard &operator=(const Wizard &);
		bool operator==(const Wizard &) const;
		
    private:
        int upHP;
	    int upMana;
	    int upMagia;
};
#endif