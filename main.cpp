#include <iostream>
#include <vector>
#include <stdlib.h>
#include"Personagem.h"
#include"Mago.h"
#include"Guerreiro.h"
#include"Wizard.h"
#include"Ranger.h"
#include"Data.h"

using std::cout;

int main(int argc, char **argv){
	
	Wizard m1("Gandalf", 1, 5);
	Wizard m2("Saruman", 10, 5);
	Ranger g1("Auros", 1, 5);
    Ranger g2("Soris", 1, 5);
	
	vector < Personagem * > personagens(4);
    
    personagens.push_back(&m1);
    personagens.push_back(&m2);
    personagens.push_back(&g1);
    personagens.push_back(&g2);
    
    system("pause");
	system("cls");
	Mago::verificarStatus(m1);
    system("pause");
	system("cls");
    Mago::verificarStatus(m2);
    system("pause");
	system("cls");
	Guerreiro::verificarStatus(g1);
	system("pause");
	system("cls");
    Guerreiro::verificarStatus(g2);
	system("pause");
	system("cls");
    g1.menuPrincipal();
	system("cls");
    Guerreiro::verificarStatus(g1);
	return 0;
}
