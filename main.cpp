#include <iostream>
#include <stdlib.h>
#include"Personagem.h"
#include"Mago.h"
#include"Guerreiro.h"
#include"Wizard.h"
#include"Ranger.h"
#include"Data.h"

using std::cout;

int main(int argc, char **argv){
	
	Wizard luz("Gandalf", 1, 5);
	Wizard trevas("Saruman", 10, 5);
	Ranger g1("Auros", 1, 5);
    Ranger g2("Soris", 1, 5);
	
	cout << "Mago de luz: " << luz;
	cout << "Mago de trevas: " << trevas;
    
    cout << "Guerreiro g1: " << g1;
    cout << "Guerreiro g2: " << g2;
	
	if(luz == trevas){
		cout << "Os magos sao iguais\n" << endl;
	}
	else{
		cout << "Os magos nao sao iguais\n" << endl;
	}
	
    if(g1 == g2){
		cout << "Os guerreiros sao iguais\n" << endl;
	}
	else{
		cout << "Os guerreiros nao sao iguais\n" << endl;
	}
    
	Mago::verificarStatus(luz);
    system("pause");
	system("cls");
	Guerreiro::verificarStatus(g1);
	system("pause");
	system("cls");
	g1.menuPrincipal();
	system("cls");
	Guerreiro::verificarStatus(g1);
	return 0;
}
