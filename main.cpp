#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include"Personagem.h"
#include"Mago.h"
#include"Guerreiro.h"
#include"Data.h"

#include"Wizard.h"
#include"Sorcerer.h"
#include"Ranger.h"

using std::cout;

int main(int argc, char **argv){
    int opcao;
	
	Wizard w1("Gandalf", 1);
    Sorcerer s1("Soris", 1);
	Ranger r1("Auros", 1);
	
	vector < Personagem * > personagens(3);
    
    cout << "Escolha o personagem: " << endl << endl;
    cout << "1 - Mago " << endl;
    cout << "2 - Guerreiro Ranger " << endl << endl;
    cout << "Opcao: ";
    cin >> opcao;
    
	system("cls");
    if(opcao == 1){
        
        cout << "Escolha o Mago: " << endl << endl;
        cout << "1 - Wizard" << endl;
        cout << "2 - Sorcerer " << endl << endl;
        cout << "Opcao: ";
        cin >> opcao;
        
        if(opcao == 1){
            
            w1.verificarStatus();
            system("pause");
            system("cls");
            w1.menuPrincipal();
            system("cls");
            w1.verificarStatus();
        }
        else if(opcao == 2){
            s1.verificarStatus();
            system("pause");
            system("cls");
            s1.menuPrincipal();
            system("cls");
            s1.verificarStatus();
        }
    }
    else if(opcao == 2){
        r1.verificarStatus();
        system("pause");
        system("cls");
        r1.menuPrincipal();
        system("cls");
        r1.verificarStatus();
    }
    else{
        cout << "\n\nOpcao invalida" << endl;
    }
    return 0;
}