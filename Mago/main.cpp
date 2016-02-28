#include <iostream>
#include"Mago.h"

using std::cout;

int main(int argc, char **argv){
	bool opcao; 
	
	Mago luz("Gandalf", 1, 5);
	
	Mago::verificarStatus(luz);
	system("pause");
	system("cls");
	luz.menuPrincipal();
	system("cls");
	Mago::verificarStatus(luz);
	return 0;
}
