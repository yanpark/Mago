#include <iostream>
#include <string>

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

using namespace std;

class Personagem{
	
    friend ostream &operator<<(ostream &, const Personagem &);
    
    public:
        
        Personagem(const string &, int);
	    Personagem(const Personagem &);
	    ~Personagem();

        void menuPrincipal();
		void ganharXP(bool);
		bool verificarItem();
		void inventario();
        void guardarItem();
        virtual void verificarStatus() = 0;
        virtual void batalhar() = 0;
        virtual void atacar() = 0;
		virtual void defender() = 0;
		virtual void imprimirData() const = 0;
		
		const Personagem &operator=(const Personagem &);
		bool operator==(const Personagem &) const;
		
	protected:
		string nome;
        int hp;
        int level;
		int defesa; // resistência a ataques físicos
	    int defesaEspecial; // resistência a ataques mágico
        string item;
	    int opcao;
	    int dano;
        bool xp;
	    bool sucesso;
	    int itemInventario;
	    int cont;
	    int quantItens;
	    int aux;
        static int numeroDePersonagens;
        string *ptr_inventario;
	    string *nomeItens;
};

typedef struct{
    int hp_ini = 150;
    int forca_ini = 110;
    int def_esp_ini = 120;	
}Inimigo;

#endif
