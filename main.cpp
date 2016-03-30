#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include"Personagem.h"
#include"Mago.h"
#include"Guerreiro.h"
#include"Data.h"

#include"Wizard.h"
#include"Ranger.h"

using std::cout;

int main(int argc, char **argv){
    int opcao;
	
	Wizard m1("Gandalf", 1, 5);
	Ranger g1("Auros", 1, 5);
	
	vector < Personagem * > personagens(4);
    
    personagens.push_back(&m1);
    personagens.push_back(&g1);
    
    cout << "Escolha o personagem: " << endl << endl;
    cout << "1 - Wizard Gandalf" << endl;
    cout << "2 - Ranger Auros " << endl << endl;
    cout << "Opcao: ";
    cin >> opcao;
    system("cls");
    
    switch(opcao){
		case 1: Wizard::verificarStatus(m1);
                system("pause");
                system("cls");
                m1.menuPrincipal();
                system("cls");
                Wizard::verificarStatus(m1);
				break;
		case 2: Ranger::verificarStatus(g1);
                system("pause");
                system("cls");
                g1.menuPrincipal();
                system("cls");
                Ranger::verificarStatus(g1);
				break;
		default: cout << "\n\nOpcao invalida.\n" << endl;
				break;
	}
    
    personagens[opcao] -> menuPrincipal();
    personagens[opcao] -> imprimirData();
    
    for(size_t i = 0; i < personagens.size(); i++){
	
        Wizard *derivedPtr = dynamic_cast<Wizard*> (personagens[i]);
        Ranger *derivedPtr2 = dynamic_cast<Ranger*> (personagens[i]);
        
        if (derivedPtr != 0){
            derivedPtr -> verificarStatus(m1);
        }
        if (derivedPtr2 != 0){
            derivedPtr -> verificarStatus(g1);
        }
    }
    return 0;
}
