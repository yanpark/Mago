#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>
using namespace std;

class Personagem{
	
    friend ostream &operator<<(ostream &, const Personagem &);
    
    public:
        
        Personagem(const string &, int, const int &);
	    Personagem(const Personagem &);
	    ~Personagem();

        static const void verificarStatus(const Personagem &); 
		void ganharXP(bool);
		bool verificarItem();
		void inventario();
		void imprimirData() const;
		void guardarItem();
		
		const Personagem &operator=(const Personagem &);
		bool operator==(const Personagem &) const;
		
	protected:
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
	    int itemInventario;
	    int cont;
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
