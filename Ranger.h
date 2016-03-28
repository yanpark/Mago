#ifndef RANGER_H
#define RANGER_H

#include <iostream>
#include <string>
#include"Data.h"
#include"Espada.h"
#include"Personagem.h"
#include"Guerreiro.h"

using namespace std;

class Ranger : public Guerreiro{
	
    friend ostream &operator<<(ostream &, const Ranger &);
    
	public:
	    Ranger(const string &, int, const int &);
		~Ranger();
		
		const Ranger &operator=(const Ranger &);
		bool operator==(const Ranger &) const;
		
    private:
        int upForca;
        int upHP;
};
#endif