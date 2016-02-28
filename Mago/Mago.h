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
		
		void menuPrincipal();
		static const void verificarStatus(const Mago &); 
		void ganharXP(bool);
		bool batalhar();
		bool atacar(); 
		bool defender();
		bool verificarItem();
		void inventarioDoMago();
		void imprimirData() const;
		void equiparCajado();
		void guardarItem();
		
		friend ostream &operator<<(ostream &, const Mago &);
		const Mago &operator=(const Mago &);
		bool operator==(const Mago &) const;
		
	private:
		string nome;
		int forca;
		int defesa; // resistência a ataques físicos
	    int magia;
	    int defesaEspecial; // resistência a ataques mágicos
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
