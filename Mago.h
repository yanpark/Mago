#ifndef MAGO_H
#define MAGO_H

#include <iostream>
#include <string>
#include"Data.h"
#include"Livro.h"
#include"Personagem.h"

using namespace std;

class Mago : public Personagem{
	
    friend ostream &operator<<(ostream &, const Mago &);
    
	public:
	    Mago(const string &, int);
		~Mago();
		
        virtual void batalhar();
        virtual void atacar();
        virtual void defender();
        virtual void ganharXP(bool);
		virtual void imprimirData() const;
        virtual int aumentarMana() = 0;
		void equiparLivro();
		
		const Mago &operator=(const Mago &);
		bool operator==(const Mago &) const;
		
	protected:
	    int magia;
	    int mana;
        int contEspecial;
        int auxHP;
	    const Data dataFormacaoMagica;
	    Livro livroDasProfecias;
};
#endif
