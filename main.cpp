#include <iostream>
#include"Mago.h"
#include"Data.h"

using std::cout;

int main(int argc, char **argv){
	bool item, opcao; 
	
	Mago luz("Gandalf", 1);
	
	luz.verificarStatus();
	system("pause");
	system("cls");
	luz.menuPrincipal();
	return 0;
}
