#include <iostream>
#include"Mago.h"

using std::cout;

int main(int argc, char **argv){
	bool item, opcao; 
	
	Mago luz("Gandalf", 1);
	Mago trevas("Gandalf", 1);
	
	cout << "Mago de luz: " << luz;
	cout << "Mago de trevas: " << trevas;
	
	if(luz == trevas){
		cout << "Sao iguais\n" << endl;
	}
	else{
		cout << "Nao sao iguais\n" << endl;
	}
	
	luz.verificarStatus();
	system("pause");
	system("cls");
	luz.menuPrincipal();
	return 0;
}
