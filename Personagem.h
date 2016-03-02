#include <iostream>
#include <string>
using namespace std;

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

class Personagem{
	
    friend ostream &operator<<(ostream &, const Personagem &);
    
    public:


		void menuPrincipal();
		static const void verificarStatus(const Personagem &); 
		void ganharXP(bool);
		bool batalhar();
		bool atacar(); 
		bool defender();
		bool verificarItem();
		void inventario();
		void imprimirData() const;
		void guardarItem();
		
		const Personagem &operator=(const Personagem &);
		bool operator==(const Personagem &) const;
		
	private:
		string nome;
		int defesa; // resistência a ataques físicos
	    int defesaEspecial; // resistência a ataques mágico
        string item;
	    int hp;
	    int level;
	    int opcao;
	    int dano;
	    bool sucesso;
	    bool xp;
	    string *ptr_inventario;
	    string *nomeItens;
	    int itemInventario = 7;
	    int cont = 0;
	    int quantItens;
	    int nItens;
	    int aux;
        static int numeroDePersonagens;
};

typedef struct{
	int hp_ini = 125;
	int forca_ini = 98 ;
	int def_esp_ini = 95;	
} Inimigo;
#endif // MAGO_H
