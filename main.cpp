#include <iostream>
using std::cout;

#include"Mago.h"

int main(int argc, char **argv){
	bool item, opcao; 
	
	Mago luz("Gandalf", 1);
	Mago trevas("Saruman", 10);
	
	luz.verificarStatus();
	system("cls");
	cout << "1. Entrar em batalha" << endl;
	cout << "0. Recolher item\n" << endl;
	cout << "Escolha uma das opcoes acima: ";
	cin >> opcao;
	system("cls");
	switch(opcao){
		case 0: luz.verificarItem(item);
				break;
		case 1: luz.batalhar();
				break;
		default: cout << "\n\nOpcao invalida.\n" << endl;
				break;
	}
	return 0;
}
