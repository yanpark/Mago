#ifndef MAGO_H
#define MAGO_H

#include <iostream>
#include <string>
#include"Data.h"
#include"Cajado.h"
#include"Personagem.h"

using namespace std;

class Mago : public Personagem{
	
    friend ostream &operator<<(ostream &, const Mago &);
    
	public:
	    Mago(const string &, int, const int &);
		~Mago();
		
        virtual void menuPrincipal();
        bool batalharMago();
		bool atacarComMago();
		bool defenderComMago();
		virtual void imprimirData() const;
		void equiparCajado();
		
		const Mago &operator=(const Mago &);
		bool operator==(const Mago &) const;
		
	protected:
	    int magia;
	    int mana;
	    static int numeroDeMagos;
	    const Data dataFormacaoMagica;
	    Cajado cajadoMistico;
};
#endif
