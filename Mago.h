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
		
        void menuPrincipal();
        bool batalharMago();
		bool atacarComMago();
		bool defenderComMago();
		void equiparCajado();
		
		const Mago &operator=(const Mago &);
		bool operator==(const Mago &) const;
		
	private:
	    int magia;
	    int mana;
	    static int numerodeMagos;
	    const Data dataFormacaoMagica;
	    Cajado cajadoMistico;
};
typedef struct{
	int hp_ini = 125;
	int forca_ini = 98 ;
	int def_esp_ini = 95;	
} Inimigo;
#endif
