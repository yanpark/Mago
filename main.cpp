#include <iostream>
#include <stdlib.h>
#include"Personagem.h"
#include"Mago.h"
#include"Guerreiro.h"
#include"Wizard.h"
#include"Data.h"

using std::cout;

int main(int argc, char **argv){
	
	Mago luz("Gandalf", 1, 5);
	Mago trevas("Gandalf", 1, 5);
	Guerreiro g1("Auros", 1, 5);
	
	cout << "Mago de luz: " << luz;
	cout << "Mago de trevas: " << trevas;
	
	if(luz == trevas){
		cout << "Os magos sao iguais\n" << endl;
	}
	else{
		cout << "Os magos nao sao iguais\n" << endl;
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
