#include <iostream>
using std::cout;

#include"Mago.h"

int main(int argc, char **argv){
	bool opcao = true, item = true; 
	
	Mago luz;
	
	luz.verificarStatus();
	luz.batalhar(opcao);
	luz.verificarItem(item);
	return 0;
}
