#include <iostream>
#include <string>
#include"Data.h"
#include"Cajado.h"
using namespace std;

#ifndef MAGO_H
#define MAGO_H

class Mago{
	
	public:
	    Mago(const string &, int, int const);
	    Mago(const Mago &);
	    ~Mago();
	    
	    friend ostream &operator<<(ostream &, const Mago &);
		const Mago &operator=(const Mago &);
		bool operator==(const Mago &) const;
		
		void menuPrincipal();
		void verificarStatus(); // Verifica os status de batalha do Mago
		void ganharXP(bool);
		bool batalhar();
		bool atacar(); 
		bool defender();
		bool verificarItem(); // Verifica se h� um item no ch�o
		void inventarioDoMago();
		void imprimirData() const;
		void equiparCajado();
		void guardarItem();
		
	private:
		string nome;
		int forca;
		int defesa; // resist�ncia a ataques f�sicos
	    int magia;
	    int defesaEspecial; // resist�ncia a ataques m�gicos
	    int hp;
	    int mana;
	    int level;
	    int opcao;
	    int dano;
	    bool sucesso;
	    string item;
	    bool xp;
	    string *inventario;
	    string *nomeItens;
	    int itemInventario = 7;
	    int cont = 0;
	    int quantItens;
	    int nItens;
	    int aux;
	    static int numerodeMagos;
	    const Data dataFormacaoMagica;
	    Cajado cajadoMistico;
};

typedef struct{
	int hp_ini = 125;
	int forca_ini = 98 ;
	int def_esp_ini = 95;	
} Inimigo;
#endif // MAGO_H
