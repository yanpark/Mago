#include <iostream>
#include"Mago.h"

using std::cout;

int main(int argc, char **argv){
	bool opcao; 
	
	Mago luz("Gandalf", 1, 5);
	Mago trevas("Gandalf", 1, 5);
	
	cout << "Mago de luz: " << luz;
	cout << "Mago de trevas: " << trevas;
	
	if(luz == trevas){
		cout << "Os magos sao iguais\n" << endl;
	}
	else{
		cout << "Os magos nao sao iguais\n" << endl;
	}
	
	luz.verificarStatus();
	system("pause");
	system("cls");
	luz.menuPrincipal();
	return 0;
}
